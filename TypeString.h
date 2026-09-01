#ifndef TypeString_H
#define TypeString_H

/*
    Arquivo de cabeçalho para prototipar os métodos
    e criar variáveis e structs.
*/

// Struct que permite criar o novo tipo da variável string
typedef struct str {

    char *string;
    unsigned int size;

} string;

// Prototipagem dos métodos
string newString(char *);
string newEmptyString();
void changeString(string *, char *);
void string_free(string *);

#endif