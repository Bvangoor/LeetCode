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

char top(){
    return head->value;
}

bool isEmpty(){
    return (head==NULL)?true:false;
}

char pop(){
    char temp;
    temp=head->value;
    head=head->next;
    return temp;
}

int evaluate(int a, int b, string c){
    int ret;
    if(c=="+") 
        ret=a+b; 
    if(c=="-")
        ret=a-b; 
    return ret;
}


    int calculate(string s) {
        vector<string> RPNList;
        int len=s.length();
        for(int i=0;i<len;i++){
            if((s[i]!='+')||(s[i]!='-')||(s[i]!='(')||(s[i]!=')')||(s[i]!=' ')){
                RPNList.push_back(string(&s[i]));
            }else if(s[i]!=' '){
                if(s[i]==')'){
                    char temp;
                    while(top()!='('){
                        temp=pop();
                        RPNList.push_back(string(&temp));
                    }
                    temp=pop();
                }else{
                    push(s[i]);
                }
            }
        }
        head=NULL;
        int temp1,temp2,temp3;
        for(int i=0;i<RPNList.size();i++){
            if((RPNList[i]=="+")||(RPNList[i]=="-")){
                temp1=(pop()-'0');
                temp2=(pop()-'0');
                temp3=evaluate(temp2, temp1, RPNList[i]);
                push(temp3+'0');
            }else{
                const char* t;
                t=RPNList[i].c_str();
                push(t[0]);
            }
        }
        return (top()-'0');
    }
};
