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
void nhap(list& l)
{
	int x;
	while (1)
	{
		cin >> x;
		if (x == 0)
			break;
		node* p = GetNode(x);;
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
void dem(list l)
{
	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		int dem = 1;
		node* q = i;
		for (node* j = i->pNext; j != NULL;)
		{
			if (j->info == i->info)
			{
				node* temp = j->pNext;
				deleQ(l, q);
				j = temp;
				dem++;
			}
			else
			{
				q = j;
				j = j->pNext;
			}
		}
		cout << i->info << ": " << dem << endl;
	}
}
int main()
{
	list l;
	CreateList(l);
	nhap(l);
	if (l.pHead == NULL)
	{
		cout << "Danh sach rong.";
			return 0;
	}
	xuat(l);
	cout << endl;
	dem(l);
	return 0;
}