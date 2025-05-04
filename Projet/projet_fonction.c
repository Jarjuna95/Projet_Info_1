#include "projet.h"


void AfficheAnimal(int indice, Animal* refuge){
        printf("%d, %s, %d, %d, %f, %s \n", refuge[indice].numero_id, refuge[indice].nom, refuge[indice].espece, refuge[indice].anniv, refuge[indice].poids, refuge[indice].comm);
}
 

int Age(int h, Animal *refuge){
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


void RechercheAnimal(Animal *refuge){
     char nomRecherche[50];
     int espece, age;
     printf("Entrez le nom de l'animal à chercher (laissez vide pour ignorer):\n");
     scanf("%s", nomRecherche);
        if(nomRecherche[0]>='a' || nomRecherche[0]<='z'){
          nomRecherche[0]-=32;
        }
     printf("Quel espèce cherchez-vous ? (0=chien; 1=chat; 2=hamster; 3=autruche; -1=ignorer)\n");
     scanf("%d", &espece);
        while(espece<-1 || espece>3){
             printf("Erreur veuillez ressaisir :\n");
             scanf("%d", &espece);
        }
     printf("Le type d'âge ? (1 pour sénior, 2 pour jeune, 3 pour ado, -1 pour ignorer) \n");
     scanf("%d", &age);
        while(age!=1 && age!=2 && age!=3 && age!=-1){
             printf("Erreur veuillez ressaisir :\n");
             scanf("%d", &age);        
        }      
        for (int j = 0; j < 2; j++) {             // changer le 2 (nombre d'animal au total     
             if (strcmp(refuge[j].nom, nomRecherche) == 0 && refuge[j].espece==espece && Age(j,refuge)==age){                     
                  printf("Animal trouvé voici les informations : \n");
                  AfficheAnimal(j,refuge);
             }
             else if(strcmp(refuge[j].nom, nomRecherche) == 0 && refuge[j].espece==espece && age==-1){
                   printf("Voici notre sélection :\n");
                   AfficheAnimal(j);
             }
             else if(strcmp(refuge[j].nom, nomRecherche) == 0 && espece==-1 && Age(j,refuge)==age){
                   printf("Voici notre sélection :\n");
                   AfficheAnimal(j);
             }
             else if(strcmp(refuge[j].nom, nomRecherche) == 0 && espece==-1 && age==-1){
                   printf("Voici notre sélection :\n");
                   AfficheAnimal(j);
             }
             else if(nomRecherche[0]== ' ' && refuge[j].espece==espece && Age(j,refuge)==age){
                   printf("Voici notre sélection :\n");
                   AfficheAnimal(j);
             }
             else if(nomRecherche[0]== ' ' && refuge[j].espece==espece && age==-1){
                   printf("Voici notre sélection :\n");
                   AfficheAnimal(j);
             }
             else if(nomRecherche[0]== ' ' && espece==-1 && Age(j,refuge)==age){
                   printf("Voici notre sélection :\n");
                   AfficheAnimal(j);
             }
             else if(nomRecherche[0]== ' ' && espece==-1 && age==-1){
                   printf("Voici notre sélection :\n");
                   AfficheAnimal(j);
             }             
             /*else{
                   printf("Les critères saisies ne correspondent à aucun animal.\n");
             }*/
         }
     }

void Adoption(Animal *refuge){
      int id;
      printf("Saisir le numéro d'identification de l'animal à adopter:\n");
      scanf("%d", &id);
      while(id<0){
            printf("Il n'y a pas un numéro d'identification de la sorte ressaisir :\n");
            scanf("%d", &id);
      }
      int trouve=0;
      for(int p=0; p<2; p++){                //changer le 2 plus tard
          if(refuge[p].numero_id==id){
            trouve=1;
          }
      }
      if(trouve!=1){
        printf("Ce numéro d'identification est invalide\n");
      }
      FILE * ancienf = fopen("Animal/Animaux.txt", "r");
      FILE * nouveauf = fopen("Animal/temporaire.txt", "w"); 
      if(ancienf==NULL || nouveauf==NULL){
    	printf("Erreur \n");
        exit(5);
      }
      char ligne[2];
      while(fgets(ligne, sizeof(ligne), ancienf)){
           int id_fichier;
           sscanf(ligne, "%d", &id_fichier);
        if (id_fichier != id) {
            fputs(ligne, nouveauf);
        }
      }
      fclose(ancienf);
      fclose(tempf);
      remove("Animal/Animaux.txt");
      rename("Animal/temporaire.txt", "Animal/Animaux.txt");
      printf("L'animal %d a été adopté avec succès.\n", id);
}   

void Menu(int choix, Animal* refuge){
        int continuer;
        if(choix==1){
           RechercheAnimal(refuge);
        }
        else if(choix==2){
          Ajouter(refuge);
        }
        else if(choix==3){
          Adoption(refuge);
        }
        printf("Vous voulez vous continuer vos recherches ? \n
      
