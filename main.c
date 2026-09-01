#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TypeString.h"

// Prototipagem de funções
string newWord();
string hideWord(string *);
void drawGallows(short int);
short int testLetter(char, string, string *);
short int checkStrings(string *, string *);

int main(int argc, char *argv[]) {

    short int isPlaying = '1';              // Criando variável que mantém o loop girando
    short int score = 0;                    // Variável que aumenta se o usuário errar uma letra
    char letter = ' ';                      // Variável que armazena a letra que o usuário quer tentar usar

    // Receber entrada de usuário:
    printf("Digite o a palavra: ");
    string word = newWord();                // Recebe uma cópia do tipo string
    system("clear");                        // Limpa a tela

    // criando a string que será imprimida para o jogador
    string secret = hideWord(&word);

    // Gameloop:
    while (isPlaying) {
        system("clear");                    // Limpa o terminal
        letter = ' ';                       // Limpa a letra de teste

        drawGallows(score);                 // Imprimindo a forca

        printf("%s", secret.string);        // Desenha a palavra secreta

        printf("\n\n");                     // Pulando linha

        printf("Digite uma letra: ");
        setbuf(stdin, NULL);                // Limpa o buffer de possíveis remanescentes
        scanf(" %c", &letter);              // Recebe a entrada

        // Laço que limpa qualquer letra a mais que o usuário tenha digitado
        // nós verificamos o próximo caractere no buffer e então ignoramos
        // ele até encontrar o '\n' ou o final do arquivo de buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        //

        setbuf(stdin, NULL);                // Recebe a entrada

        score += (testLetter(letter, word, &secret)) ? 0 : 1;   // Aumenta o Score se o jogador errou

        // Verifica se o jogador perdeu e finaliza o jogo
        if (score >= 6) {
            printf("\n\n");
            printf("||------ Você perdeu! ------||\n");
            drawGallows(score);
            printf("\n\n");
            isPlaying = 0;
        }

        // Verifica se o jogador venceu e finaliza o jogo
        if (checkStrings(&word, &secret)) {
            printf("\n\n");
            printf("||------ Você Venceu! ------||\n");
            drawGallows(score);
            printf("A palavra era: %s", word.string);
            printf("\n\n");
            isPlaying = 0;
        }
    }

    string_free(&word);                     // Liberando a memória
    string_free(&secret);                   // Liberando a memória

    return 0;
}

// Essa função cria um array de char para receber a entrada
// então gera um novo tipo string e retorna uma cópia dele.
string newWord() {
    char array[200];                        // Cria um array para guardar a entrada do usuário
    setbuf(stdin, NULL);                    // limpa o buffer de entrada
    fgets(array, 200, stdin);               // Recebe a entrada
    //scanf("%s", array);
    setbuf(stdin, NULL);                    // limpa o buffer de entrada

    array[strcspn(array, "\n")] = '\0';     // Remove o enter da entrada e substituí por um caractere nulo

    return newString(array);                // Retorna uma variável string
}

// Essa função gera a string que será imprimida para o jogador
// que é iniciada vazia e depois modificada para caber a quantidade
// correta de caractéres. As letras são substituídas por underscore '_'
// e os espaços por traço '-'
string hideWord(string *str) {

    string word = newEmptyString();         // Cria uma nova variável string
    char array[str->size + 1];              // Cria um array de char com o tamanho da palavra-secreta

    // Laço para substituir as letras do array por '_' e '-'
    for (int i = 0; i < str->size; i++) {
        if ((str->string)[i] != ' ') {      // Se o espaço atual da string não for espaço
            array[i] = '_';                 // Preencha com underscore
        }
        else {                              // Se não (se for espaço)
            array[i] = ' ';                 // preencha com espaço
        }
    }
    array[str->size] = '\0';

    // Chamando o método para realocar a memória e atribuir o array
    // para a string e depois retornando a nova variável composta.
    changeString(&word, array);

    //printf("Chegou aqui! -final método-");

    return word;

}

void drawGallows(short int score) {
    /*
        Método que imprime a forca, é apenas visual

        =========
        ||     |
        ||     O
        ||    /|\
        ||    /\
        ||
        [---]

    */
    printf("=========\n");
    printf("||     |\n");
    printf("%s", (score >= 1) ? "||     O\n" : "||\n");
    switch (score) {
        case 2:
            printf("||     |\n");
            break;
        case 3:
            printf("||    /|\n");
            break;
        case 4:
        case 5:
        case 6:
            printf("||    /|\\ \n");
            break;
        default:
            printf("||\n");
            break;
    }
    switch (score) {
        case 5:
            printf("||    / \n");
            break;
        case 6:
            printf("||    / \\ \n");
            break;
        default:
            printf("||\n");
            break;
    }
    printf("||\n");  
    printf("[---]\n");

}


// Método que testa onde a letra se encaixa
short int testLetter(char letter, string str1, string *str2) {

    short int trys = 0;                     // Armazena a quantidade de tentativas
    for (int i = 0; i < str1.size; i++) {   // Laço para comparar as duas strings
        if ((str1.string)[i] == letter) {
            (str2->string)[i] = letter;
            ++trys;
        }
    }

    if (trys >= 1) {                        // Se a letra estava na palavra, retorna true
        return 1;
    }
    return 0;                               // Se a letra NÃO estava na palavra, retorna false
}

short int checkStrings(string *str1, string *str2) {

    int score = 0;                          // Armazena a quantidade de caracteres iguais entre as duas strings

    // Laço que verififica se as duas strings são iguais
    for (int i = 0; i < str1->size; i++) {
        if ((str1->string)[i] == (str2->string)[i]) {
            score++;
        }
    }

    if (score == str1->size) {              // Se todas as letras estão corretas, retorna true
        return 1;
    }
    return 0;                               // Se nem todas as letras estão corretas, retorna false

}