#include "projet.h"


void AfficheAnimal(int indice, Animal* refuge){
        printf("%d, %s, %d, %d, %f, %s \n", refuge[indice].numero_id, refuge[indice].nom, refuge[indice].espece, refuge[indice].anniv, refuge[indice].poids, refuge[indice].comm);
}
 

int Age(int h, Animal *refuge){
        if(2025-refuge[h].anniv<2){
                  return 2;
          }
        else if(2025-refuge[h].anniv>10){
                  return 1;
          }
        else{
                  return 3;
          }
   }


void RechercheAnimal(Animal *refuge){
     char nomRecherche[50];
     int espece, age;
     int ignore = -1;
     printf("Entrez le nom de l'animal à chercher (laissez vide pour ignorer):\n");
     scanf("%s", nomRecherche);
        if(nomRecherche[0]>='a' || nomRecherche[0]<='z'){
          nomRecherche[0]-=32;      
        }
        if(strcmp(nomRecherche, "Vide") == 0){
          ignore=0;
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
        for (int j = 0; j <50; j++) {             // changer le 2 (nombre d'animal au total     
             if (strcmp(refuge[j].nom, nomRecherche) == 0 && refuge[j].espece==espece && Age(j,refuge)==age){                     
                  printf("Animal trouvé voici les informations : \n");
                  AfficheAnimal(j,refuge);
             }
             else if(strcmp(refuge[j].nom, nomRecherche) == 0 && refuge[j].espece==espece && age==-1){
                   printf("Voici notre sélection :\n");
                   AfficheAnimal(j,refuge);
             }
             else if(strcmp(refuge[j].nom, nomRecherche) == 0 && espece==-1 && Age(j,refuge)==age){
                   printf("Voici notre sélection :\n");
                   AfficheAnimal(j,refuge);
             }
             else if(strcmp(refuge[j].nom, nomRecherche) == 0 && espece==-1 && age==-1){
                   printf("Voici notre sélection :\n");
                   AfficheAnimal(j,refuge);
             }
             else if(ignore==0 && refuge[j].espece==espece && Age(j,refuge)==age){
                   printf("Voici notre sélection :\n");
                   AfficheAnimal(j,refuge);
             }
             else if(ignore==0 && refuge[j].espece==espece && age==-1){
                   printf("Voici notre sélection :\n");
                   AfficheAnimal(j,refuge);
             }
             else if(ignore==0 && espece==-1 && Age(j,refuge)==age){
                   printf("Voici notre sélection :\n");
                   AfficheAnimal(j,refuge);
             }
             else if(ignore==0 && espece==-1 && age==-1){
                   printf("Voici notre sélection :\n");
                   AfficheAnimal(j,refuge);
             }  // a verifier        
             else{
                   printf("Les critères saisies ne correspondent à aucun animal.\n");
             }
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
      for(int p=0; p<50; p++){                //changer le 2 plus tard
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
      char ligne[300];
      while(fgets(ligne, sizeof(ligne), ancienf)){
           int id_fichier;
           sscanf(ligne, "%d", &id_fichier);
        if (id_fichier != id) {
            fputs(ligne, nouveauf);
        }
      }
      fclose(ancienf);
      fclose(nouveauf);
      remove("Animal/Animaux.txt");
      rename("Animal/temporaire.txt", "Animal/Animaux.txt");
      printf("L'animal %d a été adopté avec succès.\n", id);
}   //verifier car marche une fois sur deux

void Menu(Animal* refuge){
        int continuer;
        int choix;
        printf("Tapez 1 si vous voulez recherchez un animal, 2 pour ajoutez un animal et 3 pour adoptez un animal :"\n)
        scanf("%d", &choix);
        while(choix<1 || choix>3){
           printf("Erreur dans la saisie, veuillez ressaisir un chiffre :\n");
           scanf("%d", &choix);
        } 
        if(choix==1){
           RechercheAnimal(refuge);
        }
        else if(choix==2){
           Ajouter(refuge);
        }
        else if(choix==3){
           Adoption(refuge);
        }
        printf("Vous voulez vous continuer vos recherches ? (1=oui et 0 =non) \n");
        scanf("%d", &continuer);
        while(continuer!=1 && continuer!=0){
             printf("Erreur dans la saisie, veuillez ressaisir un chiffre :\n");
             scanf("%d", &contiuer);
        } 
        if(continuer==0){
          return ;
        }
        else{
          Menu(refuge);
        }
}

void Day_Food(Animal refuge[],int nb_animaux){
    float croq;
    for(int i=0; i<nb_animaux;i++){
        if(refuge[i].espece==2){
            printf("L'hamster a besoin de 20g de croquettes par jour.\n");
        }
        else if(refuge[i].espece==3){
            printf("L'autruche a besoin de 2.5kg de croquettes par jour.\n");
        }
        else if(refuge[i].espece==0||refuge[i].espece==1){
            if(Age(i,refuge)==2){
                if(refuge[i].espece==0){
                printf("Le chien a besoin de 500g de croquettes par jour.\n");
            }
            else{
            	printf("Le chat a besoin de 500g de croquettes par jour.\n");
            }
            }
            else{
                croq=refuge[i].poids*0.1;
                if(refuge[i].espece==0){
                printf("Le chien a besoin de %f g de croquettes par jour.\n",croq);
            }
                else{
                printf("Le chat a besoin de %f g de croquettes par jour.\n",croq);
                }
            }
        }
  }
}
/*Animal Ajouter(Animal refuge[]) {
Animal a;
int trouve = 0; //verifie qu il y a de la place dans le refuge

printf("Quelle est l'espèce de votre animal qui a été confié? (0=Chien, 1=Chat, 2=Hamster,3= Autruche)\n");
scanf("%d",& a.espece);
 
printf("Quelle est le nom de l'animal ?\n");
scanf("%s",a.nom);

printf("Quel est le poids de l'animal ?\n");
scanf("%f", &a.poids);

printf("Quelle est l'année de naissance ?\n");
scanf("%d", &a.anniv);

printf("Quelle est la caractéristique ?\n");
scanf("%s", a.comm);

  for (int i = 0; i < 50; i++) {
        if (refuge[i].numero_id == 0) { // une place libre
            a.numero_id = i + 1;
            refuge[i] = a;
            trouve = 1;

            FILE* fichier = fopen("Animal/Animaux.txt", "a"); // on ajoute à la fin du fichier
            if (fichier == NULL) {
                printf("Erreur lors de l'ouverture du fichier.\n");
                exit(1);
            }

            fprintf(fichier, "%d %s %d %d %.f %s\n",
                    a.numero_id, a.nom, a.espece, a.anniv, a.poids, a.comm);
            fclose(fichier);
            printf("Animal ajouté avec succès !\n");
            return a;
        }
    }

    if (!trouve) {
        printf("Erreur : le refuge est plein.\n");
    }

    return a;
} 
*/
