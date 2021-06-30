#include "gtest/gtest.h"

#ifdef BITS_32
extern "C" {
	int externVar = 0;
	extern void testExternFun(void );
}

TEST(test_extern_32, test_pseudo_instruction_32) {
    EXPECT_EQ(externVar, 0);
    testExternFun();
    EXPECT_EQ(externVar, 1);
}

extern "C" {
    extern int testGlobalVar;
    extern int testGlobalFun();
}

TEST(test_global_32, test_pseudo_instruction_32) {
    EXPECT_EQ(testGlobalVar, 1);
    EXPECT_EQ(testGlobalFun(), 1);
}

extern "C" {
    extern int testEquFun();
}
TEST(test_equ_32, test_pseudo_instruction_32) {
    EXPECT_EQ(testEquFun(), 6);
}

extern "C" {
    extern int testTimesFun();
}
TEST(test_times_32,test_pseudo_instruction_32){
    EXPECT_EQ(testTimesFun(), 10);
}
#endif