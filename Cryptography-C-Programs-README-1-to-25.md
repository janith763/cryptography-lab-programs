# Cryptography C Programs (Questions 1–25)

This repository contains C programs prepared for cryptography coursework. Each source file is named by question number.

## Programs

| Question | Program / Topic | Source file |
|---:|---|---|
| 1 | Caesar Cipher | `01_Caesar_Cipher.c` |
| 2 | Monoalphabetic Substitution Cipher | `02_Monoalphabetic_Substitution.c` |
| 3 | Playfair Cipher | `03_Playfair_Cipher.c` |
| 4 | Not included in the supplied ZIP files | Add the Question 4 program if required |
| 5 | Affine Caesar Cipher | `05_Affine_Caesar_Cipher.c` |
| 6 | Affine Cipher Cryptanalysis | `06_Affine_Cipher_Cryptanalysis.c` |
| 7 | Monoalphabetic Cipher Decryption | `07_Monoalphabetic_Cipher_Decryption.c` |
| 8 | Keyword Monoalphabetic Cipher | `08_Keyword_Monoalphabetic_Cipher.c` |
| 9 | Playfair Cipher Decryption (PT109 example) | `09_PT109_Playfair_Decrypt.c` |
| 10 | Playfair Cipher Encryption with Fixed Matrix | `10_Playfair_Fixed_Matrix_Encrypt.c` |
| 11 | Playfair Keyspace Calculation | `11_Playfair_Keyspace.c` |
| 12 | Hill Cipher (2×2) | `12_Hill_Cipher_2x2.c` |
| 13 | Hill Cipher Known-Plaintext Attack | `13_Hill_Known_Plaintext_Attack.c` |
| 14 | One-Time Pad / Vigenère-Style Cipher | `14_One_Time_Pad_Vigenere.c` |
| 15 | Additive Cipher Frequency Attack | `15_Additive_Cipher_Frequency_Attack.c` |
| 16 | Monoalphabetic Cipher Frequency Attack | `16_Monoalphabetic_Frequency_Attack.c` |
| 17 | DES Decryption Key Order | `17_DES_Decryption_Key_Order.c` |
| 18 | DES Subkey Bit Structure | `18_DES_Subkey_Bit_Structure.c` |
| 19 | Triple DES in CBC Mode (OpenSSL example) | `19_TripleDES_CBC_OpenSSL.c` |
| 20 | ECB vs CBC Error Propagation | `20_ECB_CBC_Error_Propagation.c` |
| 21 | ECB, CBC, CFB and Padding Demonstration | `21_ECB_CBC_CFB_Padding.c` |
| 22 | S-DES in CBC Mode | `22_SDES_CBC.c` |
| 23 | S-DES in Counter (CTR) Mode | `23_SDES_CTR.c` |
| 24 | RSA Private-Key Calculation | `24_RSA_Private_Key.c` |
| 25 | RSA Common-Factor / GCD Demonstration | `25_RSA_Common_Factor.c` |

## How to compile and run

On macOS or Linux, open Terminal and move into the folder containing the source file. Compile one program at a time:

```bash
gcc 01_Caesar_Cipher.c -o caesar
./caesar
```

Replace the source filename and executable name with the program you want to run. If your compiler uses C99 or later, this is also suitable:

```bash
gcc -std=c99 filename.c -o program
./program
```

Some programs may require extra libraries or adjustments depending on your system. For example, the Triple DES/OpenSSL example may require OpenSSL development headers and linking options.

## Notes

- Question 4 was not present in the program ZIP files previously created, so its filename/topic is intentionally marked as missing. Add the correct Q4 program before claiming that all 25 source files are present.
- Questions 17 and 18 are explanatory demonstrations of DES key scheduling concepts, rather than a complete DES implementation.
- Question 21 uses a toy XOR transformation to illustrate mode structure and padding; it is not secure encryption.
- Questions 22 and 23 use an educational S-DES implementation. Confirm the bit ordering and outputs against the exact test vectors required by your course before submission.
- Question 16 uses a simple frequency-analysis heuristic, so its suggested plaintext may need manual correction.
- Triple DES is a legacy cipher and should not be used for new real-world security systems. For real applications, use a well-reviewed cryptographic library and modern authenticated encryption such as AES-GCM.

## Uploading to GitHub

1. Open your GitHub repository.
2. Select **Add file → Upload files**.
3. Upload the `.c` source files and this `README.md`.
4. Review the file list and click **Commit changes**.

This README documents the programs from Questions 1–25. It does not replace any missing source files; check the repository file list before submission.
