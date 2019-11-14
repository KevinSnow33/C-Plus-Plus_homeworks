#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace::std;
int firstFlag = 1;

/**********-----------cLink��-----------**********/
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
			cout << "��������ѧ����Ϣ���£�" << endl;
			disp();
		}

	}
	void input();
	void disp();
};

void cLink::input()
{
	cout << "������ѧ��������";
	cin >> name;

	cout << "������ѧ��ѧ�ţ�"; 
	cin >> num;
		
	int sex0;	
	cout << "������ѧ���Ա�0���У�1��Ů����"; 
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
			cout << "������������������ѧ���Ա�0���У�1��Ů��" ; 
	}
		
	cout << "������ѧ������������(�ÿո�ָ�)��"; 
	cin >> birth[0] >> birth[1] >> birth[2];
		
	cout << "������ѧ��3�ſγɼ�(�ÿո�ָ�)��\n"; 
	cin >> score[0] >> score[1] >> score[2];
	
	cout << endl;
}

void cLink::disp()
{
	cout << "\n������" << name << "\nѧ�ţ�" << num;
	if(sex == 0)
		cout << "\n�Ա���" ;
	else if (sex == 1)
		cout << "\n�Ա�Ů";
	cout << "\n�������ڣ�" << birth[0] << " " << birth[1] << " " << birth[2]
		<< "\n3�ſγɼ���"  << score[0] << " " << score[1] << " " << score[2];
	cout << endl << endl;
}




/**********-----------cList��-----------**********/
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
			cout << "��ɾ��\n" << endl;
			break;
		}
		ptr = ptr->next;
	}
	if (deleteFlag == 0)
		cout << "ϵͳ���޴�ѧ����Ϣ\n" << endl;
	return (*this);
}

cList& cList::Find(const char* p)
{
	cLink* ptr = first;
	while (ptr->next)
	{
		if (strcmp(ptr->next->name, p) == 0)
		{
			cout << "\n��ѧ����Ϣ���£�" << endl;
			ptr->next->disp();
			break;
		}
		ptr = ptr->next;
	}
	if(!(ptr->next))
		cout << "ϵͳ���޴�ѧ����Ϣ\n" << endl;
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
	cout << "\n�ܳɼ���ߵ�ѧ����ϢΪ:";
	Find(nameBest);
	cout << "�ܳɼ���͵�ѧ����ϢΪ:";
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
	cout << "\n��ǰϵͳ��ѧ������Ϊ��" << count << endl << endl;
	return count;
}

void cList::ShowAllLink()
{
	cLink* ptr = first;
	cout << "ϵͳ�е�ǰ���ڵ�ѧ��Ϊ��\n";
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
	cout << "\n������ɣ�";
	ShowAllLink();
	return (*this);
}


/**********-----------main����-----------**********/
int main()
{
	cList List;
	firstFlag = 0;  //�����������׽ڵ㣩��ı�flag��ʹ���������ɵĽ������Զ�����������Ϣ�ĺ���
	int i = 0;
	char name[20];
	int exitFlag = 0;

	cout << "*************------�����1601-��ѩ��-201687027------*************\n" << endl;
	cout << "********************------ѧ������ϵͳ------********************" << endl;
	

	while (!exitFlag)
	{
		cout << "---------------------------------------------\n";
		cout<< "  ϵͳ���ܣ�\n" << "    1������ѧ����Ϣ\n"
		<< "    2����ʾϵͳ�е�ǰ���ڵ�����ѧ������\n" << "    3�����ݸ�����ѧ��������ʾ����Ϣ\n" 
			<< "    4�����ݸ�����ѧ������ɾ������Ϣ\n" << "    5����ʾ�ܳɼ���ߺ���͵�ѧ����Ϣ\n"
			<< "    6��ͳ�Ƶ�ǰϵͳ��ѧ������\n" << "    7����ѧ���ܳɼ��Ӹߵ�������\n" << "    8���˳�\n";
		cout << "---------------------------------------------\n";
		cout << "����������ʹ�ù��ܵ���ţ�";
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
				cout << "�������������ѧ����������";
				cin >> name;
				List.Find(name);
				break;
			case 4:
				cout << "����������ɾ��ѧ����������";
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
				cout << "��лʹ�ã�\n";
				exitFlag = 1;
				break;

			default:
				cout << "���������������������\n" << endl;
				break;
		}
	}

	cout << "\n********************------ѧ������ϵͳ------********************\n" << endl;
	cout << "*************------�����1601-��ѩ��-201687027------*************" << endl;

}
