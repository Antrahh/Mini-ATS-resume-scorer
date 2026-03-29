#include <stdio.h>
#include <string.h>
#include "ats.h"

void readResume(char resume[])
{
    FILE *f;
    char line[200];

    f = fopen("resume.txt","r");

    if(f == NULL)
    {
        printf("Error opening resume.txt\n");
        return;
    }

    while(fgets(line,sizeof(line),f))
    {
        strcat(resume,line);
    }

    fclose(f);
}

void readJobDescription(char filename[], char jobDesc[])
{
    FILE *f;
    char line[200];

    f = fopen(filename,"r");

    if(f == NULL)
    {
        printf("Error opening job file\n");
        return;
    }

    while(fgets(line,sizeof(line),f))
    {
        strcat(jobDesc,line);
    }

    fclose(f);
}