/*
> Trie is an efficient information reTrieval data structure. Using Trie, search complexities can be brought to 
optimal limit (key length). If we store keys in binary search tree, a well balanced BST will need time proportional to M * log N, where M is maximum string length and N is number of keys in tree. Using Trie, we can search the key in O(M) time. However the penalty is on Trie storage requirements.

> To deal with storage issues in a better way, we use Ternary Search tree, compressed Trie methods.

> A ternary search tree is a special trie data structure where the child nodes of a standard trie are ordered as a 
binary search tree.
Representation of ternary search trees:
Unlike trie(standard) data structure where each node contains 26 pointers for its children, each node in a ternary 
search tree contains only 3 pointers:
	1. The left pointer points to the node whose value is less than the value in the current node.
	2. The equal pointer points to the node whose value is equal to the value in the current node.
	3. The right pointer points to the node whose value is greater than the value in the current node.

> Insert and search costs O(key_length), however the memory requirements of Trie is O(ALPHABET_SIZE * key_length * 
N) where N is number of keys in Trie. There are efficient representation of trie nodes (e.g. compressed trie, 
ternary search tree, etc.) to minimize memory requirements of trie.

> During delete operation we delete the key in bottom up manner using recursion. The following are possible 
conditions when deleting key from trie,

1. Key may not be there in trie. Delete operation should not modify trie.
2. Key present as unique key (no part of key contains another key (prefix), nor the key itself is prefix of another 
key in trie). Delete all the nodes.
3. Key is prefix key of another long key in trie. Unmark the leaf node.
4. Key present in trie, having atleast one other key as prefix key. Delete nodes from end of key until first leaf 
node of longest prefix key.
*/

#include <bits/stdc++.h> 
using namespace std; 
  
const int ALPHABET_SIZE = 26; 
   
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isEndOfWord is true if the node represents end of a word 
    bool isEndOfWord; 
}; 
  
struct TrieNode *getNode() 
{ 
    struct TrieNode *pNode =  new TrieNode; 
    
    pNode->isEndOfWord = false; 
    for (int i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL; 
  
    return pNode; 
} 

void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index])  pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 

bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
}

bool isEmpty(struct TrieNode* root) 
{ 
    for (int i = 0; i < ALPHABET_SIZE; i++)  if(root->children[i]) return false; 
    return true; 
} 

struct TrieNode* remove(TrieNode* root, string key, int depth = 0) 
{ 
    // If tree is empty 
    if (!root) return NULL; 
  
    // If last character of key is being processed 
    if (depth == key.size()) { 
        // This node is no more end of word after removal of given key 
        if (root->isEndOfWord) root->isEndOfWord = false; 
  
        // If given is not prefix of any other word 
        if (isEmpty(root)) { 
            delete (root); 
            root = NULL; 
        } 
  
        return root; 
    } 
  
    // If not last character, recur for the child obtained using ASCII value 
    int index = key[depth] - 'a'; 
    root->children[index] = remove(root->children[index], key, depth + 1); 
  
    // If root does not have any child (its only child got deleted), and it is not end of another word. 
    if (isEmpty(root) && root->isEndOfWord == false) { 
        delete (root); 
        root = NULL; 
    } 
  
    return root; 
} 

int main() 
{ 
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their" }; 
    int n = sizeof(keys)/sizeof(keys[0]); 
  
    struct TrieNode *root = getNode(); 

    for (int i = 0; i < n; i++) insert(root, keys[i]); 
 
    search(root, "the") ? cout << "Yes\n" : cout << "No\n"; 
	remove(root, "heroplane");
	
    return 0; 
}  
