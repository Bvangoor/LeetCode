#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int missingNumber(vector<int>& nums) {
        long int sum=0, total_sum=0;
        int len=0;
        len = nums.size();
        for (int i=0;i<len;i++) {
            sum=sum+nums[i];
        }
        if(len!=0)
            total_sum = ((len)*(len+1))/2;
        else
            return 0;
        return (total_sum - sum);
    }
};
