#include <stdio.h>
#include <stdlib.h>

typedef enum{
        Chien,Chat,Hamster,Autruche
        }Espece;
        
typedef struct{
        int numero_id;
        char nom[50];
        Espece espece;
        int anniv;
        float poids;
        char comm[500];
        }Animal;
      

