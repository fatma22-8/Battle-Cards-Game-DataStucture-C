#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "cards.h"

 /*initialize required variables*/
   char c, type;
   int n, val, round=1;
  struct Cards *p1, *p2;
  Card *p1_head, *temp ;


void play (){
    printf("\n----- ROUND %d -----\n", round);

 printf("\nplayer 1: (%d)", getLength(p1_head) );
     printCards(p1_head);

 printf("\nplayer 2:  (%d)", getLength(p2));
     printCard(p2);

 printf("\n\nEnter the type and the value of the card you want to pull it ");
     scanf("%C",&type);
     scanf("%d",&val);

p1=Pullcard(p1_head,type,val);

while(p1==NULL)
  {      scanf("%c",&type);
         scanf("%d",&val);

         p1=Pullcard(p1_head,type,val);
         }

if(p1->card_type==0 && p2->card_type==0) //Both ATTACK
    {
        printf("\nBoth players ATTACK\n");

        if(p1->value > p2->value)
        {
            p1_head= removeCard(p1_head,p1);

           p2 = removeCard(p2,p2);

           p1_head=addCard(p1_head, createCard());

           printf("\n Player 1 gets a new card.\n");
        }

        else if(p2->value > p1->value)
        {
          p1_head= removeCard(p1_head,p1);

           p2 = removeCard(p2,p2);

           p2=addCard(p2, createCard());

           printf("\nPlayer 2 gets a new card.\n");

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
      printf("\nPlayer 1 ATTACKs player 2 DEFENDs  \n");

        if(p1->value>p2->value)
        {
            printf("\nPlayer 1 gets a new card. Player 2 loses his next card. \n");

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
    printf("\nPlayer 2 ATTACKs player 1 DEFENDs  \n");

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

            printf("\nPlayer 2 gets a new card. Player 1 loses his next card.  \n");

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

       printf("\nPlayer 1 DEFENDs and Player 2 RUNs.\n");

       printf("\nPlayer 2 loses his next card.\n");
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

    printf("\nPlayer 2 DEFENDSs and Player 1 RUNs.\n");

    printf("\nPlayer 1 loses his next card .\n");
}

    /*********************************/
else if(p1->card_type==0 && p2->card_type==2 ) //p1 ATTACK, p2 RUN
{
    printf("\nPlayer 1 ATTACKs and Player 2 RUNs.\n");

    p1_head = removeCard(p1_head,p1);

    p2= removeCard(p2,p2);

    p1_head=addCard(p1_head, createCard());

    if(getLength(p2)!=0)
        p2= removeCard(p2,p2);

    printf("\nPlayer 1 gets a new card. Player 2 loses his next card.\n");

    }
        /*********************************/
else if(p2->card_type==0 && p1->card_type==2) //p2 ATTACK, p1 RUN
{
    printf("\nPlayer 2 ATTACKs and Player 1 RUNs.\n");

    if (p1->next==NULL)
        temp=p1_head;
    else
        temp=p1->next;

    p1_head= removeCard(p1_head,p1);

    if(getLength(p1_head)!=0)
        p1_head= removeCard(p1_head,temp);

    p2= removeCard(p2,p2);

    p2=addCard(p2, createCard());

    printf("\nPlayer 2 gets a new card. Player 1 loses his next card.\n");
}
    /*********************************/

   round++;

return;
}

int main()
{
    srand(time(NULL));

    printf("============= WELCOME TO BATTLE CARDS GAME ============\n");

printf("\nINETRUCTIONS OF THE GAME\n");

printf("\n1) Enter number of cards\n");
printf("\n2) PLAYER 1 & PLAYER 2 Will have the same number of cards \n");
printf("\n3) YOU ARE PLAYER 1 & PLAYER 2 IS THE PC \n");
printf("\n4) YOUR CARDS ARE VISABLE TO YOU, SO YOU CAN CHOOSE ANY ONE OF THEM TO PLAY THE ROUND \n");
printf("\n5) 'A' means ATTACK, 'D' means DEFFEND , 'R' means RUN \n");
printf("\n6) When you ATTACK and the value of your card is greater than the value of player 2 card you will have a new card\n");
printf("\n7) in '6':\n    i.if player 2 Attack, player 2 will lose his current card\n    ii.if player 2 DEFFENDs, player 2 will lose his next card\n");
printf("\n8) if you DEFFEND and the value of your card is greater than the value of player 2 card");
printf("\n    i.if player 2 Attack,we return to case '6'\n    ii.if player 2 DEFFENDs, nothing happens\n");
printf("\n9) i.if you RUN you lose your next card whatever your value is\n   ii.if player 2 RUN, player 2 will lose his next card\n");

printf("\nEnter number of cards:   ");
  scanf("%c",&c);

while (!isdigit(c))
{
  scanf("%c",&c);
}
 n = c -'0' ;

   p1=buildCards(n);

   p2=buildCards(n);

   p1_head=createCard() ;

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
         printf("\n\n\n============ YOU WIN =============\n\n\n\n");
      }

      else
          printf("\nNone of both players win\n\n");

     printf("Player 1 ending cards: ");

      printCards(p1_head);

      printf("Player 2 ending cards: ");

      printCards(p2);


printf("The end\n");

    return 0;

     }

      play();
}

    return 0;
}
