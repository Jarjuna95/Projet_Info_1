#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum{
        chien,chat,hamster,dragon
        }Espece;
        
typedef struct{
        int numero_id;
        char nom[50];
        Espece espece;
        int anniv;
        float poids;
        char comm[500];
        }Animal;

void RechercheAnimal(Animal *refuge);
void Musique();
void Affichageespece(int espece);
int Age(int h, Animal *refuge);
void ChargerNvTab(Animal* refuge, int* taille);
void AfficheAnimal(int indice, Animal* refuge);
void Adoption(Animal *refuge);
void Day_Food(Animal refuge[]);
Animal Ajouter(Animal refuge[]); 
void Menu(Animal* refuge);     
