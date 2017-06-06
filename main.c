#include <stdio.h>
#include <stdlib.h>

struct paket {
    int a;
    char c[256];
    float b;
    
};

int main(int argc, char *argv[]) {
    FILE *f1;
    
    if ((argc == 1) || (!(fopen(argv[1], "rb")))) {
        printf("Enter correct file name\n");
        return 1;
    }
    
    f1 = fopen(argv[1], "rb");
    struct paket p1;
    
    while (!feof(f1))
    {
        fread(&p1, sizeof(struct paket), 1, f1);
        printf("%d %s %f \n", p1.a, p1.c, p1.b);
    }
    fseek(f1,0,SEEK_END);
    long size = ftell(f1);
    printf("%ld\n", size);
    fclose(f1);
    return 0;
}
