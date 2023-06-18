#ifndef AES_H
#define AES_H

void encrypt_file(char* input_filename, char* output_filename, unsigned char* key, unsigned char* iv);

void decrypt_file(char* input_filename, char* output_filename, unsigned char* key, unsigned char* iv);


#endif
