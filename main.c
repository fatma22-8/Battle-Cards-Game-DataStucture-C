#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>
#include <ctype.h>
#include "cards.h"

 /*initialize required variables*/
   long int n;
   char str[];
   char type;
   int val, round=1;
  struct Cards *p1, *p2;
  Card *p1_head, *temp ;
char player_name[50];

void play (){

    printf("\n----- ROUND %d -----\n", round);

 printf("\n%s: (%d)", player_name,getLength(p1_head) );
     printCards(p1_head);

 printf("\ncomputer:  (%d)", getLength(p2));
     printCard(p2);

 printf("\n\nEnter the type and the value of the card you want to pull: ");
     scanf("%C",&type);
     scanf("%d",&val);

p1=getvalue(p1_head,type,val);

while(p1==NULL)
  {      scanf("%c",&type);
         scanf("%d",&val);

         p1=getvalue(p1_head,type,val);
         }

if(p1->card_type==0 && p2->card_type==0) //Both ATTACK
    {
        printf("\nBoth players ATTACK\n");

        if(p1->value > p2->value)
        {
            p1_head= removeCard(p1_head,p1);

           p2 = removeCard(p2,p2);

           p1_head=addCard(p1_head, createCard());

           printf("\n %s gets a new card.\n",player_name);
        }

        else if(p2->value > p1->value)
        {
          p1_head= removeCard(p1_head,p1);

           p2 = removeCard(p2,p2);

           p2=addCard(p2, createCard());

           printf("\ncomputer gets a new card.\n");

        }
        else if(p1->value == p2->value)
        {
         p1_head= removeCard(p1_head,p1);

         p2= removeCard(p2,p2);

         printf("\nNothing happens\n"); //No winner for this round

        }
    }
     /*********************************/
else if(p1->card_type==1 && p2->card_type==1 ) //Both DEFEND
     {
         printf("\nBoth players DEFEND \n");

         printf("\nNothing happens\n");

         p1_head= removeCard(p1_head,p1);

         p2= removeCard(p2,p2);
    }
     /*********************************/
else if(p1->card_type==2 && p2->card_type==2) //Both RUN
    {
         printf("\nBoth players RUN \n");

         printf("\nBoth players lose their next cards.\n");

         if (p1->next==NULL)
           temp=p1_head;
         else
           temp=p1->next;

         p1_head= removeCard(p1_head,p1);

         p2= removeCard(p2,p2);

     if(getLength(p1_head)!=0)
        p1_head= removeCard(p1_head,temp);

     if(getLength(p2)!=0)
        p2 = removeCard(p2,p2);
    }
     /*********************************/
else if(p1->card_type==0 && p2->card_type==1) //p1 ATTACK, p2 DEFEND
    {
      printf("\n%s ATTACKs player 2 DEFENDs  \n",player_name);

        if(p1->value>p2->value)
        {
            printf("\n%s gets a new card. computer loses his next card. \n");

            p1_head= removeCard(p1_head,p1);

            p2 = removeCard(p2,p2);

            if(getLength(p2)!=0)
               p2 = removeCard(p2,p2);

            if(getLength(p1_head)!=0)
               p1_head=addCard(p1_head, createCard());
               }

        else if(p2->value>=p1->value)
            {
             printf("\nNothing happens.\n");

             p1_head= removeCard(p1_head,p1);

             p2 = removeCard(p2,p2);
            }
    }
     /*********************************/
else if(p2->card_type==0 && p1->card_type==1) //p2 ATTACK, p1 DEFEND
{
    printf("\ncomputer ATTACKs %s DEFENDs  \n",player_name);

        if(p2->value > p1->value)
            {
             if (p1->next==NULL)
                 temp=p1_head;
             else
                 temp=p1->next;

           p1_head= removeCard(p1_head,p1);

           if(getLength(p1_head)!=0)
                p1_head= removeCard(p1_head,temp);

            p2 = removeCard(p2,p2);

            p2=addCard(p2, createCard());

            printf("\ncomputer gets a new card. %s loses his next card.  \n",player_name);

            }

        else
            {
             p1_head= removeCard(p1_head,p1);

             p2 = removeCard(p2,p2);

             printf("\nNothing happens.\n");
             }
    }
    /*********************************/
else if(p1->card_type==1 && p2->card_type==2 ) //p1 DEFEND, p2 RUN
    {
       p1_head= removeCard(p1_head,p1);

       p2= removeCard(p2,p2);

      if(getLength(p2)!=0)
          p2 = removeCard(p2,p2);

       printf("\n%s DEFENDs and Player 2 RUNs.\n",player_name);

       printf("\ncomputer loses his next card.\n");
    }
     /*********************************/
else if(p2->card_type==1 && p1->card_type==2) //p2 DEFEND, p1 RUN
{
    if (p1->next==NULL)
        temp=p1_head;
    else
        temp=p1->next;

    p1_head= removeCard(p1_head,p1);

    if(getLength(p1_head)!=0)
      p1_head= removeCard(p1_head,temp);

    p2= removeCard(p2,p2);

    printf("\ncomputer DEFENDSs and %s RUNs.\n",player_name);

    printf("\n%s loses his next card .\n",player_name);
}

    /*********************************/
else if(p1->card_type==0 && p2->card_type==2 ) //p1 ATTACK, p2 RUN
{
    printf("\n%s ATTACKs and computer RUNs.\n",player_name);

    p1_head = removeCard(p1_head,p1);

    p2= removeCard(p2,p2);

    p1_head=addCard(p1_head, createCard());

    if(getLength(p2)!=0)
        p2= removeCard(p2,p2);

    printf("\n%s gets a new card. computer loses his next card.\n",player_name);

    }
        /*********************************/
else if(p2->card_type==0 && p1->card_type==2) //p2 ATTACK, p1 RUN
{
    printf("\ncomputer ATTACKs and %s RUNs.\n",player_name);

    if (p1->next==NULL)
        temp=p1_head;
    else
        temp=p1->next;

    p1_head= removeCard(p1_head,p1);

    if(getLength(p1_head)!=0)
        p1_head= removeCard(p1_head,temp);

    p2= removeCard(p2,p2);

    p2=addCard(p2, createCard());

    printf("\ncomputer gets a new card. %s loses his next card.\n",player_name);
}
    /*********************************/

   round++;

return;
}

int main()
{
    srand(time(NULL));

    printf("\n============= WELCOME TO BATTLE CARDS GAME ============\n");

    printf("\n\nWhat's your name?\n");
    gets(player_name);

printf("\n\nINETRUCTIONS OF THE GAME\n");

printf("\n1) Enter number of cards\n");
printf("\n2) PLAYER 1 & PLAYER 2 Will have the same number of cards \n");
printf("\n3) %s is PLAYER 1 & PLAYER 2 IS THE PC \n",player_name);
printf("\n4) YOUR CARDS ARE VISABLE TO YOU, SO YOU CAN CHOOSE ANY ONE OF THEM TO PLAY THE ROUND \n");
printf("\n5) 'A' means ATTACK, 'D' means DEFFEND , 'R' means RUN \n");
printf("\n6) When you ATTACK and the value of your card is greater than the value of computer card you will have a new card\n");
printf("\n7) in '6':\n    i.if player 2 Attack, player 2 will lose his current card\n    ii.if player 2 DEFFENDs, player 2 will lose his next card\n");
printf("\n8) if you DEFFEND and the value of your card is greater than the value of player 2 card");
printf("\n    i.if player 2 Attack,we return to case '6'\n    ii.if player 2 DEFFENDs, nothing happens\n");
printf("\n9) i.if you RUN you lose your next card whatever your value is\n   ii.if player 2 RUN, player 2 will lose his next card\n");

printf("\nEnter number of cards:     ");

scanf("%s",str);

n=getNumber(str);

 p1=buildCards(n);

 p2=buildCards(n);



p1_head =p1;

 printf("============= PLAYER 1 VS PLAYER 2 SHOWDOWN ============\n");

for(;; ){

    if(getLength(p1_head) ==0 || getLength(p2) ==0)
    {
    if(getLength(p1_head) ==0&&getLength(p2) !=0)
    {
        printf("\n\n\n============ GAME OVER =============\n\n\n\n");
    }

      else if(getLength(p1_head) !=0&&getLength(p2) ==0)
      {
         printf("\n\n\n============ %s WIN =============\n\n\n\n",player_name);
      }

      else
          printf("\n\n\n============ None of both players win =============\n\n\n\n");

     printf("%s ending cards: ",player_name);

      printCards(p1_head);

      printf("computer ending cards: ");

      printCards(p2);



printf("\n\n\n============ THE END =============\n\n\n\n");


    return 0;

     }

      play();
}

    return 0;
}

