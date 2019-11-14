#include <iostream>
using namespace std;

/*——————————————电计日1601 何雪松 201687027——————————————*/

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
			cout << "请输入第" << i + 1 << "个元素的值:\n";
			cin >> x[i];
		}
	}

	void disp()
	{
		cout << "\n*********** disp:***********\n";
		for (int i = 0; i < 10; i++)
		{
			cout << "第" << i + 1 << "个元素的值为:" << x[i] << endl;
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
		static int xCount[10];    //新建一数组统计每个元素（在其后面）的重复次数

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

		int result[10][2] =			//新建一二维数组存取xCount[10]中值最大元素的下标及其值(-1为不存在)
		{ {0,xCount[0]}, {-1,0}, {-1,0}, {-1,0}, {-1,0}, {-1,0}, {-1,0}, {-1,0}, {-1,0}, {-1,0} };
		
		for (int i = 1, max = xCount[0], x = 0; i < 10; i++)
		{
			//情况1：若出现新的最大项
			if (xCount[i] > max)		
			{
				max = xCount[i];   //更新最大项

				x = 0;			//更新值最大元素的下标及其值
				result[x][0] = i;
				result[x][1] = xCount[i];

				for (int j = 1; j < 10; j++)   //将原来记录的其他最大项下标清零
				{
					result[j][0] = 0;
				}
			}
			//情况2：若出现相等最大项
			else if (xCount[i] == max)   
			{
				x++;	             //值最大元素+1
				result[x][0] = i;
				result[x][1] = xCount[i];
			}
		}

		cout << "\n*********** find：***********\n";
		cout << "数组中重复次数最多的数及个数分别为：\n";
		for (int i = 0; i < 10; i++)
		{
			if (result[i][0] != -1)
				cout << "数字：" << x[result[i][0]] << "  " << "个数：" << result[i][1] << endl;
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
	cout << "最大值为：" << a.max(maxCount) << "      ";
	cout << "最大值个数为：" << maxCount << endl;
	a.find();
}

/*——————————————电计日1601 何雪松 201687027——————————————*/
