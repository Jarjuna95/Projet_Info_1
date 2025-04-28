#include "projet.h"

void AfficheAnimal(int indice){
        printf("%d, %s, %d, %d, %f, %s \n", refuge[indice].numero_id, refuge[indice].nom, refuge[indice].espece, refuge[indice].anniv, refuge[indice].poids, refuge[indice].comm);
}
 
void RechercheAnimal(int critere){
     if(critere==1){
        char nomRecherche[50];
        printf("Entrez le nom de l'animal à chercher : \n");
        scanf("%s", nomRecherche);
        if(nomRecherche[0]>='a' || nomRecherche[0]<='z'){
          nomRecherche[0]-=32;
        }
        for (int j = 0; j < 2; j++) {                                       // changer le 2 (nombre d'animal au total
            if (strcmp(refuge[j].nom, nomRecherche) == 0) {                     //comparer le nom avec les animaux du refuge
               printf("Animal trouvé voici les informations : \n");
               AfficheAnimal(j);
               break;
            }
        }
        printf("Animal non trouvé.\n");
     }
     else if(critere==2){ 
          int espece;
          
        

      
