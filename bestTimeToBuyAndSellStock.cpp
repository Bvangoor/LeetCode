class Solution {
public:

int min(int a, int b){
    if(a<=b)
        return a;
    return b;
}

int max(int a, int b) {
    if(a>=b)
        return a;
    return b;
}

    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int minToLeft[len],Max_Profit=0;
        minToLeft[0]=INFINITY;
        for (int i=1; i<len;i++){
            minToLeft[i]=min(minToLeft[i-1], prices[i-1]);
            Max_Profit=max(Max_Profit, prices[i]-minToLeft[i]);
        }
        return Max_Profit;
    }
};
