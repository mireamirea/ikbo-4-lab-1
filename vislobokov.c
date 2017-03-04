#include <stdio.h> 
#include <stdlib.h> 

struct package { 
int x; 
char string [255]; 
float y; 
}; 

int main(void) { 
	int i; 
	int razmer; 
	FILE *fp; 
	char * fname = "data.dat"; 
	fp = fopen(fname, "rb"); 
	if (fp == NULL) 
		printf ("wrong");
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
