class Solution {
public:
    vector<vector<int>> ans;
    int s;
    void re(vector<int>& num,int x){
        if(x==s) ans.emplace_back(num);
        for(int i=x;i<s;i++){
            swap(num[x],num[i]);
            re(num,x+1);
            swap(num[x],num[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        s=nums.size();
        if(nums.size()==0) return ans;
        re(nums,0);
        return ans;
    }
};