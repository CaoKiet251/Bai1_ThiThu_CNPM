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
void TronDS(List& L)
{
    Node* slow = L.Head, * fast = slow->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* start = slow->next;
    slow->next = NULL;
    Node* q = DaoNguoc(start);
    L.Tail = start;
    Node* p = L.Head;
    while (q && p)
    {
        Node* tam = q->next;
        q->next = p->next;
        p->next = q;
        p = p->next->next;
        q = tam;
    }
    if (L.Tail->next != NULL)
    {
        Node* r = L.Tail->next;
        L.Tail = r;
        L.Tail->next = NULL;
    }
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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        AddTail(L, CreateNode(x));
    }

    TronDS(L);
    Xuat(L);
}