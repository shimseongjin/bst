#include "header.h"

void Xor(int *input, int *secret, int *result){ // �Է°��� �޾� xor�Ͽ� �ش�
	*result = *input^*secret;
}
void InXor(student *input)   // �й��� �޴��� ��ȣ�� xor�Ѵ�.
{
	
	int result;
	int secret = 11333;

	Xor(&input->id, &secret, &result);
	input->id = result;
	Xor(&input->phonenumber, &secret, &result);
	input->phonenumber = result;
}
void OutXor(TreeNode *a, TreeNode *b)  // �й��� �޴��� ��ȣ�� xor�ϰ� ������ ������ �״�� �����Ѵ�.
{
	int result;
	int secret = 11333;
	
	b->s.age= a->s.age;
	b->s.grade = a->s.grade;
	strcpy(b->s.name ,a->s.name);
	strcpy(b->s.sex, a->s.sex);
	b->s.score = a->s.score;
	Xor(&a->s.id, &secret, &result);
	b->s.id = result;
	Xor(&a->s.phonenumber, &secret, &result);
	b->s.phonenumber = result;
}