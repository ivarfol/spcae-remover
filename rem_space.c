#include <stdio.h>

#define MAXLENGTH 1000
#define YES 1
#define NO 0

int Getline(char s[], int lim)
{
    int i, c, last;
    int isfirst = NO;
    for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
        if ((c == ' ' || c == '\t') && isfirst == NO) {
            last = i;
            isfirst = YES;
        }
        else {
            if (c != ' ' && c != '\t') {
                last = i + 1;
                isfirst = NO;
            }
        }
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[last] = '\n';
    s[last+1] = '\0';
    return i;
}

int main(void)
{
    char line[MAXLENGTH];
    int i;
    while (Getline(line, MAXLENGTH) > 0) {
        printf("%s", line);
    }
    return 0;
}
