class Solution {
public:
    int maxProfit(vector<int>& p) {
        if(p.size()<=1)
            return 0;
        int mn=p[0],prof=0,n=p.size();
        for(int i=1;i<n;i++)
        {
            mn=min(mn,p[i]);
            prof=max(prof,p[i]-mn);
        }
        
        return prof;
    }
};