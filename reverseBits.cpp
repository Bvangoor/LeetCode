class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t div,num=0;
        int i=32,count=0,rem;
        div=n;
        while(div!=0){
            rem=div%2;
            div=div/2;
            count++;
            if(rem==1)
                num=num+pow(2,(i-count));
        }
        return num;
    }
};
