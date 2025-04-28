#include "projet.h"
void RechercheAnimal(int critere){
     if(critere==1){
        char nomRecherche[50];
        printf("Entrez le nom de l'animal à chercher : \n");
        scanf("%s", nomRecherche);
        if(nomRecherche[0]>='a' || nomRecherche[0]<='z'){
          nomRecherche[0]-=32;
        }
        for (int j = 0; j < i; j++) {
        if (strcmp(refuge[j].nom, nomRecherche) == 0) {
            printf("Animal trouvé : %d, %s, %d, %d, %.2f, %s\n", 
                   refuge[j].numero_id, 
                   refuge[j].nom, 
                   refuge[j].espece, 
                   refuge[j].anniv, 
                   refuge[j].poids, 
                   refuge[j].comm);
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Animal non trouvé.\n");
    }
    ;
        } */

      
