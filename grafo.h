#pragma once
#include <iostream>
#include <vector>

class Estado {
public:
    int miss_esq, miss_dir;     // quantidade de missionarios
    int can_esq, can_dir;       //quantidade de canibais
    int barco;                //posicao do barco: 0 -> esquerda | 1-> direita
    Estado* pai;

    Estado(int, int, int, int, int);
    
    int operator==(const Estado& x);
    int isValid();
    //int isObj();
    std::vector<Estado*> sucessores();
    void show();
};