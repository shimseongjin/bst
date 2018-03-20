#include "header.h"
int comparename(student e1, student e2)  // 이름 비교
{
	return strcmp(e1.name, e2.name);
}
TreeNode *searchname(TreeNode *root, student item) // 이름으로 조회해서 주소값 반환
{
	TreeNode *p = root;
	while (p != NULL){
		switch (comparename(item, p->s)){
		case -1:
			p = p->left;
			break;
		case 0:
			return p;
		case 1:
			p = p->right;
			break;
		}
	}
	return p;
}
void insert_nodename(TreeNode **root, student input) // 이름 순으로 삽입
{
	TreeNode *p, *t;
	TreeNode *n;

	t = *root;
	p = NULL;

	while (t != NULL){
		if (comparename(input, t->s) == 0){ // 같은 이름이라면
			strcat(input.name, "I"); // 변수이름을 다르게 바꿔줌
		}
		p = t;
		if (comparename(input, t->s) < 0) t = t->left;
		else t = t->right;
	}

	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) return;

	n->s = input;
	n->left = n->right = NULL;

	if (p != NULL){
		if (comparename(input, p->s) < 0){
			p->left = n;
		}
		else{
			p->right = n;
		}
	}
	else *root = n;
}
void delete_nodename(TreeNode **root, student item) // 이름 정보를 받아와서 있으면 삭제
{
	TreeNode *p, *child, *succ, *succ_p, *t;

	p = NULL;
	t = *root;
	while (t != NULL&&comparename(t->s, item) != 0){
		p = t;
		t = (comparename(item, t->s)<0) ? t->left : t->right;
	}
	if (t == NULL){ // 존재하지 않는 이름이면 리턴
		printf("없는 학생입니다.\n");
		return;
	}
	if ((t->left == NULL) && (t->right == NULL)){
		if (p != NULL){
			if (p->left == t)
				p->left = NULL;
			else p->right = NULL;
		}
		else
			*root = NULL;
	}
	else if ((t->left == NULL) || (t->right == NULL)){
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL){
			if (p->left == t)
				p->left = child;
			else p->right = child;
		}
		else
			*root = child;
	}
	else{
		succ_p = t;
		succ = t->right;
		while (succ->left != NULL){
			succ_p = succ;
			succ = succ->left;
		}
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;

		t->s = succ->s;
		t = succ;
	}
	free(t);
}