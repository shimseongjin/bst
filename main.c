#include "header.h"
void print(){
	printf("�̸�	����	����	�й�		��ȭ��ȣ	�г�	����\n");
}
void main()
{
	TreeNode *id_root = NULL;      //�й� ���� ����Ʈ��
	TreeNode *name_root = NULL;  //�̸� ���� ����Ʈ��

	TreeNode *temp=NULL;             // Ž�� Ʈ��
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
	if (ftell(pass) ==  0){ // pass ������ ��������� 0000 ����
		fprintf(pass, "%s", "0000");
		strcpy(passward,"0000");
	}
	fclose(pass);

	pass = fopen("pass.txt", "rb+");
	fscanf(pass, "%s ", passward);
	fclose(pass);
	pass = fopen("pass.txt", "wt");
	if (fp == NULL){
		puts("���Ͽ��� ����!");
		return -1;
	}
	while ((ch = fgetc(fp)) != EOF){
		if (ch == '\n') { count += 1; }
	}
	rewind(fp);

	for (i = 0; i < count; i++){
		
		fscanf(fp, "%s	%s	%d	%d	%d	%d	%f", input.name, input.sex, &input.age, &input.id, &input.phonenumber, &input.grade, &input.score);
		insert_nodename(&name_root, input); // �Է°��� ��ȣȭ�Ͽ� �̸� ���� ��Ʈ�� ����
		insert_node(&id_root, input);       // �Է°��� ��ȣȭ�Ͽ� �й� ���� ��Ʈ�� ����
	}
	fclose(fp);
	do{
		printf("1.������ ��� 2. ����� ��� 3. ���� \n");
		scanf("%d", &sel1);
		if (sel1 == 1){
			printf("��й�ȣ�� �Է��Ͻÿ� (�ʱ� ��й�ȣ 0000) : \n");
			scanf("%s", inputpassward);
			if (!strcmp(passward,inputpassward)){
				printf("�α��� �Ǿ����ϴ�.\n");
				do{
					printf("1. �߰� 2. ���� 3. ���� 4. ��ȸ 5. ��ü ��� 6. ��й�ȣ ���� 7. ����\n");
					scanf("%d", &sel2);
					switch (sel2){
					case 1:
						printf("�̸�:");
						scanf("%s", input.name);
						printf("����:");
						scanf("%s", input.sex);
						printf("����:");
						scanf("%d", &input.age);
						printf("�й�:");
						scanf("%d", &input.id);
						printf("��ȭ��ȣ:");
						scanf("%d", &input.phonenumber);
						printf("�г�:");
						scanf("%d", &input.grade);
						printf("����:");
						scanf("%f", &input.score);
						
						insert_node(&id_root, input);
						insert_nodename(&name_root, input);
						fp = fopen("data.txt", "wt");    // ���Ͽ� ���� ���� ����
						rewind(fp);
						save(name_root, fp);
						printf("�л� ���� �߰��� �Ϸ� �Ǿ����ϴ�!\n");
						fclose(fp);
						break;
					case 2:
						printf("�����Ϸ��� �л��� �й��� �Է��Ͻʽÿ� : \n");
						scanf("%d", &input.id);
						
						temp = search(id_root, input); // �Է¿� ���� Ʈ���� �ִ� ����� �ּҰ� ��ȯ
						if (temp == NULL){ printf("��ܿ� ���� �л� �̸��Դϴ�.\n"); } // ���� �й��̸�
						else{
							input3 = temp->s;                   // �й��� ���� �˾Ƴ� ����� �̸��� �������
							if (temp != NULL){                   // �����ϴ� �й��̸�
								printf("������ ������ �Է��Ͻʽÿ�. \n");
								printf("�̸� :");
								scanf("%s", input2.name);
								printf("���� :");
								scanf("%s", input2.sex);
								printf("���� :");
								scanf("%d", &input2.age);
								printf("�й� :");
								scanf("%d", &input2.id);
								printf("��ȭ��ȣ :");
								scanf("%d", &input2.phonenumber);
								printf("�г� :");
								scanf("%d", &input2.grade);
								printf("���� :");
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
						
						printf("������ �Ϸ�Ǿ����ϴ�!\n");
						break;
					case 3:
						printf("������ �л��� �̸��� �Է��ϼ��� :\n");
						scanf("%s", input.name);
						print();
						stuchart(name_root, input);  // ���� �̸��� �ִٸ� Ȯ�� ��Ű�� ���� ���
						printf("������ �л��� �̸��� �ѹ� �� �Է��ϼ��� :\n");
						scanf("%s", input.name);

						temp = searchname(name_root, input); // �Է¿� ���� Ʈ���� �ִ� ����� �ּҰ� ��ȯ
						if (temp == NULL){printf("��ܿ� ���� �л� �̸��Դϴ�.\n");}
						else{
							input2 = temp->s;
							delete_nodename(&name_root, input);
							delete_node(&id_root, input2);
							printf("������ �Ϸ� �Ǿ����ϴ�\n");
							fp = fopen("data.txt", "wt");
							rewind(fp);
							save(id_root, fp);

							fclose(fp);
						}
						break;
					case 4:
						printf("1. �̸����� ��ȸ 2. �й����� ��ȸ\n");

						scanf("%d", &sel4);
						if (sel4 == 1){
							printf("�̸��� �Է��Ͻʽÿ�. \n");
							scanf("%s", input.name);
							print();
							stuchart(name_root, input); // ���� �̸��̸� ��� ���
						}
						else if (sel4 == 2)
						{
							printf("�й��� �Է��Ͻʽÿ�. \n");
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
							printf("1. �̸� ���� ��� 2. �й� ���� ��� 3. ����\n");
							scanf("%d", &sel3);
							if (sel3 == 1){
								print();
								display(name_root); // �̸��������� ���
							}
							else if (sel3 == 2){
								print();
								display(id_root);   // �й��������� ���
							}
						} while (sel3 != 3);
						break;
					case 6:
						printf("������ ��й�ȣ�� �Է��Ͻÿ�.\n");
						scanf("%s", passward);
						rewind(pass);
						fprintf(pass,"%s", passward);
						printf("��й�ȣ�� ����Ǿ����ϴ�!\n");
						break;
					case 7:
						break;
					}

				} while (sel2 != 7);
			}
			else
			{
				printf("��й�ȣ�� Ʋ�Ƚ��ϴ�.\n");
			}
		}
		else if (sel1 == 2){
			printf("1. ��ȸ 2. ��ü ��� 3. ����\n");

			scanf("%d", &sel5);
			if (sel5 == 1){
				printf("1. �̸����� ��ȸ 2. �й����� ��ȸ\n");

				scanf("%d", &sel6);
				if (sel6 == 1){
					scanf("%s", input.name);
					print();
					stuchart(name_root, input);   // ��ȸ������ �̸��� ���ٸ� ��� ���
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
					printf("1. �̸� ���� ��� 2. �й� ���� ��� 3. ����\n");
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
						printf("�ٽ� �Է��ϼ���\n");
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