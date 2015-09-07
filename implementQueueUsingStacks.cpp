class Queue {
public:

struct node{
    int value;
    node *next;
};

node *queueHead, *stack1=NULL, *stack2=NULL;

    node* stackPush(node *node1,  int k){
        node *temp2;
        temp2=(struct node*)malloc(sizeof(struct node));
        temp2->value=k;
        temp2->next=NULL;
        if(node1==NULL)
            return temp2;
        temp2->next=node1;
        return temp2;
    }

    node* stackPop(node **node2){
        node *temp;
        temp=*node2;
        *node2=(*node2)->next;
        temp->next=NULL;
        return temp;
    }

    // Push element x to the back of queue.
    void push(int x) {
        stack1=stackPush(stack1, x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(stack2==NULL){
            while(stack1!=NULL){
                node *temp1;
                temp1=stackPop(&stack1);
                stack2=stackPush(stack2,temp1->value);
            }
        }
        stack2=stack2->next;
    }

    // Get the front element.
    int peek(void) {
        if(stack2==NULL){
            while(stack1!=NULL){
                node *temp1;
                temp1=stackPop(&stack1);
                stack2=stackPush(stack2,temp1->value);
            }
        }
        return stack2->value;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (stack2==NULL)&&(stack1==NULL)?true:false;
    }
};
