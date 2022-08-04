//----------------------------------------------------------------
#include <random>
//----------------------------------------------------------------
#include "Random_Bot.hpp"
//----------------------------------------------------------------

/*
    His instance number in creation is his marking on the playfield
*/
Random_Bot::Random_Bot(int stone)
    :m_stone{stone}
{
}

bool Random_Bot::player_move(Playfield_Handler* p_PH)
{
    std::random_device rand;
    std::default_random_engine reng(rand());
    /*
        Two random numbers needed to place the stone on the field
    */
    std::uniform_int_distribution<int> r_distr(0, p_PH->get_rows());
    std::uniform_int_distribution<int> c_distr(0, p_PH->get_columns());
    
    return p_PH->player_move(r_distr(reng), c_distr(reng), this->m_stone);
}

int Random_Bot::get_stone()
{
    return this->m_stone;
}