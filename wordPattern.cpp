#include<iostream>
#include<vector>
#include<unordered_map>
/*
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
*/

using namespace std;

vector<string> splitBySpace(string given) {
    vector<string> res;
    int j=0, len;
    len = given.length();
    j = given.find(" ");
    while(j!=string::npos) {
	res.push_back(given.substr(0, j));
//	cout<<given.substr(0, j)<<"\n";
	given = given.substr(j+1,len-j+1);
	j = given.find(" ");
    }
    res.push_back(given);
    return res;
}

void print_list(vector<string>& words) {
    int len = words.size();
    for (int i=0;i<len;i++) {
	cout<<words[i]<<"\n";
    }
}

bool wordPattern(string pattern, string str) {
    unordered_map<char, string> map1;
    unordered_map<string, char> map2;
    vector<string> words;
    string result;
    int len1, len2;
    words = splitBySpace(str);
//    print_list(res);
    len1 = pattern.length();
    len2 = words.size();
    if(len1 != len2)
        return false;
    if(len1==0)
	return true;
    int i=0, j=0;
    result = pattern;
    map1[pattern[i]] = words[i];
    map2[words[i]] = pattern[i];
    result[i] = pattern[i];
    for(i=1;(i<len1);i++) {
	if(map2.count(words[i])) {
	    result[i] = map2[words[i]];
	} else if (map1.count(pattern[i])) {
	    return false;
	} else if (!map1.count(pattern[i])) {
	    map2[words[i]] = pattern[i];
	    map1[pattern[i]] = words[i];
	    result[i] = pattern[i];
	}
    }
    if(result.compare(pattern)==0)
	return true;
    else
	return false;
}

int main() {
    string given = "dog cat cab dog";
    string pattern = "abba";
    cout<<"value : "<<wordPattern(pattern, given)<<"\n";
return 0;
}
