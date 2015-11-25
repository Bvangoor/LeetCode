#include <iostream> 
#include <string>
#include <vector>

using namespace std;

vector<string> splitString(string given) {
    vector<string> result;
    int len = given.length(), j=0;
    std::size_t found;
    found=given.find(" ");
    while(found!=string::npos) {
	result.push_back(given.substr(j, found));
	j=found;
	given=given.substr(j+1, len-(j+1));
	found=given.find(" ");
	j=0;
    }
    result.push_back(given);
    return result;
}

void print_list(vector<string> res) {
    int len;
    len=res.size();
    for(int i=0;i<len;i++)
	cout<<res[i]<<"\n";
}

int main() {
    string given="ABCD EFGH IJKL MNOP";
    vector<string> result;
    result = splitString(given);
    print_list(result);
return 0;
}
