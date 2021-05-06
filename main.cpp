#include <iostream>
#include "tetris.h"

#define NUM_THREADS 5

using namespace std;

int main() {
    char input = '1';
    Block *block = new Block(Z_BLOCK);

    while(input != '0') {
        cin >> input;
        switch(input) {
            case 'i':
                block->set_shape_type(I_BLOCK);
                break;
            case 'j':
                block->set_shape_type(J_BLOCK);
                break;
            case 'l':
                block->set_shape_type(L_BLOCK);
                break;
            case 'o':
                block->set_shape_type(O_BLOCK);
                break;
            case 's':
                block->set_shape_type(I_BLOCK);
                break;
            case 't':
                block->set_shape_type(I_BLOCK);
                break;
            case 'z':
                block->set_shape_type(I_BLOCK);
                break;
        }
        block->print_block_visual();
    }

    return 0;
}