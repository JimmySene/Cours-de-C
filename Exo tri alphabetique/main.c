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

       char nom1[20];
       char nom2[20];

       int taille1 = 0;
       int taille2 = 0;
       int compare = 0;
       int i;

       printf("Saisissez un premier nom : ");
       gets(nom1);
       printf("Saisissez un deuxieme nom : ");
       gets(nom2);

       taille1 = strlen(nom1);
       taille2 = strlen(nom2);

       if(taille1>taille2)
       {
           compare = taille2;
       } else
       {
           compare = taille1;
       }

       printf("Affichage par ordre alphabetique : \n");

        for(i = 0; i <= compare; i++)
        {
            if(nom1[i] > nom2[i])
            {
                printf("%s \n", nom2);
                printf("%s", nom1);
                break;
            } else if(nom1[i] < nom2[i]) {
                printf("%s \n", nom1);
                printf("%s", nom2);
                break;
            }


        }

    return 0;
}
