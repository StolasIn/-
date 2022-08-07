#include <iostream>
#include <queue>
using namespace std;

/*
範例輸入
    8 點的個數
    10 邊的個數

    邊:

    0 1
    1 3
    1 4
    3 7
    4 7
    5 7
    6 7
    2 5
    2 6
    0 2
*/


vector<int> node[100];  //點之間的的關係
bool vis[100];          //有沒有走過
int node_num;           //點的個數
int edge;               //邊的個數

//深度優先搜尋
void dfs(int x){
    if(vis[x]) return; //如果該點走過
    vis[x]=true; //標記該點為走過
    cout<<x<<" "; //印出值
    for(auto i : node[x]){ //把與該點有連接的點丟進dfs
        dfs(i);
    }
}
int main()
{
    int tmp1,tmp2;

    //如何建立一個 adjacency list
    while(cin>>node_num>>edge){ //輸入點的
        for(int i=0;i<edge;i++){
            cin>>tmp1>>tmp2;
            node[tmp1].push_back(tmp2);
            node[tmp2].push_back(tmp1);
        }
        dfs(0);
    }
}
