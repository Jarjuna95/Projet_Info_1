#include "projet.h"

int main(){
    int i=0;
    int choix;
    Animal refuge[2];
    FILE * fichier = fopen("Animal/Animaux.txt", "r");
    if(fichier==NULL){
    	printf("Erreur \n");
        exit(1);
    }
     while (fscanf(fichier, "%d %s %d %d %f %s", &refuge[i].numero_id, refuge[i].nom, &refuge[i].espece, &refuge[i].anniv, &refuge[i].poids, refuge[i].comm) == 6) {
           i++;
    }
    /* for(int j=0; j<2; j++){
        printf("%d, %s, %d, %d, %f, %s \n", refuge[j].numero_id, refuge[j].nom, refuge[j].espece, refuge[j].anniv, refuge[j].poids, refuge[j].comm);
    }*/ //txt -> tableau verif
    printf("Bonjour dans l'accueil de notre refuge"\n);
    printf("Tapez 1 si vous voulez recherchez un animal, 2 pour ajoutez un animal et 3 pour adoptez un animal :"\n)
    scanf("%d", & choix);
    while(choix<1 || choix>3){
        printf("Erreur dans la saisie, veuillez ressaisir un chiffre :\n");
         scanf("%d", & choix);
    }
    

    
    
    RechercheAnimal(refuge);
     return 0;
}
