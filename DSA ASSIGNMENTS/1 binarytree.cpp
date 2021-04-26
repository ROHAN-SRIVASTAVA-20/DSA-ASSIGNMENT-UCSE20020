#include <stdio.h> 
#include <stdlib.h> 
struct node// Structure for node 
{ 
 	int data; 
 	struct node *LCHILD; 
 	struct node *RCHILD; 
}*tree; 
struct node *create(int val)// create new node 
{ 
   struct node *temp; 
   temp=(struct node*)malloc(sizeof(struct node)); 
   temp->data=val; 
   temp->LCHILD=NULL; 
   temp->RCHILD=NULL; 
   return temp; 
} 
void print_inorder(struct node *tr)// inorder traversal 
{ 
 	struct node *copy,*p; 
 	copy=(struct node*)malloc(sizeof(struct node)); 
 	p=(struct node*)malloc(sizeof(struct node)); 
 	copy=tr; 
 	if(copy==NULL) 
 	{ 
  		printf("EMPTY TREE\n"); 
  		return ; 
 	} 
 	if(copy->LCHILD!=NULL) 
  		print_inorder 
  	(copy->LCHILD); 
 	printf("%d\t",copy->data); 
 	if(copy->RCHILD!=NULL) 
  		print_inorder(copy->RCHILD); 
} 
void add(struct node **tr,int val)// for adding node in tree 
{ 
   struct node *copy,*copy1; 
   copy=(struct node*)malloc(sizeof(struct node)); 
   copy1=(struct node*)malloc(sizeof(struct node)); 
   copy1=*tr; 
   if(copy1==NULL) 
   { 
     *tr=create(val); 
     return ; 
   } 
   if(val>=copy1->data) 
     add(&(copy1->RCHILD),val); 
   else 
     add(&(copy1->LCHILD),val); 
} 
int main() 
{ 
  	tree=NULL; 
 REPEAT: 
  	printf("ENTER YOUR CHOICE\n"); 
  	printf("1->add node to tree\n"); 
  	printf("2->print in INORDER tree\n"); 
  	printf("3->exit\n"); 
  	int choice,val; 
  	scanf("%d",&choice); 
  	switch(choice) 
  	{ 
   		case 1: 
     	scanf("%d",&val); 
     	add(&tree,val); 
     	break; 
   		case 2: 
     	print_inorder(tree); 
     	break; 
   		case 3: 
     	exit(2); 
   		default: 
     	printf("your choice is incorrect\n"); 
  	} 
  	goto REPEAT; 
  	return 0; 
} 
