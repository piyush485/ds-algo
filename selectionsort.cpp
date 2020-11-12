/*
first find out the smallest element from the array
and this step have to be done on every pass
number of passes = n -1
2 loops : one for passes
 another for sorting algo
time complexicity is O(n^2) for both worst and best case
min = i
and in second loop check for min = i
use call by reference for swap function
*/
#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n;
    cout<<"enter limit: ";
    cin>>n;
    int arr[n];
    int i;
    cout<<"enter elements: ";
    for(i = 0 ; i < n ; i++ )
        cin>>arr[i];
    int j;
    for(i = 0 ; i < n - 1 ; i ++)
    {
        int min = i;
        for(j = i + 1 ; j < n ; j++ )
        {
            if(arr[j] < arr[min])
                min = j;
        }
        if(min != i)
            swap(&arr[i],&arr[min]);
    }
    cout<<"\nsorted array: ";
    for(i = 0 ; i < n ; i++ )
        cout<<arr[i]<<" ";
    return 0;
}