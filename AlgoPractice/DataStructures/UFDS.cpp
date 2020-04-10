/*
The idea is to always attach smaller depth tree under the root of the deeper tree. This technique is called ___union 
by rank___. This help operations to be optimized to O(Log n) in worst case. 

The second optimization to naive method is Path Compression. The idea is to flatten the tree when find() is called. 
When find() is called for an element x, root of the tree is returned. The find() operation traverses up from x to 
find root. The idea of path compression is to make the found root as parent of x so that we don’t have to traverse 
all intermediate nodes again. If x is root of a subtree, then path (to root) from all nodes under x also compresses.
Eg.
Let the subset {0, 1, .. 9} be represented as below and find() is called
for element 3.
              9
         /    |    \  
        4     5      6
     /     \        /  \
    0        3     7    8
            /  \
           1    2  

When find() is called for 3, we traverse up and find 9 as representative
of this subset. With path compression, we also make 3 as the child of 9 so 
that when find() is called next time for 1, 2 or 3, the path to root is reduced.

               9
         /    /  \    \
        4    5    6     3 
     /           /  \   /  \
    0           7    8  1   2        
    
The two techniques complement each other. The time complexity of each operation becomes even smaller than O(Logn). 
In fact, amortized time complexity effectively becomes small constant.
*/

#include<bits/stdc++.h>
using namespace std;

struct subset 
{ 
    int parent; 
    int rank; 
};

// A utility function to find set of an element i 
// (uses path compression technique) 
int find(struct subset subsets[], int i) 
{ 
    // find root and make root as parent of i (path compression) 
    if (subsets[i].parent != i) 
        subsets[i].parent = find(subsets, subsets[i].parent); 
  
    return subsets[i].parent; 
} 
  
// A function that does union of two sets of x and y 
// (uses union by rank) 
void Union(struct subset subsets[], int x, int y) 
{ 
    int xroot = find(subsets, x); 
    int yroot = find(subsets, y); 
  
    // Attach smaller rank tree under root of high rank tree 
    // (Union by Rank) 
    if (subsets[xroot].rank < subsets[yroot].rank) 
        subsets[xroot].parent = yroot; 
    else if (subsets[xroot].rank > subsets[yroot].rank) 
        subsets[yroot].parent = xroot; 
  
    // If ranks are same, then make one as root and increment 
    // its rank by one 
    else
    { 
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank++; 
    } 
} 

int main()
{
	return 0;
}
