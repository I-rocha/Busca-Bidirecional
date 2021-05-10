#include "grafo.h"

Estado::Estado(int miss_esq, int can_esq, int miss_dir, int can_dir, int barco) {
    this->miss_esq = miss_esq;
    this->miss_dir = miss_dir;
    this->can_esq = can_esq;
    this->can_dir = can_dir;
    this->barco = barco;
    this->pai = nullptr;
}


int Estado::operator==(const Estado& x)
{   
    if ((this->miss_esq == x.miss_esq) && (this->miss_dir == x.miss_dir) &&
        (this->can_esq == x.can_esq) && (this->can_dir == x.can_dir) &&
        (this->barco == x.barco)) return 1;
    return 0;
}

int Estado::isValid() {
    // Estados invalidos
    if (this->miss_esq < 0 || this->can_esq < 0 || this->miss_dir < 0 || this->can_dir < 0
        || this->miss_esq > 3 || this->can_esq > 3 || this->miss_dir > 3 || this->can_dir > 3) return 0;
    // Estados em que perde o jogo
    else if ((this->miss_esq > 0 && this->can_esq > this->miss_esq) || (this->miss_dir > 0 && this->can_dir > this->miss_dir)) return 0;
    return 1;
}

std::vector<Estado*> Estado::sucessores() {
    std::vector<Estado*> field;
    Estado* aux;

    switch (this->barco) {
    case 0:
        aux = new Estado(this->miss_esq - 1, this->can_esq, this->miss_dir + 1, this->can_dir, 1);
        if (aux->isValid()) field.push_back(aux);

        aux = new Estado(this->miss_esq - 1, this->can_esq - 1, this->miss_dir + 1, this->can_dir + 1, 1);
        if (aux->isValid())field.push_back(aux);

        aux = new Estado(this->miss_esq - 2, this->can_esq, this->miss_dir + 2, this->can_dir, 1);
        if (aux->isValid())field.push_back(aux);

        aux = new Estado(this->miss_esq, this->can_esq - 2, this->miss_dir, this->can_dir + 2, 1);
        if (aux->isValid())field.push_back(aux);

        aux = new Estado(this->miss_esq, this->can_esq - 1, this->miss_dir, this->can_dir + 1, 1);
        if (aux->isValid())field.push_back(aux);
        break;
    case 1:
        aux = new Estado(this->miss_esq + 1, this->can_esq, this->miss_dir - 1, this->can_dir, 0);
        if (aux->isValid())field.push_back(aux);

        aux = new Estado(this->miss_esq + 1, this->can_esq + 1, this->miss_dir - 1, this->can_dir - 1, 0);
        if (aux->isValid())field.push_back(aux);

        aux = new Estado(this->miss_esq + 2, this->can_esq, this->miss_dir - 2, this->can_dir, 0);
        if (aux->isValid())field.push_back(aux);

        aux = new Estado(this->miss_esq, this->can_esq + 2, this->miss_dir, this->can_dir - 2, 0);
        if (aux->isValid())field.push_back(aux);

        aux = new Estado(this->miss_esq, this->can_esq + 1, this->miss_dir, this->can_dir - 1, 0);
        if (aux->isValid())field.push_back(aux);
        break;
    default:
        std::cout << "Erro ao iniciar acoes: Posicao de barco inexistente" << std::endl;
    }

    return field;
}

void Estado::show() {
    std::cout << "No" << std::endl;
    std::cout << "Esquerda:" << "(" << this->miss_esq << "," << this->can_esq << ")" << "\t\t";
    std::cout << "Direita:" << "(" << this->miss_dir << "," << this->can_dir << ")" << std::endl << std::endl;
}