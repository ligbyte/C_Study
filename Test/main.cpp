#include <stdio.h>
#include <stdlib.h>

int main() {
	//���ļ���д������
	FILE* fp = NULL;

	fp = fopen("D:\\cpp\\test.txt", "a+");
	fprintf(fp, "This is testing for fprintf...\n");
	fputs("This is testing for fputs...\n", fp);
	fclose(fp);
	system("pause");
	return 0;

}