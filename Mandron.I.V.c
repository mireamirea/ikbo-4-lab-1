#include <stdio.h> 
#include <stdlib.h> 

struct reg {
	int num;
	char str[256];
	float numf;
};

int main(int argc, char **argv) {

	struct reg p;
	FILE *fp;

	int Size;
	char name[256];

	if (argv[1] == NULL) {
		printf("You did not specify a file address:\n");
		printf("Enter the full address of the file:\n");
		while ((fp = fopen(name, "rb")) == NULL) {
			scanf("%s", name);
		}
	}
	else {
		if ((fp = fopen(argv[1], "rb")) == NULL) {
			printf("Could not open file\n");		
			printf("Enter the full address of the file:\n");
			while ((fp = fopen(name, "rb")) == NULL) {
				scanf("%s", name);
			}
		}
	}

	while (fread(&p, sizeof(struct reg), 1, fp))
		printf("%d %s %f\n", p.num, p.str, p.numf);
 
	fseek(fp, 0, SEEK_END); 
	Size = ftell(fp); 
	rewind(fp);
	printf("Size in bytes : %d\n", Size);

	fclose(fp);
	return 0;

}