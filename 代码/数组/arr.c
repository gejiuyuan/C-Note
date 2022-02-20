/*
*	
*	一、数组
* 
*		一维数组、二维数组、数组作为函数参数、三子棋和扫雷游戏案例
* 
*		注意：C99法支持变长数组，即数组的大小可以是变量，不过VS编译器并不支持，而gcc支持
*			 
*		
*/

#include <stdio.h>
#include <string.h>

#define char_num2 30;

int main() {

	/*
	* 
	* 创建数组：type_t（数组元素类型） arr_name（数组名称） [const_n]（数组长度，必须是个常量）
	* 
	*/
	// 创建一个长度为10的内容为整型的数组arr
	int arr[10];

	//报错：常变量也不行
	//const int char_num = 20;
	//char char_arr[char_num];

	// 报错：#define定义常量也不行
	//char char_arr3[char_num2] = { "d" };

	//初始化
	int a = 19;

	//完全初始化
	int c_arr[5] = { 0,1,2,3,4 };//5个元素
	int c1_arr[] = { 0,1,2,3,4 }; //5个元素
	// 注意：此种写法在MSVC编译器中能通过，但gcc则会报错
	// int ccl_arr[] = "01234"; //['0', '1','2', '3', '4', '\0']，6个元素
	printf("%p\n", c1_arr);

	//不完全初始化，未初始化默认填充为0
	//注意，此处传入字符串等其它值，都会被转为数字
	//如果值是单引号的字符串，如'P'，则为80（ASCII码）
	// 注意：此种写法在MSVC编译器中能通过，但gcc则会报错
	// int nc_arr[5] = { 0 , 1, "p", 'p', 'P'};

	//不完全初始化，未初始化部分默认填充为"\0"（ASICC码为0）
	// int nc_char_arr[5] = { "ge", "jiu", "yuan", };

	// printf("%d %d %d %d\n", nc_arr[0], nc_arr[2], nc_arr[3], nc_arr[4]);
	//printf("%p\n", &nc_arr);
	return 0;

}