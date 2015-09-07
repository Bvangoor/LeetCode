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

struct Node{
    TreeNode *node;
    bool leftPushed;
    bool rightPushed;
    Node *next;
};

Node *head;

void push(TreeNode *node1, bool left, bool right){
    Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->node=node1;
    temp->leftPushed=left;
    temp->rightPushed=right;
    temp->next=NULL;
    if(head==NULL)
        head=temp;
    else{
        temp->next=head;
        head=temp;
    }
}

Node* pop(){
    Node *temp;
    temp=head;
    head=head->next;
    temp->next=NULL;
    return temp;
}

bool isEmpty(){
    return (head==NULL)?true:false;
}

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root==NULL)
            return result;
        push(root,false,false);
        while(head!=NULL){
            Node *temp;
            temp=pop();
            if((temp->leftPushed==true)&&(temp->rightPushed==true))
                result.push_back(temp->node->val);
            else if((temp->leftPushed==false)&&(temp->node->left!=NULL)){
                push(temp->node,true,temp->rightPushed);
                push(temp->node->left,false,false);
            }else if((temp->leftPushed==false)&&(temp->node->right!=NULL)){
                push(temp->node,true,temp->rightPushed);
            }else if((temp->rightPushed==false)&&(temp->node->right!=NULL)){
                push(temp->node,temp->leftPushed,true);
                push(temp->node->right,false,false);
            }else if((temp->rightPushed==false)&&(temp->node->right==NULL)){
                result.push_back(temp->node->val);
            }else if((temp->node->left==NULL)&&(temp->node->right==NULL)){
                result.push_back(temp->node->val);
            }
        }
    }
};
