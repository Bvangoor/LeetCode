#include<iostream>

using namespace std;

struct node {
        int val;
        struct node *next;
        struct node *prev;
};

struct node* allocate_node(void) {
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        if(temp==NULL) {
                cout<<"Error Allocating node\n";
                return NULL;
        }
        temp->next=NULL;
        temp->prev=NULL;
        return temp;
}


void delete_node(struct node *old) {
        free(old);
}

void insert_node(struct node **head, struct node* new1) {
        struct node *temp;
        if((*head)==NULL)
                *head=new1;
        else {
                temp=*head;
                while(temp->next!=NULL)
                        temp=temp->next;
                temp->next=new1;
                new1->prev=temp;
        }
}

void print_list(struct node **head) {
        struct node *temp;
        temp=*head;
        while(temp!=NULL) {
		cout<<temp->val<<"\n";
                temp=temp->next;
        }
	cout<<"================\n";
}

int reorder_list(struct node **head, int pos, int val) {
	int err=0, curr_pos=0, found_at=0;
	bool found=false;
	struct node *temp, *place_holder, *temp1;
	if((*head)==NULL) {
		err = -1; //TODO ENODATA
		goto out;
	}
	temp = (*head);
	while(temp!=NULL) {
		curr_pos++;
		if(temp->val==val) {
			found = true;
			found_at = curr_pos;
			break;
		}
		temp = temp->next;
	}

	if(!found) {
		cout<<"Not Found\n";
		err = -1 ; //TODO ENODATA
		goto out;
	}

	if (pos == found_at) {
		cout << "Nothing to change\n";
		return 0;
	}
	curr_pos=0;
	temp1 = (*head);
	while(temp1!=NULL) {
		curr_pos++;
		if(curr_pos==pos)
			break;
		temp1 = temp1->next;
	}
	if(pos>found_at) {
		if(found_at == 1)
			(*head) = temp->next;
		if(!temp1->next) { /*inserted at end*/
			if(temp->prev)
                		temp->prev->next = temp->next;
        		if(temp->next)
                		temp->next->prev = temp->prev;
			temp->prev = temp1;
			temp1->next = temp;
			temp->next = NULL;
			return err;
		}
		temp1 = temp1->next;
	}
	if(temp->prev)
		temp->prev->next = temp->next;
	if(temp->next)
		temp->next->prev = temp->prev;
	if(temp1->prev)
		temp1->prev->next = temp;
	temp->prev = temp1->prev;
	temp1->prev = temp;
	temp->next = temp1;
	if(pos==1)  /*inserting at first*/
		(*head) = temp;
out:
	return err;
}

int main(int argc, char **argv) {
    int pos, val;
    pos = stoi(argv[1]);
    val = stoi(argv[2]);
    struct node *head=NULL;
    for (int i=1;i<=4;i++) {
	struct node *temp;
	temp = allocate_node();
	temp->val = i;
	insert_node(&head, temp);
    }
    print_list(&head);
    reorder_list(&head, pos, val);
    print_list(&head);
return 0;
}
