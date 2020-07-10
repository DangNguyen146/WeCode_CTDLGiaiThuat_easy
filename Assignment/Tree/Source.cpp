#include<iostream>
using namespace std;
struct node
{
	int key;
	node* pLeft;
	node* pRight;
};
typedef node* Tree;
int insert(Tree& t, int x)
{
	if (t)
	{
		if (t->key == x)
			return 1;
		if (t->key > x)
			return insert(t->pLeft, x);
		if (t->key < x)
			return insert(t->pRight, x);
	}
	t = new node;
	t->key = x;
	t->pLeft = t->pRight = NULL;
	return 0;
}
void nhap(Tree& t)
{
	int x;
	while (1)
	{
		cin >> x;
		if (x == 0)
			break;
		insert(t, x);
	}
}
void LNR(Tree t)
{
	if (t)
	{
		LNR(t->pLeft);
		cout << t->key << " ";
		LNR(t->pRight);
	}
}
void RNL(Tree t)
{
	if (t)
	{
		RNL(t->pRight);
		cout << t->key << " ";
		RNL(t->pLeft);
	}
}
int max(int l, int r)
{
	if (l > r)
		return l;
	else
		return r;
}
int dd(Tree t)
{
	if (t == NULL)
		return 0;
	int l = 1 + dd(t->pLeft);
	int r = 1 + dd(t->pRight);
	return max(l, r);
}
void XuatTheoMucK(Tree t, int h, int k)
{
	if (t == NULL)
		return;
	if (h == k)
		cout << t->key << " ";
	XuatTheoMucK(t->pLeft, h + 1, k);
	XuatTheoMucK(t->pRight, h + 1, k);
}
int main()
{
	Tree t = NULL;
	nhap(t);
	LNR(t);
	cout << endl;
	RNL(t);

	cout << dd(t) << endl;
	int n = dd(t);
	int k = 2;
	for (int i = k; i < n; i++)
	{
		cout << i << ": ";
		XuatTheoMucK(t, 0, i);
		cout << endl;
	}
}