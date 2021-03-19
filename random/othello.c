#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 8
#define vazio 0        //posição vazia
#define pecaPreta 1    //peça do jogador 1
#define pecaBranca 2   //peça do jogador 2 
#define ACIMA 11
#define ABAIXO 12
#define DIREITA 13
#define ESQUERDA 14
#define DIAGONAL_DIREITA_E_ACIMA 15
#define DIAGONAL_DIREITA_E_ABAIXO 16
#define DIAGONAL_ESQUERDA_E_ACIMA 17
#define DIAGONAL_ESQUERDA_E_ABAIXO 18
int tabuleiro [max][max];
void inicializarTabuleiro(){
    for(int i=0; i<max;i++){
        for(int j =0; j<max; j++){
            tabuleiro[i][j]=0;
        }
    }
    tabuleiro[3][3]=2;
    tabuleiro[4][4]=2;
    tabuleiro[3][4]=1;
    tabuleiro[4][3]=1;
}
void imprimirTabuleiro(){
    printf(" ");
    for(int i=0; i<max;i++) printf("|%d", i);
    printf("|\n");
    for(int i=0; i<max;i++){
        printf("%d|", i);
        for(int j =0; j<max; j++){
            if(tabuleiro[i][j]==pecaBranca) printf("@|");
            if(tabuleiro[i][j]==pecaPreta) printf("#|");
            if(tabuleiro[i][j]==vazio) printf(" |");
        }
        printf("\n");
    }
} 
bool ehPosicaoValida(int linha, int coluna, int jogador){
    int pecaInimiga;
    if(jogador == pecaPreta) pecaInimiga = pecaBranca;
    if(jogador == pecaBranca) pecaInimiga = pecaPreta;
    if(linha >= max || linha<0 || coluna >= max || coluna<0) return 0;
    if(tabuleiro[linha][coluna]==pecaPreta || tabuleiro[linha][coluna]==pecaBranca) return 0;
    //a posicao eh valida se entre tabuleiro[linha][coluna] e tabuleiro[x][y] houver apenas pecas da cor oposta
    //e ainda tablueiro[x][y] deve ter a peca da cor do jogador da vez 
    //checa abaixo
    for(int i=linha+1;i<max-1;i++) 
        if(linha < max-1 && tabuleiro[linha+1][coluna]==pecaInimiga && tabuleiro[i+1][coluna]==jogador) return 1;
    //checa acima
    for(int i=linha-1;i>=1;i--) 
        if(linha >=1 && tabuleiro[linha-1][coluna]==pecaInimiga && tabuleiro[i-1][coluna]==jogador) return 1;
    //checa direita
    for(int i=coluna+1;i<max-1;i++) 
        if(coluna < max-1 && tabuleiro[linha][coluna+1]==pecaInimiga && tabuleiro[linha][i+1]==jogador) return 1;
    //checa esquerda
    for(int i=coluna-1;i>=1;i--) 
        if(coluna >=1 && tabuleiro[linha][coluna-1]==pecaInimiga && tabuleiro[linha][i-1]==jogador) return 1;
    //checa DIAGONAL_DIREITA_E_ABAIXO
    for(int i=1;i+linha<max && i+coluna<max;i++) 
        if(coluna < max-1 && linha < max-1 && tabuleiro[linha+1][coluna+1] == pecaInimiga && tabuleiro[linha+i][coluna+i] == jogador) return 1;
    //checa DIAGONAL_DIREITA_E_ACIMA
    for(int i=1;linha-i>=0 && i+coluna<max;i++) 
        if(coluna < max-1 && linha >= 1 && tabuleiro[linha-1][coluna+1]==pecaInimiga && tabuleiro[linha-i][coluna+i]==jogador) return 1;
    //checa DIAGONAL_ESQUERDA_E_ACIMA
    for(int i=1;linha-i>=0 && coluna-i>=0;i++) 
        if(coluna >= 1 && linha >= 1 && tabuleiro[linha-1][coluna-1]==pecaInimiga && tabuleiro[linha-i][coluna-i]==jogador) return 1;
    //checa DIAGONAL_ESQUERDA_E_ABAIXO
    for(int i=1;linha+i<max && coluna-i>=0;i++) 
        if(coluna < max-1 && linha >= 1 && tabuleiro[linha+1][coluna-1]==pecaInimiga && tabuleiro[linha+i][coluna-i]==jogador) return 1;
    return 0;
}
void reverterPecasDirecao(int linha, int coluna, int jogador, int direcao){
    int pecaInimiga;
    if(jogador == pecaPreta) pecaInimiga = pecaBranca;
    if(jogador == pecaBranca) pecaInimiga = pecaPreta;
    if(direcao == ABAIXO){ 
        for(int i=linha+1;i<max && tabuleiro[i][coluna]!=jogador;i++) tabuleiro[i][coluna]=jogador;
    }
    if(direcao == ACIMA){ 
        for(int i=linha-1;i>=0 && tabuleiro[i][coluna]!=jogador;i--) tabuleiro[i][coluna]=jogador;
    }
    if(direcao == DIREITA){ 
        for(int i=coluna+1;i<max && tabuleiro[linha][i]!=jogador;i++) tabuleiro[linha][i]=jogador;
    }
    if(direcao == ESQUERDA){ 
        for(int i=coluna-1;i>=0 && tabuleiro[linha][i]!=jogador;i--) tabuleiro[linha][i]=jogador;
    }
    if(direcao==DIAGONAL_DIREITA_E_ABAIXO){
        for(int i=1;tabuleiro[linha+i][coluna+i]!=jogador;i++) tabuleiro[linha+i][coluna+i]=jogador;
    }
    if(direcao==DIAGONAL_DIREITA_E_ACIMA){
        for(int i=1;tabuleiro[linha-i][coluna+i]!=jogador;i++) tabuleiro[linha-i][coluna+i]=jogador;
    }
    if(direcao==DIAGONAL_ESQUERDA_E_ACIMA){
        for(int i=1;tabuleiro[linha-i][coluna-i]!=jogador;i++) tabuleiro[linha-i][coluna-i]=jogador;
    }
    if(direcao==DIAGONAL_ESQUERDA_E_ABAIXO){
        for(int i=1;tabuleiro[linha+i][coluna-i]!=jogador;i++) tabuleiro[linha+i][coluna-i]=jogador;
    }
}
void reverterPecas(int linha, int coluna, int jogador){
    int pecaInimiga;
    if(jogador == pecaPreta) pecaInimiga = pecaBranca;
    if(jogador == pecaBranca) pecaInimiga = pecaPreta;
    for(int i=linha+1;i<max-1;i++) 
        if(linha < max-1 && tabuleiro[linha+1][coluna]==pecaInimiga && tabuleiro[i+1][coluna]==jogador)
            reverterPecasDirecao(linha, coluna, jogador,ABAIXO);
    for(int i=linha-1;i>=1;i--) 
        if(linha >=1 && tabuleiro[linha-1][coluna]==pecaInimiga && tabuleiro[i-1][coluna]==jogador)
            reverterPecasDirecao(linha, coluna, jogador,ACIMA);
    for(int i=coluna+1;i<max-1;i++) 
        if(coluna < max-1 && tabuleiro[linha][coluna+1]==pecaInimiga && tabuleiro[linha][i+1]==jogador)
            reverterPecasDirecao(linha, coluna, jogador,DIREITA);
    for(int i=coluna-1;i>=1;i--) 
        if(coluna >=1 && tabuleiro[linha][coluna-1]==pecaInimiga && tabuleiro[linha][i-1]==jogador)
            reverterPecasDirecao(linha, coluna, jogador,ESQUERDA);
    for(int i=1;i+linha<max && i+coluna<max;i++) 
        if(coluna < max-1 && linha < max-1 && tabuleiro[linha+1][coluna+1] == pecaInimiga && tabuleiro[linha+i][coluna+i] == jogador)
            reverterPecasDirecao(linha, coluna, jogador,DIAGONAL_DIREITA_E_ABAIXO);
    for(int i=1;linha-i>=0 && i+coluna<max;i++) 
        if(coluna < max-1 && linha >= 1 && tabuleiro[linha-1][coluna+1]==pecaInimiga && tabuleiro[linha-i][coluna+i]==jogador)
            reverterPecasDirecao(linha, coluna, jogador,DIAGONAL_DIREITA_E_ACIMA);
    for(int i=1;linha-i>=0 && coluna-i>=0;i++) 
        if(coluna >= 1 && linha >= 1 && tabuleiro[linha-1][coluna-1]==pecaInimiga && tabuleiro[linha-i][coluna-i]==jogador)
            reverterPecasDirecao(linha, coluna, jogador,DIAGONAL_ESQUERDA_E_ACIMA);
    for(int i=1;linha+i<max && coluna-i>=0;i++) 
        if(coluna < max-1 && linha >= 1 && tabuleiro[linha+1][coluna-1]==pecaInimiga && tabuleiro[linha+i][coluna-i]==jogador)
            reverterPecasDirecao(linha, coluna, jogador,DIAGONAL_ESQUERDA_E_ABAIXO);
    tabuleiro[linha][coluna]=jogador;
}
bool existeJogada(){
    for(int i =0; i< max; i++)
        for(int j = 0; j<max; j++)
            if(tabuleiro[i][j]==vazio) return 1;
    return 0;
}
void encerrarJogo(){
    int p1=0, p2=0, vencedor;
    printf("Fim do jogo!\n");
    for(int i=0; i<max;i++){
        for(int j =0; j<max; j++){
            if(tabuleiro[i][j]==1) p1++;
            if(tabuleiro[i][j]==2) p2++;
        }
    }
    printf("Pontos do jogador 1: %d\n", p1);
    printf("Pontos do jogador 2: %d\n", p2);
    if(p1>p2) vencedor = pecaPreta;
    else if(p1<p2) vencedor = pecaBranca;
    else vencedor = 0;
    printf("Vencedor: %d\n", vencedor);

}
void menu_opcoes(){
    char opcao;
    printf("a)Entrar com uma jogada\n");
    printf("b)Encerrar jogo\n");
    printf("Escolha a opcao desejada:\n");
    setbuf(stdin, NULL); //limpa buffer do teclado
    scanf("%c", &opcao);
    switch(opcao){
        case 'b': case 'B':
            encerrarJogo();
            exit(EXIT_SUCCESS);
            break;
        case 'a': case 'A':
            break;
        default:
            printf("Opcao invalida!\n");
            menu_opcoes();
    }
}
int main(){
    int jogador = pecaPreta, linha, coluna;
    bool existejogada =1;
    inicializarTabuleiro();
    while(existejogada){
        //system("cls");
        imprimirTabuleiro();
        menu_opcoes();
        printf("Jogador %d\n", jogador);
        printf("Escolha a posicao da nova peca (linha coluna):\n");
        scanf("%d%d", &linha, &coluna);
        while(ehPosicaoValida(linha, coluna, jogador)==0){
            printf("Posicao invalida!\n");
            printf("Escolha a posicao da nova peca (linha coluna):\n");
            scanf("%d%d", &linha, &coluna);
        }
        reverterPecas(linha, coluna, jogador);
        if(jogador==pecaPreta) jogador = pecaBranca;
        else jogador =pecaPreta;
        existejogada = existeJogada();
    }
    encerrarJogo();
    return 0;
}