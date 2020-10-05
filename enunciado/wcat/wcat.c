#include <stdio.h>

//Firma de los métodos
int verArchivo(char *nombreArchivo);


int main(int argc, char *argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (verArchivo(argv[i]) == 1) {
                return 1;
            }
        }
    }
    return 0;
}

int verArchivo(char *nombreArchivo) {
    FILE *fp = fopen(nombreArchivo, "r");    //fp para manejar el archivo

    //Verificar existencia del archivo
    if (fp == NULL) {
        printf("wcat: cannot open file\n");
        return 1;
    }
    char c;         //Para movernos entre los caracteres del archivo 

    //Ciclo para recorrer el archivo
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    fclose(fp);

    return 0;
}