#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int type_field() ;
int flag_p1() ;
parameters_scout() ;
parameters_scout2() ;

int init ()
{
    // On crée la map dans cette fonction
    int Lig, Col,i,j;
    char **T;
    char **T1;
    Lig = 26 ;
    Col = 55 ;


    T = (int **)malloc(Lig*sizeof(int*));
    for(i = 0 ; i < Lig ; i++)
        T[i]=(int *) malloc(Col*sizeof(int));

    for(i = 0 ; i < Lig ; i++)
        for(j = 0 ; j < Col ; j++)
            T[i][j] = ' ' ;

    T = type_field(T) ;
    T = pawns_field(T) ;
    return (T) ;

    for(i = 0 ; i < Lig ; i++)
        free(T[i]);
    free(T);

}

/** Place le 1er drapeau (temporaire) **/
flag_p1(int line, int column)
{

    int Lig, Col,i,j;
    char **T;
    char **T1;
    Lig = 26 ;
    Col = 55 ;

    line-- ;
    column-- ;

    T = (int **)malloc(Lig*sizeof(int*));
    for(i = 0 ; i < Lig ; i++)
        T[i]=(int *) malloc(Col*sizeof(int));

    for(i = 0 ; i < Lig ; i++)
        for(j = 0 ; j < Col ; j++)
            T[i][j] = ' ' ;

    T = type_field(T) ;
    T = pawns_field(T) ;

    while (T[line][column] == 'S' || T[line][column] == 'I' || T[line][column] == 'T' || T[line][column] == 'P')
    {
        printf("You can't place your flag here \n") ;
        printf("Where do you want to place your flag ?  \n") ;
        printf("Line : ") ;
        scanf("%d",&line) ;  // On veut les coordonnées du drapeau
        printf("\n") ;
        printf("Column : ") ;
        scanf("%d",&column) ;
        printf("\n") ;

        line-- ;
        column -- ;

    }


    T[line][column] = 'P' ;


    return (T) ;

    for(i = 0 ; i < Lig ; i++)
        free(T[i]);
    free(T);




}



/** Replace le 1er drapeau et place le 2e (cette fois-ci définitif) **/

flag_p2(int line1, int column1,int line2,int column2)
{

    int Lig, Col,i,j;
    char **T;
    char **T1;
    Lig = 26 ;
    Col = 55 ;

    line1-- ;
    column1-- ;

    line2-- ;
    column2-- ;

    T = (int **)malloc(Lig*sizeof(int*));
    for(i = 0 ; i < Lig ; i++)
        T[i]=(int *) malloc(Col*sizeof(int));

    for(i = 0 ; i < Lig ; i++)
        for(j = 0 ; j < Col ; j++)
            T[i][j] = ' ' ;

    T = type_field(T) ;
    T = pawns_field(T) ;

    while (T[line2][column2] == 'S' || T[line2][column2] == 'I' || T[line2][column2] == 'T' || T[line2][column2] == 'P')
    {
        printf("You can't place your flag here \n") ;
        printf("Where do you want to place your flag ?  \n") ;
        printf("Line : ") ;
        scanf("%d",&line2) ;  // On veut les coordonnées du drapeau
        printf("\n") ;
        printf("Column : ") ;
        scanf("%d",&column2) ;
        printf("\n") ;

        line2-- ;
        column2 -- ;

    }

    /*while((line1 && column1) == (line2 && column2))
    {
        printf("You can't place your flag here \n") ;
        printf("Line : ") ;
        scanf("%d",&line2) ;  // On veut les coordonnées du drapeau
        printf("\n") ;
        printf("Column : ") ;
        scanf("%d",&column2) ;
        printf("\n") ;

        line2-- ;
        column2 -- ;

    }*/

    T[line1][column1] = 'P' ;

    T[line2][column2] = '&' ;



    return (T) ;

    for(i = 0 ; i < Lig ; i++)
        free(T[i]);
    free(T);


}


/** Va permettre d'actualiser le terrain pour le Joueur 1 **/
/** Sélection pion Player 1 **/

int current_field(int line, int column,char **T) // letter_line permettra de l'affichage (plus simple que de reconvertir le nombre en lettre) à voir dans le code ci-dessous
{
    int Lig, Col,i,j;
    char choice ;


    line-- ;
    column-- ;

    while ((T[line][column] != 'S') && (T[line][column] != 'T') && (T[line][column] != 'I')) // Boucle de sécurité pour qu'il sélectionne un pion
        {
            printf("\n   PLAYER 1   \n\n") ;
            printf("You must select a pawn \n") ;
            printf("Select the case where your pawn is : \n") ;
            printf("Line : ") ;
            scanf("%d",&Lig) ;
            printf("Column : ") ;
            scanf("%d",&Col) ;
            printf("\n") ;

            line = Lig ;
            column = Col ;

            line-- ;
            column-- ;
        }
    /*while ((line > 26) && (column > 55))
    {
            printf("\n   PLAYER 1   \n\n") ;
            printf("Please enter a possible value\n") ;
            printf("You must select a pawn \n") ;
            printf("Select the case where your pawn is : \n") ;
            printf("Line : ") ;
            scanf("%d",&line) ;
            printf("\n") ;
            printf("Column : ") ;
            scanf("%d",&column) ;
            printf("\n") ;

    }*/

    if (T[line][column] == 'S')
    {
        printf("Are you sur that you want to move the pawn Scout at case %d / %d ? \n",line + 1,column + 1) ;
        printf("Tap Y for 'yes' and N for 'no' \n") ;
        scanf(" %c",&choice) ;

        if (choice == 'Y' || choice == 'y')
        {
            parameters_scout2(line,column,T) ; //Contenue dans moove.c
        }
        else
        {
            return 1 ;
        }
    }

    if (T[line][column] == 'T')
    {
        printf("Are you sur that you want to move the pawn Shock Troup at case %d / %d ? \n",line + 1,column + 1) ;
        printf("Tap Y for 'yes' and N for 'no' \n") ;
        scanf(" %c",&choice) ;

        if (choice == 'y' || choice == 'Y')
        {
            parameters_stroups(line,column,T) ; /** Accès à cette fonction dans le moove.c **/
        }
        else
        {
            return 1 ;
        }
    }

    if (T[line][column] == 'I')
    {
        printf("Are you sur that you want to move the pawn Infantry at case %d / %d ? \n",line + 1,column + 1) ;
        printf("Tap Y for 'yes' and N for 'no' \n") ;
        scanf(" %c",&choice) ;

        if (choice == 'Y' || choice == 'y')
        {

            parameters_infantry(line,column,T) ; /** Accès à cette fonction dans le mooce.c **/
        }
        else
        {
            return 1 ;
        }
    }


    return (T) ;

    for(i = 0 ; i < Lig ; i++)
        free(T[i]);
    free(T);

}

/** Actualise le terrain pour le joueur 2 (Fonction très similaire à celle qui précède) **/
int current_field_p2(int line, int column,char **T)
{
    int Lig, Col,i,j;
    char choice ;


    line-- ;
    column-- ;

    while ((T[line][column] != 'Z') && (T[line][column] != 'Y') && (T[line][column] != '1')) // Boucle de sécurité pour qu'il sélectionne un pion
        {
            printf("\n   PLAYER 2   \n\n") ;
            printf("You must select a pawn \n") ;
            printf("Select the case where your pawn is : \n") ;
            printf("Line : ") ;
            scanf("%d",&Lig) ;
            printf("Column : ") ;
            scanf("%d",&Col) ;
            printf("\n") ;

            line = Lig ;
            column = Col ;

            line-- ;
            column-- ;
        }
    /*while ((line > 26) && (column > 55))
    {
            printf("\n   PLAYER 1   \n\n") ;
            printf("Please enter a possible value\n") ;
            printf("You must select a pawn \n") ;
            printf("Select the case where your pawn is : \n") ;
            printf("Line : ") ;
            scanf("%d",&line) ;
            printf("\n") ;
            printf("Column : ") ;
            scanf("%d",&column) ;
            printf("\n") ;

    }*/

    if (T[line][column] == 'Z')
    {
        printf("Are you sur that you want to move the pawn Scout at case %d / %d ? \n",line + 1,column + 1) ;
        printf("Tap Y for 'yes' and N for 'no' \n") ;
        scanf(" %c",&choice) ;

        if (choice == 'Y' || choice == 'y')
        {
            parameters_scout_p2(line,column,T) ; //Contenue dans moove.c
        }
        else
        {
            return 1 ;
        }
    }

    if (T[line][column] == 'Y')
    {
        printf("Are you sur that you want to move the pawn Shock Troup at case %d / %d ? \n",line + 1,column + 1) ;
        printf("Tap Y for 'yes' and N for 'no' \n") ;
        scanf(" %c",&choice) ;

        if (choice == 'y' || choice == 'Y')
        {
            parameters_stroups_p2(line,column,T) ;
        }
        else
        {
            return 1 ;
        }
    }

    if (T[line][column] == '1')
    {
        printf("Are you sur that you want to move the pawn Infantry at case %d / %d ? \n",line + 1,column + 1) ;
        printf("Tap Y for 'yes' and N for 'no' \n") ;
        scanf(" %c",&choice) ;

        if (choice == 'Y' || choice == 'y')
        {

            parameters_infantry_p2(line,column,T) ;
        }
        else
        {
            return 1 ;
        }
    }


    return (T) ;

    for(i = 0 ; i < Lig ; i++)
        free(T[i]);
    free(T);
}


/** Permet de remplir la ap des types forêts ou Rivière **/

int type_field (char **T)
{


    T [23][0] = 'F' ;
    T [25][0] = 'F';
    T [24][0] = 'F';

    T [22][1] = 'F' ;
    T [23][1] = 'F' ;
    T [24][1] = 'F';
    T [25][1] = 'F';

    T [21][2] = 'F';
    T [22][2] = 'F';
    T [23][2] = 'F';
    T [24][2] = 'F';
    T [25][2] = 'F';

    T [21][3] = 'F';
    T [22][3] = 'F';
    T [23][3] = 'F';
    T [24][3] = 'F';
    T [25][3] = 'F';

    T [21][4] = 'F';
    T [22][4] = 'F';
    T [23][4] = 'F';
    T [24][4] = 'F';
    T [25][4] = 'F';

    T [20][5] = 'F';
    T [21][5] = 'F';
    T [22][5] = 'F';
    T [23][5] = 'F';
    T [24][5] = 'F';
    T [25][5] = 'F';

    T [19][6] = 'F';
    T [20][6] = 'F';
    T [21][6] = 'F';
    T [22][6] = 'F';
    T [23][6] = 'F';
    T [24][6] = 'F';
    T [25][6] = 'F';


    T [19][7] = 'F';
    T [20][7] = 'F';
    T [21][7] = 'F';
    T [22][7] = 'F';
    T [23][7] = 'F';
    T [24][7] = 'F';

    T [19][8] = 'F';
    T [20][8] = 'F';
    T [21][8] = 'F';
    T [22][8] = 'F';
    T [23][8] = 'F';
    T [24][8] = 'F';

    T [20][9] = 'F';
    T [21][9] = 'F';
    T [22][9] = 'F';
    T [23][9] = 'F';

    T [21][10] = 'F';
    T [22][10] = 'F';
    T [6][10] = 'F';

    T [5][11] = 'F';
    T [6][11] = 'F';

    T [4][12] = 'F';
    T [5][12] = 'F';
    T [6][12] = 'F';

    T [4][13] = 'F';
    T [5][13] = 'F';
    T [6][13] = 'F';
    T [7][13] = 'F';

    T [3][14] = 'F';
    T [4][14] = 'F';
    T [5][14] = 'F';
    T [6][14] = 'F';
    T [7][14] = 'F';
    T [8][14] = 'F';

    T [3][15] = 'F';
    T [4][15] = 'F';
    T [5][15] = 'F';
    T [6][15] = 'F';
    T [7][15] = 'F';
    T [8][15] = 'F';
    T [19][15] = 'F';
    T [20][15] = 'F';

    T [4][16] = 'F';
    T [5][16] = 'F';
    T [6][16] = 'F';
    T [7][16] = 'F';
    T [18][16] = 'F';
    T [19][16] = 'F';
    T [20][16] = 'F';
    T [21][16] = 'F';
    T [22][16] = 'F';

    T [5][17] = 'F';
    T [6][17] = 'F';
    T [7][17] = 'F';
    T [18][17] = 'F';
    T [19][17] = 'F';
    T [20][17] = 'F';
    T [21][17] = 'F';
    T [22][17] = 'F';
    T [23][17] = 'F';

    T [6][18] = 'F';
    T [17][18] = 'F';
    T [18][18] = 'F';
    T [19][18] = 'F';
    T [20][18] = 'F';
    T [21][18] = 'F';
    T [22][18] = 'F';
    T [23][18] = 'F';
    T [24][18] = 'F';
    T [0][18] = 'F';
    T [1][18] = 'F';
    T [2][18] = 'F';

    T [0][19] = 'F';
    T [1][19] = 'F';
    T [4][19] = 'F';
    T [18][19] = 'F';
    T [19][19] = 'F';
    T [20][19] = 'F';
    T [21][19] = 'F';
    T [22][19] = 'F';
    T [23][19] = 'F';
    T [24][19] = 'F';
    T [25][19] = 'F';

    T [0][20] = 'F';
    T [1][20] = 'F';
    T [3][20] = 'F';
    T [4][20] = 'F';
    T [5][20] = 'F';
    T [14][20] = 'F';
    T [18][20] = 'F';
    T [19][20] = 'F';
    T [20][20] = 'F';
    T [21][20] = 'F';
    T [22][20] = 'F';
    T [23][20] = 'F';
    T [24][20] = 'F';
    T [25][20] = 'F';

    T [0][21] = 'F';
    T [3][21] = 'F';
    T [4][21] = 'F';
    T [5][21] = 'F';
    T [6][21] = 'F';
    T [7][21] = 'F';
    T [13][21] = 'F';
    T [14][21] = 'F';
    T [15][21] = 'F';
    T [20][21] = 'F';
    T [21][21] = 'F';
    T [22][21] = 'F';
    T [23][21] = 'F';
    T [24][21] = 'F';
    T [25][21] = 'F';

    T [0][22] = 'F';
    T [2][22] = 'F';
    T [3][22] = 'F';
    T [4][22] = 'F';
    T [5][22] = 'F';
    T [6][22] = 'F';
    T [7][22] = 'F';
    T [12][22] = 'F';
    T [13][22] = 'F';
    T [14][22] = 'F';
    T [15][22] = 'F';
    T [21][22] = 'F';
    T [22][22] = 'F';
    T [23][22] = 'F';
    T [24][22] = 'F';
    T [25][22] = 'F';
    T [8][22] = 'F';

    T [0][23] = 'F';
    T [3][23] = 'F';
    T [4][23] = 'F';
    T [5][23] = 'F';
    T [6][23] = 'F';
    T [7][23] = 'F';
    T [13][23] = 'F';
    T [14][23] = 'F';
    T [15][23] = 'F';
    T [16][23] = 'F';
    T [22][23] = 'F';
    T [23][23] = 'F';
    T [24][23] = 'F';
    T [25][23] = 'F';

    T [8][23] = 'R';
    T [9][23] = 'R';
    T [10][23] = 'R';


    T [3][24] = 'F';
    T [4][24] = 'F';
    T [14][24] = 'F';
    T [15][24] = 'F';
    T [16][24] = 'F';
    T [17][24] = 'F';
    T [0][24] = 'F';

    T [5][24] = 'R';
    T [6][24] = 'R';
    T [7][24] = 'R';
    T [8][24] = 'R';
    T [9][24] = 'R';
    T [10][24] = 'R';
    T [11][24] = 'R';
    T [12][24] = 'R';
    T [22][24] = 'R';
    T [23][24] = 'R';
    T [24][24] = 'R';
    T [25][24] = 'R';

    T [0][25] = 'F';
    T [14][25] = 'F';
    T [15][25] = 'F';

    T [3][25] = 'R';
    T [4][25] = 'R';
    T [5][25] = 'R';
    T [6][25] = 'R';
    T [7][25] = 'R';
    T [11][25] = 'R';
    T [12][25] = 'R';
    T [13][25] = 'R';
    T [16][25] = 'R';
    T [17][25] = 'R';
    T [18][25] = 'R';
    T [22][25] = 'R';
    T [23][25] = 'R';
    T [24][25] = 'R';
    T [25][25] = 'R';

    T [0][26] ='F';
    T [22][26] ='F';
    T [23][26] ='F';
    T [24][26] ='F';
    T [25][26] ='F';

    T [1][26] ='R';
    T [3][26] ='R';
    T [4][26] ='R';
    T [13][26] ='R';
    T [14][26] ='R';
    T [15][26] ='R';
    T [16][26] ='R';
    T [17][26] ='R';
    T [18][26] ='R';
    T [19][26] ='R';
    T [20][26] ='R';

    T [16][27] ='F';
    T [17][27] ='F';
    T [18][27] ='F';
    T [22][27] ='F';
    T [23][27] ='F';
    T [24][27] ='F';
    T [25][27] ='F';

    T [20][27] ='R';
    T [19][27] ='R';
    T [14][27] ='R';
    T [15][27] ='R';
    T [0][27] ='R';
    T [1][27] ='R';

    T [14][28] ='F';
    T [15][28] ='F';
    T [16][28] ='F';
    T [17][28] ='F';
    T [18][28] ='F';
    T [19][28] ='F';
    T [22][28] ='F';
    T [24][28] ='F';
    T [23][28] ='F';
    T [25][28] ='F';

    T [0][28] ='R';

    T [13][29] ='F';
    T [14][29] ='F';
    T [15][29] ='F';
    T [16][29] ='F';
    T [17][29] ='F';
    T [21][29] ='F';
    T [22][29] ='F';
    T [23][29] ='F';
    T [24][29] ='F';
    T [25][29] ='F';

    T [12][30] ='F';
    T [13][30] ='F';
    T [14][30] ='F';
    T [15][30] ='F';
    T [16][30] ='F';
    T [21][30] ='F';
    T [22][30] ='F';
    T [23][30] ='F';
    T [24][30] ='F';
    T [25][30] ='F';

    T [12][31] ='F';
    T [13][31] ='F';
    T [14][31] ='F';
    T [15][31] ='F';
    T [20][31] ='F';
    T [21][31] ='F';
    T [22][31] ='F';
    T [23][31] ='F';
    T [24][31] ='F';
    T [25][31] ='F';

    T [13][32] ='F';
    T [14][32] ='F';
    T [15][32] ='F';
    T [20][32] ='F';
    T [21][32] ='F';
    T [22][32] ='F';
    T [23][32] ='F';
    T [24][32] ='F';

    T [19][33] ='F';
    T [20][33] ='F';
    T [21][33] ='F';
    T [22][33] ='F';
    T [23][33] ='F';

    T [20][34] ='F';
    T [21][34] ='F';
    T [22][34] ='F';
    T [23][34] ='F';

    T [3][35] ='F';
    T [21][35] ='F';
    T [22][35] ='F';
    T [23][35] ='F';

    T [1][36] ='F';
    T [2][36] ='F';
    T [3][36] ='F';
    T [4][36] ='F';
    T [22][36] ='F';

    T [1][37] ='F';
    T [2][37] ='F';
    T [3][37] ='F';
    T [4][37] ='F';
    T [5][37] ='F';

    T [0][38] ='F';
    T [1][38] ='F';
    T [2][38] ='F';
    T [3][38] ='F';
    T [4][38] ='F';
    T [5][38] ='F';

    T [0][39] ='F';
    T [1][39] ='F';
    T [2][39] ='F';
    T [3][39] ='F';
    T [4][39] ='F';
    T [16][39] ='F';
    T [17][39] ='F';

    T [0][40] ='F';
    T [1][40] ='F';
    T [2][40] ='F';
    T [3][40] ='F';
    T [4][40] ='F';
    T [19][40] ='F';
    T [15][40] ='F';
    T [16][40] ='F';
    T [17][40] ='F';
    T [18][40] ='F';

    T [0][41] ='F';
    T [1][41] ='F';
    T [2][41] ='F';
    T [3][41] ='F';
    T [4][41] ='F';
    T [5][41] ='F';
    T [14][41] ='F';
    T [15][41] ='F';
    T [16][41] ='F';
    T [17][41] ='F';
    T [18][41] ='F';
    T [19][41] ='F';
    T [20][41] ='F';

    T [0][42] ='F';
    T [1][42] ='F';
    T [2][42] ='F';
    T [3][42] ='F';
    T [4][42] ='F';
    T [5][42] ='F';
    T [14][42] ='F';
    T [15][42] ='F';
    T [16][42] ='F';
    T [17][42] ='F';
    T [18][42] ='F';
    T [19][42] ='F';
    T [20][42] ='F';

    T [0][43] ='F';
    T [1][43] ='F';
    T [2][43] ='F';
    T [3][43] ='F';
    T [4][43] ='F';
    T [5][43] ='F';
    T [6][43] ='F';
    T [13][43] ='F';
    T [14][43] ='F';
    T [15][43] ='F';
    T [16][43] ='F';
    T [17][43] ='F';
    T [18][43] ='F';
    T [19][43] ='F';

    T [0][44] ='F';
    T [1][44] ='F';
    T [2][44] ='F';
    T [3][44] ='F';
    T [4][44] ='F';
    T [5][44] ='F';
    T [6][44] ='F';
    T [13][44] ='F';
    T [14][44] ='F';
    T [15][44] ='F';
    T [16][44] ='F';
    T [17][44] ='F';
    T [18][44] ='F';

    T [0][45] ='F';
    T [1][45] ='F';
    T [2][45] ='F';
    T [3][45] ='F';
    T [4][45] ='F';
    T [5][45] ='F';
    T [13][45] ='F';
    T [14][45] ='F';
    T [15][45] ='F';
    T [16][45] ='F';
    T [17][45] ='F';
    T [18][45] ='F';
    T [22][45] ='F';

    T [0][46] ='F';
    T [1][46] ='F';
    T [2][46] ='F';
    T [3][46] ='F';
    T [4][46] ='F';
    T [14][46] ='F';
    T [15][46] ='F';
    T [16][46] ='F';
    T [17][46] ='F';
    T [18][46] ='F';
    T [21][46] ='F';
    T [22][46] ='F';
    T [23][46] ='F';

    T [0][47] ='F';
    T [1][47] ='F';
    T [2][47] ='F';
    T [3][47] ='F';
    T [14][47] ='F';
    T [15][47] ='F';
    T [16][47] ='F';
    T [17][47] ='F';
    T [21][47] ='F';
    T [22][47] ='F';
    T [23][47] ='F';
    T [24][47] ='F';

    T [1][48] ='F';
    T [2][48] ='F';
    T [15][48] ='F';
    T [16][48] ='F';
    T [20][48] ='F';
    T [21][48] ='F';
    T [22][48] ='F';
    T [23][48] ='F';

    T [20][49] ='F';
    T [21][49] ='F';
    T [22][49] ='F';
    T [23][49] ='F';

    T [19][50] ='F';
    T [20][50] ='F';
    T [21][50] ='F';
    T [22][50] ='F';

    T [18][51] ='F';
    T [19][51] ='F';
    T [20][51] ='F';
    T [21][51] ='F';
    T [22][51] ='F';

    T [16][52] ='F';
    T [17][52] ='F';
    T [18][52] ='F';
    T [19][52] ='F';
    T [20][52] ='F';
    T [21][52] ='F';

    T [15][53] ='F';
    T [16][53] ='F';
    T [17][53] ='F';
    T [18][53] ='F';
    T [19][53] ='F';
    T [20][53] ='F';

    T [15][54] ='F';
    T [16][54] ='F';
    T [17][54] ='F';
    T [18][54] ='F';
    T [19][54] ='F';
    T [20][54] ='F';
    T [21][54] ='F';

    T [2][27] = 'M' ;
    T [2][26] = 'M' ;
    T [2][25] = 'M' ;

    T[21][25] = 'M' ;
    T[21][26] = 'M' ;
    T[21][27] = 'M' ;
    //T[21][28] = 'M' ;





    return (T) ;
}

/** Permets de remplir la map avec les pions **/

int pawns_field(char **T)
{

    /** Player **/
    T [14] [1] = 'S' ;
    T [15] [1] = 'S' ;
    T [16] [1] = 'S' ;

    T [14] [2] = 'I' ;
    T [15] [2] = 'I' ;

    T [14] [3] = 'T' ;

    /** Player 2 **/
    T [7] [52] = 'Z' ; /** Equivalent scout **/
    T [8] [52] = 'Z' ;
    T [9] [52] = 'Z' ;

    T [7] [51] = '1' ; /** Equivalent Infantry **/
    T [8] [51] = '1' ;

    T [7] [50] = 'Y' ; /** Equivalent Shock Troup **/

    return (T) ;

}
