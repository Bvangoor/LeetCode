#include<iostream>
#include<vector>
#include<string>

using namespace std;

void printList(vector<string>& list) {
    int len = list.size();
    for (int i=0;i<len;i++)
        cout<<list[i]<<" ";
    cout<<"\n";
}

string copyVectorToString(vector<string>& list) {
    string result="";
    int len=list.size();
    for(int i=0;i<len;i++)
	result = result + list[i];
    return result;
}

int main() {
//    string path = "/a/./b/../../c/";
    string path = "/...", result;
    vector<string> splitList, stack;
    int len, prev=0, len1, i;
    len = path.length();
    for(i=0;i<len;i++) {
	if(path[i]=='/') {
	    if(i!=prev)
	        splitList.push_back(path.substr(prev, i-prev));
	    splitList.push_back("/");
	    prev = i+1;
	}
    }
    if(path[len-1]!='/')
	splitList.push_back(path.substr(prev, i-prev));
    printList(splitList);
    len1 = splitList.size();
    for (int i=0;i<len1;i++) {
	cout<<"i : "<<splitList[i]<<"\n";
	printList(stack);
	len = stack.size();
	if (splitList[i]==".") {
	    if(len > 0)
		stack.pop_back();
	    if(len-1 == 0)
		stack.push_back("/");
	} else if (splitList[i]=="..") {
	    if(len > 0)
		stack.pop_back();
	    if( len-1> 0)
                stack.pop_back();
	    else
		stack.push_back("/");
	} else if (splitList[i]=="/") {
	    if((len > 0)&&(stack.back()=="/"))
		stack.pop_back();
	    stack.push_back("/");
	} else {
	    stack.push_back(splitList[i]);
	}
    }
    if (stack.size()>1 && stack.back()=="/") {
	stack.pop_back();
    }
    len = stack.size();
    for (int i=0;i<len;i++)
	cout<<stack[i]<<" ";
    cout<<"\n";
    cout<<copyVectorToString(stack)<<"\n";
return 0;
}
