/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* acc(TreeNode* root){
        auto y=root->right;
        auto x=root;
        while(y->left!=nullptr){
            if(y->left->left==nullptr) x=y;
            y=y->left;
        }
        root->val=y->val;
        if(y->right!=nullptr){
            if(x==root){
                x->right=y->right;
            }
            else{
                x->left=y->right;
            }
        }
        else{
            if(x==root){
                x->right=nullptr;
            }
            else{
                x->left=nullptr;
            }
        }
        return root;
    }
    TreeNode* de(TreeNode* root){
        if(root->left==nullptr){
            return root->right;
        }
        else if(root->right==nullptr){
            return root->left;
        }
        else{
            return acc(root);
        }
    }
    TreeNode* del(TreeNode* root, int key){
        if(root==nullptr) return root;
        if(key>root->val){
            root->right=del(root->right,key);
        }
        else if(key<root->val){
            root->left=del(root->left,key);
        }
        else{
            root=de(root);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        root=del(root,key);
        return root;
    }
};