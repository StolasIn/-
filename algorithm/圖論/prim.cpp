#include <bits/stdc++.h>
#define inf 99999999
using namespace std;
/*
4 6
0 1 10
0 2 5
2 1 4
1 2 3
2 3 1
3 1 2


6
11
0 1 50
0 2 10
0 4 45
1 4 10
1 2 15
2 0 20
2 3 15
3 1 20
3 4 35
4 3 30
5 3 3


7 9
0 1 28
0 5 10
1 2 16
1 6 14
2 3 12
6 3 18
6 4 24
5 4 25
3 4 22

*/
class edge{
public:
    int to,wid;
    edge(int to,int wid)
        :to(to),wid(wid)
    {
    }
};

bool operator<(edge a,edge b){
    return a.wid>b.wid;
}

vector<edge> g[1000];
vector<int> tree;
int dis[1000];
bool vis[1000];
int e;
int v;

void prim(int root){
    int mind;
    priority_queue<edge> pq;
    pq.push(edge{root,0});
    while(tree.size()<v && !pq.empty()){
        int tmp=pq.top().wid;
        mind=pq.top().to;
        pq.pop();
        if(vis[mind]) continue;
        vis[mind] = true;
        tree.push_back(tmp);
        for(int i=0;i<g[mind].size();i++){
            if(!vis[g[mind][i].to]){
                pq.push(g[mind][i]);
            }
        }
    }
}

void init(){
    tree=vector<int>();
    for(int i=0;i<v;i++){
        vis[i]=false;
    }
}

int main()
{
    int tmp1,tmp2,tmp3;
    scanf("%d%d",&v,&e);
    for(int i=0;i<e;i++){
        scanf("%d%d%d",&tmp1,&tmp2,&tmp3);
        g[tmp1].push_back(edge{tmp2,tmp3});
        g[tmp2].push_back(edge{tmp1,tmp3});
    }
    for(int j=0;j<v;j++){
        init();
        prim(j);
        for(int i=1;i<v;i++){
            printf("%d ",tree[i]);
        }
        puts("");
    }
}
