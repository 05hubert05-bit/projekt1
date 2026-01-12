#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Implant {
    char id[100];
    char nazwa[100];
    char producent[100];
    int ryzyko;
    float energia;
    char status[20];
    struct Implant* next;
} Implant;
int showMenu()
{
    int wybor;
    printf("\n===MENU===\n");
    printf("1)Zarejestruj nowy implant\n");
    printf("2)Lista wszystkich implantow\n");
    printf("3)Edytuj dane implantu\n");
    printf("4)Usuń implant(ID)\n");
    printf("5)Usuń wiele\n");
    printf("6)Wyszukaj\n");
    printf("7. Sortuj\n");
    printf("8. Zapisz zmiany do pliku\n");
    printf("0. Wyjście z systemu\n");
         if(scanf("%d",&wybor)!=1 || wybor<0 || wybor>8)
         {
             printf("Wprowadz poprawna wartosc\n");
          while ((getchar()) != '\n');
         }
         else{
            return wybor;
         }
}
Implant* Nowyimplant(char* id,char* nazwa,char* producent,int ryzyko,float energia,char* status)
{
    Implant* nowy = calloc(1, sizeof(Implant));
    strncpy(nowy->id, id,99);
    strncpy(nowy->nazwa, nazwa,99);
    strncpy(nowy->producent, producent,99);
    nowy->ryzyko = ryzyko;
    nowy->energia = energia;
    strncpy(nowy->status, status,19);
    nowy->next = NULL;
    return nowy;
    
}
void Dodaj_implant(Implant** head) {
    char id[50], nazwa[100], producent[100], status[20];
    int ryzyko; float energia;

    printf("ID Wlasciciela: "); scanf("%s", id);
    printf("Nazwa implantu: "); scanf("%s", nazwa);
    printf("Producent: "); scanf("%s", producent);
    printf("Ryzyko (0-10): "); scanf("%d", &ryzyko);
    printf("Energia: "); scanf("%f", &energia);
    printf("Status: "); scanf("%s", status);

    Implant* nowy = Nowyimplant(id, nazwa, producent, ryzyko, energia, status);
    nowy->next = *head; 
    *head = nowy;
}
void wyswietl(Implant* head) {

    Implant* p = head;

    while (p != NULL) {
     
        printf("%s\n ", p->id);
        printf("%s\n ", p->nazwa);
           printf("%s\n", p->producent);
             printf("%d\n", p->ryzyko);
            printf("%.2f\n", p->energia);
             printf("%s\n", p->status);
      
     

        p = p->next;
    }

}
int main() {
    Implant* head = NULL;
    int menu=1; 
    int wybor;  
       while(menu==1){
         wybor=showMenu();
       switch(wybor){
 case 1:{
 Dodaj_implant(&head);
 break;
}
 case 2:{
   wyswietl(head);
   break;
     }
 case 3:{

break;
}
 case 4:{

  break;
  }
 case 5:{

      break;
    }
case 6:{

break;
}


        }
    }
        }
