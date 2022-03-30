//
// Created by Edin on 23. 03. 2022.
//

#include "Plosca.h"

Plosca plosca_new() { // ker imamo fixno dolzino ne rabimo parametrov
    Plosca this;

    this = (Plosca){
        .height = PLOSCA_ST_VRSTIC,
        .width = PLOSCA_ST_STOLPCEV,
        .active = 0,
        .frames = 0,
        .stevec2DTabele = 0,
    };

    for (int i = 0; i < PLOSCA_ST_ZETONOV; i++) {
        this.zetoni[i].aktiven = 0;
    }

    for (int i = 0; i < PLOSCA_ST_VRSTIC; i++) {
        for (int j = 0; j < PLOSCA_ST_STOLPCEV; j++) {
            this.memo_tabela[i][j] = 0;
        }
    }

    for (int i = 0; i < PLOSCA_ST_STOLPCEV; i++) {
        for (int j = 0; j < PLOSCA_ST_VRSTIC; j++) {
            this.stolpci[i][j] = 0;
        }
    }

    for (int i = 0; i < PLOSCA_ST_STOLPCEV; i++) {
        this.counterjiStolpcev[i] = 0;
    }

    return this;
}

void plosca_popolnjenost_stolpcev(Plosca* plosca, int* tabela, int stolpecCounter, int vrstica) {
    tabela[stolpecCounter] = (plosca->frames % 2 == 0) ? 1 : 2;

    plosca->stevec2DTabele++;
}

int plosca_check_vertical(int dvaDTabela[PLOSCA_ST_VRSTIC][PLOSCA_ST_STOLPCEV], int one) {
    for (int i = 0; i < PLOSCA_ST_STOLPCEV; i++){
        if ((dvaDTabela[0][i] == one && dvaDTabela[1][i] == one && dvaDTabela[2][i] == one && dvaDTabela[3][i] == one))
            return 1;
        if ((dvaDTabela[1][i] == one && dvaDTabela[2][i] == one && dvaDTabela[3][i] == one && dvaDTabela[4][i] == one))
            return 1;
        if ((dvaDTabela[2][i] == one && dvaDTabela[3][i] == one && dvaDTabela[4][i] == one && dvaDTabela[5][i] == one))
            return 1;
    }

    return 0;
}

int plosca_check_horizontal(int dvaDTabela[PLOSCA_ST_VRSTIC][PLOSCA_ST_STOLPCEV], int one) {
    for (int i = 0; i < PLOSCA_ST_VRSTIC; i++) {
        if ((dvaDTabela[i][0] == one && dvaDTabela[i][1] == one && dvaDTabela[i][2] == one && dvaDTabela[i][3] == one))
            return 1;
        if ((dvaDTabela[i][1] == one && dvaDTabela[i][2] == one && dvaDTabela[i][3] == one && dvaDTabela[i][4] == one))
            return 1;
        if ((dvaDTabela[i][2] == one && dvaDTabela[i][3] == one && dvaDTabela[i][4] == one && dvaDTabela[i][5] == one))
            return 1;
        if ((dvaDTabela[i][3] == one && dvaDTabela[i][4] == one && dvaDTabela[i][5] == one && dvaDTabela[i][6] == one))
            return 1;
    }
    return 0;
}

int plosca_check_diagonal_1(int dvaDTabela[PLOSCA_ST_VRSTIC][PLOSCA_ST_STOLPCEV], int one) {
    for (int i = 0; i < PLOSCA_ST_VRSTIC; i++) {
        for (int j = 0; j < PLOSCA_ST_STOLPCEV; j++) {
            if (i < PLOSCA_ST_VRSTIC - 3 && j < PLOSCA_ST_STOLPCEV - 3) {
                if ((dvaDTabela[i][j] == one && dvaDTabela[i+1][j+1] == one && dvaDTabela[i+2][j+2] == one && dvaDTabela[i+3][j+3] == one))
                    return 1;
            }
        }
    }
    return 0;
}

int plosca_check_diagonal_2(int dvaDTabela[PLOSCA_ST_VRSTIC][PLOSCA_ST_STOLPCEV], int one) {
    for (int i = 0; i < PLOSCA_ST_VRSTIC; i++) {
        for (int j = 0; j < PLOSCA_ST_STOLPCEV; j++) {
            if (i < PLOSCA_ST_VRSTIC - 3 && j > PLOSCA_ST_STOLPCEV - 5) {
                if ((dvaDTabela[i][j] == one && dvaDTabela[i+1][j-1] == one && dvaDTabela[i+2][j-2] == one && dvaDTabela[i+3][j-3] == one))
                    return 1;
            }
        }
    }
    return 0;
}

int plosca_is_win(Plosca* plosca, int one, int two) {
    if (plosca_check_vertical(plosca->memo_tabela, one) || plosca_check_vertical(plosca->memo_tabela, two))
        return 1;
    if (plosca_check_horizontal(plosca->memo_tabela, one) || plosca_check_horizontal(plosca->memo_tabela, two))
        return 1;
    if (plosca_check_diagonal_1(plosca->memo_tabela, one) || plosca_check_diagonal_1(plosca->memo_tabela, two))
        return 1;
    if (plosca_check_diagonal_2(plosca->memo_tabela, one) || plosca_check_diagonal_2(plosca->memo_tabela, two))
        return 1;
    return 0;
}