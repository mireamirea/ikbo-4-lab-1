#include <stdio.h>
#include <stdlib.h>


int main(int argc,char* argv[])
{
FILE *f;
int size;

struct str {
int x;
char s[256];
float num;

};

struct str data;
if ((argc == 1) || (!(fopen(argv[1], "rb")))) {
		printf("File not opened: %s <filename>\n", argv[0]);
		return 1;
	}
f = fopen(argv[1], "rb");
while (fread(&data, sizeof(struct str), 1, f))
    printf("%d  %s  %f \n", data.x, data.s, data.num);

fseek(f, 0, SEEK_END);
	size = ftell(f);
	printf("Size: %d%s", size, " bytes\n");
	fclose(f);
return 0;

}
