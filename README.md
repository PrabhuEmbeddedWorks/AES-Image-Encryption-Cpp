This project implements an AES-based image encryption and decryption tool using C++ and the OpenSSL cryptographic library. The application secures image files by encrypting their binary data using the Advanced Encryption Standard (AES) and restores the original image using the same secret key and initialization vector.

Features:
AES-128 encryption using CBC (Cipher Block Chaining) mode
Supports image formats such as PNG, JPG, BMP, and other binary files
Uses OpenSSL EVP APIs for secure cryptographic operations
Ensures complete data recovery after decryption
Command-line based implementation
Linux compatible

Technologies Used:
Programming Language: C++
Cryptographic Library: OpenSSL
Encryption Algorithm: AES-128 (CBC Mode)
Operating System: Linux (Ubuntu)

Project Structure
AES-Image-Encryption-Cpp/
AES-Image-Encryption-Cpp/ → encrypt.cpp, decrypt.cpp, sample.png, encrypted.enc, decrypted.png, README.md

Prerequisites:
Install the OpenSSL development package:
sudo apt update
sudo apt install libssl-dev

Verify installation:
openssl version

Compilation:
Compile the encryption and decryption programs using the following commands:

g++ encrypt.cpp -o encrypt -lssl -lcrypto
g++ decrypt.cpp -o decrypt -lssl -lcrypto

Usage:
Encrypt Image

Run the encryption program:
./encrypt

This generates the encrypted file:
encrypted.enc

Decrypt Image
Run the decryption program:
./decrypt

This restores the original image as:
decrypted.png

To view the original and decrypted images:
xdg-open sample.png
xdg-open decrypted.png

The decrypted image should be identical to the original image.
 
Verify that the decrypted image matches the original using SHA-256:
sha256sum sample.png decrypted.png
Matching hash values confirm successful encryption and decryption without data loss.
