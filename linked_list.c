#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

node* create(node**head)
{
    
    node *temp, *newnode;

    newnode=(node*)malloc(sizeof(node));
   if(!newnode){
    printf("Menory not allocated!!\n");
    return newnode;
   }

    printf("Enter the data: ");
    scanf("%d",&newnode->data);

    newnode->next=NULL;
    return newnode;
}

void insertAtFront(node**head)
{
    node* newnode=create(head);
   if(newnode==NULL)
   return; 

    else{

    if(*head==NULL)
    *head=newnode;

   else{
    newnode->next=*head;
    *head=newnode;
    }
  }
}

void insertAtEnd(node **head)
{
    node* newnode, *temp;
    temp=NULL;
    newnode=create(head);

    if(newnode==NULL)
    return;

    else{
       
        temp=*head;
        if(*head==NULL)
        *head=newnode;

        else{
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
}

void insertAtGivenPos(node **head){
    node*temp=NULL;
    node* newnode=create(head);
    if(newnode==NULL)
    return;

    else{
        int pos;
        printf("enter the position at which you wanna insert:");
        scanf("%d",&pos);

        if(pos==1)
        {
            if(*head==NULL)
            *head=newnode;

            else {
                newnode->next=*head;
                *head=newnode;
            }
        }
        else{
            temp=*head;
            int i=1;
            while(temp!=NULL && i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
}

void display(node **head)
{
    node* temp;
    temp=(*head);

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;

    }
}

node* deleteFront(node * head)
{
    node* temp;
    
    if(head==NULL)
    {
        printf("The list is empty");
        return;
    }


    temp=head;
    head=head->next;
    temp->next=NULL;
    free(temp);
    temp=NULL;
    return head;


}

node * deleteFromLast(node * head)
{
    node * temp,*prev;
    
    if(head==NULL){
    
    printf("The list is empty");
    }
     if(head->next == NULL)
    {
        free(head);
        return NULL;
    }

    else{
        temp=head;
        prev=head->next;
        while(prev->next!=NULL)
        {
            temp=temp->next;
            prev=prev->next;
        }
        temp->next=NULL;
        free(prev);
        
       return head;
    }
}

int main(){
    int choice,n;
    node* head=NULL;
    printf("enter 1 to insert at front: \n");
    printf("Enter 2 to insert at last \n");
    printf("enter 3 to insert at given pos\n");
    printf("Enter 4 to display\n");
    printf("enter 5 to exit\n");

    while(1){

        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch(choice){
        case 1:
        insertAtFront(&head);
        break;

        case 2:
        insertAtEnd(&head);;
        break;

        case 3:
        insertAtGivenPos(&head);
        break;

        case 4:
        display(&head);
        break;

        case 5:
        return 0;

        default:
        printf("Invalid case: ");
        return 0;
    }
}
}