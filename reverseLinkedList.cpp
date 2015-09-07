/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode *current, *next, *temp;
    if(head == NULL){
        return head;
    }
    current = head;
    next = current->next;
    current->next = NULL;
    while(next != NULL){
        temp = next->next;
        next->next = current;
        current = next;
        next = temp;
    }
    return current;
    }
};
