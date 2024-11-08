#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char input[10],temp[10];  // To store the current record (H, T, or E)
    int address = 0; // Holds the current address
    int start = 0;   // Program starting address
    int length = 0;  // Length of the program
    FILE *fp1, *fp2;

    // Open input and output files
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");

    // Read the first record (H, T, or E)
    fscanf(fp1, "%s %s", input,temp);

    // Loop through all records until the 'E' (End) record
    while (strcmp(input, "E") != 0)
    {
        if (strcmp(input, "H") == 0)
        {
            // Handle Header record
            fscanf(fp1, "%d", &length); 
            fscanf(fp1, "%s", input); // Read length
        }
        else if (strcmp(input, "T") == 0)
        {
            // Handle Text record
            fscanf(fp1, "%d", &address); // Read the starting address
            fscanf(fp1, "%s", input);    // Read the object code
            fscanf(fp1, "%s", input);    // Read the object code

            // Print object code bytes with corresponding addresses
            for (int i = 0; i < 3; i++)
            {
                fprintf(fp2, "%d\t%c%c\n", address++, input[i * 2], input[i * 2 + 1]);
            }
             
        }
        else
        {
            // Handle any other type of record
            for (int i = 0; i < 3; i++)
            {
                fprintf(fp2, "%d\t%c%c\n", address++, input[i * 2], input[i * 2 + 1]);
            }
            
        }
        // Read the next record (H, T, or E)
        fscanf(fp1, "%s", input);
    }

    // Close the files
    fclose(fp1);
    fclose(fp2);
    printf("FINISHED\n");

    return 0;
}