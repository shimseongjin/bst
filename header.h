
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
typedef struct{                // 학생 정보 구조체
	char name[15];
	char sex[10];
	int age;
	int id;
	int phonenumber;
	int grade;
	float score;
}student;

typedef struct TreeNode {    // 이진 트리 구조체
	student s;
	struct TreeNode *left, *right;
}TreeNode;