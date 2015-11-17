#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int count=0, len;
    unordered_map<int, int> counter;
    vector<int> copynums;
    copynums = nums;
    len = copynums.size();
    for(int i=0;i<len;i++) {
	if(counter.count(copynums[i])) {
	    if(counter[copynums[i]]<2) {
		counter[copynums[i]]=counter[copynums[i]]+1;
		count++;
	    }else {
		cout<<"erasing : "<<i<<"\n";
		nums.erase(nums.begin() + count);
	    }
 	} else {
	    counter[copynums[i]]=1;
	    count++;
	}
    }
    return count;
}

void print_vector(vector<int>& nums) {
    int len = nums.size();
    for(int i=0;i<len;i++)
	cout<<nums[i]<<" ";
    cout<<"\n";
}

int main() {
    vector<int> res;
    res.push_back(1);
    res.push_back(1);
    res.push_back(1);
    res.push_back(2);
    res.push_back(3);
    res.push_back(2);
    res.push_back(3);
    res.push_back(2);
    res.push_back(2);
    cout<<"answer : "<<removeDuplicates(res)<<"\n";
    print_vector(res); 
return 0;
}
