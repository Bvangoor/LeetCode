class Solution {
public:

    int max(int a, int b){
        if(a>=b)
            return a;
        return b;
    }

    int maxSubArray(vector<int>& nums) {
        int len=nums.size(),maxSum=0;
        if(len==0)
            return maxSum;
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(nums[0]);
        maxSum=nums[0];
        for(int i=1;i<len;i++){
            dp.push_back(max(dp[i]+nums[i], nums[i]));
            maxSum=max(maxSum,dp[i+1]);
        }
        return maxSum;
    }
};
