class Solution {
public:
    int getDigitsResults(int n){
        int div=n, rem,count=0;
        while(div!=0){
            rem=div%10;
            div=div/10;
            count+=rem*rem;
        }
        return count;
    }
    
    bool isHappy(int n) {
        unordered_map<int,int> map;
        map[n]=0;
        while(n!=1){
            if((map.count(n))&&(map[n]==1)){
                return false;
            }else{
                map[n]=1;
                n=getDigitsResults(n);
            }
        }
        return true;
    }
};
