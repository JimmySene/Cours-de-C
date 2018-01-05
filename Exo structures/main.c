#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*struct eleves
{
    char nom[20];
    int age;;
    float salaire;
};*/

struct client
{
    char idc[20];
    char nom[20];
    int cp;
};

struct commande
{
    char idco[20];
    char idc[20];
    float tot;
};

int main()
{
    /*

    ================= EXO 1 ==================

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

     ================= EXO 2 ================== */

     struct client cli[] = {"01", "dupont", 75000, "02", "jimmy", 93200};
     struct commande com[] = {"01","01",80,"02", "01", 120, "03", "01", 26, "04", "02", 300, "05", "02", 67};

     char nom[20];
     int i, j, trouve = 0, total = 0;

     do
     {
         printf("Entrez un nom : ");
         gets(nom);

         for(i = 0; i < 2; i++)
         {
             if(strcmp(nom, cli[i].nom)==0)
             {
                for(j = 0; j<5;j++)
                {
                    if(strcmp(cli[i].idc, com[j].idc) == 0)
                    {
                        total = total + com[j].tot;
                    }
                }
                printf("Le cout total des commandes de %s est de %d euros !", nom, total);
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
