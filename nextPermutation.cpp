class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len, k=-1, l=-1;
        len = nums.size();
        if(len>=2) {
            for (int i = len-2;i>=0;i--) {
                if(nums[i]<nums[i+1]) {
                    k=i;
                    break;
                }
            }
            if(k==-1) {
                sort(nums.begin(), nums.end());
                return ;
            }
            for (int i=len-1;i>=0;i--) {
                if(nums[k]<nums[i]) {
                    l=i;
                    break;
                }
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin()+k+1, nums.end());
    } else
        return ;
    }
};
