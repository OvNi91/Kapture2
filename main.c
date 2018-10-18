#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <index.h>
//#include <display.h>

//int display() ;
int init() ;
int index() ;
int flag_p1() ;
int flag_p2() ;
int current_field() ;
current_field_p2() ;


int main()
{
    //int players ;
    int restart = 0 ;
    /*printf("How many players ? ") ; // Permets de choisir le nb de joueurs
    scanf("%d",&players) ;
    while (players > 2)
    {
        printf("How many players ? (Max = 2) ") ; // Boucle de sécurité
        scanf("%d",&players) ;
    }*/



    index() ;

    int line ;
    int cpt = 0 ;
    int line_flag1, col_flag1;
    int line_flag2,col_flag2 ;
    int initField,disp,pos_Flag1,pos_Flag2 ;
    char current ;
    int col_case,line_case ;
    int player1 ;
    int player2 ;
    int i;
    char **Map ;

    initField = init() ;
    disp = disp_field(initField) ; // On affiche une première fois la map
    printf("%c",disp) ;
    printf("\n   PLAYER 1   \n\n") ;
    printf("Where do you want to place your flag ?  \n") ;
    printf("Line : ") ;
    scanf("%d",&line_flag1) ;  // On veut les coordonnées du drapeau
    printf("Column : ") ;
    scanf("%d",&col_flag1) ;
    printf("\n") ;




    system("cls") ;
    pos_Flag1 = flag_p1(line_flag1,col_flag1) ; // ON envoie les données pour placer le drapeau à la fonction flag

    disp = disp_field(pos_Flag1) ;




    printf("%c",disp) ; // On affiche de nouveau la map

    printf("\n   PLAYER 2   \n\n") ;
    printf("Where do you want to place your flag ?  \n") ;
    printf("Line : ") ;
    scanf("%d",&line_flag2) ;  // On veut les coordonnées du drapeau
    printf("Column : ") ;
    scanf("%d",&col_flag2) ;
    printf("\n") ;

    system("cls") ;
    pos_Flag2 = flag_p2(line_flag1,col_flag1,line_flag2,col_flag2) ; //Contient les placements des 2 drapeaux
    disp = disp_field(pos_Flag2) ;


    Map = pos_Flag2 ; // Devrait évoluer au fur et à mesure du jeu





    while (restart == 0) // Boucle contenant le jeu
    {


        /** PLAYER 1**/

        printf("\n   PLAYER 1   \n\n") ;
        printf("Select the case where your pawn is : \n") ;
        printf("Line : ") ;
        scanf("%d",&line_case) ;
        printf("Column : ") ;
        scanf("%d",&col_case) ;
        printf("\n") ;

        Map = current_field(line_case,col_case,Map) ;

        /*while (Map == 1) ; // Boucle au cas où l'utilisateur déselctionne le pawn
        {
            printf("\n   PLAYER 1   \n\n") ;
            printf("Select the case where your pawn is : \n") ;
            printf("Line : ") ;
            scanf("%d",&line_case) ;
            printf("Column : ") ;
            scanf("%d",&col_case) ;
            printf("\n") ;
            Map = current_field(line_case,col_case,Map) ;
        }*/

        // disp = disp_field(Map) ; // Pas utile

        /** PLAYER 2 **/

        printf("\n   PLAYER 2   \n\n") ;
        printf("Select the case where your pawn is : \n") ;
        printf("Line : ") ;
        scanf("%d",&line_case) ;
        printf("Column : ") ;
        scanf("%d",&col_case) ;
        printf("\n") ;


        Map = current_field_p2(line_case,col_case,Map) ;

        /*while (Map == 1) ; // Boucle au cas où l'utilisateur déselctionne le pawn
        {
            printf("\n   PLAYER 1   \n\n") ;
            printf("Select the case where your pawn is : \n") ;
            printf("Line : ") ;
            scanf("%d",&line_case) ;
            printf("Column : ") ;
            scanf("%d",&col_case) ;
            printf("\n") ;
            Map = current_field(line_case,col_case,Map) ;
        }*/

        //disp = disp_field(Map) ;



    }


    Map = current_field(line_case,col_case,Map) ;
    disp = disp_field(Map) ;


    // Si il veut recommencer une partie


    /*printf("Do you want to play another party ? \n") ;
    printf("Tap 0 to restart and whatever you want to stop : ") ;
    scanf("%d",&restart) ;*/

    if (restart == 0)
    {
        index() ;
    }




return 0;
}

















