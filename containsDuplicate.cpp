class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0)
            return false;
        std::sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            if((j<nums.size())&&(nums[i]==nums[j]))
                return true;
        }
        return false;
    }
};
