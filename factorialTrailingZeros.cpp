class Solution {
public:
    int trailingZeroes(int n) {
    int count=0,div=n;
    while(div>0){
        div=div/5;
        count+=div;
    }
    return count;
}
};
