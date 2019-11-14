#include <iostream>
using namespace std;

/*——————————————电计日1601 何雪松 201687027——————————————*/

#define R 3
#define C 4

void displayMax(int(*)[C]);

int main() {

	int(*p)[C];
	p = new int[R][C];

	cout << "请输入" << R << "行" << C << "列数组元素:\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> *(*(p + i) + j);
		}
	}

	/*测试用数据，使用时注释掉上面输入for循环*/
	//*(*(p + 0) + 0) = 52;
	//*(*(p + 0) + 1) = 52;
	//*(*(p + 0) + 2) = 52;
	//*(*(p + 0) + 3) = 52;
	//*(*(p + 1) + 0) = 91;
	//*(*(p + 1) + 1) = 3;
	//*(*(p + 1) + 2) = 27;
	//*(*(p + 1) + 3) = 8;
	//*(*(p + 2) + 0) = 20;
	//*(*(p + 2) + 1) = 13;
	//*(*(p + 2) + 2) = 55;
	//*(*(p + 2) + 3) = 5;


	cout << "\n您输入的" << R << "行" << C << "列数组元素为：\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << *(*(p + i) + j) << " ";
		}
		cout << "\n";
	}
	displayMax(p);

	delete[]p;
}

void displayMax(int(*p)[C]) {
	int max, beforeMax;
	for (int i = 0; i < R; i++) {
		max = *(*(p + i));
		beforeMax = max;
		for (int j = 1; j < C; j++) {
			switch (j) {
				case 1:    //第1次比较（第一个元素和第二个元素比较）时，若第二个元素小于第一个则把第二个元素赋给beforeMax
					if (*(*(p + i) + j) >= max) {
						beforeMax = max;
						max = *(*(p + i) + j);
					}
					else
						beforeMax = *(*(p + i) + j);
					break;

				default:
					if (*(*(p + i) + j) >= max) {
						beforeMax = max;
						max = *(*(p + i) + j);
					}
					else if (*(*(p + i) + j) >= beforeMax)
						beforeMax = *(*(p + i) + j);
			}

		}
		if (beforeMax != max)
			cout << "第" << i + 1 << "行次最大值为：" << beforeMax << "\n";
		else
			cout << "第" << i + 1 << "行没有次最大值\n";
	} 
}

/*——————————————电计日1601 何雪松 201687027——————————————*/
