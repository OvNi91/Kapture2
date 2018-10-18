
int index() ;


/** Paramètres pour les scouts **/

int parameters_scout2(int rline,int rcolumn, char **T)
{
    int f_line,f_column ;
    int save_line,save_column ;
    int i ;
    int verif ;
    int content_case ;
    char disp ;
    char content_final_case ;


    save_line = rline ;
    save_column = rcolumn ;
    //content_case = T[rline][rcolumn] ;
    content_case = ' ' ;


    system("cls") ;
    disp = disp_field(T) ;
    printf("You can do 5 moves\n") ;


    for (i = 1 ; i <=  5 ; i++)
    {

        printf("You still have %d move(s) \n",5 - i+1) ;
        printf("Where do you move ? \n") ;
        printf("Line : ");
        scanf("%d",&f_line) ;
        printf("Column : ") ;
        scanf("%d",&f_column) ;

        f_line -- ;
        f_column -- ;

        /* Boucle de sécurité pour vérifier qu'il ne sélectionne pas
           une case où il y a déjà un pion */

        while ((T[f_line][f_column] == 'S') || (T[f_line][f_column] == 'T') || (T[f_line][f_column] == 'I') || (T[f_line][f_column] == 'Z') || (T[f_line][f_column] == 'Y') || (T[f_line][f_column] == '1') )

        {
            printf("You can't move there \n") ;
            printf("Where do you move ? \n") ;
            printf("Line : ");
            scanf("%d",&f_line) ;
            printf("\n") ;
            printf("Column : ") ;
            scanf("%d",&f_column) ;

            f_line -- ;
            f_column -- ;

        }


        verif = check(save_line,save_column,f_line,f_column) ;

        /* Tant que la case demandée n'est pas dans le périmètre in continue de lui demander */
        while (verif == 1)
        {
            printf("You can't move there \n") ;
            printf("You must go near your case\n") ;
            printf("Where do you move ? \n") ;
            printf("Line : ");
            scanf("%d",&f_line) ;
            printf("\n") ;
            printf("Column : ") ;
            scanf("%d",&f_column) ;

            f_line-- ;
            f_column-- ;

            verif = check(save_line,save_column,f_line,f_column) ; /** Permets de vérifier que l'utilisateur demande une case juxtaposée **/

            while ((T[f_line][f_column] == 'S') || (T[f_line][f_column] == 'T') || (T[f_line][f_column] == 'I') || (T[f_line][f_column] == 'Z') || (T[f_line][f_column] == 'Y') || (T[f_line][f_column] == '1'))

            {
                printf("You can't move there \n") ;
                printf("Where do you move ? \n") ;
                printf("Line : ");
                scanf("%d",&f_line) ;
                printf("\n") ;
                printf("Column : ") ;
                scanf("%d",&f_column) ;

                f_line -- ;
                f_column -- ;

            }
        }

        if (T[f_line][f_column] == 'F') // On lui enlève un mouvement
        {
            i++ ;
        }
        if (T[f_line][f_column] == 'R')
        {
            i = 5 ;
        }



        T[f_line][f_column] = 'S' ;

        T[save_line][save_column] = content_case ;


        content_case = T[save_line][save_column] ;



        save_line = f_line ;
        save_column = f_column ;

        system("cls") ;
        disp = disp_field(T) ;
        if (i < 5)
        {
            printf("Your pawn is at %d / %d \n", f_line + 1,f_column + 1) ;
        }


    }

}


/** Paramètres pour les Shock Troups **/

int parameters_stroups(int rline,int rcolumn, char **T)
{
    int f_line,f_column ;
    int save_line,save_column ;
    int i ;
    int verif ;
    int content_case ;
    char disp ;
    char content_final_case ;


    save_line = rline ;
    save_column = rcolumn ;
    //content_case = T[rline][rcolumn] ;
    content_case = ' ' ;


    system("cls") ;
    disp = disp_field(T) ;

    printf("You can do 2 moves\n") ;


    for (i = 1 ; i <=  2 ; i++)
    {

        printf("You still have %d move(s) \n",2 - i+1) ;
        printf("Where do you move ? \n") ;
        printf("Line : ");
        scanf("%d",&f_line) ;
        printf("\n") ;
        printf("Column : ") ;
        scanf("%d",&f_column) ;

        f_line -- ;
        f_column -- ;

        /* Boucle de sécurité pour vérifier qu'il ne sélectionne pas
           une case où il y a déjà un pion */

        while ((T[f_line][f_column] == 'S') || (T[f_line][f_column] == 'T') || (T[f_line][f_column] == 'I') || (T[f_line][f_column] == 'Z') || (T[f_line][f_column] == 'Y') || (T[f_line][f_column] == '1'))
        {
            printf("You can't move there \n") ;
            printf("Where do you move ? \n") ;
            printf("Line : ");
            scanf("%d",&f_line) ;
            printf("\n") ;
            printf("Column : ") ;
            scanf("%d",&f_column) ;

            f_line -- ;
            f_column -- ;

        }


        verif = check(save_line,save_column,f_line,f_column) ;

        /* Tant que la case demandée n'est pas dans le périmètre in continue de lui demander */
        while (verif == 1)
        {
            printf("You can't move there \n") ;
            printf("You must go near your case\n") ;
            printf("Where do you move ? \n") ;
            printf("Line : ");
            scanf("%d",&f_line) ;
            printf("Column : ") ;
            scanf("%d",&f_column) ;

            f_line-- ;
            f_column-- ;

            verif = check(save_line,save_column,f_line,f_column) ;

            while ((T[f_line][f_column] == 'S') || (T[f_line][f_column] == 'T') || (T[f_line][f_column] == 'I') || (T[f_line][f_column] == 'Z') || (T[f_line][f_column] == 'Y') || (T[f_line][f_column] == '1') )
            {
                printf("You can't move there \n") ;
                printf("Where do you move ? \n") ;
                printf("Line : ");
                scanf("%d",&f_line) ;
                printf("\n") ;
                printf("Column : ") ;
                scanf("%d",&f_column) ;

                f_line -- ;
                f_column -- ;

            }
        }


        if (T[f_line][f_column] == 'F') // On lui enlève un mouvement
        {
            i++ ;
        }
        if (T[f_line][f_column] == 'R')
        {
            i = 5 ;
        }



        T[f_line][f_column] = 'T' ; // La case devient un pion T après toutes les vérifications

        T[save_line][save_column] = content_case ;


        content_case = T[save_line][save_column] ;



        save_line = f_line ;
        save_column = f_column ;

        system("cls") ;
        disp = disp_field(T) ;
        if (i < 2)
        {
            printf("Your pawn is at %d / %d \n", f_line + 1,f_column + 1) ;

        }


    }

}

/** Paramètres pour les InfantryMan **/

parameters_infantry(int rline,int rcolumn, char **T)
{
    int f_line,f_column ;
    int save_line,save_column ;
    int i ;
    int verif ;
    int content_case ;
    char disp ;
    char content_final_case ;


    save_line = rline ;
    save_column = rcolumn ;
    //content_case = T[rline][rcolumn] ;
    content_case = ' ' ;

    system("cls") ;
    disp = disp_field(T) ;

    printf("You can do 3 moves\n") ;


    for (i = 1 ; i <=  3 ; i++)
    {

        printf("You still have %d move(s) \n", 3 - i+1) ;
        printf("Where do you move ? \n") ;
        printf("Line : ");
        scanf("%d",&f_line) ;
        printf("\n") ;
        printf("Column : ") ;
        scanf("%d",&f_column) ;

        f_line -- ;
        f_column -- ;

        /* Boucle de sécurité pour vérifier qu'il ne sélectionne pas
           une case où il y a déjà un pion */

        while ((T[f_line][f_column] == 'S') || (T[f_line][f_column] == 'T') || (T[f_line][f_column] == 'I') || (T[f_line][f_column] == 'Z') || (T[f_line][f_column] == 'Y') || (T[f_line][f_column] == '1'))
        {
            printf("You can't move there \n") ;
            printf("Where do you move ? \n") ;
            printf("Line : ");
            scanf("%d",&f_line) ;
            printf("\n") ;
            printf("Column : ") ;
            scanf("%d",&f_column) ;

            f_line -- ;
            f_column -- ;

        }


        verif = check(save_line,save_column,f_line,f_column) ;

        /* Tant que la case demandée n'est pas dans le périmètre in continue de lui demander */
        while (verif == 1)
        {
            printf("You can't move there \n") ;
            printf("You must go near your case\n") ;
            printf("Where do you move ? \n") ;
            printf("Line : ");
            scanf("%d",&f_line) ;
            printf("\n") ;
            printf("Column : ") ;
            scanf("%d",&f_column) ;

            f_line-- ;
            f_column-- ;

            verif = check(save_line,save_column,f_line,f_column) ;

            while ((T[f_line][f_column] == 'S') || (T[f_line][f_column] == 'T') || (T[f_line][f_column] == 'I') || (T[f_line][f_column] == 'Z') || (T[f_line][f_column] == 'Y') || (T[f_line][f_column] == '1'))

            {
                printf("You can't move there \n") ;
                printf("Where do you move ? \n") ;
                printf("Line : ");
                scanf("%d",&f_line) ;
                printf("\n") ;
                printf("Column : ") ;
                scanf("%d",&f_column) ;

                f_line -- ;
                f_column -- ;

            }
        }


        if (T[f_line][f_column] == 'F') // On lui enlève un mouvement
        {
            i++ ;
        }
        if (T[f_line][f_column] == 'R')
        {
            i = 5 ;
        }


        T[f_line][f_column] = 'I' ;

        T[save_line][save_column] = content_case ;

        content_case = T[save_line][save_column] ;


        save_line = f_line ;
        save_column = f_column ;

        system("cls") ;
        disp = disp_field(T) ;
        if (i < 3)
        {
            printf("Your pawn is at %d / %d \n", f_line + 1,f_column + 1) ;
        }

    }
}



int parameters_scout_p2(int rline,int rcolumn, char **T)
{
    int f_line,f_column ;
    int save_line,save_column ;
    int i ;
    int verif ;
    int content_case ;
    char disp ;
    char content_final_case ;


    save_line = rline ;
    save_column = rcolumn ;
    //content_case = T[rline][rcolumn] ;
    content_case = ' ' ;


    system("cls") ;
    disp = disp_field(T) ;
    printf("You can do 5 moves\n") ;


    for (i = 1 ; i <=  5 ; i++)
    {

        printf("You still have %d move(s) \n",5 - i+1) ;
        printf("Where do you move ? \n") ;
        printf("Line : ");
        scanf("%d",&f_line) ;
        printf("Column : ") ;
        scanf("%d",&f_column) ;

        f_line -- ;
        f_column -- ;

        /* Boucle de sécurité pour vérifier qu'il ne sélectionne pas
           une case où il y a déjà un pion */

        while ((T[f_line][f_column] == 'S') || (T[f_line][f_column] == 'T') || (T[f_line][f_column] == 'I') || (T[f_line][f_column] == 'Z') || (T[f_line][f_column] == 'Y') || (T[f_line][f_column] == '1') )

        {
            printf("You can't move there \n") ;
            printf("Where do you move ? \n") ;
            printf("Line : ");
            scanf("%d",&f_line) ;
            printf("\n") ;
            printf("Column : ") ;
            scanf("%d",&f_column) ;

            f_line -- ;
            f_column -- ;

        }


        verif = check(save_line,save_column,f_line,f_column) ;

        /* Tant que la case demandée n'est pas dans le périmètre in continue de lui demander */
        while (verif == 1)
        {
            printf("You can't move there \n") ;
            printf("You must go near your case\n") ;
            printf("Where do you move ? \n") ;
            printf("Line : ");
            scanf("%d",&f_line) ;
            printf("\n") ;
            printf("Column : ") ;
            scanf("%d",&f_column) ;

            f_line-- ;
            f_column-- ;

            verif = check(save_line,save_column,f_line,f_column) ;

            while ((T[f_line][f_column] == 'S') || (T[f_line][f_column] == 'T') || (T[f_line][f_column] == 'I') || (T[f_line][f_column] == 'Z') || (T[f_line][f_column] == 'Y') || (T[f_line][f_column] == '1'))

            {
                printf("You can't move there \n") ;
                printf("Where do you move ? \n") ;
                printf("Line : ");
                scanf("%d",&f_line) ;
                printf("\n") ;
                printf("Column : ") ;
                scanf("%d",&f_column) ;

                f_line -- ;
                f_column -- ;

            }
        }

        if (T[f_line][f_column] == 'F') // On lui enlève un mouvement
        {
            i++ ;
        }
        if (T[f_line][f_column] == 'R')
        {
            i = 5 ;
        }



        T[f_line][f_column] = 'Z' ;

        T[save_line][save_column] = content_case ;


        content_case = T[save_line][save_column] ;



        save_line = f_line ;
        save_column = f_column ;

        system("cls") ;
        disp = disp_field(T) ;
        if (i < 5)
        {
            printf("Your pawn is at %d / %d \n", f_line + 1,f_column + 1) ;
        }


    }

}

/** Player 2 Infantry **/

parameters_infantry_p2(int rline,int rcolumn, char **T)
{
    int f_line,f_column ;
    int save_line,save_column ;
    int i ;
    int verif ;
    int content_case ;
    char disp ;
    char content_final_case ;


    save_line = rline ;
    save_column = rcolumn ;
    //content_case = T[rline][rcolumn] ;
    content_case = ' ' ;

    system("cls") ;
    disp = disp_field(T) ;

    printf("You can do 3 moves\n") ;


    for (i = 1 ; i <=  3 ; i++)
    {

        printf("You still have %d move(s) \n", 3 - i+1) ;
        printf("Where do you move ? \n") ;
        printf("Line : ");
        scanf("%d",&f_line) ;
        printf("Column : ") ;
        scanf("%d",&f_column) ;

        f_line -- ;
        f_column -- ;

        /* Boucle de sécurité pour vérifier qu'il ne sélectionne pas
           une case où il y a déjà un pion */

        while ((T[f_line][f_column] == 'S') || (T[f_line][f_column] == 'T') || (T[f_line][f_column] == 'I') || (T[f_line][f_column] == 'Z') || (T[f_line][f_column] == 'Y') || (T[f_line][f_column] == '1'))
        {
            printf("You can't move there \n") ;
            printf("Where do you move ? \n") ;
            printf("Line : ");
            scanf("%d",&f_line) ;
            printf("Column : ") ;
            scanf("%d",&f_column) ;

            f_line -- ;
            f_column -- ;

        }


        verif = check(save_line,save_column,f_line,f_column) ;

        /* Tant que la case demandée n'est pas dans le périmètre in continue de lui demander */
        while (verif == 1)
        {
            printf("You can't move there \n") ;
            printf("You must go near your case\n") ;
            printf("Where do you move ? \n") ;
            printf("Line : ");
            scanf("%d",&f_line) ;
            printf("Column : ") ;
            scanf("%d",&f_column) ;

            f_line-- ;
            f_column-- ;

            verif = check(save_line,save_column,f_line,f_column) ;

            while ((T[f_line][f_column] == 'S') || (T[f_line][f_column] == 'T') || (T[f_line][f_column] == 'I') || (T[f_line][f_column] == 'Z') || (T[f_line][f_column] == 'Y') || (T[f_line][f_column] == '1'))

            {
                printf("You can't move there \n") ;
                printf("Where do you move ? \n") ;
                printf("Line : ");
                scanf("%d",&f_line) ;
                printf("\n") ;
                printf("Column : ") ;
                scanf("%d",&f_column) ;

                f_line -- ;
                f_column -- ;

            }
        }


        if (T[f_line][f_column] == 'F') // On lui enlève un mouvement
        {
            i++ ;
        }
        if (T[f_line][f_column] == 'R')
        {
            i = 5 ;
        }


        T[f_line][f_column] = '1' ;

        T[save_line][save_column] = content_case ;

        content_case = T[save_line][save_column] ;


        save_line = f_line ;
        save_column = f_column ;

        system("cls") ;
        disp = disp_field(T) ;
        if (i < 3)
        {
            printf("Your pawn is at %d / %d \n", f_line + 1,f_column + 1) ;
        }

    }
}



int parameters_stroups_p2(int rline,int rcolumn, char **T)
{
    int f_line,f_column ;
    int save_line,save_column ;
    int i ;
    int verif ;
    int content_case ;
    char disp ;
    char content_final_case ;


    save_line = rline ;
    save_column = rcolumn ;
    //content_case = T[rline][rcolumn] ;
    content_case = ' ' ;


    system("cls") ;
    disp = disp_field(T) ;

    printf("You can do 2 moves\n") ;


    for (i = 1 ; i <=  2 ; i++)
    {

        printf("You still have %d move(s) \n",2 - i+1) ;
        printf("Where do you move ? \n") ;
        printf("Line : ");
        scanf("%d",&f_line) ;
        printf("\n") ;
        printf("Column : ") ;
        scanf("%d",&f_column) ;

        f_line -- ;
        f_column -- ;

        /* Boucle de sécurité pour vérifier qu'il ne sélectionne pas
           une case où il y a déjà un pion */

        while ((T[f_line][f_column] == 'S') || (T[f_line][f_column] == 'T') || (T[f_line][f_column] == 'I') || (T[f_line][f_column] == 'Z') || (T[f_line][f_column] == 'Y') || (T[f_line][f_column] == '1'))
        {
            printf("You can't move there \n") ;
            printf("Where do you move ? \n") ;
            printf("Line : ");
            scanf("%d",&f_line) ;
            printf("\n") ;
            printf("Column : ") ;
            scanf("%d",&f_column) ;

            f_line -- ;
            f_column -- ;

        }


        verif = check(save_line,save_column,f_line,f_column) ;

        /* Tant que la case demandée n'est pas dans le périmètre in continue de lui demander */
        while (verif == 1)
        {
            printf("You can't move there \n") ;
            printf("You must go near your case\n") ;
            printf("Where do you move ? \n") ;
            printf("Line : ");
            scanf("%d",&f_line) ;
            printf("Column : ") ;
            scanf("%d",&f_column) ;

            f_line-- ;
            f_column-- ;

            verif = check(save_line,save_column,f_line,f_column) ;

            while ((T[f_line][f_column] == 'S') || (T[f_line][f_column] == 'T') || (T[f_line][f_column] == 'I') || (T[f_line][f_column] == 'Z') || (T[f_line][f_column] == 'Y') || (T[f_line][f_column] == '1') )
            {
                printf("You can't move there \n") ;
                printf("Where do you move ? \n") ;
                printf("Line : ");
                scanf("%d",&f_line) ;
                printf("\n") ;
                printf("Column : ") ;
                scanf("%d",&f_column) ;

                f_line -- ;
                f_column -- ;

            }
        }


        if (T[f_line][f_column] == 'F') // On lui enlève un mouvement
        {
            i++ ;
        }
        if (T[f_line][f_column] == 'R')
        {
            i = 5 ;
        }



        T[f_line][f_column] = 'Y' ; // La case devient un pion T après toutes les vérifications

        T[save_line][save_column] = content_case ;


        content_case = T[save_line][save_column] ;



        save_line = f_line ;
        save_column = f_column ;

        system("cls") ;
        disp = disp_field(T) ;
        if (i < 2)
        {
            printf("Your pawn is at %d / %d \n", f_line + 1,f_column + 1) ;

        }

    }

}






int check(int init_line, int init_col,int line,int col)
{
    //printf("\n##10##\n") ;


    if ((init_line - 1 == line) && (init_col - 1 == col))  //Case au dessus à gauche
    {
        return (0) ;
    }
    else if ((init_line - 1 == line) && (init_col == col))  // case au dessus
    {
        return (0) ;
    }
    else if ((init_line - 1 == line) && (init_col + 1 == col))  // Case au dessus à droite
    {
        return (0) ;
    }
    else if ((init_line == line) && (init_col - 1 == col))  //Case à gauche sur la même ligne
    {
        return (0) ;
    }
    else if ((init_line == line) && (init_col == col))  // Il reste à la même case
    {
        return (0) ;
    }
    else if ((init_line == line) && (init_col + 1 == col))  // Case à droite même ligne
    {
        return (0) ;
    }
    else if ((init_line + 1 == line) && (init_col - 1 == col))  // Case au dessous à gauche
    {
        return (0) ;
    }
    else if ((init_line + 1 == line) && (init_col == col))  // Case au dessous
    {
        return (0) ;
    }
    else if ((init_line + 1 == line) && (init_col + 1 == col))  // Case au dessous à droite
    {
        return (0) ;
    }
    else
    {
        return (1) ;
    }

}












