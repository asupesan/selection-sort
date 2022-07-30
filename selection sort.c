#include <stdio.h>
#include <stdlib.h>
#define t 100

int preencheC(int v[]){
  for(int i = 0; i < t; i++){
    v[i] = i+1;
  }
  return 0;
}

int preencheD(int v[]){
  for(int i = 0; i < t; i++){
    v[i] = t - i;
  }
  return 0;
}

int preencheR(int v[]){
  for(int i = 0; i < t; i++){
    v[i] = rand() % t;
  }
  return 0;
}

int print(int v[]){
  for(int i=0; i<t; i++){
      printf("%d\n", v[i]);
    }printf("\n");
  return 0;
}

int ss(int v[]){
  int i = t-1, min = v[i], hp = i, b = 0;
  while(b != t){ // condiçao de parada
    for(i = t-1; i >= b; i--){ // navegar no vetor
      if(v[i] < min){ // condiçao para selecionar os parametros a serem armazenados
        min = v[i]; // armazenar valor minimo
        hp = i; // armazenar posiçao no minimo
      }      
    }
    v[hp] = v[b]; //inicio da troca, trocando o menor encontrado pelo armazenado na posiçao considerada inferior
    v[b] = min;  // da à posiçao inferior o valor do minimo
    min = v[t-1]; // atualiza o minimo para o ultimo valor do vetor dnv
    hp = t-1; // atualiza a posiçao para a ultima do vetor dnv
    b++; // incrementa o criterio de parada e sobe o valor da posicáo considerada inferior
  // print(v);
  }
  return 0;
}

int main(void){
  int v[t];

  preencheR(v);
  printf("Antes de ordenar:\n");
  print(v);
  ss(v);
  printf("Depois de ordenar:\n");
  print(v);
    
    return 0;
}
