#include <stdio.h>

int modulus(int val, int divisor);

int main(int arg, char** argv){
  for(int i = 0; i < 10; i++){
    int number = modulus(10, i);
    printf("%d \n", number);
  }
  return 1;
}

int modulus(int val, int divisor){
  if(val < divisor || divisor == 0){
    return val;
  }
  if(divisor == 1){
    return 0;
  }
  int n = val - divisor;
  int result =  modulus(n, divisor);
  return result;
}
