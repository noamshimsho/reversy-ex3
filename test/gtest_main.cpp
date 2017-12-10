/*
 * gtest_main.cpp
 *
 *  Created on: 23 בנוב׳ 2017
 *      Author: noam
 */

#include "gtest/gtest.h"


GTEST_API_ int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}


