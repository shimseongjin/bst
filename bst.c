#include "header.h"
void save(TreeNode *p, FILE *fp) // 순회하여 파일에 저장
{
	
	if (p)
	{
		save(p->left,fp);
		TreeNode *n = (TreeNode*)malloc(sizeof(TreeNode));
		
		OutXor(p, n); // 암호화(xor) 시킴
		fprintf(fp, "%s\t%s\t%d\t%d\t%d\t%d\t%f\n", n->s.name, n->s.sex, n->s.age, n->s.id, n->s.phonenumber, n->s.grade, n->s.score);
		free(n);
		
		save(p->right,fp);
	}
	
}
void display(TreeNode *p) // 순회하여 출력
{
	if (p != NULL) {
		display(p->left);
		printf("%s	%s	%d	%d	%d	%d	%f\n", p->s.name, p->s.sex, p->s.age, p->s.id, p->s.phonenumber, p->s.grade, p->s.score);
		display(p->right);
	}
}
void stuchart(TreeNode *p, student input) ///이름이 같은 사람의 정보 출력
{
	if (p != NULL) {
		stuchart(p->left, input);
		if (strncmp(input.name, p->s.name, strlen(input.name)) == 0)
		{
			printf("%s	%s	%d	%d	%d	%d	%f\n", p->s.name, p->s.sex, p->s.age, p->s.id, p->s.phonenumber, p->s.grade, p->s.score);
		}
		stuchart(p->right, input);
	}
}





