#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ats.h"

void toLowerCase(char *str)
{
    for(int i=0;str[i];i++)
        str[i]=tolower(str[i]);
}

int tokenize(char text[], char words[MAX_WORDS][WORD_LEN])
{
    int count=0;

    char *token=strtok(text," ,.-\n\t");

    while(token!=NULL)
    {
        strcpy(words[count++],token);
        token=strtok(NULL," ,.-\n\t");
    }

    return count;
}

int isPresent(char word[], char words[MAX_WORDS][WORD_LEN], int size)
{
    for(int i=0;i<size;i++)
    {
        if(strcmp(word,words[i])==0)
            return 1;
    }

    return 0;
}

float calculateScore(char resume[], char jobDesc[])
{
    char resumeWords[MAX_WORDS][WORD_LEN];
    char jobWords[MAX_WORDS][WORD_LEN];

    char rCopy[MAX_RESUME];
    char jCopy[MAX_RESUME];

    strcpy(rCopy,resume);
    strcpy(jCopy,jobDesc);

    toLowerCase(rCopy);
    toLowerCase(jCopy);

    int resumeCount=tokenize(rCopy,resumeWords);
    int jobCount=tokenize(jCopy,jobWords);

    int matchCount=0;

    for(int i=0;i<jobCount;i++)
    {
        if(isPresent(jobWords[i],resumeWords,resumeCount))
            matchCount++;
    }

    float score=((float)matchCount/jobCount)*100;

    return score;
}