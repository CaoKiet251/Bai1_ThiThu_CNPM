#include <iostream>
using namespace std;

struct Node
{
    Node* next;
    int data;
};
struct List
{
    Node* Head;
    Node* Tail;
};
Node* CreateNode(int x)
{
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}
void CreateList(List& L)
{
    L.Head = NULL;
    L.Tail = NULL;
}
void AddTail(List& L, Node* p)
{
    if (L.Head == NULL)
    {
        L.Head = p;
        L.Tail = L.Head;
    }
    else
    {
        L.Tail->next = p;
        L.Tail = p;
    }
}
Node* DaoNguoc(Node* head)
{
    Node* next = NULL, * prev = NULL;
    Node* p = head;
    while (p != NULL)
    {
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }
    return prev;
}
void DaoViTri(List& L, int n,int k)
{
    if (k == n - k || k > n ) return;
    Node* x = NULL, * y = NULL;
    Node* pre_x = NULL,* pre_y = NULL;
    Node* p = L.Head;
    for (int i = 1; i <= n; i++)
    {
        if (i == k-1)
        {
            pre_x = p;
            x = p->next;
        }
        if (i == n - k)
        {
            y = p->next;
            pre_y = p;
        }
        p = p->next;
    }
    if (pre_x)
        pre_x->next = y;
    if (pre_y)
        pre_y->next = x;
    Node* temp = x->next;
    x->next = y->next;
    y->next = temp;
}
void Xuat(List& L)
{
    for (Node* p = L.Head; p != NULL; p = p->next)
        cout << p->data << " ";
}
int main()
{
    List L;
    CreateList(L);
    int n, x;
    cout << "Nhap so phan tu: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        AddTail(L, CreateNode(x));
    }

    int k;
    cin >> k;
    DaoViTri(L, n, k);

    Xuat(L);
}