/*
    This program will add a new contact to the phone book.
    Written by Tomer Shor 
    Date: 17/5/2024

    Check out findPB.c for using insructions.
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc > 5 || argc < 3) {
        fprintf(stderr, "Usage: %s <name> <*second name> <*last name> <phone_number>\n* represents optional use.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the phone book file in append mode
    FILE *file = fopen("phonebook.txt", "a");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }


    // for only name and phone number.
    if (argc == 3)
    {
        fprintf(file, "%s,%s\n", argv[1], argv[2]);
        fclose(file);
    }
    
    // for name, last name and phone number. Could also work for name, second name and phone number.
    if (argc == 4)
    {
            fprintf(file, "%s %s,%s\n", argv[1], argv[2], argv[3]);
            fclose(file);
    }

    // for name, second name, last name and phone number.
    if (argc == 5)
    {
        fprintf(file, "%s %s %s,%s\n", argv[1], argv[2], argv[3], argv[4]);
        fclose(file);
    }

    
    return 0;
}
