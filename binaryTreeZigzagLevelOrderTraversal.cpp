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

struct Node {
    TreeNode *node;
    Node *next;
};

Node *stack1=NULL,*stack2=NULL;

Node* push(Node* head, TreeNode *node) {
    Node *temp;
    temp = (struct Node*) malloc(sizeof(struct Node));
    temp->node=node;
    temp->next=head;
    return temp;
}

Node* pop(Node **head){
    Node *temp;
    temp=*head;
    *head=(*head)->next;
    return temp;
}

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result; 
        if(root==NULL)
            return result;
        stack2=push(stack2,root);
        int count1=1;
        while(stack2!=NULL){
            stack1=stack2;
            stack2=NULL;
            vector<int> tempResult;
            while(stack1!=NULL){
                Node *temp;
                temp=pop(&stack1);
                tempResult.push_back((temp->node)->val);
                if(count1%2==1){
                    if((temp->node)->left!=NULL)
                        stack2=push(stack2,(temp->node)->left);
                    if((temp->node)->right!=NULL)
                        stack2=push(stack2,(temp->node)->right);
                }else if(count1%2==0){
                    if((temp->node)->right!=NULL)
                        stack2=push(stack2,(temp->node)->right);
                    if((temp->node)->left!=NULL)
                        stack2=push(stack2,(temp->node)->left);
                }
            }
            count1++;
            result.push_back(tempResult);
        }
        return result;
    }
};
