#include "security.h"

#define KEY 0xF3 

void encrypt_decrypt_data(void *data, size_t size) {
    char *bytes = (char *)data;
    for (size_t i = 0; i < size; i++) {
        bytes[i] = bytes[i] ^ KEY;
    }
}