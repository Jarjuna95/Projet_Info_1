#include "projet.h"


void AfficheAnimal(int indice, Animal* refuge){
       printf("\n-------------------------------\n");
       printf("   FICHE DE L'ANIMAL ID: %d\n", refuge[indice].numero_id);
       printf("-------------------------------\n");
       printf("Nom               : %s\n", refuge[indice].nom);
       Affichageespece(refuge[indice].espece);
       printf("Date de naissance : %d\n", refuge[indice].anniv);
       printf("Poids             : %.2f\n", refuge[indice].poids); // pour afficher que deux decimal .2f
       printf("A propos de lui   : %s\n", refuge[indice].comm);
}


void Musique(){
    const char *url = "https://www.youtube.com/watch?v=VEqkflPLVY0&autoplay=1";
    // Commande pour ouvrir le lien dans le navigateur par défaut sous Linux
    char commande[256];
    snprintf(commande, sizeof(commande), "xdg-open %s", url);
    system(commande);
    } //fait avec Chatgpt 


void vide_buffer(){
     while(getchar()!='\n'){
     }
}


void Affichageespece(int espece){
     if(espece==0){
       printf("Espece            : Chien\n");
     }
     else if(espece==1){
       printf("Espece            : Chat\n");
     }
     else if(espece==2){
       printf("Espece            : Hamster\n");
     }
     else if(espece==3){
       printf("Espece            : Dragon\n");
     }
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


void ChargerNvTab(Animal* refuge, int* taille){
     FILE* fichier=fopen("Animal/Animaux.txt", "r");
     if(fichier==NULL){
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(75);
     }
     fscanf(fichier,"%d", taille);
     char ligne[300];
     fgets(ligne, sizeof(ligne), fichier);
     for (int i = 0; i < *taille; i++) {
        fscanf(fichier, "%d %s %d %d %f %s",
               &refuge[i].numero_id, refuge[i].nom, &refuge[i].espece,
               &refuge[i].anniv, &refuge[i].poids, refuge[i].comm);
    }
    for (int i = *taille; i < 50; i++){
        refuge[i].numero_id = 0;
    } //remplir le reste avec des 0

    fclose(fichier);
 }
     

void RechercheAnimal(Animal *refuge){
     char nomRecherche[50];
     int espece, age;
     int ignore = -1;
     int nomincorrect=0;
     printf("Entrez le nom de l'animal à chercher (écrire vide pour ignorer):\n");
     scanf("%s", nomRecherche);
        if(nomRecherche[0]>='a' && nomRecherche[0]<='z'){
          nomRecherche[0]-=32;      
        }
        if(strcmp(nomRecherche, "Vide") == 0){
          ignore=0;
        }
     printf("Quel espèce cherchez-vous ? (0=chien; 1=chat; 2=hamster; 3=dragon; -1=ignorer)\n");
     scanf("%d", &espece);
     vide_buffer();
        while(espece<-1 || espece>3){
             printf("Erreur veuillez ressaisir :\n");
             scanf("%d", &espece);
             vide_buffer();
        }
     printf("Le type d'âge ? (1 pour sénior, 2 pour jeune, 3 pour ado, -1 pour ignorer) \n");
     scanf("%d", &age);
     vide_buffer();
        while(age!=1 && age!=2 && age!=3 && age!=-1){
             printf("Erreur veuillez ressaisir :\n");
             scanf("%d", &age);
             vide_buffer();        
        }      
        for (int j = 0; j <50; j++) {                 
             if (strcmp(refuge[j].nom, nomRecherche) == 0 && refuge[j].espece==espece && Age(j,refuge)==age){                     
                  printf("\nAnimal trouvé voici les informations : \n");
                  AfficheAnimal(j,refuge);
             }
             else if(strcmp(refuge[j].nom, nomRecherche) == 0 && refuge[j].espece==espece && age==-1){
                   printf("\nVoici notre sélection :\n");
                   AfficheAnimal(j,refuge);
             }
             else if(strcmp(refuge[j].nom, nomRecherche) == 0 && espece==-1 && Age(j,refuge)==age){
                   printf("\nVoici notre sélection :\n");
                   AfficheAnimal(j,refuge);
             }
             else if(strcmp(refuge[j].nom, nomRecherche) == 0 && espece==-1 && age==-1){
                   printf("\nVoici notre sélection :\n");
                   AfficheAnimal(j,refuge);
             }
             else if(ignore==0 && refuge[j].espece==espece && Age(j,refuge)==age){
                   printf("\nVoici notre sélection :\n");
                   AfficheAnimal(j,refuge);
             }
             else if(ignore==0 && refuge[j].espece==espece && age==-1){
                   printf("\nVoici notre sélection :\n");
                   AfficheAnimal(j,refuge);
             }
             else if(ignore==0 && espece==-1 && Age(j,refuge)==age){
                   printf("\nVoici notre sélection :\n");
                   AfficheAnimal(j,refuge);
             }
             else if(ignore==0 && espece==-1 && age==-1){
                   printf("\nVoici notre sélection :\n");
                   AfficheAnimal(j,refuge);
             }// condition pour chaque recherche   
              else if(strcmp(refuge[j].nom, nomRecherche) != 0 && strcmp(nomRecherche, "Vide") != 0){
                   nomincorrect=1;     
             }
     }
     if(nomincorrect==1){
        printf("L'animal n'existe pas !\n");
     }
}

void Adoption(Animal *refuge){
      int id=-1;
      int count=0;
      printf("Saisir le numéro d'identification de l'animal à adopter:\n");
      scanf("%d", &id);
      vide_buffer();
      while(id<0){
            printf("Il n'y a pas un numéro d'identification de la sorte ressaisir :\n");
            scanf("%d", &id);
            vide_buffer();
      }
      int trouve=0;
      for(int p=0; p<50; p++){                
          if(refuge[p].numero_id==id){
            trouve=1;
            count=p;
          }
      }
      if(trouve!=1){
        printf("Ce numéro d'identification est invalide\n");
      }
      FILE * ancienf = fopen("Animal/Animaux.txt", "r");
      FILE * nouveauf = fopen("Animal/temporaire.txt", "w"); 
      if(ancienf==NULL || nouveauf==NULL){
    	printf("Erreur \n");
        exit(50);
      }
      
      int size;
           fscanf(ancienf,"%d", &size)==1;
           size-=1;
           fprintf(nouveauf,"%d\n", size);   // retire 1 dans le fichier txt    


      char ligne[300];
      fgets(ligne, sizeof(ligne), ancienf); //saute la premiere ligne deja lu
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
      printf("%s a été adopté est son ID est %d a été adopté avec succès.\n", refuge[count].nom,id);// probleme affichage
} 


void Menu(Animal* refuge){
        int continuer;
        int choix;
        int size=0;
        ChargerNvTab(refuge, &size);
        printf("\n---------Menu---------\n");
        printf("1-Cherchez un animal\n");
        printf("2-Ajoutez un animal\n");
        printf("3-Adoptez un animal\n");
        printf("4-Nourriture nécessaire à tous les animaux\n");
        printf("------------------------\n");
        printf("Saisissez votre choix :\n");
        scanf("%d", &choix);
        vide_buffer(); // eviter infini
        while(choix<1 || choix>4){
           printf("Erreur dans la saisie, veuillez ressaisir un chiffre :\n");
           scanf("%d", &choix);
           vide_buffer();
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
        else if(choix==4){
           Day_Food(refuge);
        }

        ChargerNvTab(refuge, &size);


        printf("\nVous voulez vous continuer vos recherches ? (1=oui et 0 =non) \n");
        scanf("%d", &continuer);
        vide_buffer();
        while(continuer!=1 && continuer!=0){
             printf("Erreur dans la saisie, veuillez ressaisir un chiffre :\n");
             scanf("%d", &continuer);
             vide_buffer();
        } 
        if(continuer==0){
          printf("Merci d'être passer par notre refuge !\n"); 
          return ;
        }
        else{
          Menu(refuge);
        }
}


void Day_Food(Animal refuge[]){
    float croq;
    for(int i=0; i<50;i++){
        if(refuge[i].espece==2){
            printf("\n-------------------------------\n");
            printf("  FICHE DE L'ANIMAL ID: %d\n", refuge[i].numero_id);
            printf("-------------------------------\n");
            printf("%s a besoin de 20g de croquettes par jour.\n", refuge[i].nom);
        }
        else if(refuge[i].espece==3){
            printf("\n-------------------------------\n");
            printf("   FICHE DE L'ANIMAL ID: %d\n", refuge[i].numero_id);
            printf("-------------------------------\n"); 
            printf("%s a besoin de 2.5kg de croquettes par jour.\n", refuge[i].nom);
        }
        else if(refuge[i].espece==0||refuge[i].espece==1){
            if(Age(i,refuge)==2){
                if(refuge[i].espece==0){
                   printf("\n-------------------------------\n");
                   printf("   FICHE DE L'ANIMAL ID: %d\n", refuge[i].numero_id);
                   printf("-------------------------------\n"); 
                   printf("%s a besoin de 500g de croquettes par jour.\n", refuge[i].nom);
            }
            else{
                printf("\n-------------------------------\n");
                printf("   FICHE DE L'ANIMAL ID: %d\n", refuge[i].numero_id);
                printf("-------------------------------\n"); 
            	printf("%s a besoin de 500g de croquettes par jour.\n", refuge[i].nom);
            }
            }
            else{
                croq=refuge[i].poids*0.1;
                if(refuge[i].espece==0){
                   printf("\n-------------------------------\n");
                   printf("   FICHE DE L'ANIMAL ID: %d\n", refuge[i].numero_id);
                   printf("-------------------------------\n") ;
                   printf("%s a besoin de %f g de croquettes par jour.\n", refuge[i].nom,croq);
            }
            else{
                 printf("\n-------------------------------\n");
                 printf("   FICHE DE L'ANIMAL ID: %d\n", refuge[i].numero_id);
                 printf("-------------------------------\n");
                 printf("%s a besoin de %f g de croquettes par jour.\n", refuge[i].nom,croq);
                }
            }
        }
  }
}


Animal Ajouter(Animal refuge[]) {
    Animal a;
    int trouve = 0; //verifie qu il y a de la place dans le refuge

    printf("Quelle est l'espèce de votre animal qui a été confié? (0=Chien, 1=Chat, 2=Hamster,3= Autruche)\n");
    scanf("%d",& a.espece);
    vide_buffer();
    while(a.espece<-1 && a.espece>3){
             printf("Erreur veuillez ressaisir :\n");
             scanf("%d", &a.espece);
             vide_buffer();
    }          
                  
    printf("Quelle est le nom de l'animal ?\n");
    scanf("%s",a.nom);
    if(a.nom[0]>='a' && a.nom[0]<='z'){
          a.nom[0]-=32;      
    }

    printf("Quel est le poids de l'animal ?\n");
    scanf("%f", &a.poids);
    vide_buffer();
    while(a.poids<0){
             printf("Erreur veuillez ressaisir :\n");
             scanf("%f", &a.poids);
             vide_buffer();        
    }      

    printf("Quelle est l'année de naissance ?\n");
    scanf("%d", &a.anniv);
    vide_buffer();
    while(a.anniv<0){
          printf("Erreur veuillez ressaisir :\n");
          scanf("%d", &a.anniv); 
          vide_buffer();       
    }

    printf("Quelle est la caractéristique ?\n");
    scanf("%s", a.comm);

    for (int i = 0; i < 50; i++) {
         if (refuge[i].numero_id == 0) { // une place libre
            a.numero_id = 1+rand()%50;
              for(int j=0; j<50;j++){
                 if(refuge[j].numero_id==a.numero_id){
                    a.numero_id = 1+rand()%50;
                 }
              }
            refuge[i] = a;
            trouve = 1;

            FILE * ancienf = fopen("Animal/Animaux.txt", "r");
            FILE * nouveauf = fopen("Animal/temporaire.txt", "w"); 
            if(ancienf==NULL || nouveauf==NULL){
    	       printf("Erreur \n");
               exit(51);
            }
      
            int size;
            fscanf(ancienf,"%d", &size)==1;
            size+=1;
            fprintf(nouveauf,"%d\n", size); // rajoute +1 dans la premier ligne du txt

            char ligne[300];
            fgets(ligne, sizeof(ligne), ancienf); //saute la premiere ligne deja lu
            while(fgets(ligne, sizeof(ligne), ancienf)){
                 fputs(ligne,nouveauf); // recopie ancien fichier dans le nouveau
            }
 
            fprintf(nouveauf, "%d %s %d %d %f %s\n",
                    a.numero_id, a.nom, a.espece, a.anniv, a.poids, a.comm);
            fclose(ancienf);
            fclose(nouveauf);
            remove("Animal/Animaux.txt");
            rename("Animal/temporaire.txt", "Animal/Animaux.txt");


            printf("Animal ajouté avec succès !\n");
            return a;
        }
    }

    if (trouve!=1) {
        printf("Erreur : le refuge est plein.\n");
    }
    return a;
  }
