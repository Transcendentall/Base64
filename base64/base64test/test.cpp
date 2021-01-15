#include "pch.h"
#include "gtest/gtest.h"
using namespace std;


TEST(Test1, TestName1) {
	char inputtest[1] = "";
	ASSERT_EQ("", encodeBase64(inputtest));
}
TEST(Test2, TestName2) {
	char inputtest[7] = "qwerty";
	ASSERT_EQ("cXdlcnR5", encodeBase64(inputtest));
}
TEST(Test3, TestName3) {
	char inputtest[2] = " ";
	ASSERT_EQ("IA==", encodeBase64(inputtest));
}
TEST(Test4, TestName4) {
	char inputtest[4] = "Man";
	ASSERT_EQ("TWFu", encodeBase64(inputtest));
}
TEST(Test5, TestName5) {
	char inputtest[270] = "Man is distinguished, not only by his reason, but by this singular passion from other animals, which is a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure.";
	ASSERT_EQ("TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzIHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2YgdGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGludWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRoZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=", encodeBase64(inputtest));
}


TEST(Test6, TestName6) {
	char inputtest[1] = "";
	ASSERT_EQ("", decodeBase64(inputtest));
}
TEST(Test7, TestName7) {
	char inputtest[9] = "cXdlcnR5";
	ASSERT_EQ("qwerty", decodeBase64(inputtest));
}
TEST(Test8, TestName8) {
	char inputtest[5] = "IA==";
	ASSERT_EQ(" ", decodeBase64(inputtest));
}
TEST(Test9, TestName9) {
	char inputtest[5] = "TWFu";
	ASSERT_EQ("Man", decodeBase64(inputtest));
}
TEST(Test10, TestName10) {
	char inputtest[361] = "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzIHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2YgdGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGludWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRoZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=";
	ASSERT_EQ("Man is distinguished, not only by his reason, but by this singular passion from other animals, which is a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure.", decodeBase64(inputtest));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}