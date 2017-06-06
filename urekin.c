#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 

struct pack 
{ 
int x; 
char str [255]; 
float y; 
}; 

int main(int argc, char * argv[])
{ 
	int i;
	int size; 
	FILE *fp; 
	char * fname;
    printf("Enter correct file name: %s\n", argv[1]);
    fname = argv[1];
    fp = fopen(fname, "rb");
	if (fp == NULL) 
	{
		printf ("wrong");
		return 1;
	}

   	else printf ("correct");
	struct pack pack; 
	i = 0;
	while(fread (&pack, sizeof(struct pack), 1, fp))
	{ 
		printf("%d %s %f \n", pack.x, pack.str, pack.y); 
		i++; 
	}
	size = i * sizeof(pack); 
	printf("%d", size);
	fclose (fp); 
	return 0;
}