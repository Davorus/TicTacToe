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
        bool check_for_legal_play(int y_axis, int x_axis) const;
        bool check_horizontal_winner(int stone);
        bool check_vertical_winner(int stone);
        bool check_diagonal_winner(int stone);
        bool check_winner_diagonal_left_right(int stone);
        bool check_winner_diagonal_right_left(int stone);
    public:
        Playfield_Handler();
        void initialize_Playfield(int rows, int columns);
        void print_Playfield() const;
        bool player_move(int y_axis, int x_axis, int player_stone);
        bool check_playfield_full();
        int get_rows();
        int get_columns();
        bool check_winner(int stone);
};

#endif