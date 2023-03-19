#include<stdio.h>
#include<stdlib.h>
 
typedef struct node
{
    int value;
    int row_position;
    int column_postion;
    struct node *next;
}sm;

sm *newnode,*ptr,*head=NULL,*tail=NULL,*temphead=NULL;
void read();
void add();
void sub();
void mul();
void display();
void create(sm **head,int row,int column,int data);
void destroy(sm **head);
void printList(sm *head);
void main(){
	int opt;
	while(1){
		printf("1.Read Values\n2.Addition\n3.Subtraction\n4.Multiplication\n5.Display\n6.Exit\n");
		printf("Enter Option: ");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				read();
				break;
			case 2:
				add();
				break;
			case 3:
				sub();
				break;
			case 4:
				mul();
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
				break;
		}
	}
}
void read(){
	int r,c,i,j;
	printf("\nEnter number of rows: ");
	scanf("%d",&r);
	printf("Enter number of columns: ");
	scanf("%d",&c);
	int arr[r][c];
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(arr[i][j]!=0)
			 create(&head,i,j,arr[i][j]);
		}
	}
}
void create(sm **head,int row,int column,int data){
	newnode = (sm *)malloc(sizeof(sm));
	newnode->value = data;
	newnode->column_postion = column;
	newnode->row_position = row;
	newnode->next = NULL;
	if(*head == NULL )
	{
		*head = newnode;
		tail = newnode;
	}
	else{
		tail->next = newnode;
		tail = newnode;
	}
	
}
void add(){
	int r1,c1,r2,c2,i,j;
	printf("\nFor 1st Matrix: ");
	printf("\nEnter number of rows: ");
	scanf("%d",&r1);
	printf("Enter number of columns: ");
	scanf("%d",&c1);
	int arr1[r1][c2];
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			scanf("%d",&arr1[i][j]);
		}
	}
	printf("\nFor 2nd Matrix: ");
	printf("\nEnter number of rows: ");
	scanf("%d",&r2);
	printf("Enter number of columns: ");
	scanf("%d",&c2);
	if(r1==r2&&c1==c2){
	int arr2[r2][c2],c[r2][c2];
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++){
			scanf("%d",&arr2[i][j]);
		}
	}
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			c[i][j] = arr1[i][j]+arr2[i][j];
			create(&temphead,i,j,c[i][j]);
		}
	}
	printf("\nSum of two Sparse Matrices: ");
	printList(temphead);
	}
	else{
		printf("\nAddition can't be performed!!");
	}
	
	
}
void sub(){
	int r1,c1,r2,c2,i,j;
	printf("\nFor 1st Matrix: ");
	printf("\nEnter number of rows: ");
	scanf("%d",&r1);
	printf("Enter number of columns: ");
	scanf("%d",&c1);
	int arr1[r1][c2];
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			scanf("%d",&arr1[i][j]);
		}
	}
	printf("\nFor 2nd Matrix: ");
	printf("\nEnter number of rows: ");
	scanf("%d",&r2);
	printf("Enter number of columns: ");
	scanf("%d",&c2);
	if(r1==r2&&c1==c2){
	int arr2[r2][c2],c[r2][c2];
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++){
			scanf("%d",&arr2[i][j]);
		}
	}
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			c[i][j] = arr1[i][j]-arr2[i][j];
			create(&temphead,i,j,c[i][j]);
		}
	}
	printf("\nDifference of two Sparse Matrices: ");
	printList(temphead);
	}
	else{
		printf("\nSubtraction can't be performed!!");
	}	
}
void mul(){
	int r1,c1,r2,c2,i,j,k;
	printf("\nFor 1st Matrix: ");
	printf("\nEnter number of rows: ");
	scanf("%d",&r1);
	printf("Enter number of columns: ");
	scanf("%d",&c1);
	printf("\nFor 2nd Matrix: ");
	printf("\nEnter number of rows: ");
	scanf("%d",&r2);
	printf("Enter number of columns: ");
	scanf("%d",&c2);
	if(c1==r2){
	int arr1[r1][c2];
	printf("Enter First Matrix Elements: \n");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			scanf("%d",&arr1[i][j]);
		}
	}
		int arr2[r2][c2];
		printf("Enter Second Matrix Elements: \n");
		for(i=0;i<r2;i++){
			for(j=0;j<c2;j++){
				scanf("%d",&arr2[i][j]);
		}
	}
	int res[r1][c2];
	for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (k = 0; k < c1; k++){
                res[i][j] += arr1[i][k] * arr2[k][j];
			}
			create(&temphead,i,j,res[i][j]);
        }
    }
    printf("\nProduct of two Sparse Matrices: ");
    printList(temphead);
	}
	else{
		printf("Multiplication not Possible!!");
	}
}
void display(){
	if(head!=NULL){
	printf("\nRow Index | Column Index | Value\n");
	ptr=head;
	while(ptr!=NULL){
		printf("%7d%12d%11d\n",ptr->row_position,ptr->column_postion,ptr->value);
		ptr=ptr->next;
	}
}
else
 printf("Empty List\n");
	
}
void printList(sm *head) {
    if(head!=NULL){
	printf("\nRow Index | Column Index | Value\n");
	ptr=head;
	while(ptr!=NULL){
		printf("%7d%12d%11d\n",ptr->row_position,ptr->column_postion,ptr->value);
		ptr=ptr->next;
	}
}
else
 printf("Empty List\n");
destroy(&head);
}
void destroy(sm **head)
{
    sm *current = *head;
    sm *next;
    while (current != NULL)
    {
       next = current->next;
       free(current);
       current = next;
    }
    *head = NULL;
}
