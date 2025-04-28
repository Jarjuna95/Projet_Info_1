#include "projet.h"

int main(){
    int i=0;
    Animal refuge[2];
    FILE * fichier = fopen("Animal/Animaux.txt", "r");
    if(fichier==NULL){
    	printf("Erreur \n");
        exit(1);
    }
     while (fscanf(fichier, "%d %s %d %d %f %s", &refuge[i].numero_id, refuge[i].nom, &refuge[i].espece, &refuge[i].anniv, &refuge[i].poids, refuge[i].comm) == 6) {
           i++;
    }
    for(int j=0; j<2; j++){
        printf("%d, %s, %d, %d, %f, %s \n", refuge[j].numero_id, refuge[j].nom, refuge[j].espece, refuge[j].anniv, refuge[j].poids, refuge[j].comm);
        }
    return 0;
        }
