/*
* 
*	һ������
* 
*		C�����г�����Ϊ���֣�
*			
*			1. ���泣��
*			2. const���εĳ�����(�����ʻ��Ǳ�����
*			3. #define ����ı�ʶ������
*			4. ö�ٳ���
* 
* 
*/

#include <stdio.h>;

//����һ��MAX��ʶ������
#define MAX 10000;

//����һ��Sex����
enum Sex {
	//ö�ٳ���
	MALE,
	FEMALE,
	SECRET
};

int main() {

	// 1�����泣����������ڣ�����û������
	3.14;
	"char";

	// 2��const���εĳ�����
	const int num = 10;
	printf("num = %d\n", num);

	// 10��Ԫ��
	int arr[10] = { 0 };

	// �ᱨ��
	//int n = 10;
	//int arr2[n] = { 19 };
	
	// ���Ǵ���д��
	//const int n3 = 10;
	//int arr3[n3] = { 10 };

	// 3��#define ��ʶ������
	int h = MAX;
	// ��ӡ10000
	printf("h = %d\n", h);

	// 4��ö�ٳ���
	enum Sex s = FEMALE;

	// 0
	printf("%d\n", MALE);
	// 1
	printf("%d\n", FEMALE);
	// 2
	printf("%d\n", SECRET);


	return 0;
}