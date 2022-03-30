//
// Created by Edin on 23. 03. 2022.
//

#include "Plosca.h"

Plosca plosca_new() { // ker imamo fixno dolzino ne rabimo parametrov
    Plosca this;

    this = (Plosca){
        .height = PLOSCA_ST_VRSTIC,
        .width = PLOSCA_ST_STOLPCEV,
        .active = false,
        .frames = 0,
    };

    for (int i = 0; i < PLOSCA_ST_ZETONOV; i++) {
        this.zetoni[i].porabljen = false;
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

bool plosca_check_vertical___(Plosca* plosca, int num) {
    for (int i = 0; i < PLOSCA_ST_STOLPCEV; i++){
        if ((plosca->memo_tabela[0][i] == num && plosca->memo_tabela[1][i] == num && plosca->memo_tabela[2][i] == num && plosca->memo_tabela[3][i] == num))
            return true;
        if ((plosca->memo_tabela[1][i] == num && plosca->memo_tabela[2][i] == num && plosca->memo_tabela[3][i] == num && plosca->memo_tabela[4][i] == num))
            return true;
        if ((plosca->memo_tabela[2][i] == num && plosca->memo_tabela[3][i] == num && plosca->memo_tabela[4][i] == num && plosca->memo_tabela[5][i] == num))
            return true;
    }

    return false;
}

bool plosca_check_horizontal___(Plosca* plosca, int num) {
    for (int i = 0; i < PLOSCA_ST_VRSTIC; i++) {
        if ((plosca->memo_tabela[i][0] == num && plosca->memo_tabela[i][1] == num && plosca->memo_tabela[i][2] == num && plosca->memo_tabela[i][3] == num))
            return true;
        if ((plosca->memo_tabela[i][1] == num && plosca->memo_tabela[i][2] == num && plosca->memo_tabela[i][3] == num && plosca->memo_tabela[i][4] == num))
            return true;
        if ((plosca->memo_tabela[i][2] == num && plosca->memo_tabela[i][3] == num && plosca->memo_tabela[i][4] == num && plosca->memo_tabela[i][5] == num))
            return true;
        if ((plosca->memo_tabela[i][3] == num && plosca->memo_tabela[i][4] == num && plosca->memo_tabela[i][5] == num && plosca->memo_tabela[i][6] == num))
            return true;
    }
    return false;
}

bool plosca_check_diagonal_1___(Plosca* plosca, int num) {
    for (int i = 0; i < PLOSCA_ST_VRSTIC; i++) {
        for (int j = 0; j < PLOSCA_ST_STOLPCEV; j++) {
            if (i < PLOSCA_ST_VRSTIC - 3 && j < PLOSCA_ST_STOLPCEV - 3) {
                if ((plosca->memo_tabela[i][j] == num && plosca->memo_tabela[i+1][j+1] == num && plosca->memo_tabela[i+2][j+2] == num && plosca->memo_tabela[i+3][j+3] == num))
                    return true;
            }
        }
    }
    return false;
}

bool plosca_check_diagonal_2___(Plosca* plosca, int num) {
    for (int i = 0; i < PLOSCA_ST_VRSTIC; i++) {
        for (int j = 0; j < PLOSCA_ST_STOLPCEV; j++) {
            if (i < PLOSCA_ST_VRSTIC - 3 && j > PLOSCA_ST_STOLPCEV - 5) {
                if ((plosca->memo_tabela[i][j] == num && plosca->memo_tabela[i+1][j-1] == num && plosca->memo_tabela[i+2][j-2] == num && plosca->memo_tabela[i+3][j-3] == num))
                    return true;
            }
        }
    }
    return false;
}

bool plosca_is_win(Plosca* plosca) {
    for (int i = 1; i <= 2; i++) {
        if (plosca_check_vertical___(plosca, i))
            return true;
        if (plosca_check_horizontal___(plosca, i))
            return true;
        if (plosca_check_diagonal_1___(plosca, i))
            return true;
        if (plosca_check_diagonal_2___(plosca, i))
            return true;
    }
    return false;
}