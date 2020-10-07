#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 100

//Firma de los métodos
int func_wgrep(char termino[], char *fileName);
int wgrep_Input(char termino[]);

int main(int argc, char *argv[]){

    //Analizando casos de los argumentos
    //Caso de un solo argumento
    if (argc == 1){
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }
    if (argc == 2){
        if (wgrep_Input(argv[1]) == 1){
            return 1;
        }
    }
    if (argc > 2){
        for (int i = 2; i < argc; i++){
            if (func_wgrep(argv[1], argv[i]) == 1){
                return 1;
            }
        }
    }
    return 0;
}
int wgrep_Input(char termino[]){
    
    char str[n];            //Variable para guardar la entrada por teclado

    //Ciclo para la entrada por teclado. Se sale con ctrl+c
    while (fgets(str, n, stdin)){
        if (strstr(str, termino) != NULL){
            printf("%s", str);
        }
    }
    return 0;
}

int func_wgrep(char termino[], char *fileName){
    
    FILE *fp = fopen(fileName, "r");    //fp para manejar el archivo
    char *linea = NULL;
    size_t tamano = 0;
    int contador = 0;
    ssize_t contadorDeLinea;

    //Verificamos exixtencia del archivo 
    if (fp == NULL){
        printf("wgrep: cannot open file\n");
        return 1;
    }
    //Obtenemos el numero de la linea
    contadorDeLinea = getline(&linea, &tamano, fp);

    // Ciclo para recorrer el archivo 
    while (contadorDeLinea >= 0){
        contador++;
        if (strstr(linea, termino) != NULL){
            printf("%s", linea);
        }
        contadorDeLinea = getline(&linea, &tamano, fp);
    }
    //Liberamos buffer y cerramos el archivo
    free(linea);
    linea = NULL;
    fclose(fp);

    return 0;
}