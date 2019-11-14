#include <iostream>
using namespace std;

/*——————————————电计日1601 何雪松 201687027——————————————*/

class myString
{
	char* sp;
	int num;

public:
	myString(int n);
	~myString();
	void input();
	bool operator == (myString& second);
	void exchange();
	void disp();
};

myString::myString(int n)
{
	num = n > 0 ? n : 0;     //限制非法个数
	sp = new char[num + 1];	  //要比最大长度多申请一个	
	sp[0] = '\0';			//清空字符串
}

myString::~myString()
{
	delete[]sp;
}

void myString:: input()
{
	cout << "请输入字符串：";
	cin >> sp;
}

bool myString::operator == (myString& second)
{
	for (int i = 0; i < num; i++) {
		if (sp[i] != second.sp[i]) 
			return false;
	}
	return true;
}

void myString::exchange()
{
	char max,min;
	max = sp[0];
	min = sp[0];
	
	for (int i = 1; i < num; i++)
	{
		if (sp[i] > max)
			max = sp[i];	
		if (sp[i] < min)
			min = sp[i];
	}

	for (int i = 0; i < num; i++)
	{
		if (sp[i] == max)
			sp[i] = min;
		else if (sp[i] == min)
			sp[i] = max;
	}
	
	cout << "字符串中ASCII码最大和最小的字符互换完成！" << endl;
}

void myString::disp()
{
	cout << "现在的字符串为：" << sp << endl;
}



int main()
{
	int n;

	cout << "请输入第一个字符串的最大长度：";
	cin >> n;
	myString string1(n);
	string1.input();

	cout << "请输入第二个字符串的最大长度：";
	cin >> n;
	myString string2(n);
	string2.input();

	if(string1 == string2)
		cout << "两字符串相同" << endl;
	else
		cout << "两字符串不同" << endl;

	cout << "——————————————————————————————————" << endl;
	string1.disp();
	string1.exchange();
	string1.disp();
}

/*——————————————电计日1601 何雪松 201687027——————————————*/
