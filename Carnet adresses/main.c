#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact Contact;
struct Contact {
    char nom[20];
    char prenom[20];
    char mail[50];
    char tel[10];
    Contact *next;
};

typedef struct Carnet Carnet;
struct Carnet {
    Contact *start;
};

Carnet* construire_carnet() // CONSTRUIT UN CARNET ET ALLOUE SA MEMOIRE
{
    Carnet *carnet = (Carnet*)malloc(sizeof(Carnet));
    carnet->start = NULL;
    return carnet;
}

Contact* creer_contact() // CREER UN CONTACT ET ALLOUE SA MEMOIRE
{
    Contact *contact = (Contact*)malloc(sizeof(Contact));
    return contact;
}

void afficher_contact(Carnet *carnet) // AFFICHE LA LISTE DES CONTACTS
{
    int i = 0;
    Contact *actuel = carnet->start;
    while(actuel != NULL)
    {
        i++;
        printf("Contact %d : %s %s %s %s \n", i, actuel->nom, actuel->prenom, actuel->mail, actuel->tel);
        actuel = actuel->next;
    }
}

void ajouter_contact(Carnet *carnet) // PERMET D'AJOUTER UN CONTACT
{

    Contact *newContact = creer_contact();

    printf("\n=== AJOUTEZ UN CONTACT ===\n");
    printf("Entrez un nom : ");
    scanf("%s", newContact->nom);

    printf("Entrez un prenom : ");
    scanf("%s", newContact->prenom);

    printf("Entrez une adresse mail : ");
    scanf("%s", newContact->mail);

    printf("Entrez un numero de tel : ");
    scanf("%s", newContact->tel);

    printf("Vous avez ajoute le contact suivant : %s %s %s %s", newContact->nom, newContact->prenom, newContact->mail, newContact->tel);

    newContact->next = carnet->start;
    carnet->start = newContact;

}

struct Contact rechercher_contact(Carnet *carnet) // PERMET DE RECHERCHER UN CONTACT
{
    char saisie[20];
    int trouve = 0;

    printf("Entrez le nom du contact que vous recherchez : ");
    scanf("%s", saisie);


    Contact *actuel = carnet->start;
    while(actuel != NULL)
    {
        if(strcmp(saisie, actuel->nom)==0)
        {
            printf("Votre contact : %s %s %s %s \n", actuel->nom, actuel->prenom, actuel->mail, actuel->tel);
            trouve = 1;
        }

        actuel = actuel->next;
    }

    if(!trouve)
    {
        printf("Aucun contact ne porte ce nom !");
    }


}

void modifier_contact(Carnet *carnet) // PERMET DE MODIFIER LES INFORMATIONS D'UN CONTACT
{
    char saisie[20];
    int trouve = 0;

    printf("\n=== MODIFIER UN CONTACT ===\n");
    printf("Entrez le nom du contact que vous voulez modifier :\n ");
    scanf("%s", saisie);


    Contact *actuel = carnet->start;
    while(actuel != NULL)
    {
        if(strcmp(saisie, actuel->nom)==0)
        {

            printf("Entrez un nom : ");
            scanf("%s", actuel->nom);

            printf("Entrez un prenom : ");
            scanf("%s", actuel->prenom);

            printf("Entrez une adresse mail : ");
            scanf("%s", actuel->mail);

            printf("Entrez un numero de tel : ");
            scanf("%s", actuel->tel);

            printf("Votre contact est bien modifie : %s %s %s %s \n", actuel->nom, actuel->prenom, actuel->mail, actuel->tel);
            trouve = 1;
        }

        actuel = actuel->next;
    }

    if(!trouve)
    {
        printf("Aucun contact ne porte ce nom !");
    }

}

void supprimer_contact(Carnet *carnet) // PERMET DE SUPPRIMER UN CONTACT EXISTANT
{
    char saisie[20];
    int trouve = 0;

    printf("Entrez le nom du contact que vous voulez supprimer : ");
    scanf("%s", saisie);


    Contact *actuel = carnet->start;
    Contact *precedent = NULL;


    while(actuel != NULL)
    {
        if(strcmp(saisie, actuel->nom)==0)
        {
            printf("Le contact : %s %s %s %s a bien ete supprime. \n", actuel->nom, actuel->prenom, actuel->mail, actuel->tel);
            trouve = 1;
            if(actuel == carnet->start)
            {
                carnet->start = actuel->next;
            } else {
            precedent->next = actuel->next; }
            break;

        }
        precedent = actuel;
        actuel = actuel->next;

    }

    if(!trouve)
    {
        printf("Aucun contact ne porte ce nom !");
    }
}

int main()
{

    int choix_utilisateur = 0, sortie = 0;

    Carnet *carnet = construire_carnet();

    do
    {

        printf("\n========== CARNET D'ADRESSE ==========\n");
        printf("1 - Afficher la liste \n");
        printf("2 - Ajouter contact \n");
        printf("3 - Rechercher contact \n");
        printf("4 - Modifier contact \n");
        printf("5 - Supprimer contact \n");

        printf("Que voulez-vous faire ?");
        scanf("%d", &choix_utilisateur);


        switch(choix_utilisateur)
        {
            case 1:
                afficher_contact(carnet);
                break;
            case 2:
                ajouter_contact(carnet);
                break;
            case 3:
                rechercher_contact(carnet);
                break;
            case 4:
                modifier_contact(carnet);
                break;
            case 5:
                supprimer_contact(carnet);
                break;
            default:
                printf("Vous n'avez pas entre un nombre correct !");
                break;
        }
    }while(sortie == 0);




    return 0;
}


