/*
* 
* һ���ַ���
*	
*	��˫������������һ���ַ�����Ϊ�ַ�������ֵ������ַ���
* 
*	F10�����ϵ����
* 
*/


#include <stdio.h>;


int main() {

	//�ַ���ĩβ������һ��\0���ַ���
	// \0��ʾ�ַ����Ľ�����־
	char arr[] = "gejiuyuan";

	// ��ӡ��gejiuyuan
	//printf("%s\n", arr);

	char arr2[] = {	'a','b', 'c'};
	// ��ӡ��abc<����>����Ϊ�ַ�������û����\0����־�ַ���
	// �����ˣ������abc������ʲô���ݣ����Ի��������
	//printf("%s\n", arr2);

	// ����ֶ�����\0����������
	char arr3[] = { 'a', 'b', 'c', '\0' };
	// ��ӡ��abc
	//printf("%s\n", arr3);

	//��ӡ�ַ������ȣ�ע�⣺\0���ᱻ�����ַ�������
	//printf("%d\n", strlen(arr2));

	// ����9
	int arrLen = strlen(arr);
	// ����һ�����ֵ
	int arr2Len = strlen(arr2);
	// ����3
	int arr3Len = strlen(arr3);

	//printf("%d\n%d\n%d\n", arrLen, arr2Len, arr3Len);

	// ��ӡASCII��Ϊ110���ַ�������ֵ����H
	printf("%c\n", '\110');

	return 0;
}