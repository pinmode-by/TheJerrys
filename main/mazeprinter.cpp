#include <stdio.h>
#include <string>
#include <iostream>
#include <array>
#include <vector>
#include "maze.cpp"
#define NORTH 1
#define EAST 2
#define SOUTH 4
#define WEST 8

int main()
{
    std::vector<std::string> rows;
    std::vector<std::string> columns;

    //First row (always the same)
    for(int i = 0; i < 16; i++){
        std::cout << "o---";
    }
    std::cout << 'o' << std::endl;

    int cell = 0;
    for(int i = 16; i > 1; i--){
        // Print columns
        for(int j = 0; j < 16; j++){
            cell = (i-1) + 16*j;
            if(testmaze[cell] & WEST){
                //std::cout << "|   ";
                printf("|   ");
            }
            else{
                //std::cout << "    ";
                printf("    ");
            }
        }
        std::cout << '|' << std::endl;

        // Print rows
        for(int j = 0; j < 16; j++){
            cell = (i-1) + 16*j;
            if(testmaze[cell] & SOUTH){
                //std::cout << "o---";
                printf("o---");
            }
            else{
                //std::cout << "o   ";
                printf("o   ");
            }
        }
        std::cout << 'o' << std::endl;
    }
    for(int j = 0; j < 16; j++){
        cell = 16*j;
        if(testmaze[cell] & WEST){
            printf("|   ");
        }
        else{
            printf("    ");
        }
    }
    std::cout << '|' << std::endl;

    for(int i = 0; i < 16; i++){
        std::cout << "o---";
    }
    std::cout << 'o' << std::endl;

    return 0;
}
