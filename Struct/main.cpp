#include <stdio.h>

struct student_st
{
	char c;
	int score;
	const char* name;
};

static void show_student(struct student_st* stu)
{
	printf("c = %c, score = %d, name = %s\n", stu->c, stu->score, stu->name);
}

int main(void)
{
	// method 1: 按照成员声明的顺序初始化
	struct student_st s1 = { 'A', 91, "Alan" };
	show_student(&s1);
	return 0;
}