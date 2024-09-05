#ifndef SOUNDEX_H
#define SOUNDEX_H
 
#include <iostream>
#include <string>
#include <cctype>
#include <map>
 
std::string generateSoundex(const std::string& name);
bool isPrevLetterHWY(const std::string& name, size_t& i);
char getSoundexCode(char c);
void generateSoundexIfPrevLetterHWY(const std::string& name, size_t& i, std::string& soundex, char& lastCode);
void generateSoundexIfPrevLetterNotHWY(const std::string& name, size_t& i, std::string& soundex, char& previousCode);
void makeSoundeLengthFour(std::string& soundex);
void generateSoundexForLetter(const std::string& name, size_t& i, std::string& soundex, char& previousCode, char& lastCode);
void handleSoundex(std::string& soundex, const std::string& name);
 
#endif // SOUNDEX_H
