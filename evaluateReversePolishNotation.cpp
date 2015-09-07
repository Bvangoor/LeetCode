class Solution {
public:

struct node {
    int value;
    node *next;
};

node *head=NULL;

void push(int k){
    node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->value=k;
    temp->next=NULL;
    if(head==NULL)
        head=temp;
    else{
        temp->next=head;
        head=temp;
    }
}

int top(){
    return head->value;
}

int pop(){
    int temp;
    temp=head->value;
    head=head->next;
    return temp;
}

int evaluate(int a, int b, string c){
    int ret;
    if(c=="+") 
        ret=a+b; 
    if(c=="*")
        ret=a*b; 
    if(c=="-")
        ret=a-b; 
    if(c=="/")
        ret=a/b; 
    return ret;
}

    int evalRPN(vector<string>& tokens) {
        int temp1,temp2,temp3;
        for(int i=0;i<tokens.size();i++){
            if((tokens[i]=="+")||(tokens[i]=="-")||(tokens[i]=="/")||(tokens[i]=="*")){
                temp1=pop();
                temp2=pop();
                temp3=evaluate(temp2, temp1, tokens[i]);
                push(temp3);
            }else{
                push(stoi(tokens[i]));
            }
        }
        return top();
    }
};
