#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct matrix{
	int row,col;
};
int sol(vector<matrix>& m,vector<vector<int>>& dp,vector<vector<bool>>& vis,int x,int y){
	if(x==y) return 0;
	if(vis[x][y]==true) return dp[x][y];
	for(int i=x;i<y;i++){
		dp[x][y]=min(dp[x][y],sol(m,dp,vis,x,i)+sol(m,dp,vis,i+1,y)+m[x].row*m[i].col*m[y].col);
	}
	vis[x][y]=true;
	return dp[x][y];
}
int main(){
	int num;
	vector<matrix> mc;
	vector<vector<int>> dp;
	vector<vector<bool>> vis; 
	while(cin>>num){
		mc.resize(num);
		dp=vector<vector<int>>(num,vector<int>(num,INT_MAX));
		vis=vector<vector<bool>>(num,vector<bool>(num,false));
		for(int i=0;i<num;i++){
			cin>>mc[i].row;
			cin>>mc[i].col;
		}
		cout<<sol(mc,dp,vis,0,num-1)<<endl;
		for(auto i:dp){
			for(auto j:i){
				cout<<j<<" ";
			}
			cout<<endl;
		}
	}
}