#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* allocate_node(int val) {
    TreeNode *temp;
    temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->val = val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

bool wrapperValidBST(TreeNode* root, vector<int> leftlist, vector<int> rightlist) {
    bool left=true, right=true;
    int len1, len2;
    len1 = leftlist.size();
    len2 = rightlist.size();
    for(int i=0;i<len1;i++) {
	if(root->val >= leftlist[i])
	    return false;
    }
    for(int i=0;i<len2;i++) {
        if(root->val <= rightlist[i])
            return false;
    }
    if(root->left){
        if(root->left->val<root->val){
	    vector<int> l1;
	    l1 = leftlist;
            l1.push_back(root->val);
            left = wrapperValidBST(root->left, l1, rightlist);
        } else
            return false;
    }
    if(root->right){
        if(root->right->val>root->val){
	    vector<int> r1;
	    r1 = rightlist;
            r1.push_back(root->val);
            right = wrapperValidBST(root->right, leftlist, r1);
        } else
            return false;
    }
    return (left&&right);
}

bool isValidBST(TreeNode* root) {
    if(root) {
	bool left=true, right=true;
	vector<int> leftlist, rightlist;
	if(root->left){
	    if(root->left->val<root->val){
		vector<int> l1;
		l1 = leftlist;
		l1.push_back(root->val);
		left = wrapperValidBST(root->left, l1, rightlist);
//		cout<<"left value : "<<left<<"\n";
	    } else
		return false;
	}
	if(root->right){
	    if(root->right->val>root->val){
		vector<int> r1;
		r1 = rightlist;
		r1.push_back(root->val);
		right = wrapperValidBST(root->right, leftlist, r1);
//		cout<<"right value : "<<right<<"\n";
            } else
                return false;
	}
	return (left&&right);
    }
    return true;
}

int main() {
    TreeNode *root, *node1, *node2, *node3, *node4, *node5, *node6, *node7, *node8;
    node1 = allocate_node(3);
    node2 = allocate_node(1);
    node3 = allocate_node(5);
    node4 = allocate_node(0); 
    node5 = allocate_node(2);
    node6 = allocate_node(4);
    node7 = allocate_node(6);
    node8 = allocate_node(3);    
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node5->right = node8;
    root = node1;
    cout<<"Answer : "<<isValidBST(root)<<"\n";
return 0;
}
