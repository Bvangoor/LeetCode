class Solution {
public:

struct Node{
    int val;
    Node *next;
};

Node *head=NULL;

void push(int k){
    Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->val=k;
    temp->next=NULL;
    if(head==NULL)
        head=temp;
    else{
        temp->next=head;
        head=temp;
    }
}

Node* pop(){
    Node *temp;
    temp=head;
    head=head->next;
    temp->next=NULL;
    return temp;
}

int top(){
    return (head->val);
}

int maximum(int a, int b){
    if(a>=b)
        return a;
    return b;
}

int largestRectangleArea(vector<int>& height) {
    int i=0,maxArea=-1,len;
    len=height.size();
    if(len<1)
        return 0;
    push(i);
    i++;
    while(i<len){
        if(height[i]>=height[top()]){
            push(i);
        }else{
            Node *t;
            int tempArea;
            while((head!=NULL)&&(height[top()]>height[i])){
                t=pop();
                if(head==NULL)
                    tempArea=height[t->val]*i;
                else
                    tempArea=height[t->val]*(i-(top())-1);
                maxArea=maximum(maxArea,tempArea);
            }
            push(i);
        }
        i++;
    }
    Node *t1;
    int tempArea1;
    while(head!=NULL){
        t1=pop();
        if(head==NULL)
            tempArea1=height[t1->val]*i;
        else
            tempArea1=height[t1->val]*(i-(top())-1);
        maxArea=maximum(maxArea,tempArea1);
    }
    return maxArea;
}

vector<int> evaluate(vector<int>& list1, vector<char>& list2){
    int len;
    vector<int> result;
    len=list1.size();
    for(int i=0;i<len;i++){
        if(list2[i]=='0')
            result.push_back(0);
        else
            result.push_back(list1[i]+1);
    }
    return result;
}

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> res;
        int len,len2,maxRect=-1;
        len2=matrix.size();
        if(len2==0)
            return 0;
        len=matrix[0].size();
        for (int i=0;i<len;i++)
            res.push_back(0);
        for(int i=0;i<len2;i++){
            res=evaluate(res,matrix[i]);
            maxRect=maximum(maxRect,largestRectangleArea(res));
        }
        return maxRect;
    }
};
