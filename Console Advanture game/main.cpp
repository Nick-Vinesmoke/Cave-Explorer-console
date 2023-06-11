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


void NewGame();
string space = " ";

int main(void) 
{
    HANDLE  hConsole;
    int col = 9;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FlushConsoleInputBuffer(hConsole);
    SetConsoleTextAttribute(hConsole, col);
    HWND hWindowConsole = GetConsoleWindow();
    RECT r;
    GetWindowRect(hWindowConsole, &r);
    MoveWindow(hWindowConsole, r.left, r.top, 895, 500, TRUE);


    bool choosed = false;


	printf("%49sWelcome to console advanture\n\n",space.c_str());
	printf("%43s1.New game%21s2.Exit\n", space.c_str(), space.c_str());
    while (!choosed)
    {
        if (_kbhit()) {
            switch (_getch())
            {
            case '1':
                choosed = true;
                NewGame();
                break;
            case '2':
                choosed = true;
                abort();
                break;

            }
        }
    }
   
}

void NewGame() 
{
    system("cls");
    mainProg();
}

