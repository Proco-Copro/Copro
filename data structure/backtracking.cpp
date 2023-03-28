#include<iostream>
using namespace std;

void binary(int arr[] ,int n)
{
    if(n<1)
    {
        cout<<arr[n];
    }
    else
    {
        arr[n-1] = 0;
        binary(arr,n-1);
        arr[n-1] = 1;
        binary(arr,n-1);
    }
}

int main()
{
    int n = 2;
   int arr[n];
    binary(arr,n);

}