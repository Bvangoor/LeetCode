#include<iostream>

using namespace std;

struct node {
	int val;
	node *left;
	node *right;
};

int lookup(node *root, int val) {
	if(root==NULL)
		return -1;
	node *temp;
	temp = root;
	while(!temp) {
		if(val==temp->val)
			return 1;
		if (val<=temp->val)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return -1;
}

int insertNode(node **root, int val) {
	node *temp, *temp1, *parent;
	temp = *root;
	temp1 = (struct node*)malloc(sizeof(struct node));
	temp1->val = val;
	temp1->left = NULL;
	temp1->right = NULL;
	if(*root==NULL) {
		*root = temp1;
		return 0;
	}	
	while(temp!=NULL) {
		parent = temp;
		if(temp->val == val) {
			free(temp1);
			return -1;
		}
		if(val<=temp->val)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if(val<=parent->val)
		parent->left = temp1;
	else
		parent->right = temp1;
	return 0;
}

int main() {
	node *root=NULL;
	insertNode(&root, 1);
	insertNode(&root, 2);
	insertNode(&root, 3);
	insertNode(&root, 4);
	insertNode(&root, 5);
	insertNode(&root, 6);
	insertNode(&root, 7); 
	cout <<"lookup : "<< lookup(root, 7)<<"\n";
return 0;
}
