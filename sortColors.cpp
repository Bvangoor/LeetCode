#include<iostream>
#include<vector>

using namespace std;

void sortColors(vector<int>& nums) {
    int len, count_0=0, count_1=0, count_2=0;
    len = nums.size();
    for(int i=0;i<len;i++) {
	if (nums[i]==0)
	    count_0++;
	if (nums[i]==1)
            count_1++;
	if (nums[i]==2)
            count_2++;
    }
    int j=0;
    for(int i=0;i<count_0;i++) {
	nums[j]=0;
	j++;
    }
    for(int i=0;i<count_1;i++) {
        nums[j]=1;
        j++;
    }
    for(int i=0;i<count_2;i++) {
        nums[j]=2;
        j++;
    }
}

void print_list(vector<int>& nums) {
    int len;
    len = nums.size();
    for(int i=0;i<len;i++)
	cout<<nums[i]<<" ";
    cout<<"\n";
}

int main() {
    vector<int> res;
    res.push_back(2);
    res.push_back(1);
    res.push_back(1);
    res.push_back(0);
    res.push_back(2);
    sortColors(res);
    print_list(res);
return 0;
}
