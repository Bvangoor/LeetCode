class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        unordered_map<int, int>::iterator it;
        vector<int> result;
        int len, atleast;
        len = nums.size();
        atleast = len/3;
        cout<<atleast<<"\n";
        for (int i=0;i<len;i++) {
            if(map.count(nums[i]))
                map[nums[i]] = map[nums[i]] + 1;
            else
                map[nums[i]] = 1;
        }
        for(it=map.begin();it!=map.end();it++){
            cout<<it->second<<"\n";
            if((it)->second > atleast ) {
                cout<<it->first<<"\n";
                result.push_back((it)->first);
            }
        }
        return result;
    }
};
