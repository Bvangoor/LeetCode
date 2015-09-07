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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *current, *previous, *next, *temp;
    previous = head;
    current = head;
    int count = 0;
    while (count != n){
        current = current->next;
        count = count+1;
    }
    if(current == NULL) {
        head = head->next;
        return head;
    }
    next = current->next;
    while (next !=NULL){
        previous = previous->next;
        current = current->next;
        next = current->next;
    }
    previous->next = previous->next->next;
    return head;
    }
};
