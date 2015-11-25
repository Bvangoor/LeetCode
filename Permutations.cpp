#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
Narayana Pandita Algorithm :
Always sort the list.
1. Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
2. Find the largest index l greater than k such that a[k] < a[l].
3. Swap the value of a[k] with that of a[l].
4. Reverse the sequence from a[k + 1] up to and including the final element a[n].
*/

void print_list(vector<vector<int> > list) {
    vector<vector<int> >::iterator it;
    for (it=list.begin();it!=list.end();it++) {
	for(int i=0;i<(*it).size();i++)
	    cout<<(*it)[i]<<" ";
	cout<<"\n";
    }
}

bool next_permutations(vector<int>& nums) {
    int len, k=-1, l=-1;
    len = nums.size();
    for (int i = len-2;i>=0;i--) {
	if(nums[i]<nums[i+1]) {
	    k=i;
	    break;
	}
    }
    if(k==-1)
	return false;
    for (int i=len-1;i>=0;i--) {
	if(nums[k]<nums[i]) {
	    l=i;
	    break;
	}
    }
    swap(nums[k], nums[l]);
    reverse(nums.begin()+k+1, nums.end());
    return true;
}

int  main() {
    vector<int> res;
    vector<vector<int> > result;
    res.push_back(1);
    res.push_back(2);
    res.push_back(3);
    res.push_back(4);
    sort(res.begin(), res.end());
    result.push_back(res);
    while(next_permutations(res))
	result.push_back(res);
    print_list(result);
return 0;
}
