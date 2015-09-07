/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL)
            return head;
        RandomListNode *t1,*t2,*newHead;
        unordered_map<int,RandomListNode*> map;
        t1=head;
        t2=(struct RandomListNode*)malloc(sizeof(struct RandomListNode));
        t2->label=t1->label;
        t2->next=NULL;
        t2->random=NULL;
        newHead=t2;
        map[t2->label]=t2;
        t1=t1->next;
        while(t1!=NULL){
            RandomListNode *t3;
            t3=(struct RandomListNode*)malloc(sizeof(struct RandomListNode));
            t3->label=t1->label;
            t3->next=NULL;
            t3->random=NULL;
            map[t3->label]=t3;
            t2->next=t3;
            t1=t1->next;
            t2=t2->next;
        }
        t1=head;
        t2=newHead;
        while(t1!=NULL){
            if(t1->random!=NULL){
                t2->random=map[t1->random->label];
            }
            t1=t1->next;
            t2=t2->next;
        }
        return newHead;
    }
};
