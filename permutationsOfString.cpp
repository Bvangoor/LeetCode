#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


string returnString(vector<char>& nums) {
    std::string s( nums.begin(), nums.end() );
    return s;
}

bool next_permutation(vector<char>& nums) {
    int k=-1, l, len;
    len = nums.size();
    for (int i=len-2;i>=0;i--) {
	if(nums[i]<nums[i+1]) {
	    k=i;
	    break;
	}
    }
    if(k==-1)
	return false;
    for(int i=len-1;i>k;i--) {
	if(nums[i]>nums[k]) {
	    l=i;
	    break;
	}
    }
    swap(nums[k], nums[l]);
    reverse(nums.begin()+k+1, nums.end());
    return true;
}

void print_list(vector<string >& result) {
    int len;
    len = result.size();
    for (int i=0;i<len;i++)
	cout<<result[i]<<"\n";
}


int main() {
    vector<string> result;
    vector<char> temp;
    int len;
    string given = "ABCD";
    len = given.length();
    for (int i=0;i<len;i++) {
	temp.push_back(given[i]);
    }
    sort(temp.begin(), temp.end());
    result.push_back(returnString(temp));
    while (next_permutation(temp)) {
	result.push_back(returnString(temp));
    }
    print_list(result);
return 0;
}
