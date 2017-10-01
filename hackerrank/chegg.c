
#include<stdio.h>
#define NULL 0

typedef struct Node{

    int num;

    struct Node *next;

}node_t;



node_t *creat(void){
       node_t *head, *first, *temp = 0;

    int count = 0;

    int choice = 1;

    first = 0;



    while (1)

    {
    int n;


        printf("Input Element :");
          head  = (node_t *)malloc(sizeof(node_t));

        if( scanf("%d", &head-> num)!=1){
         break ;
       }


        if (first != 0)

        {

            temp->next = head;

            temp = head;

        }

        else

        {

            first = temp = head;

        }
                fflush(stdin);





}
    temp->next = 0;

    /*  reset temp to the beginning */

    temp = first;

}



void output(node_t *Head){


    /* write your code here*/
   while(Head!=0){
    printf(" %d ",Head->num);
    Head=Head->next;
   }

}



node_t * reverse(node_t *head){

    /* write your code here*/
     node_t *current;
    node_t *rest;
    if(head == NULL)
        return head;


    current=head;
    rest=head->next;

    if(rest == NULL)
    {

        return current;
    }
    /* You lost the return value, which will be the beginning of the reversed 'rest'. */

    rest = reverse(rest);

    /* current->next points to the last element in the reversed 'rest'.
       What do you want that to point to? */
    //current->next->next=rest;
    current->next->next = current; // temporarily circular
    current->next=NULL;

    /* Now you can return rest, since you set it to the beginning of the reversed list. */
    return rest;


}



int main(){

    node_t *head;

    head = creat();

    printf("\n\nThe original list:");

    output(head);

    head = reverse(head);

    printf("\n\nThe new list:");

    output(head);

    printf("\n\n");

    return 0;

}
