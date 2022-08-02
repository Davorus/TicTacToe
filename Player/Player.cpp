//----------------------------------------------------------------
//----------------------------------------------------------------
#include "Player.hpp"
//----------------------------------------------------------------

/*
    So that no own instance of Playfield_Handler is needed, attribute
    is pointer to the already existing Playfield_Handler
*/
bool Player::player_move(Playfield_Handler* p_PH)
{
    /*
        Useless return value, just to prevent an error while compiling
    */
    return true; 
}

int Player::get_stone()
{
    return this->m_stone;
}