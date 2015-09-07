class LRUCache{
public:
    
struct node{
    int key;
    int value;
    node *next;
    node *prev;
}*head, *last;

int length, capacity;

unordered_map<int, node*> HashTable;

void insertToCache(int key, int val){
    node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->key=key;
    temp->value=val;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL){
        head=last=temp;
        length++;
    }else{
        last->next=temp;
        temp->prev=last;
        last=temp;
        length++;
    }
}

void deleteFromCache(){
    node *temp;
    temp=head;
    head=head->next;
    temp->next=NULL;
    if(head!=NULL)
        head->prev=NULL;
    free(temp);
    length--;
}

void changeValue(node **temp, int val){
    (*temp)->value=val;
    node *tempPrev, *tempNext;
    tempPrev=(*temp)->prev;
    tempNext=(*temp)->next;
    if((tempPrev==NULL)&&(tempNext==NULL))
        return;
    if((tempPrev!=NULL)&&(tempNext==NULL))
        return;
    if((tempPrev==NULL)&&(tempNext!=NULL))
        head=head->next;
    last->next=(*temp);
    (*temp)->prev=last;
    (*temp)->next=NULL;
    last=(*temp);
    if(tempPrev!=NULL)
        tempPrev->next=tempNext;
    tempNext->prev=tempPrev;
}

    LRUCache(int cap) :
        capacity(cap), length(0), head(NULL), last(NULL)
        { }
    
int get(int key) {
    node *temp;
    if(HashTable.count(key)){
        temp=HashTable[key];
        changeValue(&temp, temp->value);
        return (temp->value);
    }else
        return -1;
}
    
void set(int key, int value) {
    node *temp;
    if(HashTable.count(key)){
        temp=HashTable[key];
        changeValue(&temp, value);
        HashTable[key]=temp;
    }else{
        if(length<capacity){
            insertToCache(key, value);
            HashTable[key]=last;
        }else{
            HashTable.erase(head->key);
            deleteFromCache();
            insertToCache(key, value);
            HashTable[key]=last;
        }
    }
}

};
