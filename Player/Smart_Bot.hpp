//----------------------------------------------------------------
#ifndef _SMART_BOT_HPP_INCLUDED
#define _SMART_BOT_HPP_INCLUDED
//----------------------------------------------------------------
//----------------------------------------------------------------
#include "Player.hpp"
//----------------------------------------------------------------

class Smart_Bot : public Player
{
    private:
        int m_stone;
        bool first_move_made;
        int x_pos;
        int y_pos;
        bool check_horizontal_move(Playfield_Handler* p_PH);
    public:
        Smart_Bot(int stone);
        bool player_move(Playfield_Handler* p_PH);
        Player_Type get_player_type();
        int get_stone();
};

#endif