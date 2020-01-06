#include "piglatin.h"
using namespace std;

int findFirstVowel(const char *word) {
    int length = strlen(word);
    for (int i = 0; i < length; ++i) {
        if (isVowel(tolower(word[i]), i, length))
            return i;
    }
    return -1;
}

void translateWord(const char *word, char *piglatin) {
    if (isdigit(word[0])) {
        strcpy(piglatin, word);
        return;
    }

    strcpy(piglatin, "");
    int vowel_i = findFirstVowel(word);

    if (vowel_i == 0) {
        strcpy(piglatin, word);
        strcat(piglatin, "w");
    } else {
        strcpy(piglatin, word+vowel_i);
        int len = strlen(piglatin);
        for (int i = 0; i < vowel_i; ++i)
            piglatin[i+len] = word[i];

        piglatin[len + vowel_i] = '\0';
        piglatin[len] = tolower(piglatin[len]);
    }

    strcat(piglatin, "ay");
    if (isupper(word[0]))
        piglatin[0] = toupper(piglatin[0]);
}

void translateStream(istream &in, ostream &out) {
    char word[64];
    char piglatin[67];

    int i = 0;
    while (isalnum(in.peek())) {
        word[i] = in.get();
        ++i;
    }
    word[i] = '\0';

    translateWord(word, piglatin);
    out << piglatin;

    while (!isalnum(in.peek())) {
        if (in.fail())
            return;

        out << (char) in.get();
    }

    translateStream(in, out);
}

bool isVowel(const char ch, const int position, const int length) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;

    if (ch == 'y' && position != 0 && position != length - 1)
        return true;

    return false;
}