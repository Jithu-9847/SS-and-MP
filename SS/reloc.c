#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char add[6], length[10], input[10], bitmask[12], relocbit;
    int start, address, opcode, addr, actualadd, len, i;
    FILE *fp1, *fp2;

    // Get the starting address from the user
    printf("Enter the actual starting address: ");
    scanf("%d", &start);

    // Open input and output files
    fp1 = fopen("relinput.txt", "r");
     
    fp2 = fopen("reloutput.txt", "w");
     
    // Read the first record from the input file
    fscanf(fp1, "%s", input);

    // Loop until the End (E) record is found
    while (strcmp(input, "E") != 0) {
        if (strcmp(input, "H") == 0) {
            // Read the header record information (address and length)
            fscanf(fp1, "%s %s", add, length);
            fscanf(fp1, "%s", input); // Move to the next record
        }

        if (strcmp(input, "T") == 0) {
            // Read the starting address and bitmask from the text record
            fscanf(fp1, "%d %s", &address, bitmask);
            address += start;  // Adjust the address with the user-provided start

            // Get the length of the bitmask to know how many address/opcode pairs are present
            len = strlen(bitmask);

            // Loop through the opcode/address pairs based on the bitmask length
            for (i = 0; i < len; i++) {
                fscanf(fp1, "%d %d", &opcode, &addr);  // Read opcode and address
                relocbit = bitmask[i];  // Get the relocation bit for this pair

                // Adjust the address if the relocation bit is '1'
                if (relocbit == '0')
                    actualadd = addr;
                else
                    actualadd = addr + start;

                // Write the relocated address, opcode, and actual address to the output file
                fprintf(fp2, "%d\t%d\t%d\n", address, opcode, actualadd);

                // Increment the address for the next instruction
                address += 3;
            }

            // Read the next record
            fscanf(fp1, "%s", input);
        }
    }

    // Close both input and output files
    fclose(fp1);
    fclose(fp2);

    printf("FINISHED\n");
    return 0;
}