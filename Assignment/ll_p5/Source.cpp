#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
	int info;
	Node* pNext;
};

struct List
{
	Node* pHead;
	Node* pTail;
};

void CreateList(List& l);
void NhapList(List& l);
int DemSoPhanTu(List l);
void Split(List l, List& l1, List& l2);
void XuatList(List l);

int main()
{
	List l, l1, l2;
	CreateList(l);
	CreateList(l1);
	CreateList(l2);
	NhapList(l);
	if (DemSoPhanTu(l) == 0)
		cout << "Danh sach rong." << endl;
	else
	{
		cout << "Danh sach vua nhap la: ";
		XuatList(l);
		cout << endl;
		Split(l, l1, l2);
		cout << "Cac so chan trong danh sach la: ";
		XuatList(l1);
		cout << endl;
		cout << "Cac so le trong danh sach la: ";
		XuatList(l2);
		cout << endl;
	}
	return 0;
}
void CreateList(List& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
Node* GetNode(int x)
{
	Node* p = new Node;
	if (p == NULL)
		exit(-1);
	p->info = x;
	p->pNext = NULL;
	return p;
}
void GetList(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void NhapList(List& l)
{
	int x;
	while (1)
	{
		cin >> x;
		if (x == 0)
			break;
		Node* p = GetNode(x);
		GetList(l, p);
	}
}
int DemSoPhanTu(List l)
{
	int dem = 0;
	Node* p = l.pHead;
	while (p != NULL)
	{
		dem++;
		p = p->pNext;
	}
	return dem;
}
bool Search(List l1, List l2, int x)
{
	Node* p = l1.pHead;
	while(p != NULL)
	{
		if (p->info == x)
			return true;
		p = p->pNext;
	}
	p = l2.pHead;
	while (p != NULL)
	{
		if (p->info == x)
			return true;
		p = p->pNext;
	}
	return false;
}
void Split(List l, List& l1, List& l2)
{
	Node* p = l.pHead;
	while (p != NULL)
	{
		if (Search(l1, l2, p->info) == false)
		{
			if (p->info % 2 == 0)
			{
				Node* i = GetNode(p->info);
				GetList(l1, i);
			}
			if(p->info%2 != 0)
			{
				Node* i = GetNode(p->info);
				GetList(l2, i);
			}
		}
		p = p->pNext;
	}
}
void XuatList(List l)
{
	Node* p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
}