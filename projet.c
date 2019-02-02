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
//#include "projet.h"

void initialise_rand()
{
    srand(time(NULL));
}


void afficher_tableau(int m, int n, int tab[m][n])
{
    int i, j;
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            printf("%d ", tab[i][j]);}
        printf("\n");
    }
    
}

int hasard(int inf, int sup)
{
    int rando = rand();
    return (inf + (rando % (sup - inf +1)));
}

void remplir(int m, int n, int tab[m][n])
{
    //Cette fonction nous sert à remplir un tableau entré en paramètre
    //Dans le cas de REDIRECTIONS nous allons utiler scanf
    int i,j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            //tab[i][j]=hasard(0,1);
            scanf("%d",&tab[i][j]);
}

void copieTab(int m,int n, int tab[m][n],int tab1[m][n]){
    
    //Cette fonction nous sert à copier un tableau dans un autre
    
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            tab[i][j]=tab1[i][j];
        }
    }
}

bool comparTab(int m,int n, int tab[m][n],int tab1[m][n]){ //On aurait pu utiliser cette fonction pour comparer deux évolutions successifs
    //On ne l'a pas utiliser ayant un problème dans l'affichage des états stables.
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            if (tab[i][j]!=tab1[i][j])
            {
                return false;
            }
            
        }
    }
    
    return true;
}

void test_tab(int M,int N,int tab[ M][ N]){
    
    int i,j; //compteur pour parcourir le tableau
    int k,l;//compteur pour tester les cases vides ou occupées
    int tmp;//variable temporaire
    int cmp;//s'incrémente à chaque où l'on tombera sur un 1 en parcourant les cases
    int val;//va stocker la ligne que nous allons parcourir
    int val1;// va stocker la colonne que nous allons parcourir
    
    
    int tab1[M][N];
    for (i=0;i<M;i++){
        for (j=0;j<N;j++){
            cmp=0;//Cette variable va s'incrementer lorsque l'on rencontre 1
            tmp =tab[i][j];
            for (k=i-1;k<i+2;k++){
                for (l=j-1;l<j+2;l++){
                    /*
                     
                     if (k<0 || l<0 || k>M-1 || l>N-1) { //Sans variante périodique
                     break;
                     }
                     
                     */
                    
                    val=k; //k va être modifié ci-dessous, il faut la garder dans une variable pour pouvoir réutiliser k.
                    val1=l; //même explication qu'ici dessus.
                    
                    if (k<0){
                        k=M-1;//la ligne au dessus de la ligne 0 correspond à M-1 : variante périodique
                    }
                    
                    if (l<0)
                    {
                        l=N-1;//la colonne à gauche de la colonne 0 correspond à N-1 : variante périodique
                    }
                    
                    if (k>M-1)
                    {
                        k=0;
                    }
                    
                    if (l>N-1)
                    {
                        l=0;
                    }
                    
                    if (tab[k][l]==1) {
                        cmp=cmp+1;
                    }
                    
                    k=val;//on récupère la valeur de k pour passer à l'étude de la ligne suivante
                    l=val1;
                }
            }
            
            //Le parcours des 9 cases ayant été achevé il faut alors déterminer si notre cellule va survivre, naitre ou mourir
            if (tmp==1) {
                
                /* Nous avons parcouru 9 cases (8 cases autour de la cellule + la cellule)
                 => il faut donc retrancher le nombre de 1 si notre cellule avait pour valeur 1. */
                
                cmp=cmp-1;
                if (cmp<=1||cmp>=4) { //mort si cellule vivante a 1 ou moins, 4 ou plus cellules autour de lui
                    tab1[i][j]=0;
                }
                else {
                    tab1[i][j]=tmp; //survie dans les autres cas
                }
            }
            else if (tmp==0) {
                if (cmp==3) {
                    tab1[i][j]=1; //naissance car cellule vide entourrée de 3 cellules vivantes
                }
                else {
                    tab1[i][j]=tmp; //La cellule reste morte, garde la valeur 0.
                }
            }
        }
    }
    
    afficher_tableau(M, N, tab1);
    copieTab(M,N,tab,tab1);//Il faut copier le tableau pour pouvoir le réutiliser aux évolutions futurs.
    
}

void menu(){
    
    printf("====================MENU========================\n");
    printf("         Bienvenu au jeu de la vie              \n");
    printf("         O représente une cellule morte         \n");
    printf("      Et 1 représente une cellule vivante        \n");
    
}



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


