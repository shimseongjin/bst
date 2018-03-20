#include "header.h"
void print(){
	printf("이름	성별	나이	학번		전화번호	학년	학점\n");
}
void main()
{
	TreeNode *id_root = NULL;      //학번 기준 이진트리
	TreeNode *name_root = NULL;  //이름 기준 이진트리

	TreeNode *temp=NULL;             // 탐색 트리
	TreeNode *temp2=NULL;
	int sel1, sel2, sel3, sel4, sel5,sel6;
	int i, len;
	int count = 0;
	char passward[10];
	char inputpassward[10];
	char ch;
	char str[20];

	student input, input2, input3;
	FILE * fp = fopen("data.txt", "rt");
	FILE * pass = fopen("pass.txt", "ab");
	fseek(pass, 0, SEEK_END);
	if (ftell(pass) ==  0){ // pass 파일이 비어있으면 0000 저장
		fprintf(pass, "%s", "0000");
		strcpy(passward,"0000");
	}
	fclose(pass);

	pass = fopen("pass.txt", "rb+");
	fscanf(pass, "%s ", passward);
	fclose(pass);
	pass = fopen("pass.txt", "wt");
	if (fp == NULL){
		puts("파일오픈 실패!");
		return -1;
	}
	while ((ch = fgetc(fp)) != EOF){
		if (ch == '\n') { count += 1; }
	}
	rewind(fp);

	for (i = 0; i < count; i++){
		
		fscanf(fp, "%s	%s	%d	%d	%d	%d	%f", input.name, input.sex, &input.age, &input.id, &input.phonenumber, &input.grade, &input.score);
		insert_nodename(&name_root, input); // 입력값을 암호화하여 이름 기준 루트에 삽입
		insert_node(&id_root, input);       // 입력값을 암호화하여 학번 기준 루트에 삽입
	}
	fclose(fp);
	do{
		printf("1.관리자 모드 2. 사용자 모드 3. 종료 \n");
		scanf("%d", &sel1);
		if (sel1 == 1){
			printf("비밀번호를 입력하시오 (초기 비밀번호 0000) : \n");
			scanf("%s", inputpassward);
			if (!strcmp(passward,inputpassward)){
				printf("로그인 되었습니다.\n");
				do{
					printf("1. 추가 2. 수정 3. 삭제 4. 조회 5. 전체 출력 6. 비밀번호 변경 7. 종료\n");
					scanf("%d", &sel2);
					switch (sel2){
					case 1:
						printf("이름:");
						scanf("%s", input.name);
						printf("성별:");
						scanf("%s", input.sex);
						printf("나이:");
						scanf("%d", &input.age);
						printf("학번:");
						scanf("%d", &input.id);
						printf("전화번호:");
						scanf("%d", &input.phonenumber);
						printf("학년:");
						scanf("%d", &input.grade);
						printf("학점:");
						scanf("%f", &input.score);
						
						insert_node(&id_root, input);
						insert_nodename(&name_root, input);
						fp = fopen("data.txt", "wt");    // 파일에 새로 쓰기 위함
						rewind(fp);
						save(name_root, fp);
						printf("학생 정보 추가가 완료 되었습니다!\n");
						fclose(fp);
						break;
					case 2:
						printf("수정하려는 학생의 학번을 입력하십시오 : \n");
						scanf("%d", &input.id);
						
						temp = search(id_root, input); // 입력에 따라 트리에 있는 노드의 주소값 반환
						if (temp == NULL){ printf("명단에 없는 학생 이름입니다.\n"); } // 없는 학번이면
						else{
							input3 = temp->s;                   // 학번을 통해 알아낸 노드의 이름을 얻기위함
							if (temp != NULL){                   // 존재하는 학번이면
								printf("수정할 정보를 입력하십시오. \n");
								printf("이름 :");
								scanf("%s", input2.name);
								printf("성별 :");
								scanf("%s", input2.sex);
								printf("나이 :");
								scanf("%d", &input2.age);
								printf("학번 :");
								scanf("%d", &input2.id);
								printf("전화번호 :");
								scanf("%d", &input2.phonenumber);
								printf("학년 :");
								scanf("%d", &input2.grade);
								printf("학점 :");
								scanf("%f", &input2.score);
								temp->s = input2;
							}
							temp2 = searchname(name_root, input3); 
							if (temp != NULL){
								temp2->s = input2;
							}

						}
						fp = fopen("data.txt", "wt");
						rewind(fp);
						save(id_root, fp);
						fclose(fp);
						
						printf("수정이 완료되었습니다!\n");
						break;
					case 3:
						printf("삭제할 학생의 이름을 입력하세요 :\n");
						scanf("%s", input.name);
						print();
						stuchart(name_root, input);  // 같은 이름이 있다면 확인 시키기 위해 출력
						printf("삭제할 학생의 이름을 한번 더 입력하세요 :\n");
						scanf("%s", input.name);

						temp = searchname(name_root, input); // 입력에 따라 트리에 있는 노드의 주소값 반환
						if (temp == NULL){printf("명단에 없는 학생 이름입니다.\n");}
						else{
							input2 = temp->s;
							delete_nodename(&name_root, input);
							delete_node(&id_root, input2);
							printf("삭제가 완료 되었습니다\n");
							fp = fopen("data.txt", "wt");
							rewind(fp);
							save(id_root, fp);

							fclose(fp);
						}
						break;
					case 4:
						printf("1. 이름으로 조회 2. 학번으로 조회\n");

						scanf("%d", &sel4);
						if (sel4 == 1){
							printf("이름을 입력하십시오. \n");
							scanf("%s", input.name);
							print();
							stuchart(name_root, input); // 같은 이름이면 모두 출력
						}
						else if (sel4 == 2)
						{
							printf("학번을 입력하십시오. \n");
							scanf("%d", &input.id);
							print();
							temp = search(id_root, input);
							if (temp != NULL){
								printf("%s\t%s\t%d\t%d\t%d\t%d\t%f\n", temp->s.name, temp->s.sex, temp->s.age, temp->s.id, temp->s.phonenumber, temp->s.grade, temp->s.score);
							}
						}
						break;
					case 5:

						do{
							printf("1. 이름 기준 출력 2. 학번 기준 출력 3. 종료\n");
							scanf("%d", &sel3);
							if (sel3 == 1){
								print();
								display(name_root); // 이름기준으로 출력
							}
							else if (sel3 == 2){
								print();
								display(id_root);   // 학번기준으로 출력
							}
						} while (sel3 != 3);
						break;
					case 6:
						printf("변경할 비밀번호를 입력하시오.\n");
						scanf("%s", passward);
						rewind(pass);
						fprintf(pass,"%s", passward);
						printf("비밀번호가 변경되었습니다!\n");
						break;
					case 7:
						break;
					}

				} while (sel2 != 7);
			}
			else
			{
				printf("비밀번호가 틀렸습니다.\n");
			}
		}
		else if (sel1 == 2){
			printf("1. 조회 2. 전체 출력 3. 종료\n");

			scanf("%d", &sel5);
			if (sel5 == 1){
				printf("1. 이름으로 조회 2. 학번으로 조회\n");

				scanf("%d", &sel6);
				if (sel6 == 1){
					scanf("%s", input.name);
					print();
					stuchart(name_root, input);   // 조회했을때 이름이 같다면 모두 출력
				}
				else if (sel6 == 2)
				{
					scanf("%d", &input.id);
					temp = search(id_root, input);

					if (temp != NULL){
						printf("%s\t%s\t%d\t%d\t%d\t%d\t%f\n", temp->s.name, temp->s.sex, temp->s.age, temp->s.id, temp->s.phonenumber, temp->s.grade, temp->s.score);
					}
				}
			}
			else if (sel5 == 2){
				do{
					printf("1. 이름 기준 출력 2. 학번 기준 출력 3. 종료\n");
					scanf("%d", &sel6);
					if (sel6 == 1){
						print();
						display(name_root);
					}
					else if (sel6 == 2){
						print();
						display(id_root);
					}
					else if (sel6 == 3){
						break;
					}
					else
						printf("다시 입력하세요\n");
				} while (sel6 != 3);
				break;
			}
			else{
				break;
			}
		}
	} while (sel1 != 3);
	fp = fopen("data.txt", "wt");
	save(name_root,fp);
	fclose(pass);
	pass = fopen("pass.txt", "wt");
	fprintf(pass, "%s", passward);
	fclose(fp);
	fclose(pass);
}