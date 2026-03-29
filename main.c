#include <stdio.h>
#include <string.h>
#include "ats.h"

int main()
{
    char resume[MAX_RESUME]="";
    char jobDesc[MAX_RESUME]="";
    char filename[100];
    char jobFile[50];

    int choice;

    printf("===== MINI ATS RESUME SCORER =====\n");

    printf("\nEnter Resume File (PDF/DOCX): ");
    scanf("%s",filename);

    convertResume(filename);

    readResume(resume);

    printf("\nSelect Job Role\n");
    printf("1. Software Developer\n");
    printf("2. Web Developer\n");
    printf("3. Data Analyst\n");

    scanf("%d",&choice);

    if(choice==1)
        strcpy(jobFile,"software_job.txt");

    else if(choice==2)
        strcpy(jobFile,"web_job.txt");

    else if(choice==3)
        strcpy(jobFile,"data_analyst_job.txt");

    else
    {
        printf("Invalid choice\n");
        return 0;
    }

    readJobDescription(jobFile,jobDesc);

    cleanText(resume);
    cleanText(jobDesc);

    float score=calculateScore(resume,jobDesc);

    printf("\n===== ATS RESULT =====\n");
    printf("Match Score: %.2f%%\n",score);

    if(score>=80)
        printf("Excellent Resume Match\n");

    else if(score>=60)
        printf("Good Resume but can improve\n");

    else
        printf("Low Match. Add more relevant skills\n");

    return 0;
}