#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int index()
{
    int choice ;
    int choice2 ;

    printf("Do you want to see index of the game ?\n") ;
    printf("Tap 0 if you want to see it and 1 if you don't : ") ;
    scanf("%d",&choice) ;

    while (choice != 0 && choice != 1)
    {
        printf("Please enter 1 or 0\n") ;
        printf("Do you want to see index of the game ?\n") ;
        printf("Tap 0 to see it and 1 if you don't : ") ;
        scanf("%d",&choice) ;
    }

    if (choice == 0)
    {
        /* Différents choix proposés à l'utilisateur */

        while (choice2 != 0)
        {
            printf("\n") ;
            printf("1. Goal of the game\n") ;
            printf("2. Different pawns and movements\n") ;
            printf("3. Battles\n") ;
            printf("4. Catching Flag\n\n") ; // \n 2 fois car on veut 2 retours  la ligne (esthétique)

            printf("Tap the number of the statement you want to know something (if you want exit this menu tap 0) \n") ;
            scanf("%d",&choice2) ;
            printf("\n") ;


            /* Boucle de sécurité */

            while (choice2 != 0 && choice2 != 1 && choice2 != 2 && choice2 != 3 && choice2 != 4)
            {
                printf("1. Goal of the game\n") ;
                printf("2. Different pawns and movements\n") ;
                printf("3. Battles\n") ;
                printf("4. Catching Flag\n\n") ; // \n 2 fois car on veut 2 retours  la ligne (esthétique)

                printf("Please enter 0, 1, 2, 3 or 4 : \n") ;
                scanf("%d",&choice2) ;
                printf("\n") ;
            }

            if (choice2 == 1)
            {
                printf("-----------------------------------------------\n") ;
                printf("The Kapture is a board game opposing two camps composed of several pawns with different roles.\nEach side has a Flag that the opposing side has to capture and bring back to his own Flag. \nThe game is played on a board representing a field that may have various obstacles (forest, rivers). \nAt the start of the game, each player occupies one side of the field and his pawns are grouped around its Flag. \nThe position of the Flag may be chosen at random or provided by the player. \nThe entire Field is not visible, it must be explored gradually to discover the obstacles and monitor in constantly the movements of the opponent.\n") ;
                printf("\n") ;
                printf("-----------------------------------------------\n") ;
            }

            if (choice2 == 2)
            {
                printf("-----------------------------------------------\n") ;
                printf("The different pawns are :\n") ;

                printf("1. The 'Scouts' (represented by a 'S')\n") ;
                printf("  -> The Scouts have 5 points of movements \n\n") ;

                printf("2. The 'Infantryman' (represented by an 'I')\n") ;
                printf("  -> The Infantryman have 3 points of movements \n\n");

                printf("3. The 'Shock Troops' (represented by a 'T') \n") ;
                printf("  -> The Shock Troops have 2 points of movements \n\n") ;

                printf("The different Field Type are : \n") ;

                printf("1. The 'Normal field' cost 1 point of movement \n") ;
                printf("2. The 'Forest field' cost 2 points of movements \n") ;
                printf("3. The 'River field' cost all the points of movements \n") ;
                printf("\n") ;
                printf("-----------------------------------------------\n") ;

            }

            if (choice2 == 3)
            {
                printf("-----------------------------------------------\n") ;
                printf("Battles : \n") ;
                printf("1. Scout VS Scout : Nothing happens \n") ;
                printf("2. Infantryman or Shock Troops VS Scout : The scout is returned to his starting position \n") ;
                printf("3. Shock Troops VS Infantryman : Infantryman is returned to his starting position \n") ;
                printf("4.  Infantryman VS Infantryman : One of them (randomly chosen with 50/100 of chance) is returned to its starting position \n") ;
                printf("5.  Shock Troops VS Shock Troops : Both Shift One Space Towards their Flag.\n    If retreat is not possible (board edge or position occupied by other pawns) then return to the starting position. \n") ;
                printf("\n") ;
                printf("-----------------------------------------------\n") ;

            }

            if (choice2 == 4)
            {
               printf("-----------------------------------------------\n") ;
               printf("To catch the flag, you need to be on a box adjacent to the flag.\n") ;
               printf("The pawn who gets the flag is considered as a Scout for battles.\n") ;
               printf("But this one keeps the same number of movements points. \n") ;
               printf("If the pawn loses a battle when it has the flag, the flag falls \n") ;
               printf("falls randomly on a square adjacent to the box where the pawn was. \n") ;
               printf("The box where the flag falls must be empty. \n") ;
               printf("It can be picked up by any pawn, wich then becomes flag bearer. \n") ;
               printf("The flag is represented by 'P'. \n") ;
               printf("\n") ;
               printf("-----------------------------------------------\n") ;
            }

        }

    }
    if (choice != 0)
        {
             printf("\n");
        }

}

