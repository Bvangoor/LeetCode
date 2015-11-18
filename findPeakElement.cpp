#include<iostream>
#include<vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int len;
    len = nums.size();
    if(len==0)
	return -1;
    if(len==1)
	return 0;
    if(nums[0]>nums[1])
	return 0;
    if(nums[len-1]>nums[len-2])
	return (len-1);
    for(int i=1;i<(len-1);i++) {
	if((nums[i]>nums[i-1])&&(nums[i]>nums[i+1]))
	    return i;
    }
    return -1;
}

/*
You may imagine that num[-1] = num[n] = -INFINIY.
For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/

int main() {
    vector<int> res;
    res.push_back(1);
    res.push_back(2);
    res.push_back(3);
    res.push_back(1);
    cout<<"index : "<<findPeakElement(res)<<"\n";
return 0;
}
