#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int disp_field (char **T)
{

    int i,j;
    int Lig  = 26 ;
    int Col = 55 ;
    char c ;

    printf("\n") ;
    printf(" ") ;
    for (j = 0 ; j < Col ; j++)
    {
        printf(" %2d",j + 1) ; // Affiche les chiffres au dessus
    }
    printf("\n") ;
    for(i = 0 ; i < Lig ; i++)
    {
        //c = 'A' + i ;
        printf("%d ",i+1) ; // Permet d'afficher les lettres sur la gauche, � la base mais on change en chiffres
        for(j = 0 ; j < Col ; j++)   // C'est de l'affichage
        {
            if (T[i][j] == 'F')  /** Couleur **/
            {
                color(2,2) ;
                fflush(stdout) ;
            }
            else if (T[i][j] == 'R')
            {
                color(9,9) ;
                fflush(stdout) ;
            }
            else if (T[i][j] == 'P' || T[i][j] == '&')
            {
                color(14,0) ;
            }
            else if((T[i][j] == 'S') || (T[i][j] == 'T') || (T[i][j] == 'I'))
            {
                color(12,0) ;
                fflush(stdout) ;
            }
            else if ((T[i][j] == 'Z') || (T[i][j] == '1') || (T[i][j] == 'Y'))
            {
                color(13,0) ;
                fflush(stdout) ;
            }
            else if (T[i][j] == 'M')
            {
                color(4,4) ;
                fflush(stdout) ;
            }
            else
            {
                color(15,0) ;
                fflush(stdout) ;
            }
            printf("%2c ",T[i][j]) ; // Affiche les cases vides

        }
        color(15,0) ;
        fflush(stdout) ;

        printf("\n") ;
        printf("  ") ;
        for (j = 0 ; j < Col ; j++) // Pareil, on affiche en quelque sorte les lignes
            {
                color(15,0) ;
                fflush(stdout) ;
                printf("--+") ;
            }
        printf("\n") ;

    }
    return 0 ;

}
