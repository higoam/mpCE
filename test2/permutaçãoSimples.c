#include <stdio .h>
 
#define NMAX 101 //Esta é uma constante que define o tamanho do vetor
#define NIVELMAX 5 //Esta constante define o número de níveis (número de caracteres numa permutação)
#define NUMEROS 2 //Esta constante define o número de números pelo qual a permutação passa.
 
int n[NMAX]; //Define o vetor "n" que contém os números pelo qual a permutação vai passando.
 
void permuta(int nivel) { //Inicia função que faz a permutação
        int i; //Define a variável i (contadora)
 
        if (nivel< =NIVELMAX) { //Se o nível for menor ou igual o nível
                for (i=1; i<=NUMEROS; i++) { //Laço para chamar uma função para cada valor diferente desse.
                        n[nivel]=i; //Define o número atual para i (o valor do laço)
                        permuta(nivel+1); //Chama a função (continua a recursão)
                } //Fim-para
        } else { //Senão
                //Imprime todas os números
                for (i=1; i<=NIVELMAX; i++) { //Laço para pegar os números de todas as funções
                        printf("%d", n[i]);
                } //Fim-para
                printf("n"); //Pula uma linha
        } //Fim-se
} //Fim da função
 
int main(void) { //Começa a função "main"
        int i; //Define a variável i (contadora)
 
        //Primeiro, zeramos o vetor "n" que contém os números que vão ser escritos.
        for (i=1; i<=NIVELMAX; i++) { //Laço
                n[i]=1;
        } //Fim-para
 
        //Chama a função com nível 1.
        permuta(1);
} //Fim-função