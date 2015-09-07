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
    bool checkPalindrome(ListNode* head, int k){
    int middle=(k/2)+(k%2);
    bool even=false;
    if(k%2==0)
        even=true;
    int count=1;
    ListNode *prev=NULL,*temp=head,*next;
    while(count<middle){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
        count++;
    }
    next=temp->next;
    temp->next=prev;
    if(!even)
        temp=temp->next;
    while((temp!=NULL) && (next!=NULL)){
        if(temp->val!=next->val)
            return false;
        temp=temp->next;
        next=next->next;
    }
    return true;
}

int count(ListNode* head){
    int count=0;
    if(head==NULL)
        return 0;
    ListNode *temp;
    temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

    bool isPalindrome(ListNode* head) {
        int len=count(head);
        if(len==0 || len==1)
            return true;
        if(len==2)
            return (head->val == head->next->val)?true:false;
        return checkPalindrome(head,len);
    }
};
