int global = 2022;

// 表示global_num只能在此文件中使用
static int global_num = 2021;

int Add(int x, int y) {
	return x + y;
}

static int StaticAdd(int x, int y) {
	return x + y;
}