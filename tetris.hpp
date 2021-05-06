#include "tetris.h"
#ifndef TETRISHPP
#define TETRISHPP

Block::Block() {}

Block::~Block() {
    free(char_mtx);
}

Block::Block(Block_type inp_shape_type) {
    set_shape_type(inp_shape_type);
}

int 
Block::get_shape_type() {
    return shape_type;
}

string*
Block::get_char_mtx() {
    return char_mtx;
}

void
Block::set_shape_type(Block_type inp_shape_type) {
    shape_type = inp_shape_type; 
    assign_char_mtx();
    char_arr = convert_to_single_string();
}

void 
Block::assign_char_mtx() {
    string *inp_char_mtx = (string *) calloc(2, sizeof(string));
    switch(shape_type) {
        case I_BLOCK:
            inp_char_mtx[0] = "@@@@";
            inp_char_mtx[1] = "    ";
            break;
        case J_BLOCK:
            inp_char_mtx[0] = "@   ";
            inp_char_mtx[1] = "@@@@";
        break;
        case L_BLOCK:
            inp_char_mtx[0] = "   @";
            inp_char_mtx[1] = "@@@@";
        break;
        case O_BLOCK:
            inp_char_mtx[0] = "@@  ";
            inp_char_mtx[1] = "@@  ";
        break;
        case S_BLOCK:
            inp_char_mtx[0] = " @@ ";
            inp_char_mtx[1] = "@@  ";
        break;
        case T_BLOCK:
            inp_char_mtx[0] = " @  ";
            inp_char_mtx[1] = "@@@ ";
        break;
        case Z_BLOCK:
            inp_char_mtx[0] = "@@  ";
            inp_char_mtx[1] = " @@ ";
        break;
    }
    char_mtx = inp_char_mtx;
}

char* Block::convert_to_single_string() {
    int id = 0;
    char *result = (char*)calloc(16, sizeof(char));
    memset(result, ' ', 16);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            result[id] = char_mtx[i].at(j);
            id++;
        }
    }
    return result;
}

void Block::print_block_visual() {
    for (int row = 0; row < 16; row+=4) {
        for (int j = row; j < row + 4; j++) {
            cout << char_arr[j];
        }
        cout << endl;
    }
}



#endif
