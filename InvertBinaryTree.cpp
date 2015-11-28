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
    TreeNode* invertTree(TreeNode* root) {
        if(root) {
            TreeNode *temp1, *temp2;
            temp1 = root->left;
            temp2 = root->right;
            root->left = temp2;
            root->right = temp1;
            root->left = invertTree(root->left);
            root->right = invertTree(root->right);
            return root;
        } else {
            return root;
        }
    }
};
