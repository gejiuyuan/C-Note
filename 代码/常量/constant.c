/*
* 
*	一、常量
* 
*		C语言中常量分为四种：
*			
*			1. 字面常量
*			2. const修饰的常变量(但本质还是变量）
*			3. #define 定义的标识符常量
*			4. 枚举常量
* 
* 
*/

#include <stdio.h>;

//定义一个MAX标识符常量
#define MAX 10000;

//定义一个Sex变量
enum Sex {
	//枚举常量
	MALE,
	FEMALE,
	SECRET
};

int main() {

	// 1、字面常量，允许存在，但是没有意义
	3.14;
	"char";

	// 2、const修饰的常变量
	const int num = 10;
	printf("num = %d\n", num);

	// 10个元素
	int arr[10] = { 0 };

	// 会报错
	//int n = 10;
	//int arr2[n] = { 19 };
	
	// 还是错误写法
	//const int n3 = 10;
	//int arr3[n3] = { 10 };

	// 3、#define 标识符常量
	int h = MAX;
	// 打印10000
	printf("h = %d\n", h);

	// 4、枚举常量
	enum Sex s = FEMALE;

	// 0
	printf("%d\n", MALE);
	// 1
	printf("%d\n", FEMALE);
	// 2
	printf("%d\n", SECRET);


	return 0;
}