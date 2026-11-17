# Cryptography C Programs 26–40

Contains 15 individual C source files for GitHub upload.

## Compile
Most files:
`gcc filename.c -o program && ./program`

Program 33 requires OpenSSL 3 with the legacy DES provider:
`gcc 33_DES_Encryption_OpenSSL.c -o des -lcrypto`

## Notes
- Educational lab demonstrations only; do not use these toy examples for real security.
- Program 29 assumes the Keccak permutation is ignored, so capacity lanes remain zero indefinitely.
- Programs 37 and 40 provide a basic frequency heuristic, not a guaranteed automatic substitution-cipher solver or true top-10 ranking.
- Program 39 provides a simple additive/Caesar frequency heuristic.
- Program 30 explains the CBC-MAC variable-length weakness; secure deployments should use CMAC or length/domain separation.
