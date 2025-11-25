#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.h"
#include "menu_order.h"
#include "ui.h"

struct restaurants foodmenuvar[10]; 

static void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void restaurant_initialize() {
    strcpy(foodmenuvar[1].restaurant, "Chillox");
    strcpy(foodmenuvar[1].Choice1, "Smoky BBQ Cheese Burger");
    foodmenuvar[1].first = 225;
    strcpy(foodmenuvar[1].Choice2, "Chicken Cheese Blast");
    foodmenuvar[1].second = 320;
    
    strcpy(foodmenuvar[2].restaurant, "7 Dayz");
    strcpy(foodmenuvar[2].Choice1, "Roast Chicken Polao");
    foodmenuvar[2].first = 220;
    strcpy(foodmenuvar[2].Choice2, "Mutton Kacchi");
    foodmenuvar[2].second = 282;
}

static void process_item_order(int price, char *itemName) {
    int n;
    printf("How many '%s'? ", itemName);
    if (scanf("%d", &n) == 1) {
        total += (n * price);
        printf(GREEN "Added %d x %s. Total: %d TK\n" RESET, n, itemName, total);
    }
    clear_buffer();
}

void restaurants(int r_choice) {
    int food_choice;
    while(1) {
        print_header(foodmenuvar[r_choice].restaurant);
        printf("1. %-25s " YELLOW "%d TK" RESET "\n", foodmenuvar[r_choice].Choice1, foodmenuvar[r_choice].first);
        printf("2. %-25s " YELLOW "%d TK" RESET "\n", foodmenuvar[r_choice].Choice2, foodmenuvar[r_choice].second);
        printf("8. View Cart\n9. Back\n");
        printf("Choice: ");
        
        scanf("%d", &food_choice);
        clear_buffer();

        switch(food_choice) {
            case 1: process_item_order(foodmenuvar[r_choice].first, foodmenuvar[r_choice].Choice1); break;
            case 2: process_item_order(foodmenuvar[r_choice].second, foodmenuvar[r_choice].Choice2); break;
            case 8: cart(); return; 
            case 9: return;
            default: print_error("Invalid Choice.");
        }
        printf("Press Enter..."); getchar();
    }
}

void search_by_restaurants() {
    restaurant_initialize();
    int r_choice;
    while (1) {
        print_header("SELECT RESTAURANT");
        printf("1. %s\n2. %s\n6. Back\n", foodmenuvar[1].restaurant, foodmenuvar[2].restaurant);
        printf("Choice: ");
        scanf("%d", &r_choice);
        clear_buffer();

        if (r_choice == 6) return;
        if (r_choice >= 1 && r_choice <= 2) restaurants(r_choice);
        else print_error("Invalid restaurant.");
    }
}

void cart() {
    int ch;
    print_header("YOUR CART");
    printf("Total Bill: " YELLOW "%d TK" RESET "\n", total);
    printf("Confirm Order? (1=Yes, 0=No): ");
    scanf("%d", &ch);
    clear_buffer();

    if (ch == 1) {
        print_success("Order Confirmed! Rider is on the way.");
        total = 0; 
    } else {
        print_error("Order Cancelled.");
        total = 0;
    }
    getchar();
}