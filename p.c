
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student {
	char address[20];
	char phone[20];
	char name[20];
	char email[20];
}student;

#define FILENAME "data.txt"

void menu() {
	printf("        Main Menu \n");
	printf("========================== \n");
	printf("[1] Add a new Contact \n");
	printf("[2] List all Contacts \n");
	printf("[3] Search for contact \n");
	printf("[4] Edit a Contact \n");
	printf("[5] Delete a Contact \n");
	printf("[0] Exit \n");
	printf("=========================== \n");
	printf("Enter the choice : ");





}

int datanum(FILE* fp) {
	int filesize;
	int n;
	fseek(fp, 0, SEEK_END);
	filesize = ftell(fp);
	n = filesize / sizeof(student); //������ ���� 

	return n;
}

void view_data(student* data)
{
	printf("Name-%s \n��ȭ��ȣ-%s,  \nAddress : %s\nEmail-%s \n\n", data->name, data->phone, data->address, data->email);
	printf("========================\n");
}


void add(FILE* fp) {
	student data;
	printf("\n================================\n ");
	printf("  ADD A NEW CONTACT\n");
	printf("Name :");
	scanf("%s", data.name);
	printf("Phone : ");
	scanf("%s", data.phone);
	printf("Address : ");
	scanf("%s", data.address);
	printf("Email : ");
	scanf("%s", data.email);
	printf("\n================================\n ");



	fseek(fp, 0, SEEK_END); //������ �̵�
	fwrite(&data, sizeof(data), 1, fp);
}


void list(FILE* fp)
{
	student data;
	int nd;
	nd = datanum(fp);
	printf("\n================================\n ");
	printf("  LIST OF CONTACTS\n");





	fseek(fp, 0, SEEK_SET);
	while (nd--) {
		fread(&data, sizeof(data), 1, fp);
		view_data(&data);
	}
	printf("\n================================\n ");
}

void search(FILE* fp) {

	student data;
	char search_name[20]; //ã�� �̸�
	int n;
	int nd;

	printf("\n================================\n ");
	printf("  SEARCH FOR CONTACT\n");
	nd = datanum(fp);

	printf("search name :");
	scanf("%s", search_name);

	fseek(fp, 0, SEEK_SET); //ó������ �̵�
	for (n = 0; n < nd; n++) {
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(data.name, search_name) == 0)break;
	}

	view_data(&data);
}

void edit(FILE* fp) {//����ó ����

	student data;

	printf("\n================================\n");
	printf("             EDIT A CONTACT");

	// ������ ����ó ���� > ����

	char edit_contact[20]; //������ ����ó

	printf("edit contact : ");
	scanf("%s", edit_contact);



	printf("\n===============================\n");








}

void delete(FILE* fp) { //����ó ����

	student data;

	printf("\n================================\n ");
	printf("    Delete contacts\n");

	remove(fp);

	char delete[25] = "����ó�� �����Ǿ����ϴ�.";

	fseek(fp, 0, SEEK_SET);

	fwrite(*delete, sizeof(delete), 1, fp);

	fseek(fp, 0, SEEK_SET);

	fread(*delete, sizeof(delete), 1, fp);


	printf("\n===============================\n");

}


void main() {
	FILE* fp;
	int menunum;

	if ((fp = fopen(FILENAME, "r+b")) == NULL) {
		//���� �� ������ 
		fp = fopen(FILENAME, "w+b");
		if (fp == NULL) {
			printf("������ �� �� �����ꈕ. \n");
			exit(0);
		}
	}

	while (1) {
		do {
			menu();
			scanf("%d", &menunum);
		} while (menunum < 1 || menunum >6);
		if (menunum == 6)break;
		switch (menunum) {
		case 1: add(fp);
			break;
		case 2: list(fp);
			break;
		case 3: search(fp);
			break;
		case 4: edit(fp);
			break;
		case 5: delete(fp);
			break;
		}
	}
}