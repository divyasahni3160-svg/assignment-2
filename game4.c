#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

/* ---------------- COLOR & CURSOR ---------------- */

void setColor(int c) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void hideCursor() {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 20;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(out, &info);
}

/* ---------------- DOUBLE BUFFER ---------------- */

HANDLE buf1, buf2;
HANDLE active;

void initBuffer() {
    CONSOLE_CURSOR_INFO ci = {1, FALSE};

    buf1 = CreateConsoleScreenBuffer(GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    buf2 = CreateConsoleScreenBuffer(GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    SetConsoleCursorInfo(buf1, &ci);
    SetConsoleCursorInfo(buf2, &ci);

    active = buf1;
    SetConsoleActiveScreenBuffer(active);
}

void swapBuffer() {
    active = (active == buf1 ? buf2 : buf1);
    SetConsoleActiveScreenBuffer(active);
}

void drawText(int x, int y, char *text) {
    DWORD written;
    COORD pos = {x, y};
    WriteConsoleOutputCharacter(active, text, strlen(text), pos, &written);
}

/* ---------------- GAME CONSTANTS ---------------- */

#define LANES 5
char *laneGraphics[] = {
    "| O         |",
    "|    O      |",
    "|      O    |",
    "|        O  |",
    "|          O|"
};

char *obstacleGraphics[] = {
    "| X         |",
    "|    X      |",
    "|      X    |",
    "|        X  |",
    "|          X|"
};

/* ---------------- TITLE SCREEN ---------------- */

void titleScreen() {
    while (1) {
        for (int i = 0; i < 20; i++)
            drawText(0, i, "                      ");

        setColor(14);
        drawText(2, 2, "===================");
        drawText(2, 3, "  ROAD DODGER 2.0  ");
        drawText(2, 4, "===================");
        setColor(11);
        drawText(2, 7, "Press ENTER to Play");
        drawText(2, 8, "Press ESC   to Quit");

        swapBuffer();
        Sleep(100);

        if (_kbhit()) {
            char key = getch();
            if (key == 13) return;   // ENTER
            if (key == 27) exit(0);  // ESC
        }
    }
}

/* ---------------- GAME LOOP ---------------- */

void playGame() {
    int playerLane = 2;   // center of 5 lanes
    int obstacleLane = rand() % LANES;
    int step = 0;
    int score = 0;
    int speed = 110;

    while (1) {

        /* INPUT */
        if (_kbhit()) {
            char key = getch();
            if (key == 75 && playerLane > 0) playerLane--;    // LEFT
            if (key == 77 && playerLane < LANES - 1) playerLane++; // RIGHT
        }

        /* CLEAR FRAME */
        for (int r = 0; r < 30; r++)
            drawText(0, r, "                      ");

        /* TOP TITLE */
        setColor(11);
        drawText(0, 0, "+-----------+");
        
        /* DRAW OBSTACLE */
        setColor(12);
        for (int y = 0; y < 12; y++) {
            if (y == step) {
                drawText(0, 1 + y, obstacleGraphics[obstacleLane]);
            } else {
                drawText(0, 1 + y, "|           |");
            }
        }

        /* DRAW PLAYER */
        setColor(10);
        drawText(0, 14, laneGraphics[playerLane]);

        /* SCORE */
        char scoreBuf[40];
        setColor(14);
        sprintf(scoreBuf, " SCORE: %d", score);
        drawText(0, 17, scoreBuf);

        /* COLLISION */
        if (step == 13 && obstacleLane == playerLane) {
            setColor(12);
            drawText(0, 20, "   GAME OVER!   ");
            swapBuffer();
            Sleep(1500);
            return; // back to title menu
        }

        Sleep(speed);
        step++;

        /* RESET OBSTACLE */
        if (step > 13) {
            step = 0;
            obstacleLane = rand() % LANES;
            score++;

            if (speed > 30) speed -= 5; // faster over time
        }

        swapBuffer();
    }
}

/* ---------------- MAIN ---------------- */

int main() {
    srand(time(NULL));
    hideCursor();
    initBuffer();

    while (1) {
        titleScreen();
        playGame();
    }

    return 0;
}
