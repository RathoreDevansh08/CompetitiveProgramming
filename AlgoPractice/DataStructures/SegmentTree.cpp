#include<bits/stdc++.h>
using namespace std;

/*
Time Complexity for tree construction is O(n). There are total 2n-1 nodes, and value of every node is calculated 
only once in tree construction.

Time complexity to query is O(Logn). To query a sum, we process at most four nodes at every level and number of 
levels is O(Logn).

The time complexity of update is also O(Logn). To update a leaf value, we process one node at every level and 
number of levels is O(Logn).
*/

int getMid(int s, int e) { return s + (e -s)/2; }  

int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)  
{  
    // If segment of this node is a part of given range, then return  
    // the sum of the segment  
    if (qs <= ss && qe >= se)  
        return st[si];  
  
    // If segment of this node is outside the given range  
    if (se < qs || ss > qe)  
        return 0;  
  
    // If a part of this segment overlaps with the given range  
    int mid = getMid(ss, se);  
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +  
        getSumUtil(st, mid+1, se, qs, qe, 2*si+2);  
}  

void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)  
{  
    // Base Case: If the input index lies outside the range of  
    // this segment  
    if (i < ss || i > se)  
        return;  
  
    // If the input index is in range of this node, then update  
    // the value of the node and its children  
    st[si] = st[si] + diff;  
    if (se != ss)  
    {  
        int mid = getMid(ss, se);  
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);  
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);  
    }  
} 

void updateValue(int arr[], int *st, int n, int i, int new_val)  
{  
    // Check for erroneous input index  
    if (i < 0 || i > n-1)  
    {  
        cout<<"Invalid Input";  
        return;  
    }  
  
    int diff = new_val - arr[i];  
  
    arr[i] = new_val;  
  
    updateValueUtil(st, 0, n-1, i, diff, 0);  
}

int getSum(int *st, int n, int qs, int qe)  
{  
    // Check for erroneous input values  
    if (qs < 0 || qe > n-1 || qs > qe)  
    {  
        cout<<"Invalid Input";  
        return -1;  
    }  
  
    return getSumUtil(st, 0, n-1, qs, qe, 0);  
} 

int constructSTUtil(int arr[], int ss, int se, int *st, int si)  
{  
    if (ss == se)  
    {  
        st[si] = arr[ss];  
        return arr[ss];  
    }  

    int mid = getMid(ss, se);  
    st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) +  
            constructSTUtil(arr, mid+1, se, st, si*2+2);  
    return st[si];  
}  

int *constructST(int arr[], int n)  
{  
    //Height of segment tree  
    int x = (int)(ceil(log2(n)));    
    //Maximum size of segment tree  
    int max_size = 2*(int)pow(2, x) - 1;  
  
    // Allocate memory  
    int *st = new int[max_size];  

    constructSTUtil(arr, 0, n-1, st, 0);  
  
    return st;  
}  

int main()
{
	int arr[] = {1, 3, 5, 7, 9, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
  
    int *st = constructST(arr, n);  
  
    updateValue(arr, st, n, 1, 10);  
  
    cout<<"Updated sum of values in the given range = "
            <<getSum(st, n, 1, 3)<<endl;  

	return 0;
}
