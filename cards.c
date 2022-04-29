#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "cards.h"
/*function dynamically allocates a new Card struct object and returns
 *   a pointer to that struct object which will later be used to insert into a linked list.
*/
Card* createCard(){

//create a new card

 Card *card;

 card = (struct Cards*)malloc(sizeof(struct Cards));

 int randomnumber = 0;

     randomnumber = (rand() % 10) +1;


    if(randomnumber>0 && randomnumber <=4){//40% chances for attack

        card->card_type=0;
        card->value= (rand() % (5)) + 1;

    }else if(randomnumber>4 && randomnumber <=9){//50% chances for DEFEND

        card->card_type=1;
        card->value= (rand() % 6) + 1;

    } else{ //10% chances for RUN


        card->card_type=2;
        card->value= (rand() % 8) + 1;
    }

    card->next=NULL;


return card;
}

/*This function removes and deallocates the first node in the linked list that head is pointing at. It returns the new head of the linked list.*/
Card* removeCard( Card *head ){

     Card *toDelete;

    if(head == NULL)
    {
       // printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        head = head->next;
        free(toDelete);

    }

return head;
}

/*This function adds a new Card struct object to the linked list that head is pointing at.*/
Card* addCard( Card *head, Card *c ){

    Card* current;
    /* Special case for the head end */
    if (head == NULL || (head)->value <= c->value) {
        c->next = head;
        head = c;
    }
    else {
        /* Locate the node before the point of insertion */
        current = head;
        while (current->next != NULL && current->next->value > c->value) {
            current = current->next;
        }
        c->next = current->next;
        current->next = c;
    }
return head;
}


/*This function returns the length of the linked list that head is pointing at.*/

int getLength( Card *head ){
     int num = 0;
    while (head != NULL)
    {
        num += 1;
        head = head->next;
    }
    return num;
}

/*function to print a single card*/
void printCard( Card *head ){
    char cardT;
if(head->card_type==0){
    cardT='A';
}else if(head->card_type==1){
    cardT='D';
}else{
    cardT='R';
}

printf("%c%d ", cardT, head->value);
}

/*This function traverses the linked list that head is pointing at*/
void printCards( Card *head ){


 for ( ; head != NULL; head = head->next )
    {
       printCard(head);
    }
    printf( "\n" );

}
/*This function builds a stack of cards using a linked list*/
Card* buildCards(int n ){
    int i;
    Card* head=NULL;
    for(i=0 ; i<n; i++){

   head= addCard(head, createCard());

    }

return head;
}
Card*Search(Card*p,int cardt,int value)
{
    Card*current=p;

    while(current!=NULL)
    {
        if(current->value==value&&current->card_type==cardt)
            return current;
        current=current->next;
    }
}
/*destroy linked list*/
Card* destroyCards( Card *head ){
 struct Cards* current = head;
 struct Cards* next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  head = NULL;

}
