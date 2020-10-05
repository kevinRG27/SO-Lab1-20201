#include <stdio.h>

//Firma de los métodos
int w_zip(char *fileName);
int ultimo(int cont_apari_1, char comparador);
int ult_char;

int main(int argc, char *argv[]){  
     
    //Analizando casos de los argumentos
    //---> Caso de un solo argumento
    if (argc == 1){
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }    

    //Variable para contar repeticiones de la última letra
    int cont = 0;

    //Ciclo para cuando entran varios argumentos
    if (argc > 1){
        for (int i = 1; i < argc; i++){
            cont = cont+ w_zip(argv[i]);
        }
        //Fin escribe el resultado en la terminal
        ultimo(cont, ult_char);
    }
}

//---------->Wzip
int w_zip(char *fileName){
    
    FILE *fp = fopen(fileName, "r");  //fp para manejar el archivo
    char char_actual;                 //Para movernos entre los caracteres 
    char char_1;                      //Para ubicarnos en la primer letra del archivo
    int cont_apari = 1;               //Contador para las apariciones de cada letra
    
    //Verificar existencia de archivo
    if (fp == NULL){
        printf("wzip: cannot open file\n");
        return 1;
    }
    char_actual = fgetc(fp);
   
   do{
        char_1 = char_actual;
        char_actual = fgetc(fp);
        if (char_actual == EOF){
            break;
        }
        if (char_actual == char_1){
            cont_apari++;
        }
        else{
            fwrite(&cont_apari, 1, sizeof(cont_apari), stdout);
            printf("%c", char_1);
            cont_apari = 1;
        }
    } while (1);

    //Por la forma en que hacemos las comprobaciones, no se imprime la compresión del último caracter
    //Lleva el ultimo char del archivo a comparadorGlobal
    ult_char = char_1;
    fclose(fp);
    return cont_apari;
}

//ultimo recibe el último caracter leido y el número de veces que se repitió
int ultimo(int cont_apari_1, char comparador){
    //Se escribe el resultado final de la compresión
    fwrite(&cont_apari_1, 1, sizeof(cont_apari_1), stdout);
    printf("%c", comparador);
    return 0;
}