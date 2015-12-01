class Solution {
public:

    bool palindromeWrapper(string s, int len1) {
        int len;
        len = len1;
        cout<<len<<"\n";
        for(int i=0;i<(len/2);i++) {
            if(s[i]!=s[len-1-i])
                return false;
        }
        return true;
    }

    bool isPalindrome(string s) {
        string result=s;
        int j=0;
        int len = s.length();
        for(int i=0;i<len;i++) {
            if(isalnum(s[i])) {
                result[j] = tolower(s[i]);
                j++;
            }
        }
        cout<<j<<"\n";
        if(j!=0) {
            for(int k=j;k<len;k++)
                result[k]='\0';
        }
        return palindromeWrapper(result, j);
    }
};
