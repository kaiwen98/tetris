#include "tetris.h"
#ifndef TETRISHPP
#define TETRISHPP

Block::Block() {}

Block::~Block() {}

Block::Block(Block_type inp_shape_type) {
    set_shape_type(inp_shape_type);
}

int 
Block::get_shape_type() {
    return shape_type;
}

vector<int>
Block::get_block_mtx() {
    return block_mtx;
}

void
Block::set_shape_type(Block_type inp_shape_type) {
    shape_type = inp_shape_type; 
    assign_block_mtx();
}

void 
Block::assign_block_mtx() {
    vector<int> inp_block_mtx;
    switch(shape_type) {
        case I_BLOCK:
            inp_block_mtx = {
                1,1,1,1
                ,0,0,0,0
                ,0,0,0,0
                ,0,0,0,0}; 
            break;
        case J_BLOCK:
            inp_block_mtx = {
                1,0,0,0
                ,1,1,1,1
                ,0,0,0,0
                ,0,0,0,0}; 
        break;
        case L_BLOCK:
            inp_block_mtx = {
                0,0,0,1
                ,1,1,1,1
                ,0,0,0,0
                ,0,0,0,0}; 
        break;
        case O_BLOCK:
            inp_block_mtx = {
                1,1,0,0
                ,1,1,0,0
                ,0,0,0,0
                ,0,0,0,0}; 
        break;
        case S_BLOCK:
            inp_block_mtx = {
                0,1,1,0
                ,1,1,0,0
                ,0,0,0,0
                ,0,0,0,0}; 
        break;
        case T_BLOCK:
            inp_block_mtx = {
                0,1,0,0
                ,1,1,1,0
                ,0,0,0,0
                ,0,0,0,0}; 
        break;
        case Z_BLOCK:
            inp_block_mtx = {
                1,1,0,0
                ,0,1,1,0
                ,0,0,0,0
                ,0,0,0,0}; 
        break;
    }
    block_mtx = inp_block_mtx;
}

void Block::print_block_visual() {
    for (int row = 0; row < 16; row+=4) {
        for (int j = row; j < row + 4; j++) {
            cout << ((block_mtx.at(j)) ? 'x' : ' ');
        }
        cout << endl;
    }
}

int positive_modulo(int i, int n) {
    return ((i % n) + n) % n;
}

COORD calculate_final_pos(COORD start_coord, COORD block_coord) {
    COORD result;
    result.X = positive_modulo(block_coord.X + start_coord.X, nScreenWidth);
    result.Y = positive_modulo(block_coord.Y + start_coord.Y, nScreenHeight);
    return result;
}

vector<COORD> Block::get_coordinates_nw(COORD start_coord) {
    vector<COORD> block_coords;
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if(block_mtx.at(row * 4 + col)) {
                block_coords.push_back(calculate_final_pos(start_coord, {(SHORT)row, (SHORT)col}));
            }
        }
    }
    return block_coords;
}

int calculate_id_rotate(int dir, int id) {
    return (dir == 0) ? 
           (3 - (id % 4)) * 4 + id / 4 :
           ((id % 4) * 4) + (3 - id / 4);
}

void Block::manipulate_block_rotation(int dir) {
    vector<int> block_mtx_new = block_mtx;
    for (int i = 0; i < 16; i++) {
        block_mtx_new[i] = block_mtx[calculate_id_rotate(dir, i)];
    }
    block_mtx = block_mtx_new;
}





#endif
