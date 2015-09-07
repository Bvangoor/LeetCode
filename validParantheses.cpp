class Solution {
public:

struct node {
    char value;
    node *next;
};

node *head=NULL;

void push(char k){
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

char pop(){
    int temp;
    if(head==NULL)
        return 'e';
    else{
        temp=head->value;
        head=head->next;
    }
    return temp;
}

    bool isValid(string s) {
        for (int i=0;i<s.length();i++){
            if(head==NULL)
                push(s[i]);
            else{
                char t;
                t=pop();
                if(((t=='(')&&(s[i]==')'))||((t=='{')&&(s[i]=='}'))||((t=='[')&&(s[i]==']'))){
                    //DO NOTHING
                }else{
                    push(t);
                    push(s[i]);
                }
            }
        }
        return (head==NULL)?true:false;
    }
};
