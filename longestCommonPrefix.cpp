class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
        return "";
    }
    if(strs.size()==1)
        return strs[0];
    int minimum=100000,index=-1;
    string smallest;
    char match[100];
    for(int i=0;i<strs.size();i++){
        if(strs[i].size()<minimum){
            minimum=strs[i].size();
            index=i;
        }
    }
    smallest=strs[index];
    for(int i=0;i<smallest.size();i++){
        for(int j=0;j<strs.size();j++){
            if(j!=index){
                if(smallest[i]==strs[j][i]){
                    match[i]=smallest[i];
                }else{
                    match[i]='\0';
                    break;
                }
            }
        }
    }
    match[smallest.size()]='\0';
    return string(match);
    }
};
