#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{

    int data ;
    struct node*next ;
};


void Print(struct node*top){

    struct node *ptr = top ;

    while ( ptr != NULL )
    {
        printf("| %d |\n",ptr->data);
        ptr = ptr->next ;
    }

    printf("|_____|\n\n");
}

struct node* push(struct node*top , int number ){

    struct node *ptr= NULL ;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = number ;
    ptr->next = top ;
    top = ptr ;

    return top ;
}

struct node* pop( struct node*top){

    struct node * ptr = NULL ;
    printf("\n\nDeleting the number %d\n\n",top->data);
    ptr = top ;
    top = top->next ;
    free(ptr);
    ptr->next = NULL ;

    return top;
}

struct node* Clear( struct node*top ){

    struct node * ptr = NULL ;

    while ( top->next != NULL )
    {
        ptr = top ;
        top = top->next ;

        free(ptr);
        ptr = NULL ;
    }
    printf("\n\nStack is now empty\n\n");
    top = NULL ;

    return top ;
}

struct node* CreateStack( int nodes , struct node*top ){

    struct node *ptr= NULL ;

    for (int i = 0; i < nodes ; i++)
    {
        ptr = (struct node*)malloc(sizeof(struct node));
        printf("Enter the number %d : ",i+1);
        scanf("%d",&(ptr->data));
        ptr->next = NULL ;

        if( top == NULL ) top = ptr ;

        else{

            ptr->next = top ;
            top = ptr ; // return the administration
        }
    }

    printf("\n\n Stack has been created \n\n");

    return top ;
}

int main(void){

    struct node * head = NULL ;
    int option , nodes , number  ;
    bool created = false ;

    do
    {
        printf("\n\n 0) _ Exit \n\n 1) _ Create Stack \n\n 2) _ Clear the Stack \n\n 3) _ add new element on the top \n\n 4) _ delete the top element\n\n 5) _ Print the stack's elements \n\n  input :  ");
        scanf("%d",&option);

        switch ( option )
        {
        case 0:
            printf("Program finished\n\n");
            exit(-1);    
            break;

        case 1:
            printf("Enter the number of nodes : ");
            scanf("%d",&nodes);
            head = CreateStack(nodes , head );
            break;

        case 2:
            head = Clear(head);
            break;

        case 3:
            printf("Enter a value : "); scanf("%d",&number);
            head = push(head,number);
            break;

        case 4:
            head = pop(head);
            break;

        case 5:
            printf("\n\nPrinting all the elements of a stack\n\n");
            Print(head);
            break;
        }
    } while ( option != 0 );
    
    return 0;
}