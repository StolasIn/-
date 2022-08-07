class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int now = 0;
        int ans = -1e9;
        for(int i=0;i<nums.size();i++){
            now+=nums[i];
            ans = max(ans,now);
            if(now<0){
                now=0;
            }
        }
        return ans;
    }
};