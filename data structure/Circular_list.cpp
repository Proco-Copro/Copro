#include<iostream>
#include<stdlib.h>
using namespace std;


typedef struct Node
{
    int data;
    Node *next;
};Node *head;

void ListLength(Node *head)
{
    Node *current = head;
    int count = 0;

    if(head == nullptr)
    {
        cout<<"\n\n::::::Linked list Empty:::::\n\n";
        return;
    }
    do
    {
        current = current -> next;
        count++;
    } while (current != head);
    
    cout<<"\n\nLength of List is ["<<count<<"]\n\n";
    return;
}
