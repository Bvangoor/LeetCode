#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=0,j=0, len1=m, len2=n;
    vector<int> temp_num1, temp_num2;
    temp_num1=nums1;
    temp_num2=nums2;
    nums1.clear();
    nums2.clear();
    for(int i=0;i<m;i++)
        nums1.push_back(temp_num1[i]);
    for(int j=0;j<n;j++)
        nums2.push_back(temp_num2[j]);
    temp_num1.clear();
    temp_num2.clear();
    while(i<len1 && j<len2) {
        if(nums1[i]>nums2[j]) {
            nums1.insert(nums1.begin()+i, nums2[j]);
            len1++;
            i++;
            j++;
        } else {
            i++;
        }
    }
    if(j<len2) {
        for(int i=j;i<len2;i++)
            nums1.push_back(nums2[i]);
    }
}


void print_list(vector<int>& nums) {
     int len=nums.size();
     for (int i=0;i<len;i++)
	cout<<nums[i]<<" ";
     cout<<"\n";
}

int main() {
    vector<int> nums1, nums2;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
//    nums1.push_back(30);
    
    nums2.push_back(2);
    nums2.push_back(5);
    nums2.push_back(6);
    merge(nums1, 3, nums2, 3);
    print_list(nums1);
return 0;
}
