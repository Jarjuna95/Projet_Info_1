#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
        chien,chat,hamster,autruche
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
int Age(int h, Animal *refuge);
void AfficheAnimal(int indice, Animal* refuge);
      

