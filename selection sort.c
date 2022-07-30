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
  while(b != t){
    for(i = t-1; i >= b; i--){
      if(v[i] < min){
        min = v[i];
        hp = i;
      }      
    }
    v[hp] = v[b];
    v[b] = min; 
    min = v[t-1];
    hp = t-1;
    b++;
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