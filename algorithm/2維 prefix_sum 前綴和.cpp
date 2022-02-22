class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& ma) {
        if(ma.empty()==true) return;
        int m=ma.size();
        int n=ma[0].size();
        prefix=vector<vector<int>>(m,vector<int>(n));
        int sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                   prefix[i][j] = ma[i][j];
                else if(i==0 && j>0)
                   prefix[i][j] = prefix[i][j-1] + ma[i][j];
                else if(i>0 && j==0)
                   prefix[i][j] = prefix[i-1][j] + ma[i][j];
                else prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + ma[i][j];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        if(prefix.empty()==true) return 0;
        if(r1==0 || c1==0){
            if(r1==0 && c1==0){
                return prefix[r2][c2];
            }
            else if(r1==0){
                return prefix[r2][c2]-prefix[r2][c1-1];
            }
            else{
                return prefix[r2][c2]-prefix[r1-1][c2];
            }
        }
        return prefix[r2][c2]-prefix[r1-1][c2]-prefix[r2][c1-1]+prefix[r1-1][c1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */