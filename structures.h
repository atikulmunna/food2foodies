#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct credentials {
    int age;
    char username[100];
    char password[100];
    char email[100];
    char mobile[10];
};

struct restaurants {
    int first, second, third, fourth, fifth, sixth, seventh;
    char restaurant[100];
    char Choice1[50], Choice2[50], Choice3[50], Choice4[50];
    char Choice5[50], Choice6[50], Choice7[50], Choice8[50];
};

struct employee {
    int serialNO, availability;
    char DeliveryMan[50];
};

// Global variables
extern struct credentials credential_var[100];
extern struct employee delivery;
extern int total;
extern int j; // User count

#endif