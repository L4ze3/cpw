#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

char* sha256_hash(const char* input) {
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256(input, strlen(input), hash);

  char* output = (char*) malloc(2 * SHA256_DIGEST_LENGTH + 1);
  if (output == NULL) {
    fprintf(stderr, "Error: Failed to allocate memory for hash\n");
    exit(EXIT_FAILURE);
  }

  for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    sprintf(output + 2 * i, "%02x", hash[i]);
  }
  output[2 * SHA256_DIGEST_LENGTH] = '\0';

  return output;
}
