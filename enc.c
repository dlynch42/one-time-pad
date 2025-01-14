#include <stdio.h>
#include <stdlib.h>

void encrypt(FILE* secret_file, FILE* encrypted_file, FILE* key_file)
{
    int c;
    while((c=fgetc(secret_file)) != EOF) // read until end of file
    {
        // Generate key
        int key = rand();
        // Encrypted character to write to encrypted file
        int encrypted_c  = c ^ key; // XOR the key

        // For each and every integer we read in from the input file, we generate its own key
        fputc(key, key_file);
        fputc(encrypted_c, encrypted_file);
    }
}

int main(int argc, char* argv[])
{
    // File to encrypt will be first argument
    if(argc != 2) 
    {
        printf("Provide the to-be encrypted file\n");
    }
    else 
    {
        char* secret_file_name = argv[1];
        // Create file pointer by opening file 
        FILE* secret_file = fopen(secret_file_name, "r"); // read file only
        FILE* encrypted_file = fopen("crypt.out", "w"); // write file only
        FILE* key_file = fopen("key.out", "w"); 

        encrypt(secret_file, encrypted_file, key_file);

        fclose(secret_file);
        fclose(encrypted_file);
        fclose(key_file);
    }
}