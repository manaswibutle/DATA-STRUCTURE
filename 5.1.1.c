#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node* NODE;

NODE createNode(int val){
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    return temp;
}

int countNodes(NODE head){
    if(head==NULL) return 0;

    int count=1;
    NODE temp=head->next;

    while(temp!=head){
        count++;
        temp=temp->next;
    }
    return count;
}

NODE createCLL(){
    int n,val;
    printf("How many nodes? ");
    scanf("%d",&n);

    if(n<=0) return NULL;

    NODE head=NULL,temp=NULL,newNode;

    for(int i=0;i<n;i++){
        scanf("%d",&val);
        newNode=createNode(val);

        if(head==NULL){
            head=newNode;
            newNode->next=head;
            temp=head;
        }
        else{
            temp->next=newNode;
            newNode->next=head;
            temp=newNode;
        }
    }
    return head;
}

void display(NODE head){
    if(head==NULL){
        printf("CLL is empty\n");
        return;
    }

    NODE temp=head;

    printf("Elements in CLL are: ");
    do{
        printf("%d -> ",temp->data);
        temp=temp->next;
    }while(temp!=head);

    printf("\n");
}

NODE insertNode(NODE head,int pos,int x){
    if(pos<=0){
        printf("Position not found\n");
        return head;
    }

    int n=countNodes(head);

    if(pos>n+1){
        printf("Position not found\n");
        return head;
    }

    NODE newNode=createNode(x);

    if(head==NULL){
        newNode->next=newNode;
        return newNode;
    }

    if(pos==1){
        NODE last=head;

        while(last->next!=head)
            last=last->next;

        newNode->next=head;
        last->next=newNode;
        head=newNode;

        return head;
    }

    NODE temp=head;

    for(int i=1;i<pos-1;i++)
        temp=temp->next;

    newNode->next=temp->next;
    temp->next=newNode;

    return head;
}

NODE deleteNode(NODE head,int pos){
    if(head==NULL){
        printf("CLL is empty\n");
        return head;
    }

    int n=countNodes(head);

    if(pos<1 || pos>n){
        printf("Position not found\n");
        return head;
    }

    NODE temp=head,prev=NULL;

    if(pos==1){
        int val=head->data;

        if(head->next==head){
            printf("Deleted element: %d\n",val);
            free(head);
            return NULL;
        }

        NODE last=head;

        while(last->next!=head)
            last=last->next;

        head=head->next;
        last->next=head;

        printf("Deleted element: %d\n",temp->data);
        free(temp);

        return head;
    }

    for(int i=1;i<pos;i++){
        prev=temp;
        temp=temp->next;
    }

    prev->next=temp->next;

    printf("Deleted element: %d\n",temp->data);
    free(temp);

    return head;
}

NODE reverseCLL(NODE head){
    if(head==NULL){
        printf("CLL is empty\n");
        return head;
    }

    NODE prev=NULL,cur=head,next=NULL;
    NODE start=head;

    do{
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }while(cur!=start);

    start->next=prev;
    head=prev;

    printf("CLL reversed\n");

    NODE temp=head;
    do{
        printf("%d -> ",temp->data);
        temp=temp->next;
    }while(temp!=head);

    printf("\n");

    return head;
}

NODE concatenate(NODE head){
    int n,val;

    printf("Creating second CLL to concatenate...\n");
    printf("How many nodes in second CLL? ");
    scanf("%d",&n);

    if(n<=0) return head;

    NODE head2=NULL,temp2=NULL,newNode;

    for(int i=0;i<n;i++){
        scanf("%d",&val);
        newNode=createNode(val);

        if(head2==NULL){
            head2=newNode;
            newNode->next=head2;
            temp2=head2;
        }
        else{
            temp2->next=newNode;
            newNode->next=head2;
            temp2=newNode;
        }
    }

    if(head==NULL)
        return head2;

    NODE last1=head;
    while(last1->next!=head)
        last1=last1->next;

    NODE last2=head2;
    while(last2->next!=head2)
        last2=last2->next;

    last1->next=head2;
    last2->next=head;

    printf("Concatenated CLL:\n");

    NODE temp=head;
    do{
        printf("%d -> ",temp->data);
        temp=temp->next;
    }while(temp!=head);

    printf("\n");

    return head;
}

int main(){

    NODE head=NULL;
    int choice,pos,x;

    while(1){

        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                head=createCLL();
                break;

            case 2:
                printf("Position: ");
                scanf("%d",&pos);
                printf("Element: ");
                scanf("%d",&x);
                head=insertNode(head,pos,x);
                break;

            case 3:
                printf("Position: ");
                scanf("%d",&pos);
                head=deleteNode(head,pos);
                break;

            case 4:
                display(head);
                break;

            case 5:
                head=reverseCLL(head);
                break;

            case 6:
                head=concatenate(head);
                break;

            case 7:
                exit(0);

            default:
                break;
        }
    }

    return 0;
}
