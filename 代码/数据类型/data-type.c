/*
* 
*  һ����������
* 
*	����		����				�ռ��С���ֽڣ�
*	
*	char		�ַ���������		1
*	short		������				2
*	int			����				4
*	long		������				4
*	long long   ����������			8
*	float		�����ȸ�����		4
*	double		˫���ȸ�����		8
* 
*	sizeof���ؼ��֡������������ڼ��������ռ�ռ��С(��λ���ֽڣ�
*	
*	ע�⣺
*	
*		1��C���Ա�׼�涨��sizeof(long) >= sizeof(int)���ɣ����Կ�����4��Ҳ������8
* 
*	
*/

#include <stdio.h>;

//ע�Ϳ�ݼ�

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
*	��������������
*
* 
*	1��scanf�����뺯��
* 
*		ʹ�øú���ʱ�ᱨ��'scanf': This function or variable may be unsafe. Consider using scanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
*		���������
*			1. ʹ��scanf_s�����ע�⣺����VS�������ṩ�ģ�������C���Ա�׼�������÷���scanf���ڲ��
*			2. ��VS-��Ŀ-�������� ����-��������-C/C++-Ԥ������-Ԥ���������壬����_CRT_SECURE_NO_DEPRECATE�꼴��
*			3. ����Ŀ�ļ���һ�У��ͷ�У������ӣ�#define _CRT_SECURE_NO_DEPRECATE 1

*	
* 
*/

// ȫ�ֱ���
//int global = 200;

//int main()
//{
	// �ֲ�����

	//int age = 30;
	//float height = 180;
	//double weight = 60;
	//int sum = 0;

	//age += 2;

	// int����
	//printf("%d\n", age);

	// float����
	//printf("%f\n", height);

	// double����
	//printf("%lf\n", weight);

	//sum = age + age;

	// &�ǵ�ַ���������ȡ�������ڴ��ַ
	//scanf_s("%d%", &age, &height);
	//scanf("%lf", &weight);

	//printf("sum = %d\n", sum);

	//return 0;
//}