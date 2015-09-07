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

Node *stack1=NULL;

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

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL)
            return result;
        stack1=push(stack1,root);
        while(stack1!=NULL){
            Node *temp;
            temp=pop(&stack1);
            result.push_back(temp->node->val);
            if(temp->node->left!=NULL){
                if(temp->node->right!=NULL)
                    stack1=push(stack1,temp->node->right);
                stack1=push(stack1,temp->node->left);
            }else if(temp->node->right!=NULL){
                stack1=push(stack1,temp->node->right);
            }
        }
        return result;
    }
};
