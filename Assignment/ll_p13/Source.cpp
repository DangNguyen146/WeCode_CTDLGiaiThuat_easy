
#include <iostream>
using namespace std;
struct node {
    int info;
    node* pNext;
};
struct List {
    node* pHead;
    node* pTail;
};
void CreateList(List& l) {
    l.pHead = NULL;
    l.pTail = NULL;
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
void GetList(List& l, node* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void SortIncrease(List& l)
{
    for(node*i=l.pHead;i!=NULL;i=i->pNext)
        for (node* j = i->pNext; j != NULL; j = j->pNext)
        {
            if (i->info > j->info)
                swap(i->info, j->info);
        }
}
void nhap(List& l)
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
int DeleQ(List& l, node* q)
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
void Search(List& l)
{
    for (node* i = l.pHead; i != NULL; i = i->pNext)
    {
        node* q = i;
        for (node* j = i->pNext; j != NULL;)
        {
            if (i->info == j->info)
            {
                node* temp = j->pNext;
                DeleQ(l, q);
                j = temp;
            }
            else
            {
                q = j;
                j = j->pNext;
            }
        }
    }
}
void xuat(List l)
{
    node* p = l.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}
int main()
{
    List l;
    CreateList(l);
    nhap(l);
    if (l.pHead == NULL) cout << "Danh sach rong.";
    else {
        //cout << "Danh sach vua nhap la: ";
        xuat(l);
        cout << endl;
        Search(l);
    /*    SortIncrease(l);*/
        //cout << endl << "Danh sach sau khi sap xep la: ";
        xuat(l);
    }
    return 0;
}