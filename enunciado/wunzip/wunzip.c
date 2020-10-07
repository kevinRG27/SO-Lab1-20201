#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    //Analizando argumentos
    if (argc == 1){
       printf("wunzip: file1 [file2 ...]\n");
       exit(1);
    }

    int cont_bytes = 1;     //Para contar cuantos 'bytes' hemos recorrido
    char char_actual;       //Para movernos entre el comprimido
    char int_bin[4];        //Para almacenar los bytes correspondientes al entero que indica el #
                            //de veces que se repite un caracter.
    
    for (int i = 1; i < argc; i++){
       
       FILE *fp = fopen(argv[i], "r");
       if (fp == NULL){
           printf("wunzip: cannot open file\n");
           exit(1);
        }

    char_actual = fgetc(fp);
    //Ciclo para recorrer el comprimido

       while (char_actual != EOF){
           //Condición para saber cuando se esta en el caracter a imprimir
           if (cont_bytes == 5){
               //Desplazamiento de los bits para generar el entero correspondiente a la cantidad de veces
               //que se debe imprimir el caracter encontrado
               int x = (int_bin[3] << 24) | (int_bin[2] << 16) | (int_bin[1] << 8) | int_bin[0];

                //Ciclo para imprimir el caracter 'n' veces.
                for (int n = 0; n < x; n++){
                   printf("%c", char_actual);
                }
               cont_bytes=0;
           }
           else{
               int_bin[cont_bytes - 1] = char_actual;
           }
           char_actual = fgetc(fp);       
           cont_bytes = cont_bytes + 1;
       }
        fclose(fp);
    }
    return 0;
} 