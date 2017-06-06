#include "stdio.h"



int main(void)

{

FILE *f;

char fname[20];

char c;

int i;

struct str {

 int x;

 char s[256];

 float num;

};

struct str data;

gets(fname);

f = fopen(fname, "r");

while (f == 0)

{

    printf("enter correct file name \n");

    gets(fname);

    f = fopen(fname, "r");

}

while (fread(&data, sizeof(struct str), 1, f))

    printf("%d  %s  %f \n", data.x, data.s, data.num);

fseek(f,0,SEEK_END);

int size = ftell(f);

printf("size of the file: %d bytes", size);

return 0;

}
