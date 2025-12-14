#include <iostream>
#include <fstream>
#include <vector>
#include <openssl/evp.h>
#include <openssl/aes.h>

using namespace std;

int main()
{
    // 16-byte AES key and IV
    unsigned char key[17] = "1234567890123456";
    unsigned char iv[17]  = "6543210987654321";

    // Read input image in binary mode
    ifstream input("/home/emertxe/Downloads/CRYPTO_PROJECT/sample.png", ios::binary);
    if (!input)
    {
        cout << "Error opening input image!" << endl;
        return 1;
    }

    vector<unsigned char> plaintext(
        (istreambuf_iterator<char>(input)),
        istreambuf_iterator<char>());

    input.close();

    // Create encryption context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv);

    vector<unsigned char> ciphertext(plaintext.size() + AES_BLOCK_SIZE);
    int len, ciphertext_len;

    // Encrypt data
    EVP_EncryptUpdate(ctx,
                      ciphertext.data(),
                      &len,
                      plaintext.data(),
                      plaintext.size());
    ciphertext_len = len;

    EVP_EncryptFinal_ex(ctx,
                        ciphertext.data() + len,
                        &len);
    ciphertext_len += len;

    // Write encrypted file
    ofstream output("encrypted.enc", ios::binary);
    output.write((char *)ciphertext.data(), ciphertext_len);
    output.close();

    EVP_CIPHER_CTX_free(ctx);

    cout << "Image encrypted successfully!" << endl;
    return 0;
}
