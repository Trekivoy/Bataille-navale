#include <stdio.h>
#include <stdlib.h>
#define J1 0
#define J2 1
#define ETAT 2
#define LONGUEUR 24
#define HAUTEUR 18
#define corvette 1
#define destroyer 2
#define croiseur 3
#define porte_avion 4
#define touched 8
#define untouched 9

void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}

int doRand(int startVal, int endVal){
    waitFor(0.05);
    srand(time(NULL)*rand());
    if(startVal == 0 && endVal == 1){
        return rand() % 2;
    }else{
        return (rand() % ((endVal + startVal -1)) + startVal);
    }
}

void afficher_tableau(int plateau[LONGUEUR][HAUTEUR][ETAT]){
      int i = 0;
      int j = 0;
      int k = 0;
      int joueur = 1;// ajouter une valeur joueur changeante
      char alph[]= "ABCDEFGHIJKLMNOPKL";
      printf("\n\n");

      printf("\n\n\nPlateau joueur %d : \n\n",joueur);
      printf ("  _1_ 2_ 3_ 4_ 5_ 6_ 7_ 8_ 9_ 10_11_12_13_14_15_16_17_18_19_20_21_22_23_24") ;
      for(i = 0; i <HAUTEUR; i++){

          printf(" \n%c |", alph[i]);

          for(j = 0; j < LONGUEUR; j++){
              printf("%d  ", plateau[j][i][k]);






              }
        }


}
void touche (int plateau[LONGUEUR][HAUTEUR][ETAT]){
    int x = 0;
    int y = 0;
    printf(" \n\n\n\nQuelles coordonees voulez vous attaquez ?\n");
    scanf ("%d",&x);// mettre une valeur maximale à sélectionner
    fflush(stdin);
    scanf ("%d",&y);//idem
    if (plateau[x][y]!=0||plateau[x][y]!=9||plateau[x][y]!=8){
        printf("TOUCHE !!!! ");
        plateau[x][y]= touched;
                               }else{
    printf("Reessaie gros cul!");
    plateau[x][y]= untouched;
    }


}
void bateau2 (int plateau[LONGUEUR][HAUTEUR][ETAT]){
        int posX_dep_bat2 = doRand(0,LONGUEUR-1);
        int posY_dep_bat2 = doRand(0,HAUTEUR-1);
        int i = 0;
        while((plateau[posY_dep_bat2][posX_dep_bat2][0] != 0) && (plateau[posY_dep_bat2 + 1][posX_dep_bat2][0] != 0) && (plateau[posY_dep_bat2 + 2][posX_dep_bat2][0] != 0) ){

        posY_dep_bat2 = doRand(0,LONGUEUR-1);
        posX_dep_bat2 = doRand(0,HAUTEUR-1);
}
        for(i = 0; i < 3; i++){
            plateau[posX_dep_bat2 + i][posY_dep_bat2][J1] = destroyer;
    }
    }


void bateau1(int plateau[LONGUEUR][HAUTEUR][ETAT]){

    int posX_dep_bat2 = doRand(0,LONGUEUR-1);
    int posY_dep_bat2 = doRand(0,HAUTEUR-1);
    while((plateau[posY_dep_bat2][posX_dep_bat2][0] != 0) && (plateau[posY_dep_bat2 + 1][posX_dep_bat2][0] != 0)){

        posY_dep_bat2 = doRand(0, LONGUEUR-1);
        posX_dep_bat2 = doRand(0, HAUTEUR-1);
}

      plateau[posX_dep_bat2][posY_dep_bat2][0] = corvette;
}
void bateau3(int plateau[LONGUEUR][HAUTEUR][ETAT]){
        int posX_dep_bat2 = doRand(0,LONGUEUR-1);
        int posY_dep_bat2 = doRand(0,HAUTEUR-1);
        int i = 0;
        while((plateau[posY_dep_bat2][posX_dep_bat2][0] != 0) && (plateau[posY_dep_bat2 + 1][posX_dep_bat2][0] != 0) && (plateau[posY_dep_bat2 + 2][posX_dep_bat2][0] != 0) && (plateau[posY_dep_bat2 + 3][posX_dep_bat2][0] != 0)){
        posY_dep_bat2 = doRand(0, LONGUEUR-1);
        posX_dep_bat2 = doRand(0, HAUTEUR-1);
}
        for(i = 0; i < 4; i++){
            plateau[posX_dep_bat2 + i][posY_dep_bat2][J1] = croiseur;
    }
    }
void bateau4(int plateau[LONGUEUR][HAUTEUR][ETAT]){

    int posX_dep_bat2 = doRand(0,LONGUEUR-1);
    int posY_dep_bat2 = doRand(0,HAUTEUR-1);
    int i = 0;
    while((plateau[posY_dep_bat2][posX_dep_bat2][0] != 0) && (plateau[posY_dep_bat2 + 1][posX_dep_bat2][0] != 0) && (plateau[posY_dep_bat2 + 2][posX_dep_bat2][0] != 0) && (plateau[posY_dep_bat2 + 3][posX_dep_bat2][0] != 0)
           && (plateau[posY_dep_bat2 + 4][posX_dep_bat2][0] != 0) && (plateau[posY_dep_bat2 + 5][posX_dep_bat2][0] != 0)){

        posY_dep_bat2 = doRand(0, LONGUEUR-1);
        posX_dep_bat2 = doRand(0, HAUTEUR-1);
}
    for(i = 0; i < 6; i++){
        plateau[posX_dep_bat2 + i][posY_dep_bat2][J1] = porte_avion;
    }
    }
int main() {

      int plateau[HAUTEUR][LONGUEUR] = {0};

      bateau2(plateau);
      bateau2(plateau);
      bateau1(plateau);
      bateau3(plateau);
      bateau3(plateau);
      bateau4(plateau);
      afficher_tableau(plateau);
      touche (plateau);
      afficher_tableau(plateau);

    return 0;
}
