// implant.h
#ifndef IMPLANT_H
#define IMPLANT_H

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
Implant* Nowyimplant(char* id,char* nazwa,char* producent,int ryzyko,float energia,char* status);


void wyczysc_bufor();

#endif