#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define t 100

int preencheC(int v[]){ // preenche de forma crescente
  for(int i = 0; i < t; i++){
    v[i] = i+1;
  }
  return 0;
}

int preencheD(int v[]){ // preenche de forma decrescente
  for(int i = 0; i < t; i++){
    v[i] = t - i;
  }
  return 0;
}

int uniqueR(int v[], int i){ // faz com que os numeros da funçao rand sejam unicos
  for(int j = 0; j < i; j++){ // obrigando a repetir o codigo 
    if(v[j] == v[i]) // até q saia um número q n esteja contido
      return 0;
  }
  return 1;
}

int preencheR(int v[]){
  for(int i = 0; i < t; i++){
    v[i] = rand() % t;
    if(uniqueR(v, i) == 0)
      i--; // faz com que a posiçao se repita até que a funçao uniqueR retorne 1
  }
  return 0;
}

int print(int v[]){
  for(int i=0; i<t; i++){
      printf("%d\n", v[i]);
    }printf("\n");
  return 0;
}

double ss(int v[]){
  double time_spent = 0.0;
  clock_t begin = clock();
  
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
  
  clock_t end = clock();
  
  
  return time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
}

int main(void){
  int v[t];
  double time;
  preencheR(v);
  printf("Antes de ordenar:\n");
  print(v);
  time = ss(v);
  printf("Depois de ordenar:\n");
  print(v);
  printf("Tempo: %f\n", time); 
  
  return 0;
}
