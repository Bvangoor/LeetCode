class Solution {
public:
bool isPrime(int n){
    int temp=ceil(sqrt(n));
    for(int i=1;i<=temp;i++){
        if((n%i==0)&&(i!=1))
            return false;
    }
    return true;
}

int countPrimes(int n) {
        int count=0;
        if (n==0||n==1||n==2)
            return 0;
        count++;
        for (int i=3;i<n;i+=2){
            if(isPrime(i))
                count+=1;
        }
        return count;
    }
};
