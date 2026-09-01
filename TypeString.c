#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TypeString.h"


/*
    Esse método é responsável por alocar a memória
    automáticamente e dinamicamente para a variável 
    string.

    O parấmetro é o ponteiro para o primeiro elemento
    de um array do tipo char, que nós vamos transformar
    em uma variável string.
*/
string newString(char *array) {
    string str;                                             // Criando uma variável composta da struct
    str.size = (unsigned int) strlen(array);                // Calculamos a quantidade de letras e espaços do array e armazenamos o tamanho
    
    str.string = (char *) malloc(str.size + 1);             // Reservando a memória na heap e retornando o ponteiro do primeiro elemento do 
                                                            // bloco contíguo que é reservado, o bloco tem o tamanho baseado na quantidade de
                                                            // Caracteres do array mais um byte para o caractere nulo que sinaliza o final
                                                            // De arrays de char na linguagem C.
    
    strcpy(str.string, array);                              // O conteúdo do array enviado como parâmetro é finalmente salvo no espaço alocado.
    return str;                                             // Retornamos a variável composta que armazena o tamanho e o array
}

/*
    Cria uma string vazia
*/
string newEmptyString() {

    string str;
    str.size = 0u;
    str.string = (char *) calloc(1, sizeof(char));

    return str;
}

/*
    Recebe como parâmetro o ponteiro da variável composta (string)
    que será modificada e o ponteiro do novo texto que será armazenado
    no lugar dele.
*/
void changeString(string *str, char *array) {
    str->string = (char *) realloc(str->string, (strlen(array) + 1));  // Nós modificamos o tamanho do espaço reservado para a string e atualizamos o ponteiro
    strcpy(str->string, array);                                        // Atualizando o conteúdo dentro da string
    str->size = strlen(array);                                         // Atualizando o tamanho da string
}

/*
    Método que libera o espaço de memória reservado para
    guardar o array de char.
*/
void string_free(string *str) {

    free(str->string);  // Enviamos o ponteiro para o espaço na memória e o método free a memória.

}