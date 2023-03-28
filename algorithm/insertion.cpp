#include<iostream>
using namespace std;
void scan_array(int arr[] , int n)
{
    cout<<"Enter element of array : "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
}
void sort (int arr[] , int n)
{
    int min = 0;
    for(int i = 1; i < n; i++)
    {
        
        int temp = arr[i];
        int j = i-1;
        while(j >= 0 && temp <= arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
void print_array(int arr[] , int n)
{
    cout<<"Array after insertion sort algo : "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main()
{
    int n;
   
    cout<<"Enter no. of element in array : "<<endl;
    cin>>n;
     int arr[n];
    scan_array(arr,n);
    sort(arr,n);
    print_array(arr,n);
    return 0;
}