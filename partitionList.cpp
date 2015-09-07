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
    ListNode* partition(ListNode* head, int x) {
        ListNode *greater, *greaterBefore=NULL, *current, *currentBefore, *temp;
        if(head==NULL)
            return head;
        if(head->val < x){
            greaterBefore=head;
            greater=greaterBefore->next;
            while((greater!=NULL)&&(greater->val < x)){
            greaterBefore=greaterBefore->next;
            greater=greater->next;
        }
        if(greater==NULL)
            return head;
        currentBefore=greater;
        current=currentBefore->next;
        }else{
            greater=head;
            currentBefore=head;
            current=head->next;
            while(current!=NULL){
                while((current!=NULL)&&(current->val >= x)){
                    currentBefore=currentBefore->next;
                    current=current->next;
                }
                if(current==NULL)
                    return head;
                head=current;
                temp=current->next;
                current->next=greater;
                greaterBefore=current;
                currentBefore->next=temp;
                current=temp;
                break;
            }
        }
        while(current!=NULL){
            while((current!=NULL)&&(current->val >= x)){
                currentBefore=currentBefore->next;
                current=current->next;
            }
            if(current==NULL)
                break;
            temp=current->next;
            current->next=greater;
            greaterBefore->next=current;
            greaterBefore=current;
            currentBefore->next=temp;
            current=temp;
        }
        return head;
    }
};
