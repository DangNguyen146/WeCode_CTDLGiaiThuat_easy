#include<iostream>
using namespace std;
struct node
{
	int info;
	node* pNext;
};
struct list
{
	node* pHead;
	node* pTail;
};
void CreateList(list& l)
{
	l.pHead = l.pTail = NULL;
}
node* GetNode(int x)
{
	node* p = new node;
	if (p == NULL)
		exit(-1);
	p->info = x;
	p->pNext = NULL;
	return p;
}
void GetList(list& l, node* p)
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
void Nhap(list& l)
{
	int x;
	while (1)
	{
		cin >> x;
		if (x == 0)
			break;
		node* p = GetNode(x);
		GetList(l, p);
	}
}
void xuat(list l)
{
	node* p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
}
int deleQ(list& l, node* q)
{
	node* p = q->pNext;
	if (p != NULL)
	{
		if (p == l.pTail)
			l.pTail = q;
		q->pNext = p->pNext;
		delete p;
	}
	return 1;
}
void SapXep(list& l)
{
	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		for (node* j = i->pNext; j != NULL; j = j->pNext)
			if (i->info > j->info)
				swap(i->info, j->info);
	}
}
void Tron(list& l1, list l2)
{
	l1.pTail->pNext = l2.pHead;
	l1.pTail = l2.pTail;
}
int main()
{
	list l1;
	list l2;
	CreateList(l1);
	CreateList(l2);
	Nhap(l1);
	Nhap(l2);
	bool test = false;
	if (l1.pHead == NULL)
	{
		cout << "Danh sach l1 rong.";
		test = true;
		cout << endl;
	}
	else
	{
		cout << "Danh sach l1 la: ";
		xuat(l1);
		cout << endl;
	}
	if (l2.pHead == NULL)
	{
		cout << "Danh sach l2 rong.";
		test = true;
		cout << endl;
	}
	else
	{
		cout << "Danh sach l2 la: ";
		xuat(l2);
		cout << endl;
	}
	if (test == true)
	{
		cout << "Khong tron duoc.";
		return 0;
	}
	else
	{
		cout << "Danh sach l1 sau khi sap xep la: ";
		SapXep(l1);
		xuat(l1);
		cout << endl << "Danh sach l2 sau khi sap xep la: ";
		SapXep(l1);
		xuat(l1);
		cout << endl << "Ket qua tron l1 voi l2 la: ";
		Tron(l1, l2);
		SapXep(l1);
		xuat(l1);
	}
}