#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "other.h"

#define TRUE  1
#define FALSE 0

int max(int num1,int num2) {
	if (num1 > num2) {
		return num1;
	}else {
		return num2;
	}
}

int add(int num1,int num2);

int b = 13;

extern int c;

//����ָ��
typedef int (*fun_ptr)(int, int);//����һ��ָ��ͬ������������ֵ�ĺ���ָ��

//ָ�뺯��
int* sub(int num1, int num2) {
	int result = num1 - num2;
	return &result;

}

//�ص�����
void pop_array(int *array,int arraySize,int (*getNextValue)(void)) {
	for (int i = 0; i < arraySize;i++) {
	 
		array[i] = getNextValue();
	
	}

}

//��ȡ���ֵ
int getNextRandomValue(void)
{
	return rand();
}

//�ṹ��
struct Books {
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
} book = {"C ����","RUNOOB","�������",123456};


typedef struct Bookss
{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
} Book;



void printBooks(struct Books book1) {
	printf(" title: %s\n author: %s\n subject: %s\n book_id: %d\n", book1.title, book1.author, book1.subject, book1.book_id);
}


void printBooks(struct Books *book1) {
	printf(" title: %s\n author: %s\n subject: %s\n book_id: %d\n", book1->title, book1->author, book1->subject, book1->book_id);
}

int main() {
	printf("\n\n=======================�����﷨============================\n");
	printf("Hello Word!\n");


	printf("\n\n=======================��    ��============================\n");

	printf("����max(50,60): %d\n",max(50,60));
 

	printf("����add(50,60): %d\n", add(50, 60));



	printf("\n\n=======================�ֲ�����============================\n");

	int a = 10;
	printf("�ֲ����� a =  %d",a);

	printf("\n\n=======================ȫ�ֱ���============================\n");

	printf("ȫ�ֱ��� b =  %d", b);

	printf("\n\n=======================extern����============================\n");

	printf("extern���� c =  %d", c);
	printf("\n\n=======================��    ��============================\n");

	int n[10];
	int i, j;

	for (i = 0; i < 10;i++) {
		n[i] = i + 100;
	}


	for (j = 0; j < 10; j ++) {
	
		printf("Element[%d] = %d\n",j,n[j]);
	
	}

	printf("\n\n=======================ö    ��============================\n");

	enum DAY {
		MON = 1,TUE,WED,THU,FRI,SAT,SUN

	};

	enum DAY day;

	day = SUN;
	printf("day=%d\n", day);


	printf("\n\n=======================ָ    ��============================\n");
	int var = 10;
	int* p;

	p = &var;

	printf("p = %p \n *p = %d",p,*p);



	printf("\n\n=======================����ָ��============================\n");
	//����ָ���� ָ�룬��һ��ָ������ָ��

	//fun_ptr = &max;

	//printf("fun_ptr(12,13) = %d", fun_ptr(12, 13));

	int (*ptr)(int,int) = &add;

	printf("ptr(12,13) = %d", ptr(12, 13));



	printf("\n\n=======================ָ�뺯��============================\n");
	//ָ�뺯���Ǻ�������һ������ָ��ĺ���


	printf("sub(12,13) = %d", *sub(12, 13));


	printf("\n\n=======================�ص�����============================\n");

	int myArray[10];

	pop_array(myArray, 10, getNextRandomValue);

		for (int k = 0; k < 10;k++) {
			printf("%d\n", myArray[k]);
		}



	printf("\n\n=======================��  ��  ��============================\n");
	char site[7] = "RUNOOB";
	printf("site=%s\n",site);

	char str1[14] = "runoob";
	char str2[14] = "google";
	char str3[14];
	int len;

	strcpy(str3,str1);
	printf("����str1��str3 -> strcpy(str3,str1): %s\n", str3);


	strcat(str1,str2);
	printf("���� str1 �� str2 -> strcat(str1,str2): %s \n",str1);


	len = strlen(str1);
	printf("strlen(str1) : %d\n",len);


	printf("\n\n=======================��  ��  ��============================\n");

	printf(" title: %s\n author: %s\n subject: %s\n book_id: %d",book.title,book.author,book.subject,book.book_id);


	struct Books book1;
	struct Books book2;

	strcpy(book1.title,"C ����");
	strcpy(book1.author, "Lime");
	strcpy(book1.subject, "C Tutorial");
	book1.book_id = 123456;


	strcpy(book2.title, "LUA ����");
	strcpy(book2.author, "Jeek");
	strcpy(book2.subject, "Lua Tutorial");
	book2.book_id = 654321;


	printBooks(book1);

	printBooks(book2);


	printf("\n\n=======================�ṹ��ָ��============================\n");

	printBooks(&book1);


	printf("\n\n=======================C typedef============================\n");

	typedef unsigned int INT;
	INT a1 = 10, b1 = 20;


	printf("a1 = %d   b1 = %d\n",a1,b1);

	Book book3;


	strcpy(book3.title, "C++ ����");
	strcpy(book3.author, "Jeek");
	strcpy(book3.subject, "C++ Tutorial");
	book3.book_id = 654321;

	printf(" title: %s\n author: %s\n subject: %s\n book_id: %d\n", book3.title, book3.author, book3.subject, book3.book_id);



	printf("\n\n=======================C define============================\n");

	printf("TRUE = %d\n",TRUE);
	printf("FALSE = %d\n", FALSE);


	printf("\n\n=======================�ļ�����============================\n");

	//���ļ���д������
	FILE* fp = NULL;

	fp = fopen("D:\\cpp\\test.txt", "a+");
	fprintf(fp, "This is testing for fprintf...\n");
	fputs("This is testing for fputs...\n", fp);
	fclose(fp);

	//��ȡ�ļ�������
	FILE* file = NULL;
	char buff[255];

	file = fopen("D:\\cpp\\test.txt","r");
	fgets(buff, 1024, (FILE*)fp);
	printf("content: %s\n", buff);



	printf("\n\n\n=======================   end   ============================\n\n\n");
	return 0;

}

int add(int num1, int num2) {

	return num1 + num2;

}