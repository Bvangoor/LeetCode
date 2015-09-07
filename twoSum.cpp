class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> result;
        int temp;
        for(int i=0;i<nums.size();i++){
            temp=target-nums[i];
            if((map.count(temp))&&((map[temp]-1)<i)){
                result.push_back(map[temp]);
                result.push_back(i+1);
                return result;
            }else{
                map[nums[i]]=i+1;
            }
        }
        return result;
}
};
