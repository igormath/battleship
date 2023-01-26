#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWCOLUMN_MAX 10

char reconvertRow(int row) {
    switch (row) {
        case 0:
            return 'A';
            break;
        case 1:
            return 'B';
            break;
        case 2:
            return 'C';
            break;
        case 3:
            return 'D';
            break;
        case 4:
            return 'E';
            break;
        case 5:
            return 'F';
            break;
        case 6:
            return 'G';
            break;
        case 7:
            return 'H';
            break;
        case 8:
            return 'I';
            break;
        case 9:
            return 'J';
            break;
        default:
            return 'Z';
            break;
    }
}

void resetMatrix(int boardMatrix[][ROWCOLUMN_MAX]) {
    for (int i = 0; i < ROWCOLUMN_MAX; i++) {
        for (int j = 0; j < ROWCOLUMN_MAX; j++) {
            boardMatrix[i][j] = 0;
        }
    }
}

void printBoard(int boardMatrix[][ROWCOLUMN_MAX]) {
    printf("============= SEU MAPA =============\n");
    printf("   1  2  3  4  5  6  7  8  9  10\n");
    for (int i = 0; i < ROWCOLUMN_MAX; i++) {
        printf("%c", reconvertRow(i));
        for (int j = 0; j < ROWCOLUMN_MAX; j++) {
            if (boardMatrix[i][j] == 0) {
                printf("   ");

            } else if (boardMatrix[i][j] == 1) {
                printf("  #");
            }
        }
        printf("\n");
    }
}

void printOpponentBoard(int opponentBoardMatrix[][ROWCOLUMN_MAX]) {
    printf("=========== MAPA OPONENTE ===========\n");
    printf("   1  2  3  4  5  6  7  8  9  10\n");
    for (int i = 0; i < ROWCOLUMN_MAX; i++) {
        printf("%c", reconvertRow(i));
        for (int j = 0; j < ROWCOLUMN_MAX; j++) {
            printf("  ~");
        }
        printf("\n");
    }
}

int convertRow(char row) {
    char lowerCaseChar = tolower(row);

    switch (lowerCaseChar) {
        case 'a':
            return 0;
            break;
        case 'b':
            return 1;
            break;
        case 'c':
            return 2;
            break;
        case 'd':
            return 3;
            break;
        case 'e':
            return 4;
            break;
        case 'f':
            return 5;
            break;
        case 'g':
            return 6;
            break;
        case 'h':
            return 7;
            break;
        case 'i':
            return 8;
            break;
        case 'j':
            return 9;
            break;
        default:
            return -1;
            break;
    }
}

int generateRandomNumber(int floor, int ceil) {
    srand(time(NULL));

    return floor + rand() % (ceil - floor + 1);
}

int validateShipPosition(int shipOp, int row, int column) {
    switch (shipOp) {
        case 1:
            if ((row < 0) || (row > 6)) {
                return 0;
            } else if ((column < 0) || (column > 9)) {
                return 0;
            } else {
                return 1;
            }
            break;

        case 2:
            if ((row < 0) || (row > 6)) {
                return 0;
            } else if ((column < 1) || (column > 8)) {
                return 0;
            } else {
                return 1;
            }
            break;

        case 3:
            if ((row < 0) || (row > 8)) {
                return 0;
            } else if ((column < 2) || (column > 7)) {
                return 0;
            } else {
                return 1;
            }
            break;

        default:
            return 0;
            break;
    }
}

int validateShipOverlap(int shipOp, int row, int column, int boardMatrix[][ROWCOLUMN_MAX]) {
    switch (shipOp) {
        case 1:
            if (boardMatrix[row][column] == 1) {
                return 0;
            } else if (boardMatrix[row + 1][column] == 1) {
                return 0;
            } else if (boardMatrix[row + 2][column] == 1) {
                return 0;
            } else if (boardMatrix[row + 3][column] == 1) {
                return 0;
            } else {
                return 1;
            }
            break;

        case 2:
            if (boardMatrix[row][column] == 1) {
                return 0;
            } else if (boardMatrix[row + 1][column] == 1) {
                return 0;
            } else if (boardMatrix[row + 1][column - 1] == 1) {
                return 0;
            } else if (boardMatrix[row + 1][column + 1] == 1) {
                return 0;
            } else if (boardMatrix[row + 2][column] == 1) {
                return 0;
            } else if (boardMatrix[row + 3][column] == 1) {
                return 0;
            } else {
                return 1;
            }
            break;

        case 3:
            if (boardMatrix[row][column] == 1) {
                return 0;
            } else if (boardMatrix[row + 1][column] == 1) {
                return 0;
            } else if (boardMatrix[row + 1][column - 1] == 1) {
                return 0;
            } else if (boardMatrix[row + 1][column - 2] == 1) {
                return 0;
            } else if (boardMatrix[row + 1][column + 1] == 1) {
                return 0;
            } else if (boardMatrix[row + 1][column + 2] == 1) {
                return 0;
            } else {
                return 1;
            }
            break;
    }
}

void placeShip(int shipOp, int row, int column, int boardMatrix[][ROWCOLUMN_MAX]) {
    switch (shipOp) {
        case 1:
            boardMatrix[row][column] = 1;
            boardMatrix[row + 1][column] = 1;
            boardMatrix[row + 2][column] = 1;
            boardMatrix[row + 3][column] = 1;
            break;

        case 2:
            boardMatrix[row][column] = 1;
            boardMatrix[row + 1][column] = 1;
            boardMatrix[row + 1][column - 1] = 1;
            boardMatrix[row + 1][column + 1] = 1;
            boardMatrix[row + 2][column] = 1;
            boardMatrix[row + 3][column] = 1;
            break;

        case 3:
            boardMatrix[row][column] = 1;
            boardMatrix[row + 1][column] = 1;
            boardMatrix[row + 1][column - 1] = 1;
            boardMatrix[row + 1][column - 2] = 1;
            boardMatrix[row + 1][column + 1] = 1;
            boardMatrix[row + 1][column + 2] = 1;
            break;
    }
}

void placeOpponentShip(int opponentBoardMatrix[][ROWCOLUMN_MAX]) {
    int shipOp, row, column, shipPositionReturn, shipOverlapReturn, dummy = 0;

    shipOp = generateRandomNumber(1, 3);

    while (dummy == 0) {
        row = generateRandomNumber(0, 8);
        column = generateRandomNumber(0, 9);
        if (validateShipPosition(shipOp, row, column) != 0 && validateShipOverlap(shipOp, row, column, opponentBoardMatrix) != 0) {
            placeShip(shipOp, row, column, opponentBoardMatrix);
            dummy = 1;
        }
    }
}

int main() {
    int boardMatrix[ROWCOLUMN_MAX][ROWCOLUMN_MAX], opponentBoardMatrix[ROWCOLUMN_MAX][ROWCOLUMN_MAX], column, shipOp, intRow, shipsQuant, countPieces = 0;
    char row;

    resetMatrix(boardMatrix);
    resetMatrix(opponentBoardMatrix);

    printf("Digite a quantidade de navios de cada jogador na partida: \n");
    scanf("%d", &shipsQuant);

    while (shipsQuant > 0) {
        printf("Escolha o tipo de Navio: \n");
        scanf("%d", &shipOp);
        printf("Digite a coordenada para posicionamento do navio: \n");
        scanf(" %c%d", &row, &column);

        column--;
        intRow = convertRow(row);

        if (validateShipPosition(shipOp, intRow, column) && validateShipOverlap(shipOp, intRow, column, boardMatrix) == 1) {
            placeShip(shipOp, intRow, column, boardMatrix);
            placeOpponentShip(opponentBoardMatrix);
            shipsQuant--;
            printBoard(boardMatrix);
            printf("\n");
            if (shipOp == 1) {
                countPieces += 4;
            } else if (shipOp == 2) {
                countPieces += 6;
            } else if (shipOp == 3) {
                countPieces += 6;
            }
        } else {
            printf("Posicao invalida!\n");
        }
    }
    printBoard(opponentBoardMatrix);

    printf("%d \n", countPieces);

    return 0;
}
