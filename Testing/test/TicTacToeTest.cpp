#include <gtest/gtest.h>
#include "../../main.cpp"

class TicTacToeTest : public ::testing::Test
{
    protected:
        void SetUp() override
        {

        }
    public:

};

TEST_F(TicTacToeTest, dummy)
{
    EXPECT_TRUE(true);
}