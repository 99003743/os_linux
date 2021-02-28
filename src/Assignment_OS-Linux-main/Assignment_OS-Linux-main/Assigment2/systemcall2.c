#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * sample_File;
    char path[100];

    char ch;
    int i=0;
    int c=0, w=0, l=0;

    printf("Enter the file path: ");
    scanf("%s", path);

    sample_File = fopen(path, "r");

    if (sample_File == NULL)
    {
        printf("Please enter the valid text file.\n");

        exit(0);
    }


    
    while ((ch = fgetc(sample_File)) != EOF)
    {
        c++;
        i++;

        
        if (ch == '\n' || ch == '\0')
            l++;

       
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            w++;
    }

    if (i > 0)
    {
        w++;
        l++;
    }

    printf("\n");
    printf("Number of characters = %d\n", c);
    printf("Number of words      = %d\n", w);
    printf("Number of lines      = %d\n", l);

    fclose(sample_File);

    return 0;
}