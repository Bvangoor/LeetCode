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
    bool traversed;
    Node *next;
};

Node *stack1=NULL;

Node* push(Node* head, TreeNode *node, bool trav) {
    Node *temp;
    temp = (struct Node*) malloc(sizeof(struct Node));
    temp->node=node;
    temp->traversed=trav;
    temp->next=head;
    return temp;
}

Node* pop(Node **head){
    Node *temp;
    temp=*head;
    *head=(*head)->next;
    return temp;
}

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL)
            return result;
        stack1=push(stack1, root, false);
        while(stack1!=NULL){
            Node *temp;
            temp=pop(&stack1);
            if((temp->node->left==NULL && temp->node->right==NULL)||(temp->traversed))
                result.push_back(temp->node->val);
            else if(temp->node->right!=NULL){
                stack1=push(stack1, temp->node->right,false);
                stack1=push(stack1, temp->node,true);
                if(temp->node->left!=NULL)
                    stack1=push(stack1, temp->node->left,false);
            }else if(temp->node->left!=NULL){
                stack1=push(stack1, temp->node,true);
                stack1=push(stack1, temp->node->left,false);
            }
        }
        return result;
    }
};
