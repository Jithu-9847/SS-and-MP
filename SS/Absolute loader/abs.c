#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char input[10],temp[10];
int length,addr;
FILE *fp1,*fp2;

void main()
{ 
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    fscanf(fp1,"%s %s",input,temp);

    while(strcmp(input,"E")!=0)
    {
        if(strcmp(input,"H")==0)
        {
            fscanf(fp1,"%d",&length);
        }
        else if(strcmp(input,"T")==0)
        {
            fscanf(fp1,"%d",&addr);
            fscanf(fp1,"%s",input);

            for(int i=0;i<3;i++)
            {
                fprintf(fp2,"%d %c%c\n",addr++,input[i*2],input[i*2+1]);
            }

        }else{

            for(int i=0;i<3;i++)
            {
                fprintf(fp2,"%d %c%c\n",addr++,input[i*2],input[i*2+1]);
            }
        }
        fscanf(fp1,"%s",input);
    }
}