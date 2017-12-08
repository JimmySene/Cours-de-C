#include <stdio.h>
#include <stdlib.h>
#include <myconio.h>
void initTab(int tab[12][12])
{
    int i, j;
    for(i=0; i<12; i++)
    {
        for(j=0; j<12; j++)
        {
            tab[i][j] = 0;
        }
    }
}
void placerMines(int tab[12][12])
{
    int x, y, i;
    srand(time(NULL));
    for(i = 0; i < 10; i++)
    {
        x = rand()% 10 + 1;
        y = rand()% 10 + 1;
        if(tab[x][y] == 9) i--;
        tab[x][y] = 9;
    }
}

void afficheTab(int tab[12][12]){
    int i, j;
    for(i=1; i<11; i++)
    {
        for(j=1; j<11; j++)
        {
            if(tab[i][j] == 0)
            {
               printf("-");
            } else {
            printf("%d", tab[i][j]);
            } //printf("-");
        }
        printf("\n");
    }
}

void fouillerTab(int tab[12][12], int tabVerif[12][12], int x, int y, int *perdu)
{
    int compteur = 0;

    if(tab[y][x] == 9)
    {
        gotoxy(12,12);
        printf("Vous avez perdu !");
        gotoxy(x,y);
        *perdu = 1;
    } else {
        if(tab[y-1][x-1] == 9)
        {
            compteur++;
        }
        if(tab[y-1][x] == 9)
        {
            compteur++;
        }
        if(tab[y-1][x+1] == 9)
        {
            compteur++;
        }
        if(tab[y][x+1] == 9)
        {
            compteur++;
        }
        if(tab[y+1][x+1] == 9)
        {
            compteur++;
        }
        if(tab[y+1][x] == 9)
        {
            compteur++;
        }
        if(tab[y+1][x-1] == 9)
        {
            compteur++;
        }
        if(tab[y][x-1] == 9)
        {
            compteur++;
        }
        tab[y][x] = compteur;
        tabVerif[y][x] = 1;
    }
    gotoxy(x-1,y-1);
    if(tab[y][x] == 0)
    {
        printf("0");
    }
    else{
    printf("%d", tab[y][x]);
    }
    gotoxy(x-1,y-1);
}

int main()
{
    int x = 0, y = 0, i, j, compteur = 0, perdu = 0;
    int tab[12][12];
    int tabVerif[12][12];
    char touche;

    initTab(tab);
    initTab(tabVerif);
    placerMines(tab);
    afficheTab(tab);


    gotoxy(0,0);

    do
    {
        touche = getch();
        if(touche == -32)
        {

            touche = getch();
            if(touche == 72)
            {
                if(y > 0) { y--; }
            }
            else if(touche == 80)
            {
                if(y < 9) { y++; }

            }

            else if(touche == 77)
            {
                if(x < 9) { x++; }
            } else
            {
                if(x > 0) { x--; }
            }
        gotoxy(x,y);
        }
        else if(touche == 102)
        {
            fouillerTab(tab, tabVerif, x + 1, y + 1, &perdu);

            for(i=1; i<11; i++)
            {
                for(j=1; j<11; j++)
                {
                    if(tabVerif[i][j] != 0)
                    {
                        compteur++;
                    }
                }
            }


            if(compteur >= 90)
            {
                gotoxy(12,12);
                printf("\nVOUS AVEZ GAGNE !!!!!!!!!!");
                break;
            }
            compteur = 0;
        }


    }while(touche != 27 && perdu == 0);

    return 0;
}

