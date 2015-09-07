class Stack {
public:

struct node{
    int value;
    node *next;
};

node *queue1=NULL, *queue2=NULL;

    node* queuePush(node *node1, int k){
        node *temp,*temp1;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->value=k;
        temp->next=NULL;
        if(node1==NULL)
            return temp;
        temp1=node1;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;
        return node1;
    }
    
    node* queuePop(node **node2){
        node *temp;
        temp=*node2;
        *node2=(*node2)->next;
        temp->next=NULL;
        return temp;
    }

    // Push element x onto stack.
    void push(int x) {
        if(queue1==NULL && queue2==NULL)
            queue1=queuePush(queue1,x);
        else if(queue1!=NULL)
            queue1=queuePush(queue1,x);
        else if(queue2!=NULL)
            queue2=queuePush(queue2,x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(queue1!=NULL){
            while(queue1->next!=NULL){
                node *temp;
                temp=queuePop(&queue1);
                queue2=queuePush(queue2,temp->value);
            }
            queue1=NULL;
        }else if(queue2!=NULL){
            while(queue2->next!=NULL){
                node *temp;
                temp=queuePop(&queue2);
                queue1=queuePush(queue1,temp->value);
            }
            queue2=NULL;
        }
    }

    // Get the top element.
    int top() {
        int val;
        if(queue1!=NULL){
            while(queue1->next!=NULL){
                node *temp;
                temp=queuePop(&queue1);
                queue2=queuePush(queue2,temp->value);
            }
            val=queue1->value;
            queue1=NULL;
            queue2=queuePush(queue2,val);
        }else if(queue2!=NULL){
            while(queue2->next!=NULL){
                node *temp;
                temp=queuePop(&queue2);
                queue1=queuePush(queue1,temp->value);
            }
            val=queue2->value;
            queue2=NULL;
            queue1=queuePush(queue1,val);
        }
        return val;
    }

    // Return whether the stack is empty.
    bool empty() {
        return (queue1==NULL)&&(queue2==NULL)?true:false;
    }
};
