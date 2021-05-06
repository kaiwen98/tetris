
#include <iostream>
#include "tetris.h"
#include <chrono>
#include <thread>
#include "global.h"
#include <utility>

#define NUM_THREADS 5
using namespace std;

int test() {
    char input = '1';
    Block *block = new Block(Z_BLOCK);

    while(input != '!') {
        Sleep(100);
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
                block->set_shape_type(S_BLOCK);
                break;
            case 't':
                block->set_shape_type(T_BLOCK);
                break;
            case 'z':
                block->set_shape_type(Z_BLOCK);
                break;
            case '1':case '0':
                block->manipulate_block_rotation(input - '0');
                break;
        }
        block->print_block_visual();
    }

    return 0;
}

int main() {
    int fall_count = 0;
    char fill = '*';
    COORD p = {0, 0};
    wchar_t *screen = new wchar_t[nScreenWidth * nScreenHeight];
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    Block *block = new Block(L_BLOCK);

    while(1) {
        this_thread::sleep_for(chrono::milliseconds(100));
        if ((fall_count++) % 10 == 0) p.Y += 1;
        if (GetAsyncKeyState((unsigned short)'P') & 0x8000) {
            p.Y--;
        } 
        if (GetAsyncKeyState((unsigned short)'A') & 0x8000) {
            p.X--;
        } 
        if (GetAsyncKeyState((unsigned short)'S') & 0x8000) {
            p.Y++;
        } 
        if (GetAsyncKeyState((unsigned short)'D') & 0x8000) {
            p.X++;
        } 
        if (GetAsyncKeyState((unsigned short)'R') & 0x8000) {
            block->manipulate_block_rotation(1);
        } 
        for (int y = 0; y < nScreenHeight; y++) {
            for(int x = 0; x < nScreenWidth; x++) {
                screen[y * nScreenWidth + x] = ' ';
            }
        }

        for (auto i : block->get_coordinates_nw(p)) {
            for (int y = 0; y < nScreenHeight; y++) {
                for(int x = 0; x < nScreenWidth; x++) {
                    if(x == i.X && y == i.Y) {
                        screen[y * nScreenWidth + x] = 'X';
                    } 
                }
            }
        }
        
        swprintf_s(screen, 40, L"X=%d, X=%d", block->get_coordinates_nw(p).at(1).X, block->get_coordinates_nw(p).at(2).X);

        screen[nScreenWidth * nScreenHeight - 1] = '\0';
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, {0,0}, &dwBytesWritten);
    }
}
