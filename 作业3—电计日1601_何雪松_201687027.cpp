#include <iostream>
using namespace std;

/*���������������������������������1601 ��ѩ�� 201687027����������������������������*/

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
	num = n > 0 ? n : 0;     //���ƷǷ�����
	sp = new char[num + 1];	  //Ҫ����󳤶ȶ�����һ��	
	sp[0] = '\0';			//����ַ���
}

myString::~myString()
{
	delete[]sp;
}

void myString:: input()
{
	cout << "�������ַ�����";
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
	
	cout << "�ַ�����ASCII��������С���ַ�������ɣ�" << endl;
}

void myString::disp()
{
	cout << "���ڵ��ַ���Ϊ��" << sp << endl;
}



int main()
{
	int n;

	cout << "�������һ���ַ�������󳤶ȣ�";
	cin >> n;
	myString string1(n);
	string1.input();

	cout << "������ڶ����ַ�������󳤶ȣ�";
	cin >> n;
	myString string2(n);
	string2.input();

	if(string1 == string2)
		cout << "���ַ�����ͬ" << endl;
	else
		cout << "���ַ�����ͬ" << endl;

	cout << "��������������������������������������������������������������������" << endl;
	string1.disp();
	string1.exchange();
	string1.disp();
}

/*���������������������������������1601 ��ѩ�� 201687027����������������������������*/