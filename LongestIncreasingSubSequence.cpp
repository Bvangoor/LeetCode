#include<iostream>
#include<vector>

using namespace std;

int maximum(int a, int b) {
    if (a<b)
	return b;
    return a;
}

int lengthOfLIS(vector<int>& nums) {
    int len = nums.size();
    if (len==0)
	return 0;
    int maxValue=-1, temp=0;
    int AdjMatrix[len][len];
    int LIS[len];
    for (int i=0;i<len;i++)
	LIS[i]=1;
    for(int i=0;i<len;i++) {
	for(int j=i;j<len;j++) {
	    if(nums[i]<nums[j])
		AdjMatrix[i][j]=1;
	    else
		AdjMatrix[i][j]=0;
	}
    }
    for (int i=0;i<len;i++) {
	for (int j=0;j<i;j++) {
	    if(AdjMatrix[j][i]==1) {
		LIS[i] = maximum(LIS[i], 1+LIS[j]);
	    }
	}
	maxValue = maximum(maxValue, LIS[i]);
    }
    return maxValue;
}

int main() {
/*[10, 9, 2, 5, 3, 7, 101, 18]*/
    vector<int> nums;
    nums.push_back(10);
    nums.push_back(9);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(7);
    nums.push_back(101);
    nums.push_back(18);
    cout<<"Longest Increasing Sequence : "<<lengthOfLIS(nums)<<"\n";
    return 0;
}
