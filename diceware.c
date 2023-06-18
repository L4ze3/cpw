#include <stdio.h>
#include <stdlib.h>
#include <sodium.h>
#include "wordlist.h"

int randint() {
  uint32_t num = randombytes_uniform(WORD_COUNT);
  return num;
}

char* getrandomword() {
  return dicewords[randint()];
}

void generate_diceware_password(int rolls) {

  for (int i = 0; i < rolls; i++) {
    printf("%s ", getrandomword());
  }
  printf("\n");
}
