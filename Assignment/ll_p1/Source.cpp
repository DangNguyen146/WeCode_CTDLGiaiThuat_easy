#include<iostream>
using namespace std;
struct node
{
	int key;
	int cout = 0;
	node* pNext;
};
struct list
{
	node* pHead;
	node* pTail;
};
node* GetNode(int x)
{
	node* p = new node;
	if (p == NULL)
		exit(-1);
	p->key = x;
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
void xuat(list l)
{
	node* p = l.pHead;
	while (p != NULL)
	{
		cout << p->key << " ";
		p = p->pNext;
	}
}
int DeleteQ(list& l, node* q)
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
void Search(list l)
{
	for (node* i = l.pHead; i != NULL; i = i->pNext)
	{
		i->cout = 1;
		node* q = i;
		for (node* j = i->pNext; j != NULL;)
		{
			if (j->key == i->key)
			{
				node* p = j->pNext;
				i->cout++;
				DeleteQ(l, q);
				j = p;
			}
			else
			{
				q = j;
				j = j->pNext;
			}
		}
			cout << i->key << ": " << i->cout << endl;
	}
}
int main()
{
	list l;
	l.pHead = l.pTail = NULL;
	while (1)
	{
		int x;
		cin >> x;
		if (x == 0)
			break;
		node* p = GetNode(x);
		GetList(l, p);
	}
	if (l.pHead == NULL)
	{
		cout << "Danh sach rong.";
		return 0;
	}
	else
	{
		cout << "Danh sach vua nhap la: ";
		xuat(l);
		cout << endl;
		cout << "So lan xuat hien cua tung phan tu trong danh sach la:" << endl;
		Search(l);
	}
	return 0;
}