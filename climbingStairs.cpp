class Solution {
public:
    int climbStairs(int n){
        vector<int> res;
        res.push_back(1);
        res.push_back(1);
        for(int i=2;i<=n;i++)
            res.push_back(res[i-1]+res[i-2]);
        return res[n];
    }
};
