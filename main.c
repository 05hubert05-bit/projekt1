#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Implant {
    char owner_id[50];
    char name[100];
    char manufacturer[100];
    int risk_level;
    float energy_demand;
    char status[20];

} Implant;
int showMenu()
{
    int wybor;
    printf("\n===MENU===\n");
    printf("1)dodaj\n");
    printf("2)usun\n");
    printf("3)modifikuj\n");
    printf("4)sortuj\n");
    printf("5)wyszukaj\n");
    printf("6)\n");
         if(scanf("%d",&wybor)!=1 || wybor<1 || wybor>7)
         {
             printf("Wprowadz poprawna wartosc\n");
          while ((getchar()) != '\n');
         }
         else{
            return wybor;
         }
}
int main() {
    int menu=1;
    int wybor;
       while(menu==1){
         wybor=showMenu();
       }
}