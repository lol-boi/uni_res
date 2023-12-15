#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i, num[10] = {0};
    char s[1000];
    scanf("%s", s);
    for (i=0; i<strlen(s); i++) {
        if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
            num[s[i] - '0'] += 1;
        }
    }
    for (i=0; i<10; i++) {
        printf("%d ", num[i]);
    }
     
    return 0;
}
