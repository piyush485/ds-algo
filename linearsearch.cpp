#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter limit of array: ";
    cin>>n;
    int arr[n];
    cout<<"enter elements: \n";
    int i;
    for(i = 0 ; i < n ; i++)
        cin>>arr[i];
    int element;
    cout<<"enter element to be searched: ";
    cin>>element;
    for(i=0;i<n;i++)
    {
        if(arr[i] == element)
        {
            cout<<"element found at "<<i+1<<" position!!";
            break;
        }
    }
    if(i == n)
        cout<<"element not found!!";
    return 0;
}