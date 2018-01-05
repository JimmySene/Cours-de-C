#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct eleves
{
    char nom[20];
    int age;
    float salaire;
};

int main()
{
    int i;
    char nom[20];
    int trouve = 0;

    struct eleves sio1[] = {"dupont", 25, 3789.25, "leroy", 36, 1250.30};
    do
    {
        printf("Entrez un nom : ");
        gets(nom);
        for(i = 0; i < 2; i++)
        {
            if(strcmp(nom, sio1[i].nom) == 0)
            {
                printf("Le salaire de %s est : %.2f €", nom, sio1[i].salaire);
                trouve = 1;
                break;
            }
        }

        if(trouve == 0)
        {
           printf("Ce nom n'existe pas !");
        }
    }while(trouve == 0);



    return 0;
}
