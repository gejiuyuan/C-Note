/*
* 
*	一、常量和宏
* 
*	#define，它是一个预处理指令，可用来定义常量（符号）和宏
* 
*	二、宏
* 
*		计算机科学里的宏，是一种抽象（Abstraction），它根据一系列预定义的
*		规则替换一定的文本模式、结束其或编译器在遇到宏时会自动尽心这一模式替换。
* 
*		简单理解就是：模式替换
* 
*/

// 定义一个MAX常量（符号）
#define MAX 1000;

// 定义一个ADD0宏 
#define ADD0(x, y) x + y;

// 定义一个ADD宏
#define ADD(x, y)(x + y);

#include <stdio.h>;

int main() {
	int sum = ADD(2, 3);

	//	打印：5
	//printf("sum= %d\n", sum);
	sum = 10 * ADD(2, 3);
	//	打印：50
	//printf("sum= %d\n", sum);

	int sum2 = ADD0(2, 3);
	//	打印：5，没问题
	//printf("%d\n", sum2);

	//	打印：102，而不是120
	sum2 = 10 * ADD0(10, 2);
	//printf("%d\n", sum2);
}