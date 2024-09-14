#include <iostream>
#include <string>
    #include "src/Remove_vowel.cpp"
using namespace std;

int main()
{
    string source_str;
    getline(cin, source_str);
    string new_str = Remove_vowel(source_str);
    cout << new_str << endl;
}