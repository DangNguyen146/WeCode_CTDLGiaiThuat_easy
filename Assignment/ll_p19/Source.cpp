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
		node* p = GetNode(x);
		GetList(l, p);
	}
}
int deleQ(list& l, node* q)
{
	node* p = q->pNext;
	while (p != NULL)
	{
		if (p == l.pTail)
			l.pTail = q;
		q->pNext = p->pNext;
		delete p;
	}
	return 1;
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
void xuli(list l, list& l1, list& l2, int k)
{
	node* p = l.pHead;
	while (p != NULL)
	{
		node* temp = p->pNext;
		p->pNext = NULL;
		if (p->info % k == 0)
		{
			GetList(l1, p);
		}
		else
		{
			GetList(l2, p);
		}
		p = temp;
	}
}
int main()
{
	list l;
	CreateList(l);
	nhap(l);
	list l1, l2;
	CreateList(l1);			//chia hết cho k
	CreateList(l2);			//không chia hết cho k
	int k;
	cin >> k;
	xuli(l, l1, l2, k);
	xuat(l1);
	cout << endl;
	xuat(l2);
}