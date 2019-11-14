#include "myClass.h"
#include <gtest/gtest.h>
#include <string>

TEST(VacationTest, CorrectAnswer)
{
    EXPECT_EQ(myClass(1, 10), 3);
    EXPECT_EQ(myClass(2, 10), 2);
}

TEST(VacationTest, UpperBound)
{
    EXPECT_TRUE(checkSecondDay(999999999));
    EXPECT_TRUE(checkFirstDay(999999999));
}

TEST(VacationTest, LowerBound)
{
    EXPECT_TRUE(checkFirstDay(1));
    EXPECT_TRUE(checkSecondDay(1));
}

TEST(VacationTest, UnderflowValue)
{
    EXPECT_FALSE(checkFirstDay(0));
    EXPECT_FALSE(checkSecondDay(0));
}

TEST(VacationTest, OverflowValue)
{
    EXPECT_FALSE(checkFirstDay(1000000001));
    EXPECT_FALSE(checkSecondDay(1000000001));
}

TEST(VacationTest, InvalidDataType)
{
    EXPECT_FALSE(firstDayDouble(5.5, 200));
    EXPECT_FALSE(secondDayDouble(4, 100.3));
}

TEST(VacationTest, BelowZero)
{
    EXPECT_FALSE(inputNegative(-5, 10));
    EXPECT_FALSE(inputNegative(2, -6));
}

TEST(VacationTest, SecondDayIsGreaterOrEqual)
{
    EXPECT_TRUE(secondDayIsGreater(2, 10));

    EXPECT_FALSE(secondDayIsGreater(2 , 2));
    EXPECT_FALSE(secondDayIsGreater(10, 2));
}