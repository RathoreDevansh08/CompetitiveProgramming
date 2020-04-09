/*
Following are some uses other than Heapsort:

Priority Queues: Priority queues can be efficiently implemented using Binary Heap because it supports insert(), 
delete() and extractmax(), decreaseKey() operations in O(logn) time. Binomoial Heap and Fibonacci Heap are 
variations of Binary Heap. These variations perform union also in O(logn) time which is a O(n) operation in Binary 
Heap. Heap Implemented priority queues are used in Graph algorithms like Prim’s Algorithm and Dijkstra’s algorithm.

The Heap data structure can be used to efficiently find the kth smallest (or largest) element in an array.
*/

#include<bits/stdc++.h> 
using namespace std; 

int capacity=0, n=0;

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

int parent(int i) { return (i-1)/2; } 
  
int left(int i) { return (2*i + 1); } 

int right(int i) { return (2*i + 2); } 

void insertKey(int A[], int k) 
{ 
    if (n == capacity) 
    { 
        cout << "\nOverflow: Could not insertKey\n"; 
        return; 
    } 
  
    // First insert the new key at the end 
    n++; 
    int i = n - 1; 
    A[i] = k; 
  
    // Fix the min heap property if its violated 
    while (i != 0 && A[parent(i)] > A[i]) 
    { 
       swap(&A[i], &A[parent(i)]); 
       i = parent(i); 
    } 
} 

void decreaseKey(int A[], int i, int new_val) 
{ 
    A[i] = new_val; 
    while (i != 0 && A[parent(i)] > A[i]) 
    { 
       swap(&A[i], &A[parent(i)]); 
       i = parent(i); 
    } 
}

void MinHeapify(int A[], int i) 
{ 
    int l = left(i); 
    int r = right(i); 
    int smallest = i; 
    if (l < n && A[l] < A[i]) 
        smallest = l; 
    if (r < n && A[r] < A[smallest]) 
        smallest = r; 
    if (smallest != i) 
    { 
        swap(&A[i], &A[smallest]); 
        MinHeapify(A, smallest); 
    } 
} 

int extractMin(int A[]) 
{ 
    if (n <= 0) return INT_MAX; 
    if (n == 1) 
    { 
        n--; 
        return A[0]; 
    } 
  
    int root = A[0]; 
    A[0] = A[n-1]; 
    n--; 
    MinHeapify(A, 0); 
  
    return root; 
}

void deleteKey(int A[], int i) 
{ 
    decreaseKey(A, i, INT_MIN); 
    extractMin(A); 
}   

//Time complexity: O(n * log(n))
void build_heap(int A[], int n)
{
	int heapSize=n;
	int j;

	for(j=n/2; j>=0; j--)
	{
	 	MinHeapify(A, j);
	}

	return; 
}

int main()
{
	//maximum capacity
	cin>>capacity;
	
	//heapSize
	cin>>n;
	
	int A[capacity];
	for(int i=0; i<n; i++) cin>>A[i];
	
	build_heap(A, n);
	insertKey(A, 15);
	extractMin(A);
	return 0;
}
