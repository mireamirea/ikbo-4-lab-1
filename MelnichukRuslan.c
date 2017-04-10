#include <stdio.h>
#include <stdlib.h>
#define STRLEN 255

struct input {
	int number;
	char str[STRLEN];
	float point;
};

int main(int argc, char *argv[])
{
	struct input p1;
	FILE *fp;
	long int size;


	if ((argc == 1) || (!(fopen(argv[1], "rb")))) {
		printf("Attempt at opening file: %s <filename>\n", argv[0]);
		return 1;
	}
	fp = fopen(argv[1], "rb");
	while (fread(&p1, sizeof(struct input), 1, fp)) {
		printf("%d,%s,%f\n", p1.number, p1.str, p1.point);
	}
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	printf("Size of file: %d%s", size, " bytes\n");
	fclose(fp);
	return 0;
}
