class Solution {
public:
    int reverse(int x) {
        int rem;
        long int num=0,div;
        if(x==-2147483648)
            return 0;
        div=abs(x);
        while(div!=0){
            rem=div%10;
            div=div/10;
            if(div==0){
                num=num+rem;
            }else{
                num=num*10+rem*10;
            }
        }
        if(num>2147483647)
            return 0;
        if(x<0)
            return (0-num);
        else
            return num;
    }
};
