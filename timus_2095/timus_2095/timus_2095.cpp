#include "MyClass.h"
#include <gtest/gtest.h>


int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	int code = RUN_ALL_TESTS();
	return code;
}