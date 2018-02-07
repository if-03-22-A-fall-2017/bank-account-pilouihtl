#include <stdio.h>

int fakult(int n);
int main(int arg, char** argv){
  for(int i = 0; i < 10; i++){
    int number = fakult(i);
    printf("%d \n", number);
  }
  return 1;
}

int fakult(int n){
  if(n == 1){
    return 1;
  }
  if(n <= 0){
    return 0;
  }
  int number = n * fakult(n - 1);
  return number;
}
