/*
bubble sort
comparison is between two adjacent elements of the array 
total passes = n -1
on every passes 4 comperisons or iterations 
2 loops required
loops for passes = for( i = 0 ; i < n - 1 ; i++ )
loops for iteration = for( j = 0 ; j < n - 1 ; j++ )
    we have toc check
        if(arr[i] > arr[j])
        {
            temp = arr[j];
            arr[j] = arr[j +1];
            arr[j +1] = temp;
        }
after every passes we got a max value
on modifying for iteraton : 
    for( j = 0 ; j < n + i - 1 ; j++ )
in order to take less complexicity: take a flag variable 
time complexicity: 
    best case: = o(n)
    worst case = o(n^2)
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter limit: ";
    cin>>n;
    int arr[n];
    cout<<"enter elements: ";
    int i;

    for(i = 0 ; i < n ; i++ )
        cin>>arr[i];
    
    int j;
    int flag = 0;
    int temp;
    for(i = 0 ; i < n-1 ; i++ )
    {
        flag = 0;
        for(j = 0 ; j < n - i - 1 ; j++ )
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
    cout<<"sorted array: \n";
    for(i = 0 ; i < n ; i++ )
        cout<<arr[i]<<" ";
    return 0;
}