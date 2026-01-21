#include "menu.h"
#include "baza.h"
int showMenu()
{
    int wybor;
    printf("\n===MENU===\n");
    printf("1)Zarejestruj nowy implant\n");
    printf("2)Lista wszystkich implantow\n");
    printf("3)Edytuj dane implantu\n");
    printf("4)Usun jeden implant(Po ID i nazwie)\n");
    printf("5)Usun wiele(Po poziomie Ryzyka)\n");
    printf("6)Wyszukaj\n");
    printf("7)Sortuj\n");
    printf("8)Zapisz zmiany do pliku\n");
    printf("9)Wczytaj dane z pliku\n");
    printf("0)Wyjscie z systemu\n");
         if(scanf("%d",&wybor)!=1 || wybor<0 || wybor>9)
         {
             printf("Wprowadz niepoprawna wartosc\n");
          while ((getchar()) != '\n');
         }
         else{
            return wybor;
         }
}
void Wybor_wyszukiwania(Implant* head)
{
    
    int opcja;
    printf("\n--- WYSZUKIWANIE IMPLANTU ---\n");
    printf("1) Wyszukaj po nazwie\n");
    printf("2) Wyszukaj po ryzyku\n");
    scanf("%d",&opcja);wyczysc_bufor();
    switch(opcja){
        case 1:{
            wyszukaj_po_nazwie(head);      
            break;
        }
        case 2:{
           wyszukaj_po_ryzyku(head);      
            break;
        }
        default:{
            printf("Blad: Nieprawidlowa opcja\n");
            break;
        }
    }
}
void Sortowanie(Implant** head)
{
    
    int opcja;
    printf("\n--- SORTOWANIE IMPLANTU ---\n");
    printf("1) Sortuj po nazwie\n");
    printf("2) Sortuj po ryzyku\n");
    scanf("%d",&opcja);wyczysc_bufor();
    switch(opcja){
        case 1:{
            sortuj_nazwe(head);      
            break;
        }
        case 2:{
           sortuj_ryzyko(head);      
            break;
        }
        default:{
            printf("Blad: Nieprawidlowa opcja\n");
            break;
        }
    }
}