#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct Pck{
    int num;
    char str[255];
    float fl;
}Pack;

int main(int argc, char *argv[]){
    FILE *readFile;
    int Count=0;
    char rout[255];
    Pack Pack1;
    if (argc>1){
        readFile = fopen(argv[1],"rb");
        if (readFile==NULL){
        while(1){
            printf("Unknown file\nEnter a new file name: ");
            scanf("%s",&rout);
            readFile = fopen(rout,"rb");
            if (readFile!=NULL)
                break;
                }
            }
        }
    else
        while(1){
            printf("\nEnter a new file name: ");
            scanf("%s",&rout);
            readFile = fopen(rout,"rb");
            if (readFile!=NULL)
                break;
            printf("Unknown file");
        }
    while(1){
        if (fread(&Pack1,sizeof(Pack),1,readFile)!= NULL){
            printf("%d\t%s\t%f\n",Pack1.num,Pack1.str,Pack1.fl);
            Count++;
        }
        else
            break;
    }
    printf("Size=%d",Count*(sizeof(int)+255*sizeof(char)+sizeof(float)));
    fclose(readFile);
    return 0;
}
