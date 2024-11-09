#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    char input1[10], bitmask[10], add[10], realocbit, length[10];
    int len, i, act_adr, address, start, opcode, addr;
    FILE *input, *output;
    printf("Enter the starting address");
    scanf("%d", &start);

    input = fopen("relinput.txt", "r");
    output = fopen("reloutput.txt", "w");

    fscanf(input, "%s", input1);

    while (strcmp(input1, "E") != 0)
    {
        if (strcmp(input1, "H") == 0)
        {
            fscanf(input, "%s %s", add, length);
            fscanf(input, "%s", input1);
        }

        if (strcmp(input1, "T") == 0)
        {
            fscanf(input, "%d %s", &address, bitmask);
            address += start;

            len = strlen(bitmask);

            for (i = 0; i < len; i++)
            {
                fscanf(input, "%d %d", &opcode, &addr);
                if (bitmask[i] == '0')
                {
                    
                    act_adr = addr;
                }
                else
                {
                    act_adr = addr + start;
                }

                fprintf(output, "%d %d %d\n", address, opcode, act_adr);
                address += 3;
            }
        }

        fscanf(input, "%s", input1);
    }
}