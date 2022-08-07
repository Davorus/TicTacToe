//----------------------------------------------------------------
#ifndef _SMART_BOT_HPP_INCLUDED
#define _SMART_BOT_HPP_INCLUDED
//----------------------------------------------------------------
#include <vector>
//----------------------------------------------------------------
#include "Player.hpp"
//----------------------------------------------------------------

class Smart_Bot : public Player
{
    private:
        int m_stone;
        int m_placed_stones;
        void count_placed_stones(Playfield_Handler* p_PH);
        bool check_next_move(Playfield_Handler* p_PH);
        bool make_random_move(Playfield_Handler* p_PH);
        bool horizontal_move(Playfield_Handler* p_PH);
        bool vertical_move(Playfield_Handler* p_PH);
    public:
        Smart_Bot(int stone);
        bool player_move(Playfield_Handler* p_PH);
        Player_Type get_player_type();
        int get_stone();
};

#endif