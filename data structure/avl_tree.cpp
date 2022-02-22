#include <iostream>
using namespace std;
template <typename T>
class node{
    public:
    T key;
    int height;
    node* left;
    node* right;
    node(T k){
        height = 1;
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class avl_tree{
    public:
        node<T>* root;

        //constructor
        avl_tree(){
            root=nullptr;
        }

        //destructor
        ~avl_tree(){
            delete_all(root);
        }

        void delete_tree(){
            delete_all(root);
        }

        //delete all node use recursive
        void delete_all(node<T>* root){
            if(root==nullptr) return;
            delete_all(root->left);
            delete_all(root->right);
            delete root;
        }

        T operator[](T x){
            auto tmp = search(x);
            if(tmp==nullptr) {
                printf("not found , return base type");
                T a;
                return a;
            }
            else return tmp->key;
        }

        //user insert data
        void insert(T x){
            root=insert_node(root, x);
        }

        //user delete data
        void remove(T x){
            root=remove_node(root, x);
        }

        //return iterator address
        node<T> * search(T x){
            return search_node(root,x);
        }

        void inorder(){
            inorder_traversal(root);
            cout<<endl;
        }

        void preorder(){
            preorder_traversal(root);
            cout<<endl;
        }

        void postorder(){
            postorder_traversal(root);
            cout<<endl;
        }

        int get_height(){
            return tree_height(root);
        }

    private:
        int tree_height(node<T>* root){
            if(root==nullptr) return 0;
            int x=tree_height(root->left);
            int y=tree_height(root->right);
            return max(x,y)+1;
        }
        int height(node<T> * head){
            if(head==nullptr) return 0;
            return head->height;
        }

       /*       y                              x
               / \      Right Rotation        / \
              x   C     -------------->      A   y
             / \                                / \
            A   B                              B   C*/

        /*
            1.y是head , x是head的左子樹
            2.x成為新的根
            3.x的右子樹變成y的左子樹
            4.y變成x的右子樹
        */

        node<T> * rightRotation(node<T> * head){
            //因為在做右旋時該點的左子樹根會替換原本的根
            node<T> * newhead = head->left;

            //根點的左子樹變成根左子樹的右子樹
            head->left = newhead->right;

            //根點變成左子根的右子根
            newhead->right = head;

            //修改點的高度
            head->height = 1+max(height(head->left), height(head->right));
            newhead->height = 1+max(height(newhead->left), height(newhead->right));

            //要回傳新的點給head的parent
            return newhead;
        }



        /*      x                              y
               / \       Left Rotation        / \
              A   y      ------------->      x   C
                 / \                        / \
                B   C                      A   B*/

        /*
            1.x是head , y是x的右子樹根
            2.y成為新的根
            3.y的左子樹變成x的右子樹
            4.x變成y的左子樹
        */

        node<T> * leftRotation(node<T> * head){

            //做左旋時head的右子樹會替換原本的head
            node<T> * newhead = head->right;

            //新點的原左子樹變成head的右子樹
            head->right = newhead->left;

            //head變成新點的左子樹
            newhead->left = head;

            //修改各點的高度
            head->height = 1+max(height(head->left), height(head->right));
            newhead->height = 1+max(height(newhead->left), height(newhead->right));

            //把新點回傳給head的parent
            return newhead;
        }

        //inorder
        void inorder_traversal(node<T> * head){
            if(head==NULL) return ;
            inorder_traversal(head->left);
            cout<<head->key<<endl;
            inorder_traversal(head->right);
        }


        //preorder
        void preorder_traversal(node<T> * head){
            if(head==NULL) return ;
            cout<<head->key<<endl;
            preorder_traversal(head->left);
            preorder_traversal(head->right);
        }


        //postorder
        void postorder_traversal(node<T> * head){
            if(head==NULL) return ;
            postorder_traversal(head->left);
            postorder_traversal(head->right);
            cout<<head->key<<endl;
        }


        //insert 點
        node<T> * insert_node(node<T> * head, T x){
            if(head==NULL){
                //如果樹是空的，生成根點
                node<T> * temp = new node<T>(x);
                return temp;
            }
            //如果insert的點比目前的點小，插入左子樹，把新做的點變成head的左子樹，
            if(x < head->key) head->left = insert_node(head->left, x);

            //否則插入右子樹，把新做的點變成head的右子樹
            else if(x > head->key) head->right = insert_node(head->right, x);
            //相等情形不考慮

            //該點的高度由左右節點的高度決定，+1 是因為自身的點
            head->height = 1 + max(height(head->left), height(head->right));

            //取得balence factor, 左子樹的高度-右子樹的高度
            int bal = height(head->left) - height(head->right);

            //插入情形 rr,lr,ll,rl
            //如果有不平衡的情形發生，abs(balence factor)>1
            if(bal>1){
                //左邊比較重，觀察x插入的位置
                if(x < head->left->key){
                    //如果x插在左子樹，情況為ll，做一次右旋
                    return rightRotation(head);
                }else{
                    //如果x插在右子樹，情況為lr，
                    //對左子樹做一次左旋，再對不平衡點做一次右旋
                    head->left = leftRotation(head->left);
                    return rightRotation(head);
                }
            }else if(bal<-1){
                //右邊比較重，觀察x插入的位置
                if(x > head->right->key){
                    //如果x插在右子樹，情況為rr，做一次左旋
                    return leftRotation(head);
                }else{
                    //如果x插在左子樹，情況為rl，
                    //對左子樹做一次右旋，再對不平衡點做一次左旋
                    head->right = rightRotation(head->right);
                    return leftRotation(head);
                }
            }
            //回傳插入點
            return head;
        }

        //刪除點
        node<T> * remove_node(node<T> * head, T x){
            //如果樹是空的
            if(head==nullptr) return nullptr;

            //找到點
            if(x < head->key){
                //如果點比目前的數字小，往左子樹走
                head->left = remove_node(head->left, x);
            }else if(x > head->key){
                //如果點比目前的數字大，往右子樹走
                head->right = remove_node(head->right, x);
            }else{
                //如果找到相等的數字
                node<T> * r = head->right;

                //該點的右子樹是空的
                if(head->right==nullptr){
                    //用該點的左小孩取代
                    node<T> * l = head->left;
                    delete(head);

                    //取代原點
                    head = l;
                }
                //如果該點的左子樹是空的
                else if(head->left==nullptr){
                    //用右小孩取代，右小孩是剛才宣告的 r
                    delete(head);
                    head = r;
                }
                else{
                    //如果該點有左右小孩
                    //往右走並一直往左走，找到比他大的最小的節點
                    while(r->left!=nullptr) r = r->left;

                    //把點替換
                    head->key = r->key;

                    //刪掉替換的節點
                    head->right = remove_node(head->right, r->key);
                }
            }

            //如果刪除後的該點沒有小孩，不用平衡直接回傳
            if(head==nullptr) return head;

            //修改該點的樹高
            head->height = 1 + max(height(head->left), height(head->right));

            //取得balence factor
            int bal = height(head->left) - height(head->right);

            //跟插入時一樣做旋轉，情形相同
            if(bal>1){
                if(x > head->left->key){
                    return rightRotation(head);
                }else{
                    head->left = leftRotation(head->left);
                    return rightRotation(head);
                }
            }else if(bal<-1){
                if(x < head->right->key){
                    return leftRotation(head);
                }else{
                    head->right = rightRotation(head->right);
                    return leftRotation(head);
                }
            }
            return head;
        }

        //搜尋點
        node<T> * search_node(node<T> * head, T x){
            //如果是空節點，回傳沒找到
            if(head == nullptr) return nullptr;
            T k = head->key;
            if(k == x) return head;
            if(k > x) return search_node(head->left, x);
            if(k < x) return search_node(head->right, x);
        }
};
int main(){
    avl_tree<int> tr;
    int a;
    cin>>a;
    for(int i=a-1;i>=0;i--){
        tr.insert(i);
    }
    tr.inorder();
}
