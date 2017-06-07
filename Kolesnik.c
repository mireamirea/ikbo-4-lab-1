//Kolesnik N.A.

#include <stdlib.h>
#include <stdio.h>


struct pack
    {
    int a;
    char b[255];
    float c;
    };

int main(int argc, char *argv[])
    {
    FILE *fp;
    struct pack temp;
    long int d;
    char name[255];

    if ( (!(fp=fopen(argv[1], "rb")))||(argc == 1))
        {
        printf("Enter file name:\n", argv[0]);
        while ((fp = fopen(name, "rb")) == NULL)
            {
			scanf("%s", name);
            }
        }

    while ((fread(&temp, sizeof(struct pack), 1, fp)!=0))
		printf("%d,%s,%f\n", temp.a, temp.b, temp.c);

	fseek(fp, 0, SEEK_END);
	d = ftell(fp);
	printf("Size: %d%s", d, " bytes\n");
	fclose(fp);
	return 0;
}
