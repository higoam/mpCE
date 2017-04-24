#define soma_ant 10
#include <stdio.h>

    int nondet_int();

    int get_destination(int vet[6], int N){

      int id;
      int c;
      c = nondet_int();
    
      for(id=0;id<N;id++){
        if(vet[id] != 0){
          __CPROVER_assume( c != id );
        }
      }

      __CPROVER_assume( (c>=0) && (c<N) );

      return c;
    
    }


    int main(){
    
      int Qdestiny = 6;
      int start = 5;
      int lastD = start;
      int step = 1;

      int k=0;
      int i=0, j=0;

      float soma = 0;

      int vet_destiny [6] = {0,0,0,0,0,0};
    
      int mat[6][6];
      mat[0][0] = 0; mat[0][1] = 5; mat[0][2] = 3; mat[0][3] = 6; mat[0][4] = 2; mat[0][5] = 1; 
      mat[1][0] = 5; mat[1][1] = 0; mat[1][2] = 2; mat[1][3] = 4; mat[1][4] = 4; mat[1][5] = 3; 
      mat[2][0] = 3; mat[2][1] = 2; mat[2][2] = 0; mat[2][3] = 1; mat[2][4] = 7; mat[2][5] = 1; 
      mat[3][0] = 6; mat[3][1] = 4; mat[3][2] = 1; mat[3][3] = 0; mat[3][4] = 8; mat[3][5] = 7; 
      mat[4][0] = 2; mat[4][1] = 4; mat[4][2] = 7; mat[4][3] = 8; mat[4][4] = 0; mat[4][5] = 8; 
      mat[5][0] = 1; mat[5][1] = 3; mat[5][2] = 1; mat[5][3] = 7; mat[5][4] = 8; mat[5][5] = 0; 
      
      vet_destiny[lastD] = step;
      
      for(k=0;k<Qdestiny-1;k++){
        j = get_destination(vet_destiny, 6);
        soma = soma + mat[lastD][j];
        lastD = j;
        step = step + 1;
        vet_destiny[lastD] = step;
      }
      
      __CPROVER_assume ( soma < soma_ant);
      
      printf("SOMA = %d!",soma);
      
      printf("{%d#0}",vet_destiny[0]);
      printf("{%d#1}",vet_destiny[1]);
      printf("{%d#2}",vet_destiny[2]);
      printf("{%d#3}",vet_destiny[3]);
      printf("{%d#4}",vet_destiny[4]);
      printf("{%d#5}",vet_destiny[5]);
      printf("!");
      
      assert( soma >= soma_ant);
      return 0;
      
    }
