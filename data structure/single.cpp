#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};struct Node *head;


int listLength(struct Node *head)
{
    struct Node *current = head;

    int count = 0;
    if(head == NULL)
    {
        cout<<"\n\n::::Empty Linked List::::::\n\n";
        return 0;
    }
     
        while(current != NULL)
        {
            current = current -> next;
            count++;
        } 

        return count;
}

void Using_array(Node **head_ref , int data , int position)
{
    int k = listLength(head)+1+position;
    Node *new_node;
    new_node = (Node*)malloc(sizeof(struct Node));

    if(*head_ref == NULL)
    {
        cout<<"\n\n::::Empty Linked List::::\n\n";
        return;
    }

    if(new_node == NULL)
    {
        cout<<"\n\n::::Oveflow::::"<<endl<<endl;
        return;
    }
}

void Array()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        Using_array(&head , arr[i] , i );
    }
}

void Insert_at_first(struct Node **head , int data)
{
    struct Node *new_node;
    new_node = (Node*)malloc(sizeof(struct Node));

    if(new_node == NULL)
    {
        cout<<"\n\n::::Overflow::::\n\n";
        return;
    }

    new_node -> data = data;
    new_node -> next = *head;
    *head = new_node;
    return;
}

void Insert_at_last(struct Node **head , int data)
{
    struct Node *new_node , *current = *head;
    new_node = (Node*)malloc(sizeof(struct Node));

    if(new_node == NULL || *head == NULL)
    {
        cout<<"\n\n::::Overflow::::\n\n";
        return;
    }

    while(current->next != NULL)
    {
        current = current->next;
    }

    new_node -> data = data;
    new_node -> next = NULL;
    current -> next = new_node;

    return;
}

void Insert_specific_positon(struct Node **head , int data, int position)
{
    
    int i = 1;
    struct Node *current , *prev , *new_node;
    new_node = (Node*)malloc(sizeof(struct Node));

    if(*head == NULL)
    {
        cout<<"\n\n::::Empty Linked List::::\n\n";
        return;
    }

    if(new_node == NULL )
    {
         cout<<"\n\n::::Overflow::::\n\n";
         return;
    }
    current = *head;
    new_node -> data = data;

    while(i<position)
    {
        i++;
        prev  = current;
        if(prev == NULL)
        {
            cout<<"\n\nPosition ["<<position<<"] does not exist\n\n";
            return;
        }
        current = current -> next;

        
    }
    new_node -> next = prev -> next;
    prev -> next = new_node;

    cout<<"\n\nNode inserted\n\n";
    return;
}

void Deletion(struct Node **head , int position)
{
    int i = 1;
    struct Node *current , *prev;
    if(*head == NULL)
    {
        cout<<"\n\n::::Already Empty::::\n\n";
        return;
    }
    current = *head;

    if(position == 1)
    {
        *head = (*head) -> next;
        delete(current);
    }
    else
    {
        while(i<position)
        {
            i++;
            prev = current;
            current = current -> next;            
            if(current == NULL)
            {
                cout<<"\n\npositon ["<<position<<"] Not exist.\n\n";
                return;
            }
        }
        
        prev -> next = current -> next;
        delete(current);
    }
}

void Print(struct Node *head)
{
    struct Node *print = head;

    if(head == NULL)
    {
        cout<<"\n\n::::Empty Linked List::::\n\n";
        return;
    }
    cout<<"\n\n";
    while(print != NULL)
    {
        cout<<"["<<print -> data<<"]->";
        print = print -> next;
    }
    cout<<"\n\n";
}

void Delete_linked_list(struct Node **head)
{
    struct Node *auxilary , *iterator;
    if(*head == NULL)
    {
        cout<<"\n\n::::LINKED LIST EMPTY::::\n\n";
    }
    
    while(*head)
    {
        auxilary = (*head) -> next;
        delete((*head));
         *head = auxilary;
    }
    *head == NULL;
    cout<<"\n\n::::::DELETED:::::::\n\n";
    return;
}

int main(void)
{

    int choice, position , data;

    

    while (choice != 8)
    {
        cout<<"\n\n************MAIN MENU**************\n";
        cout<<"\nChoose option for LINKED LIST\n";
        cout<<"\n===================================\n";
        cout << "\npress [1] for Length" << endl;
        cout << "\npress [2] for insertion at first" << endl;
        cout << "\npress [3] for insertion at Last" << endl;
        cout << "\npress [4] for insertion at random position" << endl;
        cout << "\npress [5] for DELETING a Node" << endl;
        cout << "\npress [6] for printing Linked list" << endl;
        cout << "\npress [7] for DELETING Linked list" << endl;
        cout << "\npress [8] for EXIT" << endl;
        
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout<<"\n\nLength of Linked List is : ["<<listLength(head)<<"]\n\n";
                break;

            case 2:            
                cout << "Enter data" << endl;
                cin >> data;
                Insert_at_first(&head, data);
                break;

            case 3:
                cout << "Enter data" << endl;
                cin >> data;
                if(head == NULL)
                {
                    Insert_at_first(&head , data);
                    break;
                }
                Insert_at_last(&head, data);
                break;

            case 4:
                cout << "\nEnter Position" << endl;
                cin >> position;
                cout << "\nEnter data" << endl;
                cin >> data;
                if(position == 1)
                {
                   Insert_at_first(&head,data);
                   break;
                }
                Insert_specific_positon(&head, data, position);
                break;

            case 5:
                cout << "\nEnter the position of to be deleted" << endl;
                cin >> position;
                Deletion(&head, position);
                break;

            case 6:
                Print(head);
                break;

            case 7:
                Delete_linked_list(&head);
                break;

            case 8:
                exit(0);
                break;  

            default:
            cout<<"\n\n:::::Enter Valid Option:::::\n\n";
            break;
        }
    }
    return 0;
}