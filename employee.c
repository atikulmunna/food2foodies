#include "structures.h"
#include "security.h"
#include "employee.h"
#include "ui.h"

// Define the global struct here
struct employee delivery; 

static void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void insert() {
    FILE *fp;
    fp = fopen("Record.dat", "ab");
    
    printf("Enter Serial Number: ");
    scanf("%d", &delivery.serialNO);
    clear_buffer();
    
    printf("Name: ");
    scanf("%[^\n]s", delivery.DeliveryMan); // Reads string with spaces
    clear_buffer();
    
    printf("Availability (0/1): ");
    scanf("%d", &delivery.availability);
    clear_buffer();

    encrypt_decrypt_data(&delivery, sizeof(delivery));
    fwrite(&delivery, sizeof(delivery), 1, fp);
    encrypt_decrypt_data(&delivery, sizeof(delivery)); // Decrypt back for display if needed

    fclose(fp);
    print_success("Data Encrypted and Saved!");
}

void disp() {
    FILE *fp1;
    fp1 = fopen("Record.dat", "rb");
    if (!fp1) {
        print_error("No records found.");
        return;
    }

    printf("\nSerial\tName\t\tStatus\n");
    print_divider();
    
    while (fread(&delivery, sizeof(delivery), 1, fp1)) {
        encrypt_decrypt_data(&delivery, sizeof(delivery));
        printf(" %d\t%-15s\t%d\n", delivery.serialNO, delivery.DeliveryMan, delivery.availability);
    }
    fclose(fp1);
}

void employee() {
    int c;
    while(1) {
        print_header("EMPLOYEE DATABASE");
        printf("1. Insert\n2. Display\n3. Back\n");
        printf("Choice: ");
        scanf("%d", &c);
        clear_buffer();

        switch(c) {
            case 1: insert(); getchar(); break;
            case 2: disp(); getchar(); break;
            case 3: return;
            default: print_error("Invalid");
        }
    }
}