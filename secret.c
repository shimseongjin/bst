#include "header.h"

void Xor(int *input, int *secret, int *result){ // 입력값을 받아 xor하여 준다
	*result = *input^*secret;
}
void InXor(student *input)   // 학번과 휴대폰 번호를 xor한다.
{
	
	int result;
	int secret = 11333;

	Xor(&input->id, &secret, &result);
	input->id = result;
	Xor(&input->phonenumber, &secret, &result);
	input->phonenumber = result;
}
void OutXor(TreeNode *a, TreeNode *b)  // 학번과 휴대폰 번호를 xor하고 나머지 정보는 그대로 저장한다.
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