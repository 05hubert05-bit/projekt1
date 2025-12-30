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
    struct Implant* next; // Wskaźnik na kolejny element listy
} Implant;
int main() {
}