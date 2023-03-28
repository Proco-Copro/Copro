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
    for(int i = 0; i < n; i++)
    {
        
        for (int j = i+1; j < n; j++)
        {
             if (arr[j]<arr[i])
              swap(arr[i],arr[j]);
        }
        
    }
}
void print_array(int arr[] , int n)
{
    cout<<"Array after bubble sort algo : "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main()
{
    int n;
   
    cout<<"Enter no. of element in array :";
    cin>>n;
     int arr[n];
    scan_array(arr,n);
    sort(arr,n);
    print_array(arr,n);
    return 0;
}