#include <iostream>
#include <cstring>
using namespace std;

/*——————————————电计日1601 何雪松 201687027——————————————*/

class myString
{
	char sp[10][20];  //定义10个字符串，每个字符串中最大字符个数为19

public:
	myString();
	myString(const char a[]);
	myString(const myString& s);
	void input(int n, const char a[]);
	void disp(int n);
	char *ch_min(int a[]);
	void sort();
};

myString::myString()			//空参构造函数
{
	for (int i = 0; i < 10; i++)
		sp[i][0] = '\0';  //清空每个字符
}
 
myString::myString(const char a[]) 	//变换构造函数
{
	for (int i = 0; i < 10; i++)
		strcpy(sp[i], a);  //为每个字符串赋以给定的字符串
}

myString::myString(const myString& s)  //复制构造函数
{
	for (int i = 0; i < 10; i++)
		strcpy(sp[i], s.sp[i]);  //将给定对象每个字符串的值赋给本对象下的字符串 
}

void myString::input(int n, const char a[])  //给第n个字符串赋值
{
	strcpy(sp[n - 1], a);
}

void myString::disp(int n)
{
	cout << "第" << n << "个字符串为：" << sp[n - 1] << endl;
}

char* myString::ch_min(int a[])
{
	static char ch_min[10];  //定义储存10个最小值的静态数组，用于返回数组指针
	
	for (int i = 0; i < 10; i++)
	{
		ch_min[i] = sp[i][0];
		a[i] = 1;
		
		for (int j = 1; sp[i][j] != '\0'; j++)
		{
			if (sp[i][j] < ch_min[i])
			{
				ch_min[i] = sp[i][j];
				a[i] = 1;
			}
			else if (sp[i][j] == ch_min[i])
				a[i]++;			//修改最小值个数
		}
	}

	return ch_min;	//返回储存最小值的数组指针
}

void myString::sort()
{
	char temp[20];

	for (int i = 0; i < 10 -1 ; i++)
		for (int j = 1; j < 10 - i; j++)
			if (strcmp(sp[j - 1], sp[j]) > 0)
			{
				strcpy(temp, sp[j]);
				strcpy(sp[j], sp[j - 1]);
				strcpy(sp[j - 1], temp);
			}
}



int main()
{
	myString s1("abcd");    //调用变换构造函数
	s1.input(3, "lmnlll");	//为指定字符串输入数据
	s1.input(5, "xxxyz");
	s1.input(7, "homework");
	cout << "s1对象的10个字符串为：" << endl;
	for (int i = 1; i <= 10; i++)
		s1.disp(i);

	myString s2 = s1;   //调用复制构造函数
	cout << "\ns2对象的10个字符串为：" << endl;
	for (int i = 1; i <= 10; i++)
		s2.disp(i);

	char* ch_min;     
	int min_count[10];
	ch_min = s1.ch_min(min_count);  //调用取最小字符函数，用字符指针作接受
	cout << endl;
	for (int i = 0; i < 10; i++)
		cout << "s1对象中第" << i + 1 << "个字符串中ASCII码最小的字符为：" << ch_min[i] 
			<< "   个数为：" << min_count[i] << endl;
	
	s1.sort();		//对10个字符串从小到大排序
	cout << "\ns1对象的10个字符串为：" << endl;
	for (int i = 1; i <= 10; i++)
		s1.disp(i);

}

/*——————————————电计日1601 何雪松 201687027——————————————*/


