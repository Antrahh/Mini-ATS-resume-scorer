#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ats.h"

// Convert string to lowercase
void toLowerCase(char *str)
{
    for(int i=0; str[i]; i++)
        str[i] = tolower(str[i]);
}

// Split text into words
int tokenize(char text[], char words[MAX_WORDS][WORD_LEN])
{
    int count = 0;
    char *token = strtok(text, " ,.-\n\t");
    while(token != NULL)
    {
        strcpy(words[count++], token);
        token = strtok(NULL, " ,.-\n\t");
    }
    return count;
}

// Check if word exists in array
int isPresent(char word[], char words[MAX_WORDS][WORD_LEN], int size)
{
    for(int i = 0; i < size; i++)
    {
        if(strcmp(word, words[i]) == 0)
            return 1;
    }
    return 0;
}

// Calculate score + track matched/missing skills
float calculateScore(char resume[], char jobDesc[])
{
    char resumeWords[MAX_WORDS][WORD_LEN];
    char jobWords[MAX_WORDS][WORD_LEN];

    char rCopy[MAX_RESUME];
    char jCopy[MAX_RESUME];

    strcpy(rCopy, resume);
    strcpy(jCopy, jobDesc);

    toLowerCase(rCopy);
    toLowerCase(jCopy);

    int resumeCount = tokenize(rCopy, resumeWords);
    int jobCount = tokenize(jCopy, jobWords);

    int matchCount = 0;

    char matched[MAX_MATCH][WORD_LEN];
    char missing[MAX_MATCH][WORD_LEN];
    int matchedCount = 0, missingCount = 0;

    for(int i = 0; i < jobCount; i++)
    {
        if(isPresent(jobWords[i], resumeWords, resumeCount))
        {
            matchCount++;
            if(matchedCount < MAX_MATCH)
                strcpy(matched[matchedCount++], jobWords[i]);
        }
        else
        {
            if(missingCount < MAX_MATCH)
                strcpy(missing[missingCount++], jobWords[i]);
        }
    }

    float score = ((float)matchCount / jobCount) * 100;

    // Write results to file
    FILE *f = fopen("result_data.txt", "w");
    if(f != NULL)
    {
        fprintf(f, "score=%.2f\n", score);

        fprintf(f, "matched=");
        for(int i = 0; i < matchedCount; i++)
        {
            fprintf(f, "%s", matched[i]);
            if(i != matchedCount - 1) fprintf(f, ",");
        }
        fprintf(f, "\n");

        fprintf(f, "missing=");
        for(int i = 0; i < missingCount; i++)
        {
            fprintf(f, "%s", missing[i]);
            if(i != missingCount - 1) fprintf(f, ",");
        }
        fprintf(f, "\n");

        fclose(f);
    }
    else
    {
        printf("Error: Could not write result file.\n");
    }

    // Optional: print to console for debugging
    printf("Score: %.2f%%\n", score);
    printf("Matched Skills: ");
    for(int i = 0; i < matchedCount; i++) printf("%s ", matched[i]);
    printf("\nMissing Skills: ");
    for(int i = 0; i < missingCount; i++) printf("%s ", missing[i]);
    printf("\n");

    return score;
}
