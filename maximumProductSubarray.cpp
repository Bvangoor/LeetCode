class Solution {
public:

   int max(int a, int b, int c){
        if(a>=b && a>=c)
            return a;
        else if(b>=a && b>=c)
            return b;
        return c;
    }

int max(int a, int b){
    if(a>=b)
        return a;
    return b;
}

int min(int a, int b, int c){
    if(a<=b && a<=c)
        return a;
    else if(b<=a && b<=c)
        return b;
    return c;
}

    int maxProduct(vector<int>& nums) {
        int len=nums.size(),maxProd=0,temp;
        if(len==0)
            return maxProd;
        vector<int> maxDP,leastDP;
        maxDP.push_back(0);
        leastDP.push_back(0);
        maxDP.push_back(nums[0]);
        leastDP.push_back(nums[0]);
        maxProd=nums[0];
        for(int i=1;i<len;i++){
            temp=maxDP[i];
            maxDP.push_back(max(maxDP[i]*nums[i],nums[i], leastDP[i]*nums[i]));
            leastDP.push_back(min(leastDP[i]*nums[i], nums[i],temp*nums[i]));
            maxProd=max(maxProd, maxDP[i+1]);
        }
        return maxProd;
    }
};
