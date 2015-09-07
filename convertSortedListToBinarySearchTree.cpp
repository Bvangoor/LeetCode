/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

TreeNode* insert(TreeNode *node, int val){
    TreeNode *newNode,*temp;
    newNode=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val=val;
    newNode->left=NULL;
    newNode->right=NULL;
    if(node==NULL){
        return newNode;
    }
    temp=node;
    if(val<=temp->val){
        temp->left=insert(temp->left,val);
    }else{
        temp->right=insert(temp->right,val);
    }
    return node;
}

void split(ListNode *node,int *a, ListNode **b, ListNode **c){
    ListNode *temp;
    temp=node;
    if(temp->next==NULL){
        *a=temp->val;
        *b=NULL;
        *c=NULL;
        return;
    }
    ListNode *slow,*fast,*prev;
    slow=temp;
    fast=temp->next;
    while(fast!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL)
            fast=fast->next;
        else
            break;
    }
    *a=slow->val;
    *c=slow->next;
    prev->next=NULL;
    *b=temp;
    return;
}

    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode *temp,*l1,*l2;
        TreeNode *root=NULL;
        temp=head;
        int middle;
        split(temp,&middle,&l1,&l2);
        root=insert(root,middle);
        if(l1!=NULL)
            root->left=sortedListToBST(l1);
        if(l2!=NULL)
            root->right=sortedListToBST(l2);
        return root;
    }
};
