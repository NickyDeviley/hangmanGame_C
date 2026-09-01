# Jogo da Forca em C - Aplicação de terminal utilizando a biblioteca personalizada TypeString.

### Descrição:
Este projeto é uma implementação do clássico "Jogo da Forca" em linguagem C para terminal. Ele resolve o desafio de manipular dinamicamente entradas de texto e estados do jogo ao integrar a biblioteca personalizada TypeString. O sistema permite que um jogador defina uma palavra secreta e outro tente adivinhá-la letra por letra, gerenciando o estado visual da forca, a revelação progressiva das letras ocultas e a liberação correta de memória alocada na heap.

### Pré-requisitos:

    Compilador C: GCC, Clang ou MSVC (suporte ao padrão C99 ou superior).

    Biblioteca Local: Módulo TypeString (TypeString.h e TypeString.c).

### Instalação/Uso:

    Clone ou baixe os arquivos do projeto para o seu diretório local, garantindo que os arquivos da biblioteca TypeString estejam na mesma pasta.

    Compile o código no terminal incluindo a biblioteca personalizada e a classe principal:

    gcc main.c TypeString.c -o forca

Execute o programa:

 Linux / macOS:
        ./forca

  Windows:
        .\forca.exe

### Regras de Jogo:

        Digite a palavra ou frase secreta e pressione Enter.

        A tela será limpa automaticamente para esconder a palavra.

        Insira uma letra por rodada para tentar adivinhar a palavra secreta.

        O jogo termina ao acertar todas as letras (Vitória) ou acumular 6 erros (Derrota).

### Tecnologias:

    Linguagem C

    TypeString (Biblioteca própria para alocação dinâmica de strings)

    GCC (Compilador)

### Licença:
MIT License
