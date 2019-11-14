#include <iostream>
#include <cstring>
using namespace std;

/*���������������������������������1601 ��ѩ�� 201687027����������������������������*/

class myString
{
	char sp[10][20];  //����10���ַ�����ÿ���ַ���������ַ�����Ϊ19

public:
	myString();
	myString(const char a[]);
	myString(const myString& s);
	void input(int n, const char a[]);
	void disp(int n);
	char *ch_min(int a[]);
	void sort();
};

myString::myString()			//�ղι��캯��
{
	for (int i = 0; i < 10; i++)
		sp[i][0] = '\0';  //���ÿ���ַ�
}
 
myString::myString(const char a[]) 	//�任���캯��
{
	for (int i = 0; i < 10; i++)
		strcpy(sp[i], a);  //Ϊÿ���ַ������Ը������ַ���
}

myString::myString(const myString& s)  //���ƹ��캯��
{
	for (int i = 0; i < 10; i++)
		strcpy(sp[i], s.sp[i]);  //����������ÿ���ַ�����ֵ�����������µ��ַ��� 
}

void myString::input(int n, const char a[])  //����n���ַ�����ֵ
{
	strcpy(sp[n - 1], a);
}

void myString::disp(int n)
{
	cout << "��" << n << "���ַ���Ϊ��" << sp[n - 1] << endl;
}

char* myString::ch_min(int a[])
{
	static char ch_min[10];  //���崢��10����Сֵ�ľ�̬���飬���ڷ�������ָ��
	
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
				a[i]++;			//�޸���Сֵ����
		}
	}

	return ch_min;	//���ش�����Сֵ������ָ��
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
	myString s1("abcd");    //���ñ任���캯��
	s1.input(3, "lmnlll");	//Ϊָ���ַ�����������
	s1.input(5, "xxxyz");
	s1.input(7, "homework");
	cout << "s1�����10���ַ���Ϊ��" << endl;
	for (int i = 1; i <= 10; i++)
		s1.disp(i);

	myString s2 = s1;   //���ø��ƹ��캯��
	cout << "\ns2�����10���ַ���Ϊ��" << endl;
	for (int i = 1; i <= 10; i++)
		s2.disp(i);

	char* ch_min;     
	int min_count[10];
	ch_min = s1.ch_min(min_count);  //����ȡ��С�ַ����������ַ�ָ��������
	cout << endl;
	for (int i = 0; i < 10; i++)
		cout << "s1�����е�" << i + 1 << "���ַ�����ASCII����С���ַ�Ϊ��" << ch_min[i] 
			<< "   ����Ϊ��" << min_count[i] << endl;
	
	s1.sort();		//��10���ַ�����С��������
	cout << "\ns1�����10���ַ���Ϊ��" << endl;
	for (int i = 1; i <= 10; i++)
		s1.disp(i);

}

/*���������������������������������1601 ��ѩ�� 201687027����������������������������*/


