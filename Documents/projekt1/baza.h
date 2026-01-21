#ifndef BAZA_H
#define BAZA_H
#include "implant.h"
void Dodaj_implant(Implant** head);
void wyswietl(Implant* head);
void edytuj_implant(Implant* head);
void usun_implant(Implant** head);
void Usun_wiele(Implant** head);
void zwolnij_liste(Implant* head);


void wyszukaj_po_nazwie(Implant* head);
void wyszukaj_po_ryzyku(Implant* head);
void sortuj_ryzyko(Implant** head);
void sortuj_nazwe(Implant** head);

#endif