#include<iostream>
#include<vector>
#include<list>

using namespace std;
/*Numbers are 1,2,3,4,5,6,7,8,9
Window size 3
*/
int ind=0;
int windowsize = 3;
float sum = 0 ;
list<int> window;

float next_iter(int num) {
    if(ind<windowsize) {
	sum = sum + num;
	window.push_back(num);
	ind++;
	return (sum/ind);
    } else {
	sum = sum - window.front() + num;
	window.pop_front();
	window.push_back(num);
	return (sum/windowsize);
    }
}


int main() {
    for(int i=1;i<=9;i++)
	cout<<"Avg : "<<next_iter(i)<<"\n";
return 0;
}
