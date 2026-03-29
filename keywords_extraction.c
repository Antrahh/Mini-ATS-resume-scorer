#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ats.h"

void toLower(char str[])
{
    for(int i=0;str[i];i++)
        str[i]=tolower(str[i]);
}

int countMatches(char resume[], char keywords[][30], int n)
{
    int score=0;

    for(int i=0;i<n;i++)
    {
        if(strstr(resume,keywords[i])!=NULL)
            score++;
    }

    return score;
}

int spellingErrors(char resume[])
{
    char dictionary[][20] = {
        "java","python","sql","machine","learning","project","developer",
        "data","communication","leadership","hardworking","quick","learner",
        "cgpa","percentage","teamwork","problem","solving","management",
        "university","college","aws","nptel","coursera","internship"
    };

    int dictSize = 25;

    char copy[MAX_RESUME];
    strcpy(copy,resume);

    char *token=strtok(copy," ,.-\n");

    int errors=0,total=0;

    while(token!=NULL)
    {
        total++;
        int found=0;

        for(int i=0;i<dictSize;i++)
        {
            if(strcmp(token,dictionary[i])==0)
            {
                found=1;
                break;
            }
        }

        if(!found)
            errors++;

        token=strtok(NULL," ,.-\n");
    }

    if(total==0)
        return 0;

    return (errors*100)/total;
}