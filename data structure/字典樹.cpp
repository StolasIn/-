#include<iostream>
using namespace std;
struct TrieNode{
    bool is_end=0;
    TrieNode *children[26];
    
    TrieNode() {
        is_end = false;
        
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

TrieNode* root;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n=word.size();
        TrieNode* curr=root;
        
        for(int i=0;i<n;i++)
        {
            int val=word[i]-'a';
            if(curr->children[val]==NULL)
                curr->children[val]=new TrieNode();
            curr=curr->children[val];
        }
                     
        curr->is_end=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int  n=word.size();
        TrieNode* curr=root;
        bool is_end=0;
        for(int i=0;i<n;i++)
        {
            int val=word[i]-'a';
            curr=curr->children[val];  
            if(curr==NULL)
                return 0;     
        }
        return curr->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        int  n=word.size();
        TrieNode* curr=root;
        for(int i=0;i<n;i++)
        {
            int val=word[i]-'a';
            if(curr==NULL || curr->children[val]==NULL)
                return 0;
            curr=curr->children[val];            
        }
        return 1;        
    }
};
int main(){

}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

