class MinStack {
public:

struct node {
    int value;
    node *next;
};

node *head=NULL,*minQueue=NULL;

    void push(int x) {
        node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->value=x;
        temp->next=NULL;
        int minVal;
        if(minQueue!=NULL){
            minVal=minQueue->value;
            minVal=min(minVal,x);
        }else{
            minVal=x;
        }
        if(minVal==x){
            node *temp1;
            temp1=(struct node*)malloc(sizeof(struct node));
            temp1->value=minVal;
            temp1->next=NULL;
            if(minQueue==NULL){
                minQueue=temp1;
            }else{
                temp1->next=minQueue;
                minQueue=temp1;
            }
        }
        if(head==NULL)
            head=temp;
        else{
            temp->next=head;
            head=temp;
        }
    }
    
int getMin() {
        return minQueue->value;
    }

    void pop() {
        if(head!=NULL){
            if(getMin()==head->value){
                minQueue=minQueue->next;
            }
            head=head->next;
        }
    }

    int top() {
        return head->value;
    }    
    
};
