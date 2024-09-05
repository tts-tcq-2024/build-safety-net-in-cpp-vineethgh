#include <gtest/gtest.h>
#include "Soundex.h"
 
// Test for isPrevLetterHWY
TEST(SoundexTest, IsPrevLetterHWY) {
    std::string name = "HWY";
    size_t index = 1;
    EXPECT_TRUE(isPrevLetterHWY(name, index));
    name = "HAPPY";
    index = 2;
    EXPECT_FALSE(isPrevLetterHWY(name, index));
}
 
// Test for getSoundexCode
TEST(SoundexTest, GetSoundexCode) {
    EXPECT_EQ(getSoundexCode('A'), '0');
    EXPECT_EQ(getSoundexCode('B'), '1');
    EXPECT_EQ(getSoundexCode('C'), '2');
    EXPECT_EQ(getSoundexCode('D'), '3');
    EXPECT_EQ(getSoundexCode('L'), '4');
    EXPECT_EQ(getSoundexCode('M'), '5');
    EXPECT_EQ(getSoundexCode('R'), '6');
    EXPECT_EQ(getSoundexCode('X'), '2');
    EXPECT_EQ(getSoundexCode('Z'), '2');
    EXPECT_EQ(getSoundexCode('H'), '0');
    EXPECT_EQ(getSoundexCode('W'), '0');
    EXPECT_EQ(getSoundexCode('Y'), '0');
    EXPECT_EQ(getSoundexCode('Q'), '2');
}
 
// Test for generateSoundexIfPrevLetterHWY
TEST(SoundexTest, GenerateSoundexIfPrevLetterHWY) {
    std::string name = "HWY";
    size_t index = 2;
    std::string soundex;
    char lastCode = '0';
    generateSoundexIfPrevLetterHWY(name, index, soundex, lastCode);
    EXPECT_EQ(soundex, "");
}
 
// Test for generateSoundexIfPrevLetterNotHWY
TEST(SoundexTest, GenerateSoundexIfPrevLetterNotHWY) {
    std::string name = "ABCD";
    size_t index = 1;
    std::string soundex;
    char previousCode = '0';
    generateSoundexIfPrevLetterNotHWY(name, index, soundex, previousCode);
    EXPECT_EQ(soundex, "1");
 
    index = 2;
    previousCode = '1';
    generateSoundexIfPrevLetterNotHWY(name, index, soundex, previousCode);
    EXPECT_EQ(soundex, "12");
}
 
// Test for makeSoundeLengthFour
TEST(SoundexTest, MakeSoundeLengthFour) {
    std::string soundex = "A";
    makeSoundeLengthFour(soundex);
    EXPECT_EQ(soundex, "A000");
 
    soundex = "A123";
    makeSoundeLengthFour(soundex);
    EXPECT_EQ(soundex, "A123");
}
 
// Test for generateSoundexForLetter
TEST(SoundexTest, GenerateSoundexForLetter) {
    std::string name = "ABCD";
    size_t index = 1;
    std::string soundex;
    char previousCode = '0';
    char lastCode = '0';
 
    generateSoundexForLetter(name, index, soundex, previousCode, lastCode);
    EXPECT_EQ(soundex, "1");
 
    previousCode = '1';
    lastCode = '1';
    index = 2;
    generateSoundexForLetter(name, index, soundex, previousCode, lastCode);
    EXPECT_EQ(soundex, "12");
}
 
// Test for handleSoundex
TEST(SoundexTest, HandleSoundex) {
    std::string name = "Example";
    std::string soundex;
    soundex = "E";
    handleSoundex(soundex, name);
    EXPECT_EQ(soundex, "E251");
 
    name = "Soundex";
    soundex = "S";
    handleSoundex(soundex, name);
    EXPECT_EQ(soundex, "S532");
 
    name = "HWY";
    soundex.clear();
    soundex = "H";
    handleSoundex(soundex, name);
    EXPECT_EQ(soundex, "H");
}
 
// Test for generateSoundex
TEST(SoundexTest, GenerateSoundex) {
    EXPECT_EQ(generateSoundex("Example"), "E251");
    EXPECT_EQ(generateSoundex("Soundex"), "S532");
    EXPECT_EQ(generateSoundex("HWY"), "H000");
    EXPECT_EQ(generateSoundex(""), "");
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("Abcd"), "A123");
    EXPECT_EQ(generateSoundex("pfister"), "P236");
    EXPECT_EQ(generateSoundex("Tymczak"), "T522");
}
