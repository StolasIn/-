class Solution {
public:
    struct node{
      int x,y;  
    };
    int m,n;
    bool flag=0;
    deque<node> no;
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& vis,int x,int y){
        if(x<0 || y<0 || x>=m || y>=n) return;
        if(vis[x][y]==true) return;
        if(grid[x][y]!='1')  return;
        vis[x][y]=true;
        flag=1;
        dfs(grid,vis,x-1,y);
        dfs(grid,vis,x,y-1);
        dfs(grid,vis,x+1,y);
        dfs(grid,vis,x,y+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int ans=0;
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1')
                    no.push_back(node{i,j});
            }
        }
        for(auto i : no){
            flag=0;
            dfs(grid,vis,i.x,i.y);
            if(flag==1) ans++;
        }
        return ans;
    }
};