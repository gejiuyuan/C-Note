/*
*  
*	һ���ṹ��
* 
*		�ṹ��ʹ��C���������������������͡���������ѧ����ѧ�����������֡����䡢�Ա�ѧ��
		�Ϳ����ýṹ����������Щ��Ϣ��
* 
* 
*/

#include <stdio.h>;

struct Stu {
	char name[20]; //����
	int age; //����
	char sex[5]; //�Ա�
	char id[15]; //ѧ��
};

int main() {	

	// �ṹ��Ĵ����ͳ�ʼ��
	// ע�⣺�ṹ��������ַ�������ʹ��˫����
	struct Stu s = { "����", 20, "��", "34" };

	printf("1: %s %d %s %s\n", s.name, s.age, s.sex, s.id);

	// ͨ��struct���ݵ�ַ��ȡ����ֵ
	struct Stu* ps = &s;
	printf("2: %s\n", (* ps).name);
	printf("3: %s\n", ps->name);

	return 0;
}