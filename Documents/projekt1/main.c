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
    printf("4)Usun jeden implant(Po ID i nazwie)\n");
    printf("5)Usun wiele(Po poziomie Ryzyka)\n");
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
void wyczysc_bufor() {
    int c;
    while ((c = getchar()) != '\n');
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
    char id[100], nazwa[100], producent[100], status[20];
    int ryzyko; float energia;

    printf("ID Wlasciciela: "); scanf("%99s", id);wyczysc_bufor();
    printf("Nazwa implantu: "); scanf("%99s", nazwa);wyczysc_bufor();
    printf("Producent: "); scanf("%99s", producent);wyczysc_bufor();
    printf("Ryzyko (0-10): "); while(scanf("%d", &ryzyko) != 1 || ryzyko<0 || ryzyko>10){printf("Blad: Nieprawidlowe ryzyko\n Zakres(0-10)\n"); wyczysc_bufor();}
    printf("Energia: "); while(scanf("%f", &energia) != 1){printf("Blad:wpisz liczbe\n"); wyczysc_bufor();}
    printf("Status:(legalny/szara/nielegalny)"); while(scanf("%19s", status) != 1 || (strcmp(status,"legalny")!=0 && strcmp(status,"szara")!=0 && strcmp(status,"nielegalny")!=0)){printf("Blad: Nieprawidlowy status\n Opcje(legalny/szara/nielegalny)\n"); wyczysc_bufor();}
    Implant* nowy = Nowyimplant(id, nazwa, producent, ryzyko, energia, status);
    nowy->next = *head; 
    *head = nowy;
}
void wyswietl(Implant* head) {
if (head == NULL) {
        printf("\n.Lista jest pusta\n");
        return;
    }
    Implant* p = head;
printf("\n                          --- CENTRALNY REJESTR CYBERNETYCZNY ---\n");
printf("%-15s | %-20s | %-10s | %-10s | %-10s | %-10s |\n" , "WLASCICIEL", "NAZWA", "PRODUCENT", "RYZYKO", "ENERGIA", "STATUS");
    while (p != NULL) {
     
        printf("%-15s | %-20s | %-10s | %-10d | %-10.2f | %-10s |\n",  p->id,  p->nazwa, p->producent, p->ryzyko,p->energia,p->status);
      
     

        p = p->next;
    }
printf("--------------------------------------------------------------------------------------------\n");
}
void edytuj_implant(Implant* head) {
    char tym_id[100];
    char tym_nazwa[100];

    printf("\n--- MODYFIKACJA DANYCH IMPLANTU ---\n");
    
  
    printf("Podaj ID właściciela: ");
    scanf("%99s", tym_id);wyczysc_bufor();
    printf("Podaj nazwę implantu: ");
    scanf("%99s", tym_nazwa);wyczysc_bufor();


    Implant* current = head;
    while (current != NULL) {
     
        if (strcmp(current->id, tym_id) == 0 && strcmp(current->nazwa, tym_nazwa) == 0) {
            
          
            printf("\nZnaleziono rekord. Obecne dane:\n");
            printf("Producent: %s | Ryzyko: %d | Energia: %.2f | Status: %s\n",
                   current->producent, current->ryzyko, 
                   current->energia, current->status);

            printf("\n--- WPROWADŹ NOWE DANE ---\n");
            
            
            
            printf("Nowy producent: ");
            scanf("%99s", current->producent);wyczysc_bufor();

            printf("Nowy poziom ryzyka (0-10): ");
            scanf("%d", &current->ryzyko);wyczysc_bufor();

            printf("Nowe zapotrzebowanie energetyczne: ");
            scanf("%f", &current->energia);wyczysc_bufor();

            printf("Nowy status (legalny/szara/nielegalny): ");
            scanf("%19s", current->status);wyczysc_bufor();

            printf("SUKCES: Dane implantu zaktualizowane.\n");
            return; 
        }
        current = current->next;
    }

    
    printf("BŁĄD: Nie znaleziono implantu o podanych parametrach.\n");
}
void usun_implant(Implant** head)
{

       char tym_id[100];
    char tym_nazwa[100];
  
    printf("\n--- USUWANIE IMPLANTU ---\n");
    
  
    printf("Podaj ID właściciela: ");
    scanf("%99s", tym_id);wyczysc_bufor();
    printf("Podaj nazwę implantu: ");
    scanf("%99s", tym_nazwa);wyczysc_bufor();
    Implant* current = *head;
    Implant* prev = NULL;
    while (current !=NULL)
    {   
    if(strcmp(current->id, tym_id) == 0 && strcmp(current->nazwa, tym_nazwa) == 0) {
       if(strcmp(current->status, "nielegalny") == 0 ) {
          printf("BLAD: Implant %s ma status NIELEGALNY. (Nie moze zostac usunienty).\n", current->nazwa);
            return;
        } 
          if (prev == NULL) {
                
                *head = current->next; 
            } else {
              
                prev->next = current->next; 
            }

     
            free(current);
            printf("SUKCES: Implant usunięty.\n");
            return;
    }
    prev = current;    
        current = current->next;
}
  printf("BŁĄD: Nie znaleziono implantu o podanych parametrach.\n");

}
void Usun_wiele(Implant** head) {
int ryzyko;
int git=0;
int usuniente=0;
 printf("\n--- USUWANIE WIELU IMPLANTU Z DANYM POZIOMEM RYZYKA ---\n");
    printf("Podaj poziom ryzyka implantow do usuniecia (0-10): ");
    while(scanf("%d", &ryzyko) != 1 || ryzyko<0 || ryzyko>10){printf("Blad: Nieprawidlowe ryzyko\n Zakres(0-10)\n"); wyczysc_bufor();}
    Implant* current = *head;
      Implant* prev = NULL;
       while (current !=NULL){
      if(current->ryzyko == ryzyko) {
       if(strcmp(current->status, "nielegalny") == 0 ) {
          printf("BLAD: Implant %s ma status NIELEGALNY. (Nie moze zostac usunienty).\n", current->nazwa);
            prev = current;
            current = current->next;
        } 
        else{
            Implant* do_usuniecia = current;
                current = current->next;
          if (prev == NULL) {
                
                *head = current; 
            } else {
              
                prev->next = current;
            }

     
            free(do_usuniecia);
           
            git=1;
            usuniente++;
        }
        }
        else{
         prev = current;    
        current = current->next;
        }
    }
   
if(git==1)
  printf("SUKCES: Usunieto %d implantow o poziomie ryzyka %d.\n",usuniente,ryzyko);
if(git==0)
  printf("BŁĄD: Nie znaleziono implantow z podanym poziomem ryzyka lub nadajancych sie do usuniecia(Byly nielegalne).\n");

}

void wyszukaj_po_nazwie(Implant* head) {
    char tekst[100];
    int znaleziono = 0;
    printf("\n--- WYSZUKIWANIE IMPLANTU PO NAZWIE ---\n");
    printf("Podaj nazwę implantu do wyszukania: ");
    scanf("%99s", tekst);wyczysc_bufor();
    Implant* current = head;
    printf("%-15s | %-20s | %-10s | %-10s | %-10s | %-10s |\n" , "WLASCICIEL", "NAZWA", "PRODUCENT", "RYZYKO", "ENERGIA", "STATUS");
    while (current != NULL) {
        if (strstr(current->nazwa, tekst) != NULL) {
            printf("%-15s | %-20s | %-10s | %-10d | %-10.2f | %-10s |\n",  current->id,  current->nazwa, current->producent, current->ryzyko,current->energia,current->status);
            znaleziono++;
        }
        current = current->next;
    }
    if(znaleziono!=0) {
    {
        printf("Znaleziono %d implant(ów) o nazwie zawierającej '%s'.\n", znaleziono, tekst);
    }
    if (znaleziono==0) {
        printf("Nie znaleziono implantów o podanej nazwie.\n");
    }
}
}
void wyszukaj_po_ryzyku(Implant* head) {
    int ryzyko;
    int znaleziono = 0;
    printf("\n--- WYSZUKIWANIE IMPLANTU PO RYZYKU ---\n");
    printf("Podaj poziom ryzyka do wyszukania: ");
    scanf("%d", &ryzyko);wyczysc_bufor();
    Implant* current = head;
    printf("%-15s | %-20s | %-10s | %-10s | %-10s | %-10s |\n" , "WLASCICIEL", "NAZWA", "PRODUCENT", "RYZYKO", "ENERGIA", "STATUS");
    while (current != NULL) {
        if (current->ryzyko == ryzyko) {
            printf("%-15s | %-20s | %-10s | %-10d | %-10.2f | %-10s |\n",  current->id,  current->nazwa, current->producent, current->ryzyko,current->energia,current->status);
            znaleziono++;
        }
        current = current->next;
    }
    if(znaleziono!=0) {
    {
        printf("Znaleziono %d implant(ów) o ryzyku rownym '%d'.\n", znaleziono, ryzyko);
    }
    if (znaleziono==0) {
        printf("Nie znaleziono implantów o podanym poziomie ryzyka.\n");
    }
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
    edytuj_implant(head);
break;
}
 case 4:{
usun_implant(&head);
  break;
  }
 case 5:{
Usun_wiele(&head);
      break;
    }
case 6:{
Wybor_wyszukiwania(head);
      break;
    }
break;
}


        }
    }
        
