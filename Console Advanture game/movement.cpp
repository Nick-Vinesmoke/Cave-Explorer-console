/*
███╗░░██╗██╗░█████╗░██╗░░██╗░░░░░░██╗░░░██╗██╗███╗░░██╗███████╗░██████╗███╗░░░███╗░█████╗░██╗░░██╗███████╗
████╗░██║██║██╔══██╗██║░██╔╝░░░░░░██║░░░██║██║████╗░██║██╔════╝██╔════╝████╗░████║██╔══██╗██║░██╔╝██╔════╝
██╔██╗██║██║██║░░╚═╝█████═╝░█████╗╚██╗░██╔╝██║██╔██╗██║█████╗░░╚█████╗░██╔████╔██║██║░░██║█████═╝░█████╗░░
██║╚████║██║██║░░██╗██╔═██╗░╚════╝░╚████╔╝░██║██║╚████║██╔══╝░░░╚═══██╗██║╚██╔╝██║██║░░██║██╔═██╗░██╔══╝░░
██║░╚███║██║╚█████╔╝██║░╚██╗░░░░░░░░╚██╔╝░░██║██║░╚███║███████╗██████╔╝██║░╚═╝░██║╚█████╔╝██║░╚██╗███████╗
╚═╝░░╚══╝╚═╝░╚════╝░╚═╝░░╚═╝░░░░░░░░░╚═╝░░░╚═╝╚═╝░░╚══╝╚══════╝╚═════╝░╚═╝░░░░░╚═╝░╚════╝░╚═╝░░╚═╝╚══════╝

https://github.com/Nick-Vinesmoke
*/

#include "include.h"

int px = 1;
int py = 1;
bool gameOverM = false;
bool winM = false;


int Forward(int score, int(&arr)[27][110]);

int Left(int score, int(&arr)[27][110]);

int Backward(int score, int(&arr)[27][110]);

int Right(int score, int(&arr)[27][110]);

void PlayerMovement(int(&arr)[27][110], int score)
{
   int  myScore = score;

    if (_kbhit()) {
        switch (_getch())
        {
        case 'w':
            Forward(myScore,arr);
            break;
        case 'a':
            Left(myScore, arr);
            break;
        case 's':
            Backward(myScore, arr);
            break;
        case 'd':
            Right(myScore,arr);
            break;

        }
    }
    if ((py == 25 || py == 26 || py == 24 || py == 23) && px == 109)
    {
        winM = true;
        GameWin(winM);
    }

}


int Forward(int score, int(&arr)[27][110])
{
    if (arr[py - 1][px] != 1)
    {
        if (arr[py - 1][px] == 2)
        {
            arr[py - 1][px] = 0;
            score++;
        }
        if (arr[py - 1][px] == 4)
        {
            arr[py - 1][px] = 0;
            gameOverM = true;
        }
        swap(arr[py][px], arr[py - 1][px]);
        py = py - 1;
        Draw(arr, score, gameOverM);
    }
    return score;

}

int Left(int score, int(&arr)[27][110])
{
    if (arr[py][px - 1] != 1)
    {
        if (arr[py][px - 1] == 2)
        {
            arr[py][px - 1] = 0;
            score++;
        }
        if (arr[py][px - 1] == 4)
        {
            arr[py][px - 1] = 0;
            gameOverM = true;
        }
        swap(arr[py][px], arr[py][px - 1]);
        px = px - 1;
        Draw(arr, score, gameOverM);
    }
    return score;

}

int Backward(int score, int(&arr)[27][110])
{
    if (arr[py + 1][px] != 1) 
    {
        if (arr[py + 1][px] == 2)
        {
            arr[py + 1][px] = 0;
            score++;
        }
        if (arr[py + 1][px] == 4)
        {
            arr[py + 1][px] = 0;
            gameOverM = true;
        }
        swap(arr[py][px], arr[py + 1][px]);
        py = py + 1;
        Draw(arr, score, gameOverM);
    }
    return score;
}

int Right(int score, int(&arr)[27][110])
{
    if (arr[py][px + 1] != 1)
    {
        if (arr[py][px +1] == 2)
        {
            arr[py][px + 1] = 0;
            score++;
        }
        if (arr[py][px + 1] == 4)
        {
            arr[py][px + 1] = 0;
            gameOverM = true;
        }

        swap(arr[py][px], arr[py][px + 1]);
        px = px + 1;
        Draw(arr, score, gameOverM);
    }
    return score;
}