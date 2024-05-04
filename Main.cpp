#include <conio.h>
#include<stdio.h>
#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define SPACE 32
#define ESC 27

int getInput(int key)
{
    if (_kbhit())
    {
        key = _getch();

        return key;
    }
    return false;
}

void setCursorPointer(int x = 0, int y = 0)
{
    HANDLE handle;
    COORD coordinates;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(handle, coordinates);
}

void drawWhiteSpace(int a_x, int a_y, int b_x, int b_y)
{ // To clean a certain space in the terminal
    for (int i = a_x; i < b_x; i++)
    {
        for (int j = a_y; j < b_y; j++)
        {
            setCursorPointer(i, j); printf(" ");
        }
    }
}

void drawGameFrame(int a_x, int a_y, int b_x, int b_y)
{ // This will draw a rectangular frame defined by two points
    drawWhiteSpace(a_x, a_y, b_x, b_y);
    for (int i = a_x; i < b_x; i++)
    {
        setCursorPointer(i, a_y); printf("%c", 205);
        setCursorPointer(i, b_y); printf("%c", 205);
    }
    for (int i = a_y; i < b_y; i++)
    {
        setCursorPointer(a_x, i); printf("%c", 186);
        setCursorPointer(b_x, i); printf("%c", 186);
    }
    setCursorPointer(a_x, a_y); printf("%c", 201);
    setCursorPointer(b_x, a_y); printf("%c", 187);
    setCursorPointer(a_x, b_y); printf("%c", 200);
    setCursorPointer(b_x, b_y); printf("%c", 188);
}

void gameOverDefeatMessage()
{ // When you lose the game you see this in screen
    int a_x = 94;
    int a_y = 20;
    int b_x = a_x + 23;
    int b_y = a_y + 4;
    setCursorPointer(a_x + 1, a_y + 2); printf("      DEFEAT!!!");
}

void drawScoreFrame(int a_x, int a_y, int b_x, int b_y)
{ // This will draw a rectangular frame defined by two points
    drawWhiteSpace(a_x, a_y, b_x, b_y);
    for (int i = a_x; i < b_x; i++)
    {
        setCursorPointer(i, a_y); printf("%c", 205);
        setCursorPointer(i, b_y); printf("%c", 205);
    }
    for (int i = a_y; i < b_y; i++)
    {
        setCursorPointer(a_x, i); printf("%c", 186);
        setCursorPointer(b_x, i); printf("%c", 186);
    }
    setCursorPointer(a_x, a_y); printf("%c", 201);
    setCursorPointer(b_x, a_y); printf("%c", 187);
    setCursorPointer(a_x, b_y); printf("%c", 200);
    setCursorPointer(b_x, b_y); printf("%c", 188);
}

void drawGameLimits()
{
    // Draws the game limits, and information that doesn't have to be printed repeatedly
    drawGameFrame(1, 1, 150, 49); // The default size of the Windows terminal is 25 rows x 80 columns
    drawScoreFrame(153, 1, 209, 49); // The default size of the Windows terminal is 25 rows x 80 columns
    setCursorPointer(160, 10);
    cout << "LIVES: ";
    setCursorPointer(160, 15);
    cout << "SCORE: ";
    setCursorPointer(160, 5);
    cout << "LEVEL: ";
    setCursorPointer(160, 25);
    cout << "----------------- LAST SCORE -----------------";
    setCursorPointer(155, 46);
    cout << "Instructions: Every asteroid gives you 10 points, the";
    setCursorPointer(155, 47);
    cout << "Level is over when you reach 50 points.(5 Level) ";
    setCursorPointer(155, 48);
    cout << "Game Speed Increase After Every Level";
}

void welcomeMessage()
{
    int x = 77;
    int y = 20;
    setCursorPointer(x, y); cout << " _____                    _____ _           _           ";
    setCursorPointer(x, y + 1); cout << "|   __|___ ___ ___ ___   |   __| |_ ___ ___| |_ ___ ___ ";
    setCursorPointer(x, y + 2); cout << "|__   | . | .'|  _| -_|  |__   |   | . | . |  _| -_|  _|";
    setCursorPointer(x, y + 3); cout << "|_____|  _|__,|___|___|  |_____|_|_|___|___|_| |___|_|  ";
    setCursorPointer(x, y + 4); cout << "      |_|";
    setCursorPointer(x, y + 6); cout << "                 Press any key to play";
    setCursorPointer(x, y + 7); cout << "               Developed By Abdullah Awan";
}



void buildSpaceShip(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3, int& x4, int& y4, int& x5, int& y5, int key)
{
    if (key == 75) {
        setCursorPointer(x1 + 1, y1);
        cout << " ";
        setCursorPointer(x2 + 1, y2);
        cout << " ";
        setCursorPointer(x3 + 1, y3);
        cout << " ";
        setCursorPointer(x4 + 1, y4);
        cout << " ";
        setCursorPointer(x5 + 1, y5);
        cout << " ";
    }

    if (key == 77) {
        setCursorPointer(x1 - 1, y1);
        cout << " ";
        setCursorPointer(x2 - 1, y2);
        cout << " ";
        setCursorPointer(x3 - 1, y3);
        cout << " ";
        setCursorPointer(x4 - 1, y4);
        cout << " ";
        setCursorPointer(x5 - 1, y5);
        cout << " ";
    }

    setCursorPointer(x1, y1);
    printf("%c", 17);
    setCursorPointer(x2, y2);
    printf("%c", 223);
    setCursorPointer(x3, y3);
    printf("%c", 16);
    setCursorPointer(x4, y4);
    printf("%c", 4);
    setCursorPointer(x5, y5);
    printf("%c", 30);
}

void readFile(string filename) {
    int y = 28;
    int i = 0;
    int minimum_level;
    int minimum_score;
    bool flag = false;

    string line = { ' ' };
    ifstream file(filename);

    if (!file.is_open()) {
        setCursorPointer(160, y);
        cout << "File Not Found";
    }
    else {
        getline(file, line);
        setCursorPointer(160, y);
        cout << line;
    }
}

void writeFile(string filename, int level, int score) {
    ofstream file("score.txt");
    file << "Level " << level << " Score " << score << endl;
    file.close();
}

void createAliens(char aliens[][150]) {
    int x = rand() % 148;
    x = x + 2;

    setCursorPointer(x, 2);
    aliens[2][x] = 'X';
    cout << aliens[2][x];
}

void performOperation(char aliens[][150], int& bx, int& x1, int& y1, int& x2, int& y2, int& x3, int& y3, int& x4, int& y4, int& x5, int& y5, int key, bool& isShoot, int& score)
{
    key = getInput(key);

    if (isShoot && key == SPACE) {
        return;
    }

    switch (key) {
    case 75:
        if (x1 == 2) {
            break;
        }

        x1--;
        x2--;
        x3--;
        x4--;
        x5--;
        buildSpaceShip(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, key);

        break;
    case KEY_RIGHT:
        if (x3 == 149) {
            break;
        }

        x1++;
        x2++;
        x3++;
        x4++;
        x5++;
        buildSpaceShip(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, key);
        break;
    case SPACE:
        bx = x5;
        isShoot = true;
    case NULL:
        break;
    }
}

void moveAliens(char aliens[][150], int key, int& score, bool& isKilled, int& speed)
{
    char tempAliens[47][150] = { 0 };

    for (int i = 0; i < 47; i++) {
        for (int j = 0; j < 150; j++) {
            tempAliens[i][j] = aliens[i][j];
        }
    }

    for (int i = 2; i < 47; i++) {
        for (int j = 2; j < 150; j++) {
            if (tempAliens[i][j] == 'X') {
                setCursorPointer(j, i);
                aliens[i][j] = ' ';
                cout << aliens[i][j];

                setCursorPointer(j, i + 1);
                aliens[i + 1][j] = 'X';
                cout << aliens[i + 1][j];

                if (aliens[46][j] == 'X')
                {
                    isKilled = true;
                }
            }
        }
    }

    createAliens(aliens);
}

void shootAlien(char aliens[][150], int& x, int& y, int& score, bool& isShoot) {
    if (y == 2) {
        setCursorPointer(x, y);
        cout << " ";

        isShoot = false;
        y = 44;

        return;
    }

    y--;

    setCursorPointer(x, y + 1);
    cout << " ";
    setCursorPointer(x, y);
    printf("%c", 30);

    if (aliens[y][x] == 'X') {
        aliens[y][x] = ' ';
        score += 10;

        setCursorPointer(170, 15);
        cout << score;

        setCursorPointer(x, y);
        cout << " ";

        y = 44;
        isShoot = false;
    }
}


int main()
{
    system("Color 70");
    system("mode con COLS=700");
    srand(time(0));

    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

    welcomeMessage();
    _getch();

    int speed = 15000;
    int level = 1;
    int lives = 3;
    int interval = 0;
    int Exit = 0;
    string line;
    int i = 0;
    bool flag = true;
    bool isShoot = false;
    int bulltetSpeed = 1000;
    int bulletInterval = 0;

    while (lives > 0 && level <= 5) {
        system("cls");
        drawGameLimits();

        int key = 0, score = 0;
        int x1 = 73, y1 = 48, x2 = 75, y2 = 48, x3 = 77, y3 = 48, x4 = 75, y4 = 47, x5 = 75, y5 = 46, bx = 75, by = 44;
        char aliens[47][150] = { 0 };
        bool isKilled = false;

        buildSpaceShip(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, 0);
        createAliens(aliens);

        setCursorPointer(170, 10);
        cout << lives;

        setCursorPointer(170, 5);
        cout << level;

        while (!isKilled && score < 50)
        {
            performOperation(aliens, bx, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, key, isShoot, score);

            if (isShoot && bulletInterval > bulltetSpeed)
            {
                shootAlien(aliens, bx, by, score, isShoot);
                bulletInterval = 0;
            }

            bulletInterval++;

            if (interval > speed) {
                moveAliens(aliens, key, score, isKilled, speed);
                interval = 0;
            }

            interval++;

            if (flag) {
                readFile("score.txt");
                flag = false;
            }
        }

        if (isKilled) {
            system("cls");
            gameOverDefeatMessage();
            _getch();
            lives--;
        }
        else {
            flag = true;
            writeFile("score.txt", level, score);
            system("cls");
            if (level != 5) {
                setCursorPointer(98, 22);
                cout << "LEVEL " << level << " COMPLETE!!!";
                _getch();
                speed = speed - 2500;
            }
            else if (level == 5) {
                setCursorPointer(98, 22);
                cout << "VICTORY";
                _getch();
                break;
            }
            level++;

        }
    }
}