#include <stdio.h>;

// ��Ϊglobal_age��global_vars.c��������ȫ�ֱ�����
// ��������ļ���main.c����Ҫʹ�õĻ�������Ҫʹ��
// extern�ؼ�������
extern int global_age;

int mian() {

	printf("%d\n", global_age);

	return 0;
}