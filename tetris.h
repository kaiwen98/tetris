#ifndef TETRISH
#define TETRISH

#include <string>
#include <string.h>
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
        ~Block();
        Block(Block_type inp_shape_type);
        void set_shape_type(Block_type inp_shape_type);
        int get_shape_type();
        string *get_char_mtx();
        char* convert_to_single_string();
        void print_block_visual();
    
    private:
        string *char_mtx;
        char *char_arr;
        void assign_char_mtx();
};

#include "tetris.hpp"
#endif
