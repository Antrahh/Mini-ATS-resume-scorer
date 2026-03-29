#ifndef ATS_H
#define ATS_H

#define MAX_RESUME 5000
#define MAX_WORDS 1000
#define WORD_LEN 50

// resume parser
void convertResume(char filename[]);

// file handling
void readResume(char resume[]);
void readJobDescription(char filename[], char jobDesc[]);

// keyword module
void toLower(char str[]);
int countMatches(char resume[], char keywords[][30], int n);
int spellingErrors(char resume[]);

// string matching
void cleanText(char *text);
void computeLPS(char pattern[], int m, int lps[]);
int KMPSearch(char text[], char pattern[]);

// scoring
float calculateScore(char resume[], char jobDesc[]);

#endif