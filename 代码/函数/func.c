/*
*	一、函数
* 
*		1、基本使用
* 
*			1.1 函数是什么
* 			
*				维基百科对函数的定义：
* 
*					子程序，是一个大型程序中的某部分代码，由一个或多个语句块组成。
*					它负责完成某项特定任务，而且相较于其它代码，具备相对的独立性。一般会有输入参数和返回值，
*					提供对过程的封装和细节的隐藏。这些代码通常被集成为软件库。
*			
*				C语言中，函数分为库函数和自定义函数两大类。
* 
*			1.2 库函数
* 
*				为什么会有库函数？
*					
*					我们在学习C语言编程时，总是在一个代码编写完成之后迫不及待的想知道结果，想把
*					这个结果打印到我们的屏幕上看看。这时我们会频繁使用一个功能：将信息按照一定的格式打印
*					到屏幕上（printf）；
* 
*					在编程过程中我们会频繁的做一些字符串的拷贝工作（strcpy）；
* 
*					在编程是我们也计算，总是会计算n的k次方这样的运算（pow）；
* 
*				像上面我们描述的基础功能，它们不是业务性的代码。我们在开发的过程中每个程序员都可能用得到。
*				为了支持可移植性和提高程序的效率，所以C语言的基础库中提供了一系列类似的库函数，方便软件开发。
* 
*				那怎么学习库函数呢？可以看 www.cplusplus.com 网站教程
* 
*			1.3 自定义函数
* 
*			1.4 函数参数
* 
*			1.5 函数调用
* 
*			1.6 函数的嵌套调用和链式访问
* 
*			1.7 函数的声明和定义
* 
*			1.8 函数递归
* 
* 
*/

#include <stdio.h>;
#include <string.h>;

//int Add(int x, int y);
// 可以改写成
#include "add.h" 

//导入静态库，add.lib是其它项目的头文件静态库
//#pragma comment(lib, "add.lib")

int my_strlen(char* str) {
	int count = 0;
	while (*str != '\0') {
		count++;
		//printf("%p\n", &str);
		printf("%p %s\n", *str, str); 
		str++;
	}
	return count;
}

//my_strlen的优化版（不允许创建count变量）
//解决方案：函数递归
int my_strlen2(char* str) {
	if(*str != '\0')
	{
		return 1 + my_strlen2(str+1);
	}
	return 0;
}

int main() {

	char arr1[20] = { 0 };

	char arr2[] = "hello";

	// 复制字符串arr2到arr1数组中
	//strcpy(arr1, arr2);

	// 打印：hello
	//printf("%s\n", arr1);

	// 内存设置
	//memset(arr1, 'x', 5);
	// 打印：20
	//printf("%d\n", sizeof(arr1));

	//printf("%s\n", arr1);

	//printf("%d\n", Add(3, 9));

	printf("%d\n", my_strlen(arr2));
	//printf("%d\n", my_strlen2(arr2));

	return 0;

}