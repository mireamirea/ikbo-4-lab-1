#include<stdio.h>
#include<stdlib.h>
struct paket {
    int a;
    char c[256];
    float b;
};
int main(int argc, char **argv) {
    struct paket d;
    FILE *fp;
    
    fp = fopen(argv[1], "rb");
    
    if (fp == NULL) {
        printf("Не открывается\n");
        return 0;
    }
    while (fread(&d, sizeof(struct paket), 1, fp)) {
        printf("%2d %s %f\n", d.a, d.c, d.b);
    }
    fseek(fp, 0, SEEK_END); /*Move to the end of the file*/
    long size = ftell(fp); /*Get the byte number*/
    fseek(fp, 0, SEEK_SET);
    printf("file size= %ld (byte)", size);
    fclose(fp);
    return 0;
}
