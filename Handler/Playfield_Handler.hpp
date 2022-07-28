//----------------------------------------------------------------
#ifndef _PLAYFIELD_HANDLER_HPP_INCLUDED
#define _PLAYFIELD_HANDLER_HPP_INCLUDED
//----------------------------------------------------------------
#include <vector>
//----------------------------------------------------------------
//----------------------------------------------------------------

class Playfield_Handler
{
    private:
        bool m_gameStarted;
        std::vector<std::vector<int>> m_playfield;
        int m_rows;
        int m_columns;
    public:
        Playfield_Handler();
        void initialize_Playfield(int rows, int columns);
        void print_Playfield() const;
        void check_for_legal_play() const;
};

#endif