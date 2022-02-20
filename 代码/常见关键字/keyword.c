/*
* 
* 一、常见关键字：
*
*	int char const double float enum short long
*	auto break case continue default do else extern
*	sizeof static struct switch typedef union unsigned
*	void volatile while signed return register if goto
*	for
* 
*	注意：define、include等都不是关键字，它们是“预处理指令”
*	
*	1、auto：每个局部变量都是auto修饰的。
*			表示自动创建、自动销毁，所以每个局部变量都是自动变量。
*			当然，auto在新的C语言中也有其它用法，不过暂时不考虑。
*
*	2、typedef：字面为类型定义，实际应该理解为类型重命名（重定义），通俗点说就是起个别名
* 
*	3、extern：用来声明外部符号的
* 
*	4、goto：
* 
*	5、register：寄存器关键字。为什么要将数据存到寄存器中呢？
*		首先要知道，计算机中的数据可以存储到：
*			寄存器、
*			高速缓存（如L3、L2、L1）、
*			内存、
*			硬盘、
*			网盘（需要联网，如百度网盘，速度依赖于服务商服务器网速）
*		（速度由快到慢，空间由小到大，造价由高到低）
* 
*		早期的电脑，CPU运行所需的数据都直接从内存获取，但随着CPU运算速度快速提升，
*		而内存读写取跟不上了CPU的读写速度，所以产生了高速缓存和寄存器，以提升效率
* 
*		由此不难推出register的应用场景：大量/频繁被使用的数据，想放在寄存器中，用以提升获取效率。
*		不过，随着编译器的完善，现已能很好的能推断出哪些数据需要放入寄存器中，因此此关键字意义不是特别大了。
*		
*	6、signed：有符号的
* 
*	7、unsigned：无符号的
* 
*	8、static：静态的。可用来修改函数、全局变量、全局变量
*		
*	   8.1 static在修饰局部变量时，其实是改变了此变量的存储类型，从而致使此变量的生命周期更改
*	   
*			那是如何修改了变量的存储类型呢？内存会被划分为三个区域：
* 
*					栈区：存储局部变量、函数参数
*					堆区：用于动态内存分配
*					静态区：存储全局变量、static修饰的静态变量
*		
*			所以本质是，将变量存到了静态区
* 
*	   8.2 static在修饰全局变量和函数时，表示目标内容只能在其源文件中使用，同工程的其它文件不能用
*			
*		  原因：全局变量和全局函数在其它源文件内存可以被使用，是因为它们具有外部链接属性，
*				但当被static修饰后，外部链接属性变成了内存链接属性，其它源文件就不能链接到这个静态的数据了
*  
* 
*	9、struct：结构
* 
*	10、union：联合体（共用体）
* 
*	11、void：无、空
* 
*	12、volatile：C语言中暂时不讲。这是一个能体现你C语言段位的关键字
* 
*	
* 
*/

#include <stdio.h>;

// 将unsigned int类型起个简写名称：u_int
typedef unsigned int u_int;

extern int global;

extern int global_num;

extern int Add(int x, int y);

extern int StaticAdd(int x, int y);

void test() 
{
	// 每次执行完test后，都会销毁a变量，再次执行又会创建新的a变量
	int a = 1;
	a++;
	printf("%d\n", a);
};

void test2()
{
	//static表示，执行完test2后，不销毁a变量，下次再次执行直接取该第一次执行创建的a使用
	static int a = 1;
	a++;
	printf("%d\n", a);
};

int main() {

	{
		// 实际上等于：auto int a = 10
		int a = 10;
	}

	// 表示建议num的值存放在寄存器中（但最终是否这样做由编译器来决定）
	register int num = 100;

	// 两者同义
	unsigned int num2 = 100;
	u_int num3 = 100;

	int i = 0;
	while (i<10)
	{
		// 打印：10个2
		//test();
		// 打印：2、3、4、5、6、7、8、9、10、11
		//test2();
		i++;
	}

	//printf("%d\n", global);

	//global_num整型变量被static修饰了，此处访问会报错
	//printf("%d\n", global_num);

	int sum = Add(num, num2);
	//printf("sum=%d", sum);

	//StaticAdd函数被static修饰了，此处访问会报错
	printf("%d", StaticAdd(num, num2));

	return 0;
}