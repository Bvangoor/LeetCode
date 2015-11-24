/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        list<TreeLinkNode *> Queue_one, Queue_two;
        TreeLinkNode *temp;
        if (root)
            Queue_one.push_back(root);
        else
            return;
        while(!Queue_one.empty()) {
            temp = Queue_one.front();
            Queue_one.pop_front();
            if (temp->left)
                Queue_two.push_back(temp->left);
            if (temp->right)
                Queue_two.push_back(temp->right);
            if(Queue_one.empty()) {
                temp->next = NULL;
                Queue_one = Queue_two;
                Queue_two.clear();
            } else {
                temp->next = Queue_one.front();
            }
        }
    }
};
