#include <stdio.h>

void main() {
    FILE *fp;
    int karakter;
    int a;

    if ((fp = fopen("input.txt", "r")) == NULL) {
        printf("input.txt tidak bisa dibuka");
    } else {
        while (fscanf(fp,"%d\n",&karakter) != EOF)
        if (karakter%2==0)
            {printf("%d",karakter);}
        else{printf("error");}
        fclose(fp);
    }

    printf("\n\n");
    }

