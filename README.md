## Caesar Cipher Algorithm
This project aims to be an simple encrypter and decrypter using the caesar cipher.

### How it is structured?
```bash
/caesarCipher
  | caesar_cipher.c // Algorithm logic, all the encrypting and decrypting work is made here.
  | caesar_cipher.h // Header to index encrypting and decrypting functions in a clean way.
  | main.c          // Main code. All data input and output is here.
  | README.md       // Just to give context.
```

### How it works?
It follows the [Caesar Cipher](https://en.wikipedia.org/wiki/Caesar_cipher), so, basically, it generates an key, and based in that key it "shifts" the present char n, where n is the key, char's to the right, when the result is above 26, we take the rest of division by 26, because that way we'll loop trough the alphabet.
