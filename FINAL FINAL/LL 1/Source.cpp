#include<iostream>
using namespace std;
int SelectionSort(int a[], int n)
{
	int min;
	for (int i = 0; i < n-1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] == a[j] || a[j]==0 || a[i]==0)
				return 0;
			if (a[j] < a[min])
				min = j;
		}
		swap(a[min], a[i]);
	}
	return 1;
}
void xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
int nhap(int a[])
{
	int x;
	int i = 0;
	while(1)
	{
		do
		{
			cin >> x;
			if (x == -1)
				return i;
			a[i] = x;
		} while (SelectionSort(a, i + 1) == 0);
		cout << "STEP #" << i + 1 << " :";
		xuat(a, i+1);
		cout << endl;
		i++;
	}
	return 1;
}
int main()
{
	int* a = new int;
	int n=nhap(a);
	if (n == 0)
	{
		cout << "Danh sach rong.";
	}
	else
	{
		cout << "Day so sau khi duoc them la: ";
		xuat(a, n);
	}
}