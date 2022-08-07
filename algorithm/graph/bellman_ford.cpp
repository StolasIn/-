struct edge{
    int to,d;
};
bool operator<(edge a, edge b){
    return a.d>b.d;
}
class Solution {
public:
    bool bell(vector<vector<int>>& t, int n, int k) {
        int m=t.size();
        int ma=-1;
        int tmp,i1,i2;
        vector<bool> vis(n+1,false);
        vector<int> dis(n+1,1000000);
        vector<vector<edge>> g(n+1);
        dis[k]=0;
        for(int i=1;i<=n;i++){
            for(auto j : t){
                if(dis[j[1]]>dis[j[0]]+j[2]){
                    dis[j[1]]=dis[j[0]]+j[2];
                }
            }
        }
        
        return 1;
    }
};