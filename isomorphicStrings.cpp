class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char,char> hashMap;
        vector<int> ex;
        for (int i=0;i<s.size();i++){
            if(hashMap.count(s[i])){
                if(hashMap[s[i]]!=t[i])
                    return false;
            }else{
                if(std::find(ex.begin(),ex.end(),static_cast<int>(t[i]))!=ex.end())
                    return false;
                hashMap[s[i]]=t[i];
                ex.push_back(static_cast<int>(t[i]));
            }
        }
        return true;
    }
};
