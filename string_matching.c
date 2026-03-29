#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ats.h"

void cleanText(char *text)
{
    int i,j=0;
    char temp[MAX_RESUME];

    for(i=0;text[i]!='\0';i++)
    {
        if(isalnum(text[i]) || text[i]==' ')
            temp[j++]=tolower(text[i]);
    }

    temp[j]='\0';

    strcpy(text,temp);
}

void computeLPS(char pattern[],int m,int lps[])
{
    int len=0,i=1;

    lps[0]=0;

    while(i<m)
    {
        if(pattern[i]==pattern[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
                len=lps[len-1];
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}

int KMPSearch(char text[],char pattern[])
{
    int n=strlen(text);
    int m=strlen(pattern);

    int lps[100];
    computeLPS(pattern,m,lps);

    int i=0,j=0;

    while(i<n)
    {
        if(pattern[j]==text[i])
        {
            i++;
            j++;
        }

        if(j==m)
            return 1;

        else if(i<n && pattern[j]!=text[i])
        {
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
    }

    return 0;
}