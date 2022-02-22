#include <bits/stdc++.h>
using namespace std;
class node{
	node(){}
	node(int a)
	:data(a),path(0),left(nullptr),right(nullptr)
	{}
	int data;
	int path;
	node* left;
	node* right;
};
class leftist{
public:
	void push(int data){
		if(size==0){
			root=new node(data);
			size++;
		}
		else push_uilt(root,data);
	}
	void merge(leftist& obj){
		merge_uilt(root,obj.root);
	}
private:
	node* merge_uilt(node* root,node* obj){
		if(root==nullptr) return obj;
		if(obj==nullptr) return root;
		if(root->data<obf->data){
			root->right=merge_uilt(root->right,obj);
			return root->right;
		}
		else{
			merge_uilt(obj->right,root);
		}
	}
	node* push_uilt(node* root,int data){
		
	}
	int size=0;
	node* root=nullptr;
};