#include <iostream>
using namespace std;

/*���������������������������������1601 ��ѩ�� 201687027����������������������������*/

#define R 3
#define C 4

void displayMax(int(*)[C]);

int main() {

	int(*p)[C];
	p = new int[R][C];

	cout << "������" << R << "��" << C << "������Ԫ��:\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> *(*(p + i) + j);
		}
	}

	/*���������ݣ�ʹ��ʱע�͵���������forѭ��*/
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


	cout << "\n�������" << R << "��" << C << "������Ԫ��Ϊ��\n";
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
				case 1:    //��1�αȽϣ���һ��Ԫ�غ͵ڶ���Ԫ�رȽϣ�ʱ�����ڶ���Ԫ��С�ڵ�һ����ѵڶ���Ԫ�ظ���beforeMax
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
			cout << "��" << i + 1 << "�д����ֵΪ��" << beforeMax << "\n";
		else
			cout << "��" << i + 1 << "��û�д����ֵ\n";
	} 
}

/*���������������������������������1601 ��ѩ�� 201687027����������������������������*/
