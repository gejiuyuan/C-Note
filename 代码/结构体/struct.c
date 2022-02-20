/*
*  
*	一、结构体
* 
*		结构体使得C语言有能力描述复杂类型。比如描述学生，学生包含：名字、年龄、性别、学号
		就可以用结构体来描述这些信息。
* 
* 
*/

#include <stdio.h>;

struct Stu {
	char name[20]; //名字
	int age; //年龄
	char sex[5]; //性别
	char id[15]; //学号
};

int main() {	

	// 结构体的创建和初始化
	// 注意：结构体里面的字符串必须使用双引号
	struct Stu s = { "张三", 20, "男", "34" };

	printf("1: %s %d %s %s\n", s.name, s.age, s.sex, s.id);

	// 通过struct数据地址获取属性值
	struct Stu* ps = &s;
	printf("2: %s\n", (* ps).name);
	printf("3: %s\n", ps->name);

	return 0;
}