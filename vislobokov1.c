#include <stdio.h> 
#include <stdlib.h> 

#define j 1

struct package { 
int x; 
char string [255]; 
float y; 
}; 

int main(int argc, char * argv[]) { 
	int i;
	int razmer; 
	FILE *fp; 
	char * fname; 
    printf("Argument: %s\n", argv[j]);
    fname = argv[j];
    fp = fopen(fname, "rb");
	if (fp == NULL) {
		printf ("wrong");
		return 1;
	}
   	else printf ("correct");
	struct package pack; 
	i = 0;
	while(fread (&pack, sizeof(struct package), 1, fp)){ 
		printf("%d %s %f \n", pack.x, pack.string, pack.y); 
		i++; 
	}
	razmer = i * sizeof(pack); 
	printf("%d", razmer);
	fclose (fp); 
	return 0;
}
