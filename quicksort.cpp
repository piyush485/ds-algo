#include<iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y; 
    *y = temp;
}

int quicksort(int a[], int lb, int ub)
{
    int i, j , pivot;
    if(lb < ub)
    {
        pivot = lb;
        i = lb;
        j = ub;
        while(i < j)
        {
            while(a[i] <= a[pivot] && i < ub)
                i++;
            while(a[j] > a[pivot])
                j--;
            if(i<j)
                swap(a[i], a[j]);
        }
    }
    int tempo = a[pivot];
    a[pivot] = a[j];
    a[j] = tempo;
    quicksort(a, lb, j - 1);
    quicksort(a, j + 1, ub);
    
}

int main()
{
    int i, n;
    cout<<"enter the limit: ";
    cin>>n;
    int arr[n];
    cout<<"enter the elements: \n";
    for(i = 0 ; i < n ; i++ )
        cin>>arr[i];
    quicksort(arr, 0, n-1);
    cout<<"sorted array is: ";
    for(i = 0 ; i < n ; i++ )
        cout<<arr[i]<<" ";
    return 0;
}