#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "auth.h"
#include "structures.h"
#include "ui.h"

// Helper to clear input buffer
static void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Wrapper for safe string input
static void get_safe_input(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        } else {
            clear_input_buffer();
        }
    }
}

static int is_strong_password(char *pass) {
    int up = 0, low = 0, num = 0, special = 0;
    for (int i = 0; pass[i] != '\0'; i++) {
        if (isupper(pass[i])) up++;
        else if (islower(pass[i])) low++;
        else if (isdigit(pass[i])) num++;
        else if (strchr("@&#*", pass[i])) special++;
    }
    return (up && low && num && special && strlen(pass) >= 8 && strlen(pass) <= 32);
}

void registration() {
    char t_name[100], t_pass1[100], t_pass2[100], t_email[100], t_mobile[100];
    int t_age;

    print_header("REGISTRATION");

    printf("Name (Nickname): ");
    get_safe_input(t_name, sizeof(t_name));

    printf("Age: ");
    if (scanf("%d", &t_age) != 1) {
        print_error("Invalid number!");
        clear_input_buffer();
        return;
    }
    clear_input_buffer();

    if (t_age <= 0) {
        print_error("Invalid age.");
        return;
    }

    printf("Email: ");
    get_safe_input(t_email, sizeof(t_email));
    
    printf("Password (8-32 chars, Upper, Lower, Num, Special): ");
    get_safe_input(t_pass1, sizeof(t_pass1));

    if (!is_strong_password(t_pass1)) {
        print_error("Password is too weak!");
        getchar();
        return;
    }

    printf("Confirm Password: ");
    get_safe_input(t_pass2, sizeof(t_pass2));

    if (strcmp(t_pass1, t_pass2) != 0) {
        print_error("Passwords do not match!");
        getchar();
        return;
    }

    printf("Contact Number: ");
    get_safe_input(t_mobile, sizeof(t_mobile));

    // Save
    strcpy(credential_var[j].username, t_name);
    credential_var[j].age = t_age;
    strcpy(credential_var[j].password, t_pass1); 
    strcpy(credential_var[j].email, t_email);
    strcpy(credential_var[j].mobile, t_mobile);
    j++; 
    
    print_success("Registration Successful!");
    printf("Press Enter to continue...");
    getchar();
}

void login() {
    char email[100], pass[100];
    int found = 0;

    print_header("LOGIN");
    
    printf("Email: ");
    get_safe_input(email, sizeof(email));

    printf("Password: ");
    get_safe_input(pass, sizeof(pass));

    for (int i = 0; i < 100; i++) {
        if (strlen(credential_var[i].email) > 0) {
            if (strcmp(credential_var[i].email, email) == 0 && 
                strcmp(credential_var[i].password, pass) == 0) {
                print_success("Login Successful!");
                printf("Welcome %s. Press Enter...", credential_var[i].username);
                getchar();
                found = 1;
                // In a real flow, you'd trigger the order menu here or return a success flag
                break;
            }
        }
    }

    if (!found) {
        print_error("Invalid Credentials.");
        getchar();
    }
}