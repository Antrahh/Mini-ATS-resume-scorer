#include <stdio.h>
#include <stdlib.h>
#include "ats.h"

void convertResume(char filename[])
{
    char command[300];

    printf("Converting resume to text...\n");

    sprintf(command,
    "\"C:\\Users\\Dell\\Downloads\\Release-25.12.0-0\\poppler-25.12.0\\Library\\bin\\pdftotext.exe\" \"%s\" \"resume.txt\"",
    filename);

    system(command);

    printf("Conversion complete. resume.txt created.\n");
}