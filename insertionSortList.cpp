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
    ListNode* insert(ListNode *listHead, int val){
        ListNode *newNode;
        newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val=val;
        newNode->next=NULL;
        if(listHead==NULL)
            return newNode;
        ListNode *temp,*prev;
        if(val <= listHead->val){
            newNode->next=listHead;
            return newNode;
        }else{
            temp=listHead->next;
            prev=listHead;
            while( (temp!=NULL) && (val > temp->val)){
                prev=prev->next;
                temp=temp->next;
            }
            prev->next=newNode;
            newNode->next=temp;
        }
        return listHead;
    }

    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *newList=NULL;
        while(head!=NULL){
            newList=insert(newList,head->val);
            head=head->next;
        }
        return newList;
    }
};
