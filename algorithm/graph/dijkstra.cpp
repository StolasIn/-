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
*/
struct edge{
    int to,d;
};
bool operator<(edge a, edge b){
    return a.d>b.d;
}
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        int m=t.size();
        int ma=-1;
        int tmp,i1,i2;
        vector<bool> vis(n+1,false);
        vector<int> dis(n+1,INT_MAX);
        vector<vector<edge>> g(n+1);
        priority_queue<edge> pq;
        for(int i=0;i<m;i++){
            g[t[i][0]].emplace_back(edge{t[i][1],t[i][2]});
        }
        pq.push(edge{k,0});
        dis[k]=0;
        while(!pq.empty()){
            tmp=pq.top().to;
            pq.pop();
            if(vis[tmp]) continue;
            vis[tmp]=true;
            for(auto i : g[tmp]){
                if(dis[i.to]>dis[tmp]+i.d){
                    dis[i.to]=dis[tmp]+i.d;
                    pq.push(edge{i.to,dis[i.to]});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX) return -1;
            ma=max(ma,dis[i]);
        }
        return ma;
    }
};
