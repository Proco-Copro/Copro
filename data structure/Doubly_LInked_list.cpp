#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};struct Node *head;


int listLength(struct Node *head)
{
    if (head == NULL)
    {
        cout << "\n\nEmpty Linked List\n"<< endl;
        return;
    }
    
        struct Node *current = head;
        int cnt = 0;
        while (current != NULL)
        {
            cnt++;
            current = current->next;
        }
    return cnt;
}


void Print_Linked_list(struct Node *head)
{
    struct Node *print = head;
    if (print == NULL)
    {
     cout << "\n\nlinked list empty\n\n";
     return;
    }
        
    cout << "\n\n";
    while (print != NULL)
    {
        cout << print->data << "->";
        print = print->next;
    }
    cout << "\n\n";
}


void Insert_at_first(struct Node **head , int data)
{
    
    struct Node *new_node;
    new_node = (Node*)malloc(sizeof(struct Node));

    if(*head == NULL)
    {
        cout<<"\n\n::::Empty Linked List::::\n\n";
        return;
    }

    if(new_node == NULL)
    {
        cout<<"\n\n::::Oveflow::::"<<endl<<endl;
        return;
    }
        

        new_node -> data = data;
    
        new_node -> prev = NULL;
        new_node -> next = *head;

        if(*head)
         (*head) -> prev = new_node;

        *head = new_node;  
}


void Insert_at_last(struct Node **head , int data)
{
    struct Node *new_node , *current;
    new_node = (Node*)malloc(sizeof(struct Node));
    if(new_node == NULL)
    {
        cout<<"\n\n::::Oveflow::::"<<endl<<endl;
        return;
    }
    current = *head;
    new_node -> data = data;

    while(current -> next != NULL)
    {
        current = current -> next;
    }
    new_node -> next = NULL;
    current -> next = new_node;
    new_node -> prev = current;
    
    cout<<"\n\n:::::Node Inserted:::::\n\n";
    return;
}


void Insert_at_specific(struct Node **head, int data , int position)   
{
    int i = 1;
    struct Node *new_node , *prev_node , *current_node;
    new_node = (Node*)malloc(sizeof(struct Node));

    if(new_node == NULL)
    {
        cout<<"\n\n:::::Overflow::::::\n\n";
        return;
    }

    current_node = *head;
    new_node -> data = data;
    
    while(i<position)
    {
        i++;
        prev_node = current_node;
        if(prev_node == NULL)
        {
            cout<<"\n\n:::::Position Not Exist:::::\n\n";
            return;
        }
        current_node = current_node -> next;
    }
    new_node -> next = prev_node -> next;
    new_node -> prev = prev_node;

    if(prev_node->next)
    prev_node->next->prev = new_node;

    prev_node->next = new_node;
    cout<<"\n\n:::::Node Inserted:::::\n\n";
    return;

}


void Deletion(struct Node **head , int position)
{
    struct Node *temp1 , *temp2;

    int i = 1;
    if(*head == NULL)
    {
        cout<<"\n\n:::::Alreday Empty:::::\n\n";
        return;
    }

    temp1 = *head;
    if(position == 1)
    {
        *head = (*head)->next;

        if(*head!=NULL)
        (*head) -> prev = NULL;

        delete temp1;

        return;
    }

    while(i<position )
    {
        i++;
        temp2 = temp1;
        if(temp2 == NULL)
        {
            cout<<"\n\n:::::Position Not Exist:::::\n\n";
            return;
        }
        temp1 = temp1 -> next;
    }

    temp2 -> next = temp1 -> next;
    if(temp1 -> next != NULL)
    {
        temp1 -> next -> prev = temp2;
    }
    delete temp1;

    cout<<"\n\n::::Node deleted::::\n\n";
    return;
}


void Delete_Linked_List(struct Node **head)
{
    struct Node *aux , *iter;
    if(*head == NULL)
    {
        cout<<"\n\n:::::Already Empty:::::\n\n";
        return;
    }
   
    while(*head)
    {
        aux = (*head) -> next;
        delete (*head);
        *head = aux;
    }
    cout<<"\n\n::::::Linked List Deleted::::::\n\n";
    *head == NULL;
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
                Insert_at_specific(&head, data, position);
                break;

            case 5:
                cout << "\nEnter the position of to be deleted" << endl;
                cin >> position;
                Deletion(&head, position);
                break;

            case 6:
                Print_Linked_list(head);
                break;

            case 7:
                Delete_Linked_List(&head);
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