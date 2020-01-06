#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

int findFirstVowel(const char *word);

bool isVowel(const char ch, const int position, const int length);

void translateWord(const char *word, char *piglatin);

void translateStream(istream &in, ostream &out);