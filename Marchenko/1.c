#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct Packet
{
int num;
char str[255];
float fnum;
} Pack;

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"RUS");
    char rz[255];
    FILE *f;
    Pack temp;
    if (argc>1)
        { if ((f = fopen(argv[1],"rb"))==0) { printf("Не могу открыть этот фаил\n"); return 1; } }
    else {printf("Введите имя фаила\n");
        scanf("%s",rz);
        if (!(f=fopen(rz,"rb"))) {
            printf("Не могу открыть этот фаил");
            return 0;
            }
        }
    while ((fread(&temp,sizeof(Pack),1,f)!=0))
        printf("%d\t%s\t%.2f\n",temp.num,temp.str,temp.fnum);
    fseek(f, 0, SEEK_END);
	printf("Размер файла %d%s", ftell(f), " байт\n");
	fclose(f);
    return 0;
}
