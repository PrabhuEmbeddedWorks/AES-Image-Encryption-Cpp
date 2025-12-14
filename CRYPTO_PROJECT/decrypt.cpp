#include <iostream>
#include <fstream>
#include <vector>
#include <openssl/evp.h>
#include <openssl/aes.h>

using namespace std;

int main()
{
    // Same key and IV used for encryption
    unsigned char key[17] = "1234567890123456";
    unsigned char iv[17]  = "6543210987654321";

    // Read encrypted file
    ifstream input("/home/emertxe/Downloads/CRYPTO_PROJECT/encrypted.enc", ios::binary);
    if (!input)
    {
        cout << "Error opening encrypted file!" << endl;
        return 1;
    }

    vector<unsigned char> ciphertext(
        (istreambuf_iterator<char>(input)),
        istreambuf_iterator<char>());

    input.close();

    // Create decryption context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv);

    vector<unsigned char> plaintext(ciphertext.size());
    int len, plaintext_len;

    // Decrypt data
    EVP_DecryptUpdate(ctx,
                      plaintext.data(),
                      &len,
                      ciphertext.data(),
                      ciphertext.size());
    plaintext_len = len;

    EVP_DecryptFinal_ex(ctx,
                        plaintext.data() + len,
                        &len);
    plaintext_len += len;

    // Write decrypted image
    ofstream output("/home/emertxe/Downloads/CRYPTO_PROJECT/decrypted.png", ios::binary);
    output.write((char *)plaintext.data(), plaintext_len);
    output.close();

    EVP_CIPHER_CTX_free(ctx);

    cout << "Image decrypted successfully!" << endl;
    return 0;
}
