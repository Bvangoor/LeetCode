class Solution {

#include<list>

public:


    int maximum (int a, int b) {
        if(a>b)
            return a;
        return b;
    }

    int max_from_list(list<int>& list1 ) {
        list<int>::iterator it;
        int max=-1;
        for (it = list1.begin();it!=list1.end();it++) {
            max = maximum(*it, max);
        }
        return max;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> window;
        vector<int> result;
        int len;
        len = nums.size();
        for(int i=0;i<k;i++)
            window.push_back(nums[i]);
        if(window.size())
            result.push_back(max_from_list(window));
        for (int i=1;i<=(len-k);i++) {
            window.pop_front();
            window.push_back(nums[i+k-1]);
            result.push_back(max_from_list(window));
        }
        return result;
    }
};
