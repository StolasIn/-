#include <iostream>
#include <queue>
using namespace std;

//廣度優先搜尋 範例

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
deque<int> de;         //bfs用到的queue資料結構，FIFO

void bfs(int x){ //x為起始點
    de.push_back(x);    //把需要bfs的點丟進queue
    while(!de.empty()){ //一路bfs到整個queue空掉
        int n=de.front();
        de.pop_front(); //從queue中拿一個點出來連線
        if(!vis[n]){    //如果該點沒走過
            cout<<n<<" "; //印出點
            for(auto i : node[n]){ //把該點可連到的其他點丟進queue
                de.push_back(i);
            }
        }
        vis[n]=true;
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
        bfs(0);
    }
}
