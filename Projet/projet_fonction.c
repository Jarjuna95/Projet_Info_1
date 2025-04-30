#include "projet.h"

void AfficheAnimal(int indice){
        printf("%d, %s, %d, %d, %f, %s \n", refuge[indice].numero_id, refuge[indice].nom, refuge[indice].espece, refuge[indice].anniv, refuge[indice].poids, refuge[indice].comm);
}
 
int Age(int h){
        if(2025-refuge[h].anniv>2){
                  return 2;
          }
          else if(2025-refuge[h].anniv<10){
                  return 1;
          }
          else{
                  return 3;
          }
   }
}





void RechercheAnimal(){
     char nomRecherche[50];
     int espece, age;
     printf("Entrez le nom de l'animal à chercher (laissez vide pour ignorer):\n");
     scanf("%s", nomRecherche);
        if(nomRecherche[0]>='a' || nomRecherche[0]<='z'){
          nomRecherche[0]-=32;
        }
     printf("Quel espèce cherchez-vous ? (0=chien; 1=chat; 2=hamster; 3=autruche; -1=ignorer)\n";
     scanf("%d", &espece);
        while(espece<0 && espece>3){
             printf("Erreur veuillez ressaisir :\n");
             scanf("%d", &espece);
        }
     printf("Le type d'âge ? (1 pour sénior, 2 pour jeune, 3 pour ado) \n");
     scanf("%d", &age);
        while(age=!1 || age=!2 || age=!3){
             printf("Erreur veuillez ressaisir :\n");
             scanf("%d", &age);        
        }
     if(espece==-1 && nomRecherche[0]==''){                        // si y'a pas de critère a part l'age
        printf("Voici notre sélection :\n");
           for (int k= 0; k < 2; k++) {                            //changer le 2
                AfficheAnimal(j);
           }
     }
     else if(              ){
        
         for (int j = 0; j < 2; j++) {                                       // changer le 2 (nombre d'animal au total     
              if (strcmp(refuge[j].nom, nomRecherche) == 0 && refuge[j].espece==espece && Age(j)==age){                     //comparer le nom avec les animaux du refuge
                  printf("Animal trouvé voici les informations : \n");
                  AfficheAnimal(j);
              }
          }
           printf("Non trouvé" \n);
     }


        

      
