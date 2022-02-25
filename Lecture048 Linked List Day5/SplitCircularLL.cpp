#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data = 0)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        cout << "Deleted element is: " << this->data << endl;
    }
};
void insertStart(int data, Node *&tail) // recieving head by refrence
{
    Node *newnode = new Node(data);
    if (tail == NULL)
    {
        newnode->next = newnode;
        tail = newnode;
        return;
    }
    newnode->next = tail->next;
    tail->next = newnode;
}
void print(Node *&tail)
{
    if (tail == NULL)
    {
        cout << "Empty Linked List" << endl;
        exit(1);
    }
    Node *t = tail->next;
    do
    {
        cout << t->data << " ";
        t = t->next;
    } while (t != tail->next);
    cout << endl;
}
void insertTail(int data, Node *&tail)
{
    Node *temp = new Node(data);
    if (tail == NULL)
    {
        temp->next = temp;
        tail = temp;
        return;
    }
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
}
int getLength(Node *tail)
{
    if (tail == NULL)
    {
        return 0;
    }
    int cnt = 0;
    Node *t = tail->next;
    do
    {
        cnt++;
        t = t->next;
    } while (t != tail->next);
    return cnt;
}
void splitList(Node *tail, Node *&head, Node *&head2)
{
    int len = getLength(tail);
    if (len == 0)
        return;
    int mid = len / 2 - 1;
    if (len % 2 != 0)
    {
        mid += 1;
    }
    Node *temp = tail->next;
    while (mid)
    {
        temp = temp->next;
        mid--;
    }
    head2 = temp->next;
    temp->next = tail->next;
    head = temp;
    temp = head2;
    while (temp->next != tail->next)
    {
        temp = temp->next;
    }
    temp->next = head2;
    head2 = temp;
}
int main()
{
    Node *tail = NULL;
    insertStart(1, tail);
    insertTail(2, tail);
    insertTail(3, tail);
    insertTail(4, tail);
    insertTail(5, tail);
    insertTail(6, tail);
    print(tail);
    Node *head = NULL, *head2 = NULL;
    splitList(tail, head, head2);
    print(head);
    print(head2);
    return 0;
}