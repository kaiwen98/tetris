#ifndef TETRISH
#define TETRISH

#include <string>
#include <string.h>
#include <vector>
#include "global.h"
using namespace std;

enum 
Block_type {
    I_BLOCK,
    J_BLOCK, 
    L_BLOCK,
    O_BLOCK,
    S_BLOCK,
    T_BLOCK,
    Z_BLOCK
};

class 
Block {
    public:
        Block_type shape_type;

        Block();
        Block(Block_type inp_shape_type);
        ~Block();

        void set_shape_type(Block_type inp_shape_type);
        int get_shape_type();
        vector<int> get_block_mtx();
        void print_block_visual();
        void manipulate_block_rotation(int dir);
        vector<COORD> get_coordinates_nw(COORD start_coord);
    private:
        vector<int> block_mtx;
        void assign_block_mtx();
};

#include "tetris.hpp"
#endif
