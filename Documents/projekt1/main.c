#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "implant.h"
#include "baza.h"
#include "fileio.h"
#include "menu.h"
void wyczysc_bufor(){
 int c;
    while ((c = getchar()) != '\n');
}
int main(int argc, char* argv[]) {
  
    if (argc < 2) {
        printf("Uzycie: %s <nazwa_pliku_bazy>\n", argv[0]);
    }
char* sciezka_pliku = argv[1];
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
case 7:{
Sortowanie(&head);
      break;
    }
case 8:{
zapis_do_pliku(head, sciezka_pliku);
      break;
    }
case 9:{
wczytaj_z_pliku(&head, sciezka_pliku);
      break;
    }
    case 0:{
    menu=0;
    zwolnij_liste(head);
    printf("Wyjscie z systemu\n");
}


        }
    }
} 
