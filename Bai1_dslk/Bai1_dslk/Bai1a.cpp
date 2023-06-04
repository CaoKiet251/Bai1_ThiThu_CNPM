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
void AddTail(List& L,Node* p)
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
    Node* next = NULL, *prev=NULL;
    Node* p = head;
    while(p!=NULL)
    { 
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }
    return prev;
}
void DaoNguocKhoang(List& L, int h, int k)
{
    Node* start = NULL, * end = NULL;
    Node* pre_s = NULL, * next_e = NULL;
    int i = 1;
    if (h == k) return;
    for (Node* p = L.Head; p != NULL; p = p->next)
    {
        if (i < h)
            pre_s = p;
        if (i == h)
            start = p;
        if (i == k)
            end = p;
        if (i > k)
        {
            next_e = p;
            break;
        }
        i++;
    }
    end->next = NULL;
    end = DaoNguoc(start);
    if (pre_s!=NULL)
        pre_s->next = end;
    else
        L.Head = end;
    start->next = next_e;
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

    cout << endl;
    int h, k;
    cin >> h >> k;
    DaoNguocKhoang(L, h, k);

    cout << endl;
    Xuat(L);
}