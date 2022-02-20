/*
* 
*  一、数据类型
* 
*	类型		含义				空间大小（字节）
*	
*	char		字符数据类型		1
*	short		短整型				2
*	int			整型				4
*	long		长整型				4
*	long long   更长的整型			8
*	float		单精度浮点数		4
*	double		双精度浮点数		8
* 
*	sizeof：关键字、操作符，用于计算变量所占空间大小(单位：字节）
*	
*	注意：
*	
*		1、C语言标准规定：sizeof(long) >= sizeof(int)即可，所以可能是4，也可能是8
* 
*	
*/

#include <stdio.h>;

//注释快捷键

//int main() {
//	char ch = "gejiuyuan";
//	int age = 20;
//
//	short num = 10;
//
//	float weight = 55.5;
//
//	double digit = 0.01;
//	 
//	printf("%d\n", num);
//	// 1
//	printf("%d\n", sizeof(char)); 
//	// 2
//	printf("%d\n", sizeof(short));
//	// 4
//	printf("%d\n", sizeof(int));
//	// 4
//	printf("%d\n", sizeof(long));
//	// 8
//	printf("%d\n", sizeof(long long));
//	// 4
//	printf("%d\n", sizeof(float));
//	// 8
//	printf("%d\n", sizeof(double));
//
//	return 0;
//}



/*
*
*	二、常亮、变量
*
* 
*	1、scanf：输入函数
* 
*		使用该函数时会报错：'scanf': This function or variable may be unsafe. Consider using scanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
*		解决方案：
*			1. 使用scanf_s替代。注意：这是VS编译器提供的，不符合C语言标准，而且用法与scanf存在差别
*			2. 在VS-项目-数据类型 属性-配置属性-C/C++-预处理器-预处理器定义，增加_CRT_SECURE_NO_DEPRECATE宏即可
*			3. 在项目文件第一行（最开头行），增加：#define _CRT_SECURE_NO_DEPRECATE 1

*	
* 
*/

// 全局变量
//int global = 200;

//int main()
//{
	// 局部变量

	//int age = 30;
	//float height = 180;
	//double weight = 60;
	//int sum = 0;

	//age += 2;

	// int类型
	//printf("%d\n", age);

	// float类型
	//printf("%f\n", height);

	// double类型
	//printf("%lf\n", weight);

	//sum = age + age;

	// &是地址运算符，获取变量的内存地址
	//scanf_s("%d%", &age, &height);
	//scanf("%lf", &weight);

	//printf("sum = %d\n", sum);

	//return 0;
//}