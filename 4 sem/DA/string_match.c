#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SM(char t[100], char p[100])
{
    int i, j, m, n, comp=0;
    m = strlen(t);
    n = strlen(p);
    
    for(i=0; i<=(m-n); i++)
    {
        j=0;
        while(j<n && t[i+j] == p[j])
        {
            j++;
            comp++;
        }
        if(j==n)
        {
            printf("No of comparisons: %d", comp);
            return i;
        }
        comp++;
    }
    printf("No of comparisons: %d", comp);
    return -1;
}

int main()
{
    char t[100], p[100];
    int result;
    printf("Enter the text: ");
    gets(t);
    printf("Enter the pattern: ");
    scanf("%s", p);
    result = SM(t, p);
    if(result != -1)
        printf("\nPattern found at %d index in the text", result+1);
    else
        printf("\nPattern not found in the text");
    return 0;
}
