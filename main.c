#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "cards.h"
int main()
{


	clock_t start = clock();

    //initialize required variables
      int n;
   struct Cards *p1;
   struct Cards *p2;
    int round=1;
    srand(time(NULL));

	printf("Enter number of cards:    ");
scanf("%d",&n);

 p1=buildCards(n);
 p2=buildCards(n);

 printf("============= PLAYER 1 V PLAYER 2 SHOWDOWN ============\n");

 printf("Start size: %d cards\n", n);

 printf("Player 1 starting cards: ");

 printCards(p1);

 printf("Player 2 starting cards: ");

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

        clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f", elapsed);

 return 0;
    }
    printf("\n----- ROUND %d -----\n", round);

    printf("\nplayer 1: (%d)", getLength(p1) );

    printCard(p1);

    printf("\nplayer 2: (%d)", getLength(p2) );

    printCard(p2);

    /***********/
    if(p1->card_type==0 && p2->card_type==0){//attack

        printf("\nBoth players ATTACK\n");

        if(p1->value > p2->value){

           p1= removeCard(p1);

           p2 = removeCard(p2);
           p2 = removeCard(p2);

           p1=addCard(p1, createCard());

           printf("\n Player 1 wins and gets a new card. Player 2 loses their next card into the abyss.\n");

        }else if(p2->value > p1->value){

           p1= removeCard(p1);
           p1= removeCard(p1);

           p2 = removeCard(p2);

           p2=addCard(p2, createCard());

           printf("\nPlayer 2 wins and gets a new card. Player 1 loses their next card into the abyss.\n");

        }else if(p1->value == p2->value){

         p1= removeCard(p1);

         p2= removeCard(p2);
        }


    }
     /***********/
     else if(p1->card_type==1 && p2->card_type==1){//defend

      printf("\nBoth players DEFEND \n");

      printf("Nothing happens\n");

      p1= removeCard(p1);

      p2= removeCard(p2);

    }

    else if(p1->card_type==2 && p2->card_type==2){//run

     printf("\nBoth players RUN \n");

     printf("Both players lose their next cards into the abyss.\n");

      p1= removeCard(p1);

      p2= removeCard(p2);

      p1= removeCard(p1);

      p2 = removeCard(p2);
    }

    else if(p1->card_type==0 && p2->card_type==1){//attacking vs defending

      printf("\nPlayer 1 ATTACKs player 2 DEFENDs  \n");

        if(p1->value>p2->value){

            //p1 wins

            printf("\nPlayer 1 wins. Player 1 gets a new card.  \n");

            p1= removeCard(p1);

            p2 = removeCard(p2);

            p1=addCard(p1, createCard());

        }else if(p2->value>=p1->value){

             printf("Player 1 loses their next card into the abyss.\n");

            //p2 wins
             p1= removeCard(p1);

             p1= removeCard(p1);

             p2 = removeCard(p2);

        }

    }


    else if(p2->card_type==0 && p1->card_type==1){//attacking vs defending

        printf("\nPlayer 2 ATTACKs player 1 DEFENDs  \n");

        if(p2->value > p1->value){

            //p1 wins

            p1= removeCard(p1);

            p2 = removeCard(p2);

            p2=addCard(p2, createCard());

            if(getLength(p1) ==1){

              printf("Player 1 loses and Player 2 survives\n");

            }
            else if(getLength(p1) ==1){

              printf("Player 2 loses and Player 1 survives\n");
            }

            printf("\nPlayer 2 wins. Player 2 gets a new card.  \n");

        }else{



            //p2 wins
             p1= removeCard(p1);

             p2= removeCard(p2);

             p2 = removeCard(p2);

             if(getLength(p1) ==1){

              printf("Player 1 loses and Player 2 survives\n");

            }
            else if(getLength(p1) ==1){

              printf("Player 2 loses and Player 1 survives\n");
            }


             printf("Player 2 loses their next card into the abyss.\n");


        }

    }
    /***********/
    else if(p1->card_type==0 && p2->card_type==2 ){//attacking vs running

       p1= removeCard(p1);

       p2= removeCard(p2);

       p2 = removeCard(p2);

       printf("\nPlayer 1 ATTACKs and Player 2 RUNs.\n");

       printf("Player 2 loses their next card into the abyss.\n");


    }
     /***********/
     else if(p2->card_type==0 && p1->card_type==2){

      p1= removeCard(p1);

      p1 = removeCard(p1);

      p2= removeCard(p2);

      printf("Player 2 ATTACKs and Player 1 RUNs.\n");

      printf("Player 1 loses their next card into the abyss.\n");
    }

    /***********/
    /***********/
    else if(p1->card_type==1 && p2->card_type==2 ){//attacking vs running

        printf("Player 1 gets a new card. Player 2 loses their next card into the abyss.\n");

        p1 = removeCard(p1);

        p2= removeCard(p2);

        p1=addCard(p1, createCard());

        p2= removeCard(p2);

    }else if(p2->card_type==1 && p1->card_type==2){

      printf("Player 2 gets a new card. Player 1 loses their next card into the abyss.\n");

        p1 = removeCard(p1);

        p2= removeCard(p2);

        p2=addCard(p2, createCard());

        p1= removeCard(p1);
    }
    /***********/
    /***********/


    round++;

}

 return 0;
 }
