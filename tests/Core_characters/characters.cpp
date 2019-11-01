#include "Linuxduino.h"

// Test CHARACTERS functions
int main(void) {

    printf("isAlpha('a') = %d \n", isAlpha('a'));
    printf("isAlpha('1') = %d \n", isAlpha('1'));
    printf("isAlphaNumeric('a') = %d \n", isAlphaNumeric('a'));
    printf("isAlphaNumeric('\\n') = %d \n", isAlphaNumeric('\n'));
    printf("isAscii('a') = %d \n", isAscii('a'));
    printf("isAscii(1234) = %d \n", isAscii(1234));
    printf("isControl('\\r') = %d \n", isControl('\r'));
    printf("isControl('a') = %d \n", isControl('a'));
    printf("isDigit('0') = %d \n", isDigit('0'));
    printf("isDigit('a') = %d \n", isDigit('a'));
    printf("isGraph('a') = %d \n", isGraph('a'));
    printf("isGraph(' ') = %d \n", isGraph(' '));
    printf("isHexadecimalDigit('F') = %d \n", isHexadecimalDigit('F'));
    printf("isHexadecimalDigit('G') = %d \n", isHexadecimalDigit('G'));
    printf("isLowerCase('a') = %d \n", isLowerCase('a'));
    printf("isLowerCase('A') = %d \n", isLowerCase('A'));
    printf("isPrintable('a') = %d \n", isPrintable('a'));
    printf("isPrintable('\\r') = %d \n", isPrintable('\r'));
    printf("isPunct(',') = %d \n", isPunct(','));
    printf("isPunct('a') = %d \n", isPunct('a'));
    printf("isSpace('\\t') = %d \n", isSpace('\t'));
    printf("isSpace('a') = %d \n", isSpace('a'));
    printf("isUpperCase('A') = %d \n", isUpperCase('A'));
    printf("isUpperCase('a') = %d \n", isUpperCase('a'));
    printf("isWhitespace(' ') = %d \n", isWhitespace(' '));
    printf("isWhitespace('a') = %d \n", isWhitespace('a'));

    return 1;
}