/*
* 
* 一、字符串
*	
*	用双引号括起来的一串字符，称为字符串字面值，简称字符串
* 
*	F10开启断点调试
* 
*/


#include <stdio.h>;


int main() {

	//字符串末尾隐藏了一个\0的字符，
	// \0表示字符串的结束标志
	char arr[] = "gejiuyuan";

	// 打印：gejiuyuan
	//printf("%s\n", arr);

	char arr2[] = {	'a','b', 'c'};
	// 打印：abc<乱码>，因为字符串后面没有用\0来标志字符串
	// 结束了，不清楚abc后面是什么内容，所以会出现乱码
	//printf("%s\n", arr2);

	// 如果手动加上\0，就正常了
	char arr3[] = { 'a', 'b', 'c', '\0' };
	// 打印：abc
	//printf("%s\n", arr3);

	//打印字符串长度，注意：\0不会被记入字符串长度
	//printf("%d\n", strlen(arr2));

	// 会是9
	int arrLen = strlen(arr);
	// 会是一个随机值
	int arr2Len = strlen(arr2);
	// 会是3
	int arr3Len = strlen(arr3);

	//printf("%d\n%d\n%d\n", arrLen, arr2Len, arr3Len);

	// 打印ASCII码为110的字符串字面值——H
	printf("%c\n", '\110');

	return 0;
}