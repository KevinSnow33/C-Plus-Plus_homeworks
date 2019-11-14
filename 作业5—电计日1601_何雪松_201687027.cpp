#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace::std;
int firstFlag = 1;

/**********-----------cLink类-----------**********/
class cLink
{
public:
	friend class cList;
	cLink* next;

	char name[20];
	int num;
	enum { male, female }sex;
	int birth[3];
	double score[3];
public:
	cLink()
	{
		if(!firstFlag)
		{
			input();
			cout << "您所输入学生信息如下：" << endl;
			disp();
		}

	}
	void input();
	void disp();
};

void cLink::input()
{
	cout << "请输入学生姓名：";
	cin >> name;

	cout << "请输入学生学号："; 
	cin >> num;
		
	int sex0;	
	cout << "请输入学生性别（0是男，1是女）："; 
	while(1)
	{
		cin >> sex0;

		if(sex0 == 0)
		{
			sex = male;
			break;
		}	
		else if(sex0 == 1)
		{
			sex = female;
			break;
		}
		else
			cout << "输入有误，请重新输入学生性别（0是男，1是女）" ; 
	}
		
	cout << "请输入学生出生年月日(用空格分隔)："; 
	cin >> birth[0] >> birth[1] >> birth[2];
		
	cout << "请输入学生3门课成绩(用空格分隔)：\n"; 
	cin >> score[0] >> score[1] >> score[2];
	
	cout << endl;
}

void cLink::disp()
{
	cout << "\n姓名：" << name << "\n学号：" << num;
	if(sex == 0)
		cout << "\n性别：男" ;
	else if (sex == 1)
		cout << "\n性别：女";
	cout << "\n出生日期：" << birth[0] << " " << birth[1] << " " << birth[2]
		<< "\n3门课成绩："  << score[0] << " " << score[1] << " " << score[2];
	cout << endl << endl;
}




/**********-----------cList类-----------**********/
class cList
{
public:
	cLink* first;
	//	cLink * last;
public:
	cList()
	{
		//		first = last = new cLink;
		first = new cLink;
		first->next = NULL;
	}
	//	~cList()
	//	{
	//		Clear();
	//		delete first;
	//	}
	cList& Insert(const cLink&);
	//cList& Append(const cLink&);
	cList& Delete(const char* p);
	cList& Find(const char* p);
	cList& ScoreBestWorst();
	int Count();
	void ShowAllLink();
	cList& Sort();
};

cList& cList::Insert(const cLink& x)
{
	cLink* ptr = first;
	cLink* fisrtnext = first->next;
	firstFlag = 1;
	first = new cLink;
	firstFlag = 0;
	first->next = ptr;
	*ptr = x;
	ptr->next = fisrtnext;
	return (*this);
}

cList& cList::Delete(const char* p)
{
	cLink* ptr = first;
	int deleteFlag = 0;
	while (ptr->next)
	{
		if (strcmp(ptr->next->name, p) == 0)
		{
			cLink* q = ptr->next;
			cLink* r = ptr->next->next;
			ptr->next = r;
			delete q;
			deleteFlag = 1;
			cout << "已删除\n" << endl;
			break;
		}
		ptr = ptr->next;
	}
	if (deleteFlag == 0)
		cout << "系统中无此学生信息\n" << endl;
	return (*this);
}

cList& cList::Find(const char* p)
{
	cLink* ptr = first;
	while (ptr->next)
	{
		if (strcmp(ptr->next->name, p) == 0)
		{
			cout << "\n该学生信息如下：" << endl;
			ptr->next->disp();
			break;
		}
		ptr = ptr->next;
	}
	if(!(ptr->next))
		cout << "系统中无此学生信息\n" << endl;
	return (*this);
}

cList& cList::ScoreBestWorst()
{
	double total, best, worst, temp = 0;
	char *nameBest, *nameWorst;

	cLink* ptr = first->next;
	best = worst = total = (ptr->score[0] + ptr->score[1] + ptr->score[2]);
	nameWorst = nameBest = ptr->name;
	ptr = ptr->next;

	while (ptr)
	{
		total = (ptr->score[0] + ptr->score[1] + ptr->score[2]);
		if (total > best)
		{
			best = total;
			nameBest = ptr->name;
		}
		else if (total < worst)
		{
			worst = total;
			nameWorst = ptr->name;
		}
		ptr = ptr->next;
	}
	cout << "\n总成绩最高的学生信息为:";
	Find(nameBest);
	cout << "总成绩最低的学生信息为:";
	Find(nameWorst);

	return (*this);
}

int cList::Count()
{
	int count = 0;
	cLink* ptr = first;
	while (ptr->next)
	{
		count++;
		ptr = ptr->next;
	}
	cout << "\n当前系统中学生总数为：" << count << endl << endl;
	return count;
}

void cList::ShowAllLink()
{
	cLink* ptr = first;
	cout << "系统中当前存在的学生为：\n";
	while (ptr->next)
	{
		ptr = ptr->next;
		cout << ptr->name << endl;
	}
	cout << endl;
}

cList& cList::Sort()
{
	int count = Count();
	int i = 0;
	while(i < count)
	{
		int j = 1;
		cLink* ptr = first;
		while (j++ < count - i)
		{
			if ((ptr->next->score[0] + ptr->next->score[1] + ptr->next->score[2]) <
				(ptr->next->next->score[0] + ptr->next->next->score[1] + ptr->next->next->score[2]))
			{
				cLink* q = ptr->next->next;
				ptr->next->next = ptr->next->next->next;
				q->next = ptr->next;
				ptr->next = q;
			}

			ptr = ptr->next;
		}
		i++;
	}
	cout << "\n排序完成，";
	ShowAllLink();
	return (*this);
}


/**********-----------main函数-----------**********/
int main()
{
	cList List;
	firstFlag = 0;  //生成链表（的首节点）后改变flag，使接下来生成的结点可以自动调用输入信息的函数
	int i = 0;
	char name[20];
	int exitFlag = 0;

	cout << "*************------电计日1601-何雪松-201687027------*************\n" << endl;
	cout << "********************------学生管理系统------********************" << endl;
	

	while (!exitFlag)
	{
		cout << "---------------------------------------------\n";
		cout<< "  系统功能：\n" << "    1：新增学生信息\n"
		<< "    2：显示系统中当前存在的所有学生姓名\n" << "    3：根据给定的学生姓名显示其信息\n" 
			<< "    4：根据给定的学生姓名删除其信息\n" << "    5：显示总成绩最高和最低的学生信息\n"
			<< "    6：统计当前系统中学生人数\n" << "    7：按学生总成绩从高到低排序\n" << "    8：退出\n";
		cout << "---------------------------------------------\n";
		cout << "请输入您想使用功能的序号：";
		cin >> i;
		cout << endl;

		switch (i)
		{
			case 1:
				List.Insert(cLink());
				break;
			case 2:
				List.ShowAllLink();
				break;
			case 3:
				cout << "请输入您想查找学生的姓名：";
				cin >> name;
				List.Find(name);
				break;
			case 4:
				cout << "请输入您想删除学生的姓名：";
				cin >> name;
				List.Delete(name);
				break;
			case 5:
				List.ScoreBestWorst();
				break;
			case 6:
				List.Count();
				break;
			case 7:
				List.Sort();
				break;
			case 8:
				cout << "感谢使用！\n";
				exitFlag = 1;
				break;

			default:
				cout << "输入序号有误，请重新输入\n" << endl;
				break;
		}
	}

	cout << "\n********************------学生管理系统------********************\n" << endl;
	cout << "*************------电计日1601-何雪松-201687027------*************" << endl;

}
