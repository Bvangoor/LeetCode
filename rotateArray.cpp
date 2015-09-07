class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp,i=0,j,old=nums[i],count=0,size=nums.size();
        unordered_map<int,int> map;
        while(count<size){
            j=(i+k)%size;
            if(map.count(j)){
                i=i+1;
                old=nums[i];
                j=(i+k)%size;
            }
            temp=nums[j];
            nums[j]=old;
            i=j;
            old=temp;
            map[j]=1;
            count++;
        }
}
};
