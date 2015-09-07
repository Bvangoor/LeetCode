class Solution {
public:
    
    int trap(vector<int>& height) {
        int len=height.size(),sum=0;
        if(len<2)
            return sum;
        int left[len],right[len];
        left[0]=0;
        for(int i=1;i<len;i++)
            left[i]=max(left[i-1],height[i-1]);
        right[len-1]=0;
        for(int i=len-2;i>=0;i--)
            right[i]=max(right[i+1],height[i+1]);
        for(int i=0;i<len;i++){
            int temp;
            temp=min(left[i],right[i]) - height[i];
            sum+=(temp>0)?temp:0;
        }
        return sum;
    }
};
