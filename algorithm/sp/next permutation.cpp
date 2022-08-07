class Solution {
public:
    void nextPermutation(vector<int>& n) {
        int i,j,mi=INT_MAX,po;
        int m=n.size();
        for(i=m-1;i>0;i--){
            if(n[i]>n[i-1]) break;
        }
        if(i==0){
            int l=(m+1)/2;
            for(int k=0;k<l;k++){
                swap(n[k],n[m-k-1]);
            }
            return;
        }
        else{
            for(j=i;j<m;j++){
                if(n[j]>n[i-1]){
                    mi=min(mi,n[j]);
                    po=j;
                }
            }
            swap(n[po],n[i-1]);
            sort(n.begin()+i,n.end());
        }
    }
};