#ifndef FILEIO_H
#define FILEIO_H
#include "implant.h" // Musi widzieć strukturę

void zapis_do_pliku(Implant* head, const char* nazwa_pliku);
void wczytaj_z_pliku(Implant** head, const char* nazwa_pliku);

#endif