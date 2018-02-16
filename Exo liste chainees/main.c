#include<stdlib.h>
#include<stdio.h>
struct personne{
  char nom[20];
  int age;
  float salaire;
  struct personne *next;
};

main()
{

    struct personne *start, *pc, *end;
    int i;
    pc = (struct personne *)malloc(sizeof(struct personne));
    start = pc;
    strcpy(pc->nom, "dupont");
    pc->age = 25;
    pc->salaire = 2500;
    pc->next = NULL;
    end = pc;

for(i=0; i<2; i++){
    pc = (struct personne *)malloc(sizeof(struct personne));
    end->next = pc;
    printf("Le nom : ");
    fflush(stdin);
    gets(pc->nom);
    printf("L'age : ");
    scanf("%d",&pc->age);
    printf("Le salaire : ");
    scanf("%f",&pc->salaire);
    pc->next = NULL;
    end = pc;
}
pc = start;
end = pc;
while(end->next != NULL)
{
    printf("\n%s", pc->nom);
    end = pc;
    pc = pc->next;
}



}
