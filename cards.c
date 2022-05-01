#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>
#include <ctype.h>
#include "cards.h"

Card* createCard(){

 Card *card;

 card = (struct Cards*)malloc(sizeof(struct Cards));

 int randomnumber = 0;

     randomnumber = (rand() % 10) +1;

    if(randomnumber>0 && randomnumber <=4){//40% chances for attack

        card->card_type=ATTACK;
        card->value= (rand() % 10) + 1;

    }
    else if(randomnumber>4 && randomnumber <=9){//50% chances for DEFEND

        card->card_type=DEFEND;
        card->value= (rand() % 10) + 1;

    }
     else{ //10% chances for RUN

        card->card_type=RUN;
        card->value= (rand() % 10) + 1;
    }
    card->next=NULL;
return card;
}

Card* removeCard( Card *head ){

     Card *toDelete;

    if(head != NULL)
    {
           toDelete = head;
        head = head->next;
        free(toDelete);
 }
return head;
}

Card* addCard( Card *head, Card *c ){

    Card* current;

    if (head == NULL || (head)->value <= c->value) {
        c->next = head;
        head = c;
    }
    else {
        current = head;
        while (current->next != NULL && current->next->value > c->value) {
            current = current->next;
        }
        c->next = current->next;
        current->next = c;
    }
return head;
}

int getLength( Card *head ){
     int num = 0;
    while (head != NULL)
    {
        num += 1;
        head = head->next;
    }
    return num;
}

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

void printCards( Card *head ){

 for ( ; head != NULL; head = head->next )
       printCard(head);
    
    printf( "\n" );
}

Card* buildCards(int n ){
    int i;
    Card* head=NULL;

    for(i=0 ; i<n; i++){
   head= addCard(head, createCard());
    }
return head;
}

int getNumber( char str[]){

    for (int i=0; i<strlen(str); i++)
 {
        if(!isdigit(str[i]))
        {
            printf("Invalid input, please enter an integer number: \n");
            scanf("%s",str);
            getNumber(str);
        }

 }
long int   n = atoi(str);
return n;
}
