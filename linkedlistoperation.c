// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node* insertAtbeg(struct node *head,int data){
 struct node *ptr=(struct node*)malloc(sizeof(struct node));
 ptr->data=data;
 ptr->next=head;
 head=ptr;
 return head;
}
struct node* insertAtend(struct node *head,int data){
 struct node *ptr=(struct node*)malloc(sizeof(struct node));
 ptr->data=data;
 
struct node *temp;
temp=head;
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=ptr;
ptr->next=NULL;
return head;
}
//insert in between
struct node *insertinbetween(struct node*head,int data,int position){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if (position==1){
        head=newnode;
        newnode->next=NULL;
        return head;
    }
    struct node *temp=head;
    for(int i=1;temp!=NULL&&i<position-1;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("position is out of range\n");
        free(newnode);
        return head;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
    
}
struct node* delFirstNode(struct node* head){
    struct node*temp;
    temp=head;
    if(head==NULL){
      printf("list is empty\n");
        return head;
   
    }
    head=head->next;
    free(temp);
    return head;
}
//delete the last node
struct node* deleteAtlast(struct node*head){
    if (head==NULL){
        printf("List is empty\n");
        return head;
    }
    if(head->next==NULL){
        free(head);
        return head;
    }
    struct node*p=head;
    struct node*q=head->next;
    while(q->next!=NULL){
    p=p->next;
    q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

void display(struct node*head){
    struct node *temp;
    temp=head;
    if(head==NULL){
        printf("list is empty\n");
        return;
    }
    while(temp!=NULL){
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
   printf("NULL\n");
}

int main() {
 struct node *head=NULL;
 int choice,data,position;
 do{
 printf("-------------------------MENU-------------------------\n");
 
printf("\n1.insert at beginning\n2.insert in between\n3.insert at last\n4.delete from beginning\n5.delete from last\n6.delete in between\n7.display\n8.exit\n");
printf("Enter your choice : ");
 scanf("%d",&choice);
switch(choice){
    case 1:
    printf("\n Enter an element to insert:");
    scanf("%d",&data);
    head=insertAtbeg(head,data);
    break;
     case 2:
    printf("\n Enter an element to insert:");
    scanf("%d",&data);
    printf("\nenter the position :");
    scanf("%d",&position);
   head= insertinbetween(head,data,position);
    break;
     case 3:
    printf("\nEnter an element to insert:");
    scanf("%d",&data);
   head= insertAtend(head,data);
    break;
     case 4:
    head=delFirstNode(head);
    break;
     case 5:
    head=deleteAtlast(head);
    break;
    case 6 :
    printf("Preogram is not written\n");
    break;
    case 7:
    display(head);
    break;
    case 8:
    printf("exiting.....");
    break;
    default:
    printf("invalid choice\n");
     }
}while(choice!=8);
    return 0;
}