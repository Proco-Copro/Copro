#include<iostream>

#define MAX 1000

using namespace std;

class Stack
{
    private:
    int top;

    public:
    int stack[MAX];
    Stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if(top>=MAX-1)
        {
            cout<<"Stack is Overflow"<<endl;
            return;
        }
        else
        {
            stack[++top] = x;
            cout<<"Pushed into Stack"<<endl;
            return;
        }
    }

    int pop()
    {
        if(top<0)
        {
            cout<<"Stack is UnderFlow"<<endl;
            return 0;
        }
        else
        {
            int ret = stack[top--];
            return ret;
        }
    }

    int peek()
    {
        if(top<0)
        {
            cout<<"Stack is UnderFlow"<<endl;
            return 0;
        }
        else
        {
            int x =  stack[top];
            return x;    
        }
    }

    bool isEmpty()
    {
        return (top<0);
    }

    void printStack()
    {
        cout<<endl;
        while(!isEmpty())
        {
            cout<< peek()<<" ";
            pop();
        }
    }
};

int main(void)
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";
    
    //print top element of stack after popping
    cout << "Top element is : " << s.peek() << endl;
    s.push(30);
    s.push(30);
    s.push(30);
    s.push(30);
    s.push(30);
    s.push(30);
    s.printStack();
    s.pop();
    


}