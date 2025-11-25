#include <stdio.h>
#include <stdlib.h>
#include "ui.h"

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void print_divider() {
    printf(CYAN "============================================================\n" RESET);
}

void print_header(char *title) {
    clear_screen();
    
    printf(CYAN); 
    
    printf("\n\t\tPROJECT GROUP:   ESCAPE SEQUENCE\n\n");
    printf("\t\tGROUP MEMBERS:  AZMAIN IQTIDAR ARNOB\n");
    printf("\t\t\t\tATIKUL ISLAM MUNNA\n");
    printf("\t\t\t\tAUNGGON CHOWDHURY\n\n");

    printf("\t\t||||||||||||   |||||||||||   ||||||||||||| \n");
    printf("\t\t|||                    |||   |||           \n");
    printf("\t\t|||                    |||   |||           \n");
    printf("\t\t|||||||OOD             |TO   |||||OODIES   \n");
    printf("\t\t|||            |||||||||||   |||           \n");
    printf("\t\t|||            |||           |||           \n");
    printf("\t\t|||            |||           |||           \n");
    printf("\t\t|||            |||           |||           \n");
    printf("\t\t|||            |||||||||||   |||           \n");

    printf(RESET); // Stop coloring here
    
    printf("\n");
    print_divider();
    // This prints the dynamic title (e.g., "MAIN MENU", "LOGIN") centered
    printf("\t\t   %s %s %s\n", YELLOW, title, RESET);
    print_divider();
    printf("\n");
}


void print_success(char *msg) {
    printf("\n" GREEN "[SUCCESS] %s" RESET "\n", msg);
}

void print_error(char *msg) {
    printf("\n" RED "[ERROR] %s" RESET "\n", msg);
}