#include <iostream>
using namespace std;

/*���������������������������������1601 ��ѩ�� 201687027����������������������������*/

class arrayManage
{
	int x[10];

public:
	arrayManage();

	void input()
	{
		cout << "*********** input:***********\n";
		for (int i = 0; i < 10; i++)
		{
			cout << "�������" << i + 1 << "��Ԫ�ص�ֵ:\n";
			cin >> x[i];
		}
	}

	void disp()
	{
		cout << "\n*********** disp:***********\n";
		for (int i = 0; i < 10; i++)
		{
			cout << "��" << i + 1 << "��Ԫ�ص�ֵΪ:" << x[i] << endl;
		}
	}

	int max(int &maxCount)
	{
		maxCount = 0;
		int max = x[0];
		for (int i = 1; i < 10; i++)
		{
			if (max < x[i])
			{
				max = x[i];
				maxCount = 1;
			}
			else if (max == x[i])
				maxCount++;
		}
		return max;
	}

	void find()
	{
		static int xCount[10];    //�½�һ����ͳ��ÿ��Ԫ�أ�������棩���ظ�����

		for (int i = 0; i < 10; i++)
		{
			xCount[i] = 1;
			int j = i + 1;
			while (j < 10)
			{
				if (x[j] == x[i])
					xCount[i]++;
				j++;
			}
		}

		int result[10][2] =			//�½�һ��ά�����ȡxCount[10]��ֵ���Ԫ�ص��±꼰��ֵ(-1Ϊ������)
		{ {0,xCount[0]}, {-1,0}, {-1,0}, {-1,0}, {-1,0}, {-1,0}, {-1,0}, {-1,0}, {-1,0}, {-1,0} };
		
		for (int i = 1, max = xCount[0], x = 0; i < 10; i++)
		{
			//���1���������µ������
			if (xCount[i] > max)		
			{
				max = xCount[i];   //���������

				x = 0;			//����ֵ���Ԫ�ص��±꼰��ֵ
				result[x][0] = i;
				result[x][1] = xCount[i];

				for (int j = 1; j < 10; j++)   //��ԭ����¼������������±�����
				{
					result[j][0] = 0;
				}
			}
			//���2����������������
			else if (xCount[i] == max)   
			{
				x++;	             //ֵ���Ԫ��+1
				result[x][0] = i;
				result[x][1] = xCount[i];
			}
		}

		cout << "\n*********** find��***********\n";
		cout << "�������ظ������������������ֱ�Ϊ��\n";
		for (int i = 0; i < 10; i++)
		{
			if (result[i][0] != -1)
				cout << "���֣�" << x[result[i][0]] << "  " << "������" << result[i][1] << endl;
		}

	}
};

arrayManage::arrayManage()
{
	for (int i = 0; i < 10; i++)
	{
		x[i] = 0;
	}
}



int main() 
{
	arrayManage a;
	a.input();
	a.disp();
	int maxCount;
	cout << "\n*********** max:***********\n";
	cout << "���ֵΪ��" << a.max(maxCount) << "      ";
	cout << "���ֵ����Ϊ��" << maxCount << endl;
	a.find();
}

/*���������������������������������1601 ��ѩ�� 201687027����������������������������*/
