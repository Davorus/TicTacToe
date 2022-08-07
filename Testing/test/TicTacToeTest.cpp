#include <gtest/gtest.h>
#include "../../Handler/Playfield_Handler.hpp"
#include "../../Handler/Game_Handler.hpp"
#include "../../Handler/Gamesetup_Handler.hpp"
#include "../../Player/Smart_Bot.hpp"
#include "../../Player/Random_Bot.hpp"

class TicTacToeTest : public ::testing::Test
{
    public:
        Playfield_Handler* handler = new Playfield_Handler();
        Random_Bot* randy = new Random_Bot(1);
        
        void SetUp() override
        {
            handler->initialize_Playfield(3,3);
        }
};

TEST_F(TicTacToeTest, randys_placement)
{
    for(int i = 0; i < 100; i++)
    {
        handler->reset_field();
        EXPECT_TRUE(randy->player_move(handler));
    }
}
