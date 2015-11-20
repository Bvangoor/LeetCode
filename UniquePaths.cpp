#include<iostream>

using namespace std;
/*Atmost 100x100 Grid*/
int uniquePaths(int m, int n) {
    int DP[102][102];
    for(int i=0;i<102;i++) {
	for(int j=0;j<102;j++)
	    DP[i][j]=0;
    }
    DP[m][n]=1;
    for(int i=m;i>=1;i--) {
	for(int j=n;j>=1;j--) {
	    if(i==m && j==n) {
		//DO Nothing
	    }else{
//		cout<<"i : "<<i<<" j : "<<j<<"\n";
		DP[i][j] = DP[i+1][j] + DP[i][j+1];
	    }
	}
    }
    return DP[1][1];
}

int main() {
    cout<<"Answer : "<<uniquePaths(2,2)<<"\n";
return 0;
}
