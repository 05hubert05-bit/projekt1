#include "baza.h"
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
    
  
    printf("Podaj ID wlasciciela: ");
    scanf("%99s", tym_id);wyczysc_bufor();
    printf("Podaj nazwe implantu: ");
    scanf("%99s", tym_nazwa);wyczysc_bufor();


    Implant* current = head;
    while (current != NULL) {
     
        if (strstr(current->id, tym_id) != NULL && strstr(current->nazwa, tym_nazwa) != NULL) {
            
          
            printf("\nZnaleziono rekord. Obecne dane:\n");
            printf("Producent: %s | Ryzyko: %d | Energia: %.2f | Status: %s\n",
                   current->producent, current->ryzyko, 
                   current->energia, current->status);

            printf("\n--- WPROWADZ NOWE DANE ---\n");
            
            
            
            printf("Nowy producent: ");
            scanf("%99s", current->producent);wyczysc_bufor();
            int ryzyko;
            printf("Nowy poziom ryzyka (0-10): ");
           while(scanf("%d", &ryzyko) != 1 || ryzyko<0 || ryzyko>10){printf("Blad: Nieprawidlowe ryzyko\n Zakres(0-10)\n"); wyczysc_bufor();}
            current->ryzyko = ryzyko;
            float energia;
            printf("Nowe zapotrzebowanie energetyczne: ");
            while(scanf("%f", &energia) != 1){printf("Blad:wpisz liczbe\n"); wyczysc_bufor();}
            current->energia = energia;
            printf("Nowy status (legalny/szara/nielegalny): ");
            char status[20];
          while(scanf("%19s", status) != 1 || (strcmp(status,"legalny")!=0 && strcmp(status,"szara")!=0 && strcmp(status,"nielegalny")!=0)){printf("Blad: Nieprawidlowy status\n Opcje(legalny/szara/nielegalny)\n"); wyczysc_bufor();}
            strncpy(current->status, status,19);
            printf("SUKCES: Dane implantu zaktualizowane.\n");
            return; 
        }
        current = current->next;
    }

    
    printf("BLAD: Nie znaleziono implantu o podanych parametrach.\n");
}
void usun_implant(Implant** head)
{

       char tym_id[100];
    char tym_nazwa[100];
  
    printf("\n--- USUWANIE IMPLANTU ---\n");



    printf("Podaj ID wlasciciela: ");
    scanf("%99s", tym_id);wyczysc_bufor();
    printf("Podaj nazwe implantu: ");
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
            printf("SUKCES: Implant usuniety.\n");
            return;
    }
    prev = current;    
        current = current->next;
}
  printf("BLAD: Nie znaleziono implantu o podanych parametrach.\n");

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
  printf("BLAD: Nie znaleziono implantow z podanym poziomem ryzyka lub nadajancych sie do usuniecia(Byly nielegalne).\n");

}
void zwolnij_liste(Implant* head) {
    Implant* current = head;
    while (current != NULL) {
        Implant* next = current->next;
        free(current); 
        current = next;
    }
}

void wyszukaj_po_nazwie(Implant* head) {
    char tekst[100];
    int znaleziono = 0;
    printf("\n--- WYSZUKIWANIE IMPLANTU PO NAZWIE ---\n");
    printf("Podaj nazwe implantu do wyszukania: ");
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
        printf("Znaleziono %d implantow o nazwie zawierajacej '%s'.\n", znaleziono, tekst);
    }
    if (znaleziono==0) {
        printf("Nie znaleziono implantow o podanej nazwie.\n");
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
        printf("Znaleziono %d implantow o ryzyku rownym '%d'.\n", znaleziono, ryzyko);
    }
    if (znaleziono==0) {
        printf("Nie znaleziono implantow o podanym poziomie ryzyka.\n");
    }
}
}
Implant* wstaw_posortowane_ryzyko(Implant* sorted, Implant* nowy_wezel) {
    
    if (sorted == NULL || nowy_wezel->ryzyko <= sorted->ryzyko) {
        nowy_wezel->next = sorted;
        return nowy_wezel;
    }

    Implant* p = sorted;

    while (p->next != NULL && p->next->ryzyko < nowy_wezel->ryzyko) {
        p = p->next;
    }


    nowy_wezel->next = p->next;
    p->next = nowy_wezel;

    return sorted;
}
void sortuj_ryzyko(Implant** head) {
    Implant* sorted = NULL;
    Implant* current = *head;

    while (current != NULL) {
        Implant* next = current->next; 
        
        current->next = NULL;
        sorted = wstaw_posortowane_ryzyko(sorted, current);
        
        current = next; 
    }

    *head = sorted; 
    printf("Lista zostala posortowana wedlug poziomu ryzyka.\n");
}
Implant* wstaw_posortowane_nazwe(Implant* sorted, Implant* nowy_wezel) {
    
    if (sorted == NULL || strcmp(nowy_wezel->nazwa, sorted->nazwa) <= 0) {
        nowy_wezel->next = sorted;
        return nowy_wezel;
    }

    Implant* p = sorted;

    while (p->next != NULL && strcmp(p->next->nazwa, nowy_wezel->nazwa) < 0) {
        p = p->next;
    }


    nowy_wezel->next = p->next;
    p->next = nowy_wezel;

    return sorted;
}
void sortuj_nazwe(Implant** head) {
    Implant* sorted = NULL;
    Implant* current = *head;

    while (current != NULL) {
        Implant* next = current->next; 
        
        current->next = NULL;
        sorted = wstaw_posortowane_nazwe(sorted, current);
        
        current = next; 
    }

    *head = sorted; 
    printf("Lista zostala posortowana alfabetycznie wedlug nazwy.\n");
}