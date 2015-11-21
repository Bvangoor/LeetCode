#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int no_of_rounds(float a, float b) {	
    float res;
    if(a<b) {
	res = a/2;
	return ceil(res);
    } else {
	res = b/2;
        return ceil(res);
    }
}

vector<int> spiralOrder(vector<vector<int> >& matrix) {
    int M, N, rounds=0, l=1;
    vector<int> result; 
    M = matrix.size();
    if(M>0)
        N = (matrix[0]).size();
    else
	return result;
    rounds = no_of_rounds(M,N); /*No of spiral rounds*/
    int i=0, j=0, k=0, m=N, n=M, rowParsed, columnParsed;
    cout<<" rounds : "<<rounds<<"\n";
    while(l<=rounds) {
	cout<<"i : "<<i<<" j : "<<j<<" m : "<<m<<" n : "<<n<<" k : "<<k<<"\n";
	for(i=i;i<m;i++) {	/*From Left to Right*/ 
	    cout<<matrix[j][i]<<"\n";
	    rowParsed = j;
	    result.push_back(matrix[j][i]);
	}
	cout<<"===\n";
	i=i-1;
	for(j=j+1;j<n;j++){  /*From Top to Bottom*/
	    cout<<matrix[j][i]<<"\n";
	    columnParsed = i;
	    result.push_back(matrix[j][i]);
	}
	cout<<"===\n";
	j=j-1;
	for(i=i-1;i>=k;i--){ /*From Right to Left*/
	    if(rowParsed!=j){
	        cout<<matrix[j][i]<<"\n";
	        result.push_back(matrix[j][i]);
	    }
	}
	cout<<"===\n";
	i=i+1;
 	for(j=j-1;j>=(k+1);j--){  /*From Bottom to Top*/
	    if(columnParsed!=i) {
	        cout<<matrix[j][i]<<"\n";
	        result.push_back(matrix[j][i]);
	    }
	}
	cout<<"===\n";
	i++;
        j++;
        k++;
	m--;
	n--;
	l++;
    }
    return result;
}

void print_list(vector<int>& result) {
    int len = result.size();
    for (int i=0;i<len;i++)
	cout<<result[i]<<" ";
    cout<<"\n";
}

int main() {
    vector<vector<int> > matrix;
    vector<int> temp, result;
    temp.push_back(1);
    temp.push_back(2);
/*    temp.push_back(3);
    matrix.push_back(temp);
    temp.clear();
    temp.push_back(4);
//    temp.push_back(5);
//    temp.push_back(6);
    matrix.push_back(temp);
    temp.clear();
    temp.push_back(7);
    temp.push_back(8);
    temp.push_back(9);*/
    matrix.push_back(temp);
    temp.clear();
    result = spiralOrder(matrix);
    print_list(result);
return 0;
}
