#define _CRT_SECURE_NO_WARNINGS
#define N 255
#include <stdio.h>

int main() {
	FILE *file;
	struct output {
		int x;
		char y[255];
		float z;
	};
	struct output t;
	int i = 0, size=0, s=sizeof(struct output);
	file = fopen("data.dat", "rb");
	if (file!= NULL) {
		while (!feof(file)) {
			fread(&t, sizeof(struct output), 1, file);
			printf("%d %s %.2f\n", t.x, t.y, t.z);
			++size;
		};
	}
	else {
		printf("File not found");
	}
	size *= s;
	printf("File fize: %u bytes \n", size);
	fclose(file);
}