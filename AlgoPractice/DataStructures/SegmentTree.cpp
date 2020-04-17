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
int lazy[1000] = {0};  // To store pending updates 

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

int getSumUtil_Lazy(int *st, int ss, int se, int qs, int qe, int si) 
{ 
    // If lazy flag is set for current node of segment tree, then there are some pending updates. So we need to 
    // make sure that the pending updates are done before processing the sub sum query 
    if (lazy[si] != 0) 
    { 
        // Make pending updates to this node. Note that this node represents sum of elements in arr[ss..se] and 
        // all these elements must be increased by lazy[si] 
        st[si] += (se-ss+1)*lazy[si]; 
  
        // checking if it is not leaf node because if it is leaf node then we cannot go further 
        if (ss != se) 
        { 
            // Since we are not yet updating children os si, we need to set lazy values for the children 
            lazy[si*2+1] += lazy[si]; 
            lazy[si*2+2] += lazy[si]; 
        } 
  
        // unset the lazy value for current node as it has been updated 
        lazy[si] = 0; 
    } 
  
    // Out of range 
    if (ss>se || ss>qe || se<qs) 
        return 0; 
  
    // At this point we are sure that pending lazy updates are done for current node. So we can return value  
    // (same as it was for query in our previous post) 
  
    // If this segment lies in range 
    if (ss>=qs && se<=qe) 
        return st[si]; 
  
    // If a part of this segment overlaps with the given range 
    int mid = (ss + se)/2; 
    return getSumUtil_Lazy(st, ss, mid, qs, qe, 2*si+1) + 
           getSumUtil_Lazy(st, mid+1, se, qs, qe, 2*si+2); 
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

// update range without lazy propagation
void updateRange(int *st, int ss, int se, int us, int ue, int diff, int si) 
{ 
    // out of range 
    if (ss>se || ss>ue || se<us) 
        return ; 
  
    // Current node is a leaf node 
    if (ss==se) 
    { 
        st[si] += diff; 
        return; 
    } 
  
    // If not a leaf node, recur for children. 
    int mid = (ss+se)/2; 
    updateRange(st, ss, mid, us, ue, diff, si*2+1); 
    updateRange(st, mid+1, se, us, ue, diff, si*2+2); 
  
    // Use the result of children calls to update this node 
    st[si] = st[si*2+1] + st[si*2+2]; 
}


// update range with lazy propagation
void updateRange_Lazy(int *st, int ss, int se, int us, int ue, int diff, int si) 
{ 
    // If lazy value is non-zero for current node of segment tree, then there are some pending updates. So we need 
    // to make sure that the pending updates are done before making new updates. Because this value may be used by 
    // parent after recursive calls (See last line of this function) 
    if (lazy[si] != 0) 
    { 
        // Make pending updates using value stored in lazy nodes 
        st[si] += (se-ss+1)*lazy[si]; 
  
        // checking if it is not leaf node because if it is leaf node then we cannot go further 
        if (ss != se) 
        { 
            // We can postpone updating children we don't need their new values now. 
            // Since we are not yet updating children of si, we need to set lazy flags for the children 
            lazy[si*2 + 1]   += lazy[si]; 
            lazy[si*2 + 2]   += lazy[si]; 
        } 
  
        // Set the lazy value for current node as 0 as it has been updated 
        lazy[si] = 0; 
    } 
  
    // out of range 
    if (ss>se || ss>ue || se<us) 
        return; 
  
    // Current segment is fully in range 
    if (ss>=us && se<=ue) 
    { 
        // Add the difference to current node 
        st[si] += (se-ss+1)*diff; 
  
        // same logic for checking leaf node or not 
        if (ss != se) 
        { 
            // This is where we store values in lazy nodes, rather than updating the segment tree itelf 
            // Since we don't need these updated values now we postpone updates by storing values in lazy[] 
            lazy[si*2 + 1]   += diff; 
            lazy[si*2 + 2]   += diff; 
        } 
        return; 
    } 
  
    // If not completely in rang, but overlaps, recur for children, 
    int mid = (ss+se)/2; 
    updateRange_Lazy(st, ss, mid, us, ue, diff, si*2+1); 
    updateRange_Lazy(st, mid+1, se, us, ue, diff, si*2+2); 
  
    // And use the result of children calls to update this node 
    st[si] = st[si*2+1] + st[si*2+2]; 
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
