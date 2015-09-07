class Solution {
public:
    int hammingWeight(uint32_t n) {
        long int div=n;
        int count=0,rem;
        while(div!=0){
            rem=div%2;
            div=div/2;
            if(rem==1)
                count++;
        }
        return count;
    }
};
