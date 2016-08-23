#include <stdio.h>

void main() {
    FILE *fp;
    int karakter;
    int a;

    if ((fp = fopen("teks_pintarcoding.txt", "r")) == NULL) {
        printf("teks_pintarcoding.txt tidak bisa dibuka");
    } else {
        while (fscanf(fp,"%d\n",&karakter) != EOF)
        if (karakter%2==0)
            {printf("%d",karakter);}
        else{printf("error");}
        fclose(fp);
    }

    printf("\n\n");
    }

