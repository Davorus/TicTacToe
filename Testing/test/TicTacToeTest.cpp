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
        Smart_Bot* smarty = new Smart_Bot(2);
        
        void SetUp() override
        {
            handler->initialize_Playfield(3,3);
        }
};

TEST_F(TicTacToeTest, randys_placement_only_true)
{
    for(int i = 0; i < 100; i++)
    {
        handler->reset_field();
        EXPECT_TRUE(randy->player_move(handler));
    }
}

TEST_F(TicTacToeTest, first_move_random)
{
    EXPECT_TRUE(smarty->player_move(handler));
}

TEST_F(TicTacToeTest, horizontal_move_check)
{
    for(int i = 0; i < 3; i++)
    {
        smarty->player_move(handler); 
    }
    EXPECT_TRUE(smarty->check_horizontal_move(handler));
}