#include<iostream>
#include<vector>
#include<cstring>
#include<stdlib.h>
#include<unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
    int len1, len2, temp=0;
    unordered_map<char, int> map;
    len1 = s.length();
    len2 = t.length();
    if(len1!=len2)
	return false;
    for (int i=0;i<len1;i++) {
	if(map.count(s[i])) {
	    map[s[i]] = map[s[i]] + 1;
	} else {
	    map[s[i]] = 1;
	}
    }
    for (int i=0;i<len2;i++) {
	if(map.count(t[i])) {
	    if (map[t[i]] > 0)
	        map[t[i]] = map[t[i]] - 1;
	    else
		return false;
	} else {
	    return false;
	}
    }
    return true;
}

int main() {
    string s, t;
    s = "aaaac";
    t = "aaaab";
    cout<<"Return value : " << isAnagram(s, t)<<"\n";
    return 0;
}
