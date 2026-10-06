# Cryptography C Programs - Questions 5 to 10

## 5. Affine Caesar Cipher
Allowed values of `a` are values relatively prime to 26:
`1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25`.

There is no special restriction on `b`; for the alphabet, `b` is normally 0 to 25.

## 6. Affine Cipher Cryptanalysis
Using the frequency assumptions B -> E and U -> T:
`a = 3`, `b = 15`.

The program asks for the ciphertext and decrypts it using this key.

## 7. Monoalphabetic Cipher
The program uses frequency-analysis substitutions to decrypt the supplied classical cryptogram.

Plaintext:
A good glass in the bishop's hostel in the devil's seat forty-one degrees and thirteen minutes northeast and by north main branch seventh limb east side shoot from the left eye of the death's-head a bee line from the tree through the shot fifty feet out.

## 8. Keyword Monoalphabetic Cipher
Example keyword: CIPHER

Cipher alphabet:
`CIPHERABDFGJKLMNOQSTUVWXYZ`

## 9. PT-109 Playfair Decryption
Key: `ROYAL NEW ZEALAND NAVY`

Decrypted message:
`PT BOAT ONE OWEN NINE LOST IN ACTION IN BLACK STRAIT TWO MILES SW MERESUCOVE X CREW OF TWELVE X REQUEST ANY INFORMATION X`

(`X` represents Playfair filler/separators.)

## 10. Fixed Playfair Matrix
Given matrix:
M F H I/J K
U N O P Q
Z V W X Y
E L A R G
D S T B C

Plaintext:
`Must see you over Cadogan West. Coming at once.`

Encrypted text:
`UZTBDLGZPNNWLGTGTUEROVLDBDUHFPERHWQSRZ`
