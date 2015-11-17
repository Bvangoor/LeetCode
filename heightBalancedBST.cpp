#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* allocate_node() {
    TreeNode *temp;
    temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

TreeNode* balanceTreeBST(vector<int>& list) {
    int len, middle;
    len = list.size();
    if(len==0)
	return NULL;
    TreeNode *root;
    root = allocate_node();
    if(len==1) {
	root->val = list[0];
	return root;
    } else {
	middle = len/2;
	vector<int> l1, l2;
	root->val = list[middle];
	for(int i=0;i<middle;i++){
	    l1.push_back(list[i]);
	}
	root->left = balanceTreeBST(l1);
	for(int i=(middle+1);i<len;i++){
	    l2.push_back(list[i]);
	}
	root->right = balanceTreeBST(l2);
	return root;
    }
} 

void print_inorder(TreeNode *root) {
    if(root) {
        if(root->left)
	    print_inorder(root->left);
        if(root)
            cout<<root->val<<"\n";
        if(root->right)
	    print_inorder(root->right);
    }
}


int main() {
    vector<int> res;
    res.push_back(1);
    res.push_back(2);
    res.push_back(3);
    res.push_back(4);
    res.push_back(5);
    TreeNode *root;
    root = balanceTreeBST(res);
    print_inorder(root);
return 0;
}
