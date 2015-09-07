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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int> hashMap;
        ListNode *slow;
        slow=head;
        while(slow!=NULL){
            if(hashMap.count(slow)){
                return slow;
            }else{
                hashMap[slow]=1;
            }
            slow=slow->next;
        }
        return NULL;
    }
};
