#include "Soundex.h"
using namespace std;
bool isPrevLetterHWY(const std::string& name, size_t& i) {
  return (name[i-1] == 'H' || name[i-1] == 'W' || name[i-1] == 'Y');
}
char getSoundexCode(char c) {
    std::map<char, char> soundexMap = {
        {'A', '0'}, {'E', '0'}, {'I', '0'}, {'O', '0'}, {'U', '0'},
        {'H', '0'}, {'W', '0'}, {'Y', '0'}, {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };
    auto it = soundexMap.find(toupper(c));
    return (it != soundexMap.end()) ? it->second : '0';
}
void generateSoundexIfPrevLetterHWY(const std::string& name, size_t& i, std::string& soundex, char& lastCode) {
  char currCode = getSoundexCode(name[i]);
  if(lastCode != currCode) {
     soundex += currCode;
  }
}
void generateSoundexIfPrevLetterNotHWY(const std::string& name, size_t& i, std::string& soundex, char& previousCode) {
  if (getSoundexCode(name[i]) != '0' && getSoundexCode(name[i]) != previousCode) {
    soundex += getSoundexCode(name[i]);
  }
}
void makeSoundeLengthFour(std::string& soundex) {
  while (soundex.length() < 4) {
        soundex += '0';
    }
}
void generateSoundexForLetter(const std::string& name, size_t& i, std::string& soundex, char& previousCode, char& lastCode) {
  if (isPrevLetterHWY(name, i)) {
    generateSoundexIfPrevLetterHWY(name, i, soundex, lastCode);
  }
  else {
    generateSoundexIfPrevLetterNotHWY(name, i, soundex, previousCode);
  }
}
void handleSoundex(std::string& soundex, const std::string& name) {
    char previousLetter = toupper(name[0]);
    char previousCode = getSoundexCode(name[0]);
    char lastLetter = toupper(name[0]);
    char lastCode = getSoundexCode(name[0]);
    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
      generateSoundexForLetter(name, i, soundex, lastCode, previousCode);
        lastCode = previousCode;
        previousCode = getSoundexCode(name[i]);
    }
}
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";
    std::string soundex(1, toupper(name[0]));
    handleSoundex(soundex, name);
    makeSoundeLengthFour(soundex);
    return soundex;
}
