/*
NAME - AVI GARG
SID - 21105032
BRANCH - ECE
*/

// QUESTION - APPLY BINARY SEARCH WHEN THE SIZE OF AN ARRAY IS UNKNOWN.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

// CREATING THE FUNCTION SUCH THAT WE ARE NOT PASSING THE SIZE OF THE ARRAY TO THE FUNCTION.

// LINEAR SEARCH

// in linear search we are traversing the array while  not keeping any limitation on the the traversing index(i).
int linear_search(int arr[], int x)
{
    for (int i = 0;; i++) // There's no condition to stop the loop until the element is found.
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
}

// BINARY SEARCH
int binary_search_code(int arr[],int l,int r,int x)
{
    int mid = (l+r) / 2;
    while(l<=r)
    {
        if(arr[mid]>x)
        {
            r = mid - 1;
            mid = (l+r) / 2;
        }
        else if(arr[mid]<x)
        {
            l = mid+1;
            mid = (l+r) / 2;
        }
        else
        {
            return mid;
        }
    }

}
//By increasing the range of our search by 2 we are hereby trying to reduce the time complexity to O(log(N)).
int binary_search(int arr[], int x)
{
    int low = 0;
    int high = 1;

    while (arr[high] < x)//if element to be found is still high the value at high index .
    {
        low = high;//update the low value
        high = 2 * high;//double the range of search, when the condition is satisfies then we call BINARY SEARCH on that range(low to high).
    }

    return binary_search_code(arr,low,high,x);
}
/*
NOTE - An array has been created but the size of the array isn't passed to the function.
*/
int main()
{
    // starting index of the array.
    int *arr = new int[10000];
    int n;
    cout << "Number of elements in an array : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << "ENTER THE ELEMENT TO SEARCH FOR : ";
    cin >> x;
    cout << endl;

    cout << "Index of " << x << " from LINEAR SEARCH is : " << linear_search(arr, x) << endl;
    cout << "Index of " << x << " from BINARY SEARCH is : " << binary_search(arr, x) << endl;
    delete[] arr;
}