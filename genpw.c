#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <sodium.h>

void generate_password(int length) {
  srand(time(0));

  char characters[100] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
  
  unsigned int random_num;
  
  for (int i = 0; i <= length; i++) {
    //random_num = randombytes_uniform(100);
    random_num = rand() % 100 + 1;
    printf("%c", characters[random_num]);
  }
  printf("\n");
}

