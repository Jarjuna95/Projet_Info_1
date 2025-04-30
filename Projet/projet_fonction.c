#include "projet.h"

void AfficheAnimal(int indice){
        printf("%d, %s, %d, %d, %f, %s \n", refuge[indice].numero_id, refuge[indice].nom, refuge[indice].espece, refuge[indice].anniv, refuge[indice].poids, refuge[indice].comm);
}
 
void RechercheAnimal(){
     char nomRecherche[50];
     int espece, age;
     printf("Entrez le nom de l'animal à chercher : \n");
     scanf("%s", nomRecherche);
        if(nomRecherche[0]>='a' || nomRecherche[0]<='z'){
          nomRecherche[0]-=32;
        }
     printf("Quel espèce cherchez-vous ? (0=chien; 1=chat; 2=hamster; 3=autruche; -1=ignorer)\n";
     scanf("%d", &espece);
        while(espece<0 && espece>3){
             printf("Erreur veuillez ressaisir :\n);
             scanf("%d", &espece);
        }
     printf("Le type d'âge ? (1 pour sénior, 2 pour jeune, 3 pour ado) \n");
     scanf("%d", &age);
        while(age=!1 || age=!2 || age=!3){
             printf("Erreur veuillez ressaisir :\n);
             scanf("%d", &age);        
        }
     for (int j = 0; j < 2; j++) {                                       // changer le 2 (nombre d'animal au total
            if (strcmp(refuge[j].nom, nomRecherche) == 0 && refuge[j].espece==espece && (2025-refuge[j].anniv) {                     //comparer le nom avec les animaux du refuge
               printf("Animal trouvé voici les informations : \n");
               AfficheAnimal(j);
               break;
            }
        }

/*void RechercheAnimal(int critere){    
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
          int espece;*/
          
        

      
