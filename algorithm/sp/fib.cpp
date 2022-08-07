class Solution {
public:
    unordered_map<int,int> map;
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        if(map.find(n)!=map.end()){
            return map[n];
        }
        return map[n] = climbStairs(n-2) + climbStairs(n-1);
    }
};