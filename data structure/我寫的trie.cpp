class trie_node{
public:
    bool isend;
    vector<trie_node*> link;
    trie_node(){
        isend=false;
        link.assign(26,nullptr);
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    trie_node* root;
    trie_node* trie_pointer;
    int counter;
    vector<string> strs;
    Trie() {
        root=new trie_node();
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        counter=0;
        int m=word.size();
        trie_pointer=root;
        while(counter<word.size()){
            if(trie_pointer->link[word[counter]-'a']==nullptr){
                trie_pointer->link[word[counter]-'a']=new trie_node();
            }
            trie_pointer=trie_pointer->link[word[counter]-'a'];
            counter++;
        }
        trie_pointer->isend=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trie_pointer=root;
        counter=0;
        while(trie_pointer!=nullptr && counter<word.size()){
            trie_pointer=trie_pointer->link[word[counter++]-'a'];
        }
        if(trie_pointer==nullptr) return false;
        if(trie_pointer->isend==false) return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trie_pointer=root;
        counter=0;
        while(trie_pointer!=nullptr && counter<prefix.size()){
            trie_pointer=trie_pointer->link[prefix[counter++]-'a'];
        }
        if(trie_pointer==nullptr) return false;
        else{
            if(trie_pointer->isend==true) return true;
            for(int i=0;i<26;i++){
                if(trie_pointer->link[i]!=nullptr){
                    return true;
                }
            }
            return false;
        }
    }

    vector<string> related(string prefix){
        strs.clear();
        if(startsWith(prefix)==false){
            return strs;
        }
        trie_pointer = root;
        string now = "";
        related_u(trie_pointer,strs,now,prefix,0);
        return strs;
    }

    void related_u(trie_node* r,vector<string>& strs,string now,string prefix,int ind){
        if(ind<prefix.size()){
            now+=prefix[ind];
            related_u(r->link[prefix[ind]-'a'],strs,now,prefix,ind+1);
        }
        else{
            if(r->isend==true){
                strs.emplace_back(now);
            }
            for(int i=0;i<26;i++){
                if(r->link[i]!=nullptr){
                    now+=(char)(i+'a');
                    related_u(r->link[i],strs,now,prefix,ind);
                    now.pop_back();
                }
            }
        }
    }
};