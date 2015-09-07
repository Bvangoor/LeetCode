class Solution {
public:
    int max(int a,int b){
        if(a>b)
            return a;
        else
            return b;
    }
    
    int rob(vector<int>& nums) {
        int included_sum, excluded_sum=0;
        if(nums.size()==0)
            return 0;
        included_sum = nums[0];
        for(int i=1;i<nums.size();i++){
            int temp=included_sum;
            included_sum=excluded_sum+nums[i];
            excluded_sum=max(temp,excluded_sum);
        }
        return max(included_sum,excluded_sum);
    }
};
