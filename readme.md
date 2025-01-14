# One-Time Pad Encryption Project

## Introduction

### What is One-Time Pad?
The One-Time Pad (OTP) is an encryption technique that provides theoretically unbreakable security when used correctly. It employs a key that is as long as the message to be encrypted, with each character of the message being XORed with the corresponding character of the key. The randomness and uniqueness of the key for every encryption ensure absolute security.

## How It Works
1. The program takes a text file as input and generates:
   - An encrypted file (`crypt.out`).
   - A corresponding key file (`key.out`), which is necessary for decryption.
2. The output encrypted file is completely random, making it impossible to deduce the original message without the key.
3. The key must be kept secure and should never be reused.

### Contrasts with Traditional Encryption:
- Traditional methods use shorter passwords or keys with algorithms to encrypt data.
- OTP ensures that the key is the same size as the plaintext, which makes brute-forcing impossible.

## Encryption Algorithm
1. **Input Files:**
   - A plaintext file to be encrypted.
   - A random key is generated for each character in the plaintext.
2. **Processing:**
   - XOR each character in the plaintext with a random key value.
   - Save the result in the encrypted file (`crypt.out`) and the key in the key file (`key.out`).
3. **Output Files:**
   - `crypt.out`: The encrypted data.
   - `key.out`: The randomly generated key.

Refer to the `enc.c` file for the implementation.

## Decryption Algorithm
1. **Input Files:**
   - The encrypted file (`crypt.out`).
   - The key file (`key.out`).
2. **Processing:**
   - XOR each character in the encrypted file with the corresponding character in the key file.
   - This reverses the XOR operation, restoring the original plaintext.
3. **Output Files:**
   - `decrypt.out`: The decrypted text, which matches the original plaintext.

Refer to the `dec.c` file for the implementation.

## How to Use

### Compilation
To compile the encryption and decryption programs, use the following commands:
```bash
gcc -o encrypt enc.c
gcc -o decrypt dec.c
```

### Encryption 
Run the encryption program with the file to be encrypted:
```bash
./encrypt <plaintext_file>
```

This will generate two files:

- `crypt.out`: The encrypted file.
- `key.out`: The key file.

### Decryption
Run the decryption program with the encrypted file and key file:

```bash
./decrypt crypt.out key.out
```
This will generate `decrypt.out`, which contains the original plaintext.

### Important Notes

- The key file is essential for decryption. If lost, the encrypted file cannot be decrypted.
- Ensure that the key is kept secure and is not reused, as reuse compromises the security of the encryption.