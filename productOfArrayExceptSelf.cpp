class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length;
        length=nums.size();
        vector<int> output;
        if(length==0)
            return output;
        int before[length],after[length];
        before[0]=1;
        after[length-1]=1;
        for(int i=1;i<length;i++){
            before[i]=before[i-1]*nums[i-1];
            after[(length-1)-i]=after[length-i]*nums[length-i];
        }
        for(int i=0;i<length;i++)
            output.push_back(before[i]*after[i]);
        return output;
    }
};
