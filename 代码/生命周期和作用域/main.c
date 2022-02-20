#include <stdio.h>;

// 因为global_age在global_vars.c中生命了全局变量，
// 而如果此文件（main.c）中要使用的话，则需要使用
// extern关键字声明
extern int global_age;

int mian() {

	printf("%d\n", global_age);

	return 0;
}