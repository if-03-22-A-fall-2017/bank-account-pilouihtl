#include <stdio.h>

int fibonacci(int n);

int main(int arg, char ** argv){
  for(int i = 0; i < 10; i++){
    int number = fibonacci(i);
    printf("%d \n", number);
  }
  return 1;
}

int fibonacci(int n){
  if(n <= 1){
    return 1;
  }
  int result = fibonacci(n - 1) + fibonacci(n - 2);
  return result;
}
