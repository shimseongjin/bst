#include "header.h"
int compare(student e1, student e2)  // 학번 비교 하여 값 반환
{
	if (e1.id > e2.id){
		return 1;
	}
	else if (e1.id < e2.id)
	{
		return -1;
	}
	else
		return 0;
}
TreeNode *search(TreeNode *root, student item) // 학번으로 조회해서 주소값 반환
{
	TreeNode *p = root;
	while (p != NULL){
		switch (compare(item, p->s)){
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
void insert_node(TreeNode **root, student input) // 학번 순으로 삽입
{
	TreeNode *p, *t;
	TreeNode *n;

	t = *root;
	p = NULL;

	while (t != NULL){
		if (compare(input, t->s) == 0) return;
		p = t;
		if (compare(input, t->s)<0) t = t->left;
		else t = t->right;
	}

	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL) return;

	n->s = input;
	n->left = n->right = NULL;

	if (p != NULL){
		if (compare(input, p->s)<0){
			p->left = n;
		}
		else{
			p->right = n;
		}
	}
	else *root = n;
}
void delete_node(TreeNode **root, student item)  // 학번 정보를 받아와서 있으면 삭제
{
	TreeNode *p, *child, *succ, *succ_p, *t;

	p = NULL;
	t = *root;
	while (t != NULL&&compare(t->s, item) != 0){
		p = t;
		t = (compare(item, t->s)<0) ? t->left : t->right;
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