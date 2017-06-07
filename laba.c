#include <stdio.h>
#include <stdlib.h>

struct paket {
  int a; 
  char c[255]; 
  float b;
};
int main(int argc, char *argv[]) {   
  struct paket d;   
  int x;   
  FILE *fp=NULL;
  if (argc>=2)   
      fp = fopen(argv[1], "rb");   
  if (fp == NULL){      
      printf("the file was unable to access\n");       
      printf("enter: %s <file name>\n", argv[0]);      
      return 1;  
  }   
  while (fread(&d, sizeof(struct paket), 1, fp)) {     
      printf("%d %s %f\n", d.a, d.c, d.b);       
      x++;  
  }    
  printf("Size of file = %d bytes\n", x*sizeof(d)); 
  fclose(fp);   
  return 0;
}
