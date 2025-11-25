#include <stdio.h>
#include "structures.h"
#include "auth.h"
#include "employee.h"
#include "menu_order.h"
#include "ui.h"

// Define globals
struct credentials credential_var[100];
int total = 0;
int j = 0;

int main() {
    int choice;
    while (1) {
        print_header("MAIN MENU"); 
        printf(" 1. " BLUE "Sign Up" RESET "\n");
        printf(" 2. " BLUE "Login" RESET "\n");
        printf(" 3. " BLUE "Order Food" RESET "\n");
        printf(" 4. " BLUE "Employee DB (Encrypted)" RESET "\n");
        printf(" 5. " RED "Exit" RESET "\n");
        print_divider();
        printf(" Select Option: ");
        
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1: registration(); break;
            case 2: login(); break;
            case 3: search_by_restaurants(); break; 
            case 4: employee(); break;
            case 5: 
                print_success("Exiting...");
                return 0;
            default:
                print_error("Invalid Choice.");
                getchar(); getchar(); 
        }
    }
    return 0;
}