//
//  main.c
//  1.lab
//
//  Created by Георгий Фалилеев on 14.02.17.
//  Copyright © 2017 Георгий Фалилеев. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct paket {
    int a;
    char c[256];
    float b;
    
};

int main(int argc, char *argv[]) {
    printf("Vvedite imya faila: ");
    char *fname=(char *)malloc(256);
ar:
    scanf("%s",fname);
    FILE *f1=fopen(fname,"rb");
    if(f1==NULL) {
        printf("Error.\n");
        goto ar;
    }
    
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
