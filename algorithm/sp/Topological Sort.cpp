class Solution {
public:
    int time=0;
    struct node{
        int ver,fin;  
    };
    vector<vector<int>> dag;
    vector<int> vis;
    vector<node> so;
    bool flag=false;
    static bool cmp(node a,node b){
        return a.fin>b.fin;
    }
    void dfs(int x){
        if(flag==true) return;
        if(vis[x]==1){
            flag=true;
            return;
        }
        if(vis[x]==2){
            return;
        }
        vis[x]=1;
        for(auto i : dag[x]){
            dfs(i);
        }
        vis[x]=2;
        time++;
        so[x].ver=x;
        so[x].fin=time;
    }
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<int> ans;
        if(pre.size()==0){
            for(int i=1;i<=num;i++) ans.emplace_back(i);
            return ans;
        }
        dag.resize(num+1);
        so.resize(num+1);
        vis=vector<int>(num+1,0);
        int m=pre.size();
        for(int i=0;i<m;i++){
            dag[pre[i][1]].emplace_back(pre[i][0]);
        }
        for(int i=1;i<=num;i++){
            if(vis[i]==0)
                dfs(i);
            if(flag==true) return vector<int>(0);
        }
        sort(so.begin(),so.end(),cmp);
        for(int i=0;i<num;i++){
            ans.emplace_back(so[i].ver);
        }
        return ans;
    }
};