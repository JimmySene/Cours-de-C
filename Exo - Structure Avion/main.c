#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Avion {
    char refAvion[20];
    char libelle[20];
    int nbPlaces;
};

struct Place {
    char refAvion[20];
    int idVoyageur;
    int placeReservee;
};

int main()
{
    char ref[20];
    int nbPlaces = 0, trouve = 0;
    int i;
    struct Avion avions[] = {"A380EF", "Hatim", 380, "A380TI", "Andy", 400};
    struct Place places[] = {"A380EF",34,228, "A380EF", 149, 150, "A380EF", 11, 78, "A380TI", 47, 22};
    printf("Entrez une reference : ");

    do
    {

        gets(ref);

        for(i = 0; i < 2; i++)
        {
            if(strcmp(avions[i].refAvion, ref) == 0)
            {
                trouve = 1;
                nbPlaces = avions[i].nbPlaces;
                break;
            }
        }
        if(trouve == 0)
        {
            printf("Cet avion n'existe pas.");
        }
    }while(trouve == 0);

    for(i = 0; i < 4; i++)
    {
        if(strcmp(places[i].refAvion, ref)==0)
        {
            nbPlaces -= 1;
        }
    }

    printf("Il reste %d places dans cet avion.", nbPlaces);

    return 0;
}
