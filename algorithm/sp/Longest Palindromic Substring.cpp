class Solution {
public:
    string longestPalindrome(string& s) {
        int max_left = 0;
        int max_len = -1;
        bool isodd = false;
        for(int i=0;i<s.size();i++){
            int odd = expand(s,i,i);
            int even = expand(s,i,i+1);
            if(max_len<odd || max_len<even){
                max_left=i;
                max_len = max(odd,even);
                isodd = odd>even ? true : false;
            }
        }
        if(isodd){
            return s.substr(max_left-max_len/2,max_len);
        }
        else{
            return s.substr(max_left-max_len/2+1,max_len);
        }
    }
    int expand(string& s,int l,int r){
        while(l>=0 && r<=s.size() && s[l]==s[r]){
            r++;
            l--;
        }
        r--;
        l++;
        return r-l+1;
    }
};