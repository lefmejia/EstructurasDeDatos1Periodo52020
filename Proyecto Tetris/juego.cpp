#include <iostream>
#include <string.h>
#include "tapio/rlutil.h"
#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <vector>
#include <list>
#include <time.h> 

using namespace std;

const int nScreenWidth = 25;			
const int nScreenHeight = 25;	

string tetromino[7][4];
const int boardW = 14;
const int boardH = 20;
string board[boardH];

void Rotation(int idx, int nPosX, int nPosY)
{
    string temp[4];

    for(int i=0;i<4;i++)
        temp[i] = "    ";

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            temp[i][j] = tetromino[idx][3-j][i];
        }
    }

    while(temp[0][3] == ' ' && temp[1][3] == ' ' && temp[2][3] == ' ' && temp[3][3] == ' ')
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<3; j++)
            {
                temp[i][3-j] = temp[i][3-j-1];
                temp[i][3-j-1] = ' ';
            }
        }
    }

    for(int i=0;i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(temp[i][j]=='X' && (board[nPosY+i][nPosX+j]=='X' || board[nPosY+i][nPosX+j]=='#'))
                return;
        }
    }

    for(int i=0; i<4; i++)
        tetromino[idx][i] = temp[i];
}

void cRotation(int idx, int nPosX, int nPosY)
{
    string temp[4];

    for(int i=0;i<4;i++)
        temp[i] = "    ";

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            temp[i][j] = tetromino[idx][j][3-i];
        }
    }

    while(temp[0][3] == ' ' && temp[1][3] == ' ' && temp[2][3] == ' ' && temp[3][3] == ' ')
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<3; j++)
            {
                temp[i][3-j] = temp[i][3-j-1];
                temp[i][3-j-1] = ' ';
            }
        }
    }

    for(int i=0;i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(temp[i][j]=='X' && (board[nPosY+i][nPosX+j]=='X' || board[nPosY+i][nPosX+j]=='#'))
                return;
        }
    }

    for(int i=0; i<4; i++)
        tetromino[idx][i] = temp[i];
}

bool canMove(int piece, int nPosX, int nPosY, char dir)
{
	for(int i=0;i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(dir == 'r')
            {
                if(tetromino[piece][i][j]=='X' && (board[nPosY+i][nPosX+j+1]=='X' || board[nPosY+i][nPosX+j+1]=='#'))
                    return false;
            }
            else
            {
                if(tetromino[piece][i][j]=='X' && (board[nPosY+i][nPosX+j-1]=='X' || board[nPosY+i][nPosX+j-1]=='#'))
                    return false;
            }
            
        }
    }

	return true;
}

bool canDown(int piece, int nPosX, int nPosY)
{
	for(int i=0;i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(tetromino[piece][i][j]=='X' && (board[nPosY+i+1][nPosX+j]=='X' || board[nPosY+i+1][nPosX+j]=='#'))
                return false;
        }
    }

	return true;
}

bool canRotate(int piece, int nPosX, int nPosY, char dir)
{
	for(int i=0;i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(tetromino[piece][i][j]=='X' && (board[nPosY+i][nPosX+j+1]=='X' || board[nPosY+i][nPosX+j+1]=='#'))
                return false;
        }
    }

	return true;
}

int main()
{
    list<int> que;
    srand (time(NULL));

    for(int i=0; i<4; i++)
        que.push_back(rand() % 7);

    for(auto n: board)
        n="";

    for(int i=0; i<boardH; i++)
    {
        for(int j=0; j<boardW; j++)
        {
            if(i!=boardH-1)
                board[i] += ' ';
            if(i==boardH-1)
                board[boardH-1] += '#';
        }
    }
    
    for(int i=0; i<boardH; i++)
    {
        board[i][0] = '#';
        board[i][boardW-1] = '#';
    }

    string newscreen[nScreenHeight];
    for(int i=0; i<boardH; i++)
        {
            newscreen[i] = board[i];
        }

    tetromino[0][0] = "   X";
    tetromino[0][1] = "   X";
    tetromino[0][2] = "   X";
    tetromino[0][3] = "   X";

    tetromino[1][0] = "    ";
    tetromino[1][1] = "  XX";
    tetromino[1][2] = "  XX";
    tetromino[1][3] = "    ";

    tetromino[2][0] = "    ";
    tetromino[2][1] = "  XX";
    tetromino[2][2] = "  X ";
    tetromino[2][3] = "  X ";

    tetromino[3][0] = "    ";
    tetromino[3][1] = "  XX";
    tetromino[3][2] = "   X";
    tetromino[3][3] = "   X";

    tetromino[4][0] = "    ";
    tetromino[4][1] = "   X";
    tetromino[4][2] = "  XX";
    tetromino[4][3] = "   X";

    tetromino[5][0] = "    ";
    tetromino[5][1] = "  X ";
    tetromino[5][2] = "  XX";
    tetromino[5][3] = "   X";

    tetromino[6][0] = "    ";
    tetromino[6][1] = "   X";
    tetromino[6][2] = "  XX";
    tetromino[6][3] = "  X ";


    bool gameover = false;
    bool active = false;
    bool collision = false;
    int currentPiece = rand() % 7;
	int minX;
    int minY;
	int currentX = boardW / 2 - 1;
	int currentY = 0;
	int nSpeed = 0;
    int hold;
    int framecount=0;
	int nSpeedCount = 0;
	bool bForceDown = false;
	bool bRotateHold = true;
	int nPieceCount = 0;
	int nScore = 0;
	vector<int> vLines;
    while(!gameover)
    {
        // Timer
        this_thread::sleep_for(16ms);
        framecount++;
        
        if(kbhit())
        {
            char in = getch();
            if(in == '\033')
            {
                getch();
                switch(getch()) 
                {
                case 'A': //FLECHA ARRIBA
                while(true)
                {
                    if(canDown(currentPiece,currentX, currentY))
                        currentY++;
                    else
                        break;
                }
                break;
                case 'B': //FLECHA ABAJO
                if(canDown(currentPiece,currentX, currentY))
                    currentY++;
                break;
                case 'C':  //FLECHA DERECHA
                if(canMove(currentPiece,currentX, currentY, 'r'))
                    currentX++;
                break;
                case 'D': // FLECHA IZQUIERDA
                if(canMove(currentPiece,currentX, currentY, 'e'))
                    currentX--;
                break;

                default: gameover = true; // ESC
                }
            }
            else
            {
                switch(in)
                {
                    case 'r':
                        Rotation(currentPiece, currentX, currentY);
                        break;

                    case 'e':
                        cRotation(currentPiece, currentX, currentY);
                        break;
                }
            }
            
        }
        
        // Logic
    
        if(framecount>= 60 - nSpeed)
        {
            currentY++;
            framecount = 0;
        }

        for(int i=0; i<boardH; i++)
        {
            newscreen[i] = board[i];
        }

        //Calculate if new piece fits
        int endpos = -1;
        if(currentY==0)
        {
            for(int i=0; i<4; i++)
            {
                if(i==endpos)
                    break;
                for(int j=0; j<4; j++)
                {
                    if(tetromino[currentPiece][i][j] == 'X' && newscreen[currentY+i][currentX+j] == 'X')
                    {
                        endpos = i;
                        i=0;
                        break;
                    }
                }
                if(endpos != -1)
                {
                    for(int j=0; j<4; j++)
                    {
                        newscreen[i][currentX+j] = tetromino[currentPiece][4-endpos+i][j];
                    }
                    gameover = true;
                }
            }
        }

        //Draw current piece and its position
        if(endpos==-1)
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    if(tetromino[currentPiece][i][j] != ' ')
                        newscreen[currentY+i][currentX+j] = tetromino[currentPiece][i][j];
                }
            }

        //Colission detection
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if((newscreen[currentY+i+1][currentX+j] == 'X' && tetromino[currentPiece][i+1][j]!='X' && tetromino[currentPiece][i][j]!=' ') || (newscreen[currentY+i+1][currentX+j] == '#' && tetromino[currentPiece][i][j]!=' '))
                {
                    for(int i=0; i<boardH; i++)
                    {
                        board[i] = newscreen[i];
                        
                    }
                    currentPiece = que.front();
                    que.pop_front();
                    que.push_back(rand()%7);

                    currentX = boardW/2 - 1;
                    currentY = 0;

                    for(int h = 0; h<4; h++)
                    {
                        if(board[currentY][currentX+h]=='X')
                            gameover = true;
                    }

                    tetromino[0][0] = "   X";
                    tetromino[0][1] = "   X";
                    tetromino[0][2] = "   X";
                    tetromino[0][3] = "   X";

                    tetromino[1][0] = "    ";
                    tetromino[1][1] = "  XX";
                    tetromino[1][2] = "  XX";
                    tetromino[1][3] = "    ";

                    tetromino[2][0] = "    ";
                    tetromino[2][1] = "  XX";
                    tetromino[2][2] = "  X ";
                    tetromino[2][3] = "  X ";

                    tetromino[3][0] = "    ";
                    tetromino[3][1] = "  XX";
                    tetromino[3][2] = "   X";
                    tetromino[3][3] = "   X";

                    tetromino[4][0] = "    ";
                    tetromino[4][1] = "   X";
                    tetromino[4][2] = "  XX";
                    tetromino[4][3] = "   X";

                    tetromino[5][0] = "    ";
                    tetromino[5][1] = "  X ";
                    tetromino[5][2] = "  XX";
                    tetromino[5][3] = "   X";

                    tetromino[6][0] = "    ";
                    tetromino[6][1] = "   X";
                    tetromino[6][2] = "  XX";
                    tetromino[6][3] = "  X ";
                    nScore+=20;
                }
            }
        }

        //Complete line

        for(int i=0; i<boardH-1; i++)
        {
            for(int j=1; j<boardW-1; j++)
            {
                if(board[i][j]!='X')
                    break;
                else if(j==boardW-2)
                {
                    for(int py = i; py>0; py--)
                    {
                        board[py] = board[py-1];
                    }
                    for(int px=1; px<boardW-2; px++)
                    {
                        board[0][px] = ' ';
                    }

                    nScore += ((boardW-2)*100);
                    if(nSpeed<48)
                        nSpeed += 2;
                }
            }
        }
        collision = false;

        //Output
        rlutil::cls();
        bool first = true;
        std::list<int>::iterator it = que.begin();
        newscreen[0] += "  Next:";
        for(int i=0; i<que.size(); i++)
        {
            for(int j = 0; j<4; j++)
            {
                newscreen[(i*4)+j+1] += " " + tetromino[*it][j];
            }
            it++;
        }
        for(int i=0; i < boardH; i++)
        {
            cout<<newscreen[i];
            cout<<'\n';
        }

        active = false;
    }
    cout << "Game Over!! Score:" << nScore << endl;
    return 0;
}