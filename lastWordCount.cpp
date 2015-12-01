class Solution {
public:
    int lengthOfLastWord(string s) {
        int len, count=0, prevCount=0;
        len = s.length();
        for (int i=0;i<len;i++) {
            if(s[i]==' ') {
                if(count!=0)
                    prevCount = count;
                count = 0;
            }
            else
                count++;
        }
        if(count==0)
            count=prevCount;
        return count;
    }
};
