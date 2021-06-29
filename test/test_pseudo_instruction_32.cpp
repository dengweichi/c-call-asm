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
#endif