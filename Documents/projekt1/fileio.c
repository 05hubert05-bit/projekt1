#include "fileio.h"


void zapis_do_pliku(Implant* head, const char* nazwa_pliku) {
    FILE* plik = fopen(nazwa_pliku, "w");
    if (plik == NULL) {
        printf("BLAD: Nie mozna otworzyc pliku do zapisu.\n");
        return;
    }
    Implant* current = head;
    while (current != NULL) {
        fprintf(plik, "%s;%s;%s;%d;%.2f;%s\n", current->id, current->nazwa, current->producent, current->ryzyko, current->energia, current->status);
        current = current->next;
    }   
    fclose(plik);
    printf("SUKCES: Dane zostaly zapisane do pliku '%s'.\n", nazwa_pliku);
}
void wczytaj_z_pliku(Implant** head, const char* nazwa_pliku) {
    FILE* plik = fopen(nazwa_pliku, "r");
    
    if (plik == NULL) {
        printf("BLAD: Nie mozna otworzyc pliku %s do odczytu.\n", nazwa_pliku);
        return;
    }

    char id[50], nazwa[100], producent[100], status[20];
    int ryzyko;
    float energia;
    int wczytane = 0;

    while (fscanf(plik, "%49[^;];%99[^;];%99[^;];%d;%f;%19[^\n]", 
                  id, nazwa, producent, &ryzyko, &energia, status) == 6) {
        
        
        Implant* nowy = Nowyimplant(id, nazwa, producent, ryzyko, energia, status);
        if (nowy != NULL) {
            nowy->next = *head;
            *head = nowy;
            wczytane++;
        }
    }

    fclose(plik);
    printf("SUKCES: Wczytano %d rekordow z pliku %s.\n", wczytane, nazwa_pliku);
}