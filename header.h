
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
typedef struct{                // �л� ���� ����ü
	char name[15];
	char sex[10];
	int age;
	int id;
	int phonenumber;
	int grade;
	float score;
}student;

typedef struct TreeNode {    // ���� Ʈ�� ����ü
	student s;
	struct TreeNode *left, *right;
}TreeNode;