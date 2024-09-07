#include <iostream>
#include <string>

std::string Remove_vowel(std::string source_str)
{
    std::string ret_str;
    for (int i = 0; i < source_str.length(); ++i)
    {
        int AsciiCode = static_cast<int>(source_str[i]);
        if (AsciiCode == 65 || AsciiCode == 69 || AsciiCode == 73 || AsciiCode == 79 || AsciiCode == 85 ||
            AsciiCode == 97 || AsciiCode == 101 || AsciiCode == 105 || AsciiCode == 111 || AsciiCode == 117)
        {
            continue;
        }
        else
        {
            ret_str.push_back(static_cast<char>(AsciiCode));
        }
    }
    return ret_str;
}