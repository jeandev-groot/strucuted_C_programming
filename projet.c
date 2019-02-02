//
//  projet.c
//  IMA 3 Groupe TD2 12/01/2018
//
//  Created by Brinda Muzakare && Jean de Dieu Nduwamungu.
//  Copyright © 2018 Muzakare Nduwamungu. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include "projet.h"



int main()
{
    initialise_rand();
    int compteur=0;
    int m=10,n=10;
    int nombreGeneration;
    scanf("%d",&nombreGeneration);
    int tab[m][n] ;
    
    remplir(m,n,tab);
    printf("Voici le tableau initial\n");
    afficher_tableau(m, n, tab);
    printf("\n");


        ////////REDIRECTIONS, EVOLUTIONS AUTOMATIQUES/////////

    
    do
    {
       system("clear");
       test_tab(m,n,tab);
       sleep(1);
       compteur=compteur+1;
    } while (compteur<nombreGeneration);

    /*

        ///////SANS REDIRECTIONS, AFFICHAGE D'UN ETAT AU SUIVANT/////
    menu();
    int menu1=1;
    while (menu1==1){
      test_tab(m,n,tab);

      printf("Voulez-vous passer à l'évolution suivante?\n");
      printf("Appuyer sur 1 pour continuer et n'importe quel autre CHIFFRE pour quitter\n");
      scanf("%d",&menu1);
      system("clear");
    }

    if (menu1!=1)
    {
      printf("Vous avez choisi de quitter. À bientôt\n");
    }
    */

    

    return 0;
}


