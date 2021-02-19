#include "pch.h"
int searchWords(char* string, int size) {
	int amount = 0, curLength = 0;
	char* ptr;
	while (*string != '\0') {
		if (isalpha(*string)) {
			curLength++;
		}
		else {
			if (curLength == size) {
				amount++;
			}
			curLength = 0;
		}
		string++;
	}
	if (curLength == size) {
		amount++;
	}
	return amount;
}

TEST(TestFunction, OneLengthWordTest) {
	char testStr[] = "q w e r t y asd oij qwe njk asp qp";
	int wordSize = 1;
	EXPECT_EQ(searchWords(testStr, wordSize), 6);
}

TEST(TestFunction, TwoLengthWordTest) {
	char testStr[] = "qw jd oijquf uiwhe asdkjb qkj ww";
	int wordSize = 2;
	EXPECT_EQ(searchWords(testStr, wordSize), 3);
}

TEST(TestFunction, ThreeLengthWordTest) {
	char testStr[] = "dhqu kqw hukwq";
	int wordSize = 3;
	EXPECT_EQ(searchWords(testStr, wordSize), 1);
}

TEST(TestFunction, FourLengthWordTest) {
	char testStr[] = "";
	int wordSize = 4;
	EXPECT_EQ(searchWords(testStr, wordSize), 0);
}

TEST(TestFunction, FiveLengthWordTest) {
	char testStr[] = "guijk";
	int wordSize = 5;
	EXPECT_EQ(searchWords(testStr, wordSize), 1);
}

TEST(TestFunction, SixLengthWordTest) {
	char testStr[] = "oiusy tysrthc ytrdou ";
	int wordSize = 6;
	EXPECT_EQ(searchWords(testStr, wordSize), 1);
}

TEST(TestFunction, SevenLengthWordTest) {
	char testStr[] = "hguyr ytduyd qtrfgd g yt j tyd dq";
	int wordSize = 7;
	EXPECT_EQ(searchWords(testStr, wordSize), 0);
}

TEST(TestFunction, EightLengthWordTest) {
	char testStr[] = "duyf erueu fhgh tyfit qwexfds";
	int wordSize = 8;
	EXPECT_EQ(searchWords(testStr, wordSize), 0);
}

TEST(TestFunction, NineLengthWordTest) {
	char testStr[] = "dsad nq kloq cmn qjfhdncew hukwq";
	int wordSize = 9;
	EXPECT_EQ(searchWords(testStr, wordSize), 1);
}