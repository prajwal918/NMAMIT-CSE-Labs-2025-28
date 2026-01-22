#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int stringmatch(char t[], char p[]) {
    int m, n;
    m = strlen(t);
    n = strlen(p);
    for (int i = 0; i <= m - n; i++) {
        int j = 0;
        while (j < n && p[j] == t[i + j]) {
            j = j + 1;
        }
        if (j == n) {
            return i;
        }
    }
    return -1;
}

int main() {
    char t[100], p[100];
    int pos;
    printf("Enter the string : \n");
    gets(t);
    printf("Enter the pattern : \n");
    gets(p);
    pos = stringmatch(t, p);
    if (pos == -1) {
        printf("Pattern not found");
    } else {
        printf("Pattern found in the position : %d \n", pos);
    }
    return 0;
}