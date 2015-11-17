#include<iostream>
#include<vector>

using namespace std;

/*(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).*/

int returnShift(vector<int>& res) {
    int len, shift=0;
    len = res.size();
    for(int i=1;i<len;i++) {
	if(res[i]<res[i-1])
	    shift=i;
    }
    return shift;
}

int search(vector<int>& nums, int target) {
    int len,shift;
//    shift = returnShift(nums);
    len = nums.size();
    for(int i=0;i<len;i++) {
	if(target==nums[i])
	    return i;
//	    return (len + (i-shift))%len;
    }
    return -1;
}

int main() {
    vector<int> res;
    res.push_back(4);
    res.push_back(5);
    res.push_back(6);
    res.push_back(7);
    res.push_back(0);
    res.push_back(1);
    res.push_back(2);
//    cout<<"shift : "<<returnShift(res)<<"\n";
    cout<<"index : "<<search(res, 4)<<"\n";
return 0;
}
