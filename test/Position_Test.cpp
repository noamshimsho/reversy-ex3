/*
 * Position_Test.cpp
 *
 *  Created on: 23 בנוב׳ 2017
 *      Author: noam
 */

#include "Position.h"
#include "gtest/gtest.h"
#include <iostream>


TEST(Positiotest, start) {
	Position p(1,1);
	Position p1(1,1);
	EXPECT_EQ(p.getColumn(), 1);
	EXPECT_EQ(p.getRow(), 1);
	EXPECT_TRUE(p == p1);

}


