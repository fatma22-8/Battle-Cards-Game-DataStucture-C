#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "cards.h"
 /*initialize required variables*/
   int n;
   int option;
   struct Cards *p1;
   struct Cards *p2;
   int round=1;
    char type;
    int val;
     int x=1;
    int cardt;

void play (){


    printf("1.Pull out a card \n2.Exist from game \n");
    scanf("%d",&option);
 if(option==1){
    printf("\n----- ROUND %d -----\n", round);

 printf("\nplayer 1: (%d)", getLength(p1) );
     printCards(p1);

printf("Enter the type and the value of the you want to pull it ");
    scanf("%c",&type);
    scanf("%d",&val);


    while(x)
    {
    if(type=='A' || type=='a' )
        {
            cardt=0;
            break;
        }
    else if(type=='D'|| type=='d')
       {
            cardt=1;
             break;
        }
    else if(type=='R'|| type=='r')
        {
            cardt=2;
             break;
        }
    else play();
    }
if (!(val>= 1 && val <= 9))
    {
        printf("The value of the card not correct, Please Enter the type and the value again");
       play();
    }

p1=Search(p1,cardt,val);

while(p1==NULL)
    {
        printf("This card doesn't exist,please pull an other card ");
        p1=Search(p1,cardt,val);
    }
 printf("\nplayer 1: (%d)", getLength(p1) );

    printCard(p1);

    printf("\nplayer 2: (%d)", getLength(p2) );

    printCard(p2);


    /*********************************/
     if(p1->card_type==0 && p2->card_type==0){//Both ATTACK

        printf("\nBoth players ATTACK\n");

        if(p1->value > p2->value){

           p1= removeCard(p1);

           p2 = removeCard(p2);

           p1=addCard(p1, createCard());

           printf("\n Player 1 wins and gets a new card. Player 2 loses his next card.\n");

        }else if(p2->value > p1->value){

           p1= removeCard(p1);

           p2 = removeCard(p2);

           p2=addCard(p2, createCard());

           printf("\nPlayer 2 wins and gets a new card. Player 1 loses their next card.\n");

        }else if(p1->value == p2->value){

         p1= removeCard(p1);

         p2= removeCard(p2);
         //No winner for this round
        }


    }
     /*********************************/
     else if(p1->card_type==1 && p2->card_type==1){//Both DEFEND

      printf("\nBoth players DEFEND \n");

      printf("Nothing happens\n");

      p1= removeCard(p1);

      p2= removeCard(p2);

    }

    else if(p1->card_type==2 && p2->card_type==2){//Both RUN

     printf("\nBoth players RUN \n");

     printf("Both players lose their next cards.\n");

      p1= removeCard(p1);

      p2= removeCard(p2);

      p1= removeCard(p1);

      p2 = removeCard(p2);
    }

    else if(p1->card_type==0 && p2->card_type==1){//p1 ATTACK, p2 DEFEND

      printf("\nPlayer 1 ATTACKs player 2 DEFENDs  \n");

        if(p1->value>p2->value){

            //p1 wins

            printf("Player 1 wins. Player 1 gets a new card.  \n");

            p1= removeCard(p1);

            p2 = removeCard(p2);
            p2 = removeCard(p2);

            p1=addCard(p1, createCard());

        }else if(p2->value>=p1->value){

             printf("Player 1 loses his card.\n");

            //p2 wins
             p1= removeCard(p1);

             p2 = removeCard(p2);

        }

    }


    else if(p2->card_type==0 && p1->card_type==1){//p2 ATTACK, p1 DEFEND

        printf("\nPlayer 2 ATTACKs player 1 DEFENDs  \n");

        if(p2->value > p1->value){

            //p2 wins

            p1= removeCard(p1);
            p1= removeCard(p1);

            p2 = removeCard(p2);

            p2=addCard(p2, createCard());

          /*  if(getLength(p1) ==1){

              printf("Player 1 loses and Player 2 survives\n");

            }
            else if(getLength(p2) ==1){

              printf("Player 2 loses and Player 1 survives\n");
            }*/

            printf("Player 2 wins. Player 2 gets a new card.  \n");

        }else{



            //p1 wins
             p1= removeCard(p1);

             p2 = removeCard(p2);

            /* if(getLength(p1) ==1){

              printf("\nPlayer 1 loses and Player 2 survives\n");

            }
            else if(getLength(p2) ==1){

              printf("\nPlayer 2 loses and Player 1 survives\n");
            }*/


             printf("Player 2 loses his next card.\n");


        }

    }
    /*********************************/
    else if(p1->card_type==1 && p2->card_type==2 ){//p1 DEFEND, p2 RUN

       p1= removeCard(p1);

       p2= removeCard(p2);

       p2 = removeCard(p2);

       printf("\nPlayer 1 DEFENDs and Player 2 RUNs.\n");

       printf("Player 2 loses his next card.\n");


    }
     /*********************************/
     else if(p2->card_type==1 && p1->card_type==2){//p2 DEFEND, p1 RUN

      p1= removeCard(p1);

      p1 = removeCard(p1);

      p2= removeCard(p2);

      printf("\nPlayer 2 DEFENDSs and Player 1 RUNs.\n");

      printf("Player 1 loses his next card .\n");
    }

    /*********************************/
    /*********************************/
    else if(p1->card_type==0 && p2->card_type==2 ){//p1 ATTACK, p2 RUN

        printf("\nPlayer 1 ATTACKs and Player 2 RUNs.\n");
        p1 = removeCard(p1);

        p2= removeCard(p2);

        p1=addCard(p1, createCard());

        p2= removeCard(p2);

        printf("\nPlayer 1 gets a new card. Player 2 loses his next card.\n");

    }else if(p2->card_type==0 && p1->card_type==2){//p2 ATTACK, p1 RUN

        printf("\nPlayer 2 ATTACKs and Player 1 RUNs.\n");

        p1 = removeCard(p1);

        p2= removeCard(p2);

        p2=addCard(p2, createCard());

        p1= removeCard(p1);

        printf("\nPlayer 2 gets a new card. Player 1 loses his next card.\n");
    }
    /*********************************/
    /*********************************/


    round++;

    }



}
int main()
{
    srand(time(NULL));
    printf("============= WELCOME TO CARDS GAME ============\n");
printf("INETRUCTIONS OF GAME\n");
printf("\n1) Enter number of cards\n");
printf("\n2) PLAYER 1 & PLAYER 2 Will have the same number of cards \n");
printf("\n3) YOU ARE PLAYER 1 & PLAYER 2 IS THE PC \n");
printf("\n4) YOUR CARDS ARE VISABLE TO YOU, SO YOU CAN CHOOSE ANY ONE OF THEM TO PLAY THE ROUND \n");
printf("\n5) 'A' means ATTACK, 'D' means DEFFEND , 'R' means RUN \n");
printf("\n6) When you ATTACK and the value of your card is greater than the value of player 2 card you will have a new card\n");
printf("\n7) in '6':\n    i.if player 2 Attack, player 2 will lose his card\n    ii.if player 2 DEFFENDs, player 2 will lose his next card\n");
printf("\n8) if you DEFFEND and the value of your card is greater than the value of player 2 card\n");
printf("\n    i.if player 2 Attack,we return to case '6'\n    ii.if player 2 DEFFENDs, nothing happends\n");
printf("\n9) if you RUN you lose your next card whatever your value\n    i.if player 2 RUN, player 2 will lose his next card\n");


printf("\nEnter number of cards \n");
 scanf("%d",&n);

 p1=buildCards(n);
 p2=buildCards(n);

 printf("============= PLAYER 1 V PLAYER 2 SHOWDOWN ============\n");

 printf("Start size: %d cards ", n);

 //printf("Player 1 starting cards: ");

 //printCards(p1);

 printf("\nPlayer 2 starting cards: ");

 printCards(p2);


for(;; ){

    if(getLength(p1) ==0 || getLength(p2) ==0){

      printf("\n\n\n============ GAME OVER =============\n\n\n\n");

      printf("Player 1 ending cards: ");

      printCards(p1);

      printf("Player 2 ending cards: ");

      printCards(p2);

      if(getLength(p1) ==0){

        printf("\nPlayer 1 ran out of cards. Player 2 wins\n\n");

      }else{

        printf("\nPlayer 2 ran out of cards. Player 1 wins\n\n");

      }


      printf("The end\n");

        return 0;
    }


      play();

}
    return 0;
}
//ATTACK : when wins (new card), when loses (loses current and next card)
//DEFEND : always loses current card only even if loses
