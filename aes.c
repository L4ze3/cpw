#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define BLOCK_SIZE 16

void encrypt_file(char* input_filename, char* output_filename, unsigned char* key, unsigned char* iv) {
  AES_KEY aes_key;
  FILE* input_filename, output_filename;
  unsigned char input_data[BLOCK_SIZE], output_data[BLOCK_SIZE];
  int num_bytes_read;

  input_file = fopen(input_filename, "rb");
  if (input_file == NULL) {
    fprintf(stderr, "Error: could not open input file %s\n", input_filename);
    exit(EXIT_FAILURE);
  }

  output_file = fopen(output_filename, "wb");
  if (output_file == NULL) {
    fprintf(stderr, "Error: could not open output file %s\n", output_filename);
    exit(EXIT_FAILURE);
  }

  AES_set_encrypt_key(key, 256, &aes_key);

  while ((num_bytes_read = fread(input_data, 1, BLOCK_SIZE, input_file)) > 0) {
    AES_cbc_encrypt(input_data, output_data, BLOCK_SIZE, &aes_key, iv, AES_ENCRYPT);
    fwrite(output_data, 1, BLOCK_SIZE, output_file);
  }

  fclose(input_file);
  fclose(output_file);
}


void decrypt_file(char* input_filename, char* output_filename, unsigned char* key, unsigned char* iv) {
  AES_KEY aes_key;
  FILE* input_filename, output_filename;
  unsigned char input_data[BLOCK_SIZE], output_data[BLOCK_SIZE];
  int num_bytes_read;

  input_file = fopen(input_filename, "rb");
  if (input_file == NULL) {
    fprintf(stderr, "Error: could not open input file %s\n", input_filename);
    exit(EXIT_FAILURE);
  }

  output_file = fopen(output_filename, "wb");
  if (output_file == NULL) {
    fprintf(stderr, "Error: could not open output file %s\n", output_filename);
    exit(EXIT_FAILURE);
  }

  AES_set_decrypt_key(key, 256, &aes_key);

  while ((num_bytes_read = fread(input_data, 1, BLOCK_SIZE, input_file)) > 0) {
    AES_cbc_encrypt(input_data, output_data, BLOCK_SIZE, &aes_key, iv, AES_DECRYPT);
    fwrite(output_data, 1, BLOCK_SIZE, output_file);
  }

  fclose(input_file);
  fclose(output_file);
}
