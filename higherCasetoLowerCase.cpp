#include <iostream>
#include <cstring>

using namespace std;

void higher_to_lower(string& given) {
    int len;
    len = given.size();
    for(int i=0;i<len;i++) {
	given[i]=tolower(given[i]);
    }
}

int main() {
    string given="Abc";
    cout <<" given : "<<given<<"\n";
    higher_to_lower(given);
    cout<<" result : "<<given<<"\n";
return 0;
}

