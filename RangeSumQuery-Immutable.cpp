class NumArray {
public:
    vector<int> numArray;
    NumArray(vector<int> &nums) {
        int len;
        len = nums.size();
        numArray.push_back(0);
        if(len)
            numArray.push_back(nums[0]);
        for (int i=1;i<len;i++)
            numArray.push_back(numArray[i] + nums[i]);
    }

    int sumRange(int i, int j) {
        return (numArray[j+1] - numArray[i]);
    }
};
