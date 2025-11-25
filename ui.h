#ifndef UI_H
#define UI_H

// ANSI Colors
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"
#define BOLD    "\033[1m"

void print_header(char *title);
void print_divider();
void print_success(char *msg);
void print_error(char *msg);
void clear_screen();

#endif