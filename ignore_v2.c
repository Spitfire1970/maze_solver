#include"graphics.h"
#include<stdio.h>
#include <stdlib.h>

const int mazelength = 12, mazewidth = 12;
const int windowlength = 600, windowwidth = 600;
const int blocklength = windowlength/mazelength, blockwidth = windowwidth/mazewidth;

int homecoords[] = {0, 0}, markercoords[] = {0, 0};

int maze[mazelength][mazewidth] =    {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1}, 
                                      {2, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1},
                                      {1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
                                      {1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1},
                                      {1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
                                      {1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
                                      {1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1},
                                      {1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1},
                                      {1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1},
                                      {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1},
                                      {1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1},
                                      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1}};

//possibilities takes two coordinates (x1, y1, x2, y2) at a time, when robot can move from (x1, y1) to (x2, y2)
int possibilities[100][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,}};

//path works similar to possibilities
int path[100][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0,}};

int visited[100][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
                    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
                    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
                    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
                    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
                    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
                    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
                    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
                    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
                    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};

void get_home_marker_coords()
{
    int i = 0;
    int j = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (maze[i][j] == 2)
            {
                homecoords[0] = i;
                homecoords[1] = j;
            }
        }
    }
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            if (maze[i][j] == 3)
            {
                markercoords[0] = i;
                markercoords[1] = j;
            }
        }
    }
}

void drawmaze()
{
    background();
    int row;
    int col;
    int x1 = 0;
    int y1 = 0;
    for (row = 0; row < mazelength; row++)
    {
        for (col = 0; col < mazewidth; col++)
        {
            if (maze[row][col] == 0)
            {
                setColour(white);
            }
            if (maze[row][col] == 1)
            {
                setColour(black);
            }
            if (maze[row][col] == 2)
            {
                setColour(gray);
            }
            fillRect(x1, y1, blockwidth, blocklength);
            x1 += blockwidth;
        }
        x1 = 0;
        y1 += blocklength;
    }
    setColour(blue);
    fillRect(homecoords[1]*blockwidth, homecoords[0]*blocklength, blockwidth, blocklength);
}

void drawgrid(void)
{
    setColour(black);
    int row;
    int col;
    int x1 = 0;
    int y1 = 0;
    for (row = 0; row < mazelength; row++)
    {
        for (col = 0; col < mazewidth; col++)
        {
            drawRect(x1, y1, blockwidth, blocklength);
            x1 += blockwidth;
        }
        x1 = 0;
        y1 += blocklength;
    }
}

int at_marker(int x, int y)
{
    if ((markercoords[0] == x) && (markercoords[1] == y))
    {
        return 1;
    }
    return 0;
}

int len_path()
{
    int len = 0;
    for (int i = 0; i < 100; i++)
    {
        if ((path[i][0] != 0) && (path[i][1] != 0))
        {
            len+=1;
        }
    }
    return len;
}

//draws robot at block (i, j) when robot is moving from block (x, y), also takes care of its orientation
void drawrobot(int x, int y, int i, int j)
{
    foreground();
    clear();
    setColour(green);
    if ((i == homecoords[1]*blockwidth) && (j==homecoords[0]*blocklength))
    {
        int icoords[] = {i, i + blockwidth, i};
        int jcoords[] = {j, j + (blocklength/2), j + blocklength};
        fillPolygon(3, icoords, jcoords);
        sleep(500);
        return;
    }
    if (x == i)
    {
        if (y<j)
        {          
            int icoords[] = {i, i + blockwidth, i + (blockwidth/2)};
            int jcoords[] = {j, j, j + blocklength};
            fillPolygon(3, icoords, jcoords);
            
        }
        else
        {
            int icoords[] = {i + (blockwidth/2), i + blockwidth, i};
            int jcoords[] = {j, j + blocklength, j + blocklength};
            fillPolygon(3, icoords, jcoords);
        }
    }
    else
    {
        if (x<i)
        {
            int icoords[] = {i, i + blockwidth, i};
            int jcoords[] = {j, j + (blocklength/2), j + blocklength};
            fillPolygon(3, icoords, jcoords);
        }
        else
        {
            int icoords[] = {i + blockwidth, i + blockwidth, i};
            int jcoords[] = {j, j + blocklength, j + (blocklength/2)};
            fillPolygon(3, icoords, jcoords);
        }
    }
    sleep(200);
    
    if (at_marker(j/blockwidth, i/blocklength))
    {
        int len = len_path();
        for (int r = 0; r<len;r++)
        {
            setColour(yellow);
            fillRect(path[r][1]*blockwidth, path[r][0]*blocklength, blockwidth, blocklength);
            drawgrid();
            setColour(red);
            drawString("PATH FOUND.", 258, 330);
        }
        exit(0);
    }
}

int check_visited(int x, int y)
{
    int len = 0;
    for (int i = 0; i <100;i++)
    {
        if ((visited[i][0] != 0) || (visited[i][1] != 0))
        {
            len+=1;
        }
    }
    for (int i = 0; i <100;i++)
    {
        if ((visited[i][0] == x) && (visited[i][1] == y))
        {
            return 1;
        }
        
    }
    //if block not visited before then adds to visited array
    visited[len][0] = x;
    visited[len][1] = y;
    return 0;
}

void del_from_possibilities(int index)
{
    for (int i = index; i < 99; i++)  
        for (int j = 0; j<4;j++)
        {  
            possibilities[i][j] = possibilities[i+1][j];
        }  
}

//for robot at (x, y), checks the available adjacent blocks it can go to that it hasn't gone to before
int num_in_possibilities(int x, int y)
{
    int n = 0;
    for (int i = 0; i < 100; i++)
    {
        if ((possibilities[i][0]==x) && (possibilities[i][1] == y))
        {
            n += 1;
        }
    }
    return n;
}

int len_possibilities()
{
    int len = 0;
    for (int i = 0; i < 100; i++)
    {
        if ((possibilities[i][0] != 0) && (possibilities[i][1] != 0))
        {
            len+=1;
        }
    }
    return len;
}

//algo() and backtrack() combined basically implement the Depth First Search Algorithm
void algo(int x, int y);

//goes to last point in path where the robot had an unexplored option
void backtrack(int x, int y)
{
    int len = len_path();
    int new_x;
    int new_y;
    
    //starting from the latest point, each point in path is checked one by one
    for (int i = len; i >= 0; i--)
    {
        for (int j = 0; j < 100; j++)
        {
            if ((possibilities[j][0] == path[i][0]) && (possibilities[j][1] == path[i][1]))
            {
                new_x = path[i][0];
                new_y = path[i][1];
                path[i][0] = 0;
                path[i][1] = 0;
                path[i][2] = 0;
                path[i][3] = 0;
                drawrobot(y*blockwidth, x*blocklength, path[i][1]*blockwidth, path[i][0]*blocklength);
                algo(new_x, new_y);
                break;
            }
        }
        new_x = path[i][0];
        new_y = path[i][1];
        path[i][0] = 0;
        path[i][1] = 0;
        path[i][2] = 0;
        path[i][3] = 0;
        drawrobot(y*blockwidth, x*blocklength, path[i][1]*blockwidth, path[i][0]*blocklength);
        backtrack(new_x, new_y);
    }
}

void algo(int x, int y)
{
    foreground();
    int len_of_poss = 0;
    int new_x = 0;
    int new_y = 0;   
    if (!check_visited(x, y))
    {
        //if not block not visited then check adjacent blocks and add them to possibilities
        if ((maze[x][y+1] == 0) || (maze[x][y+1] == 3))
        {
            len_of_poss = len_possibilities();
            possibilities[len_of_poss][0] = x;
            possibilities[len_of_poss][1] = y;
            possibilities[len_of_poss][2] = x;
            possibilities[len_of_poss][3] = y+1;
        }

        if ((maze[x+1][y] == 0) || (maze[x+1][y] == 3))
        {
            len_of_poss = len_possibilities();
            possibilities[len_of_poss][0] = x;
            possibilities[len_of_poss][1] = y;
            possibilities[len_of_poss][2] = x+1;
            possibilities[len_of_poss][3] = y;
        }

        if ((maze[x-1][y] == 0) || (maze[x-1][y] == 3))
        {
            len_of_poss = len_possibilities();
            possibilities[len_of_poss][0] = x;
            possibilities[len_of_poss][1] = y;
            possibilities[len_of_poss][2] = x-1;
            possibilities[len_of_poss][3] = y;
        }

        if ((maze[x][y-1] == 0) || (maze[x][y-1] == 3))
        {
            len_of_poss = len_possibilities();
            possibilities[len_of_poss][0] = x;
            possibilities[len_of_poss][1] = y;
            possibilities[len_of_poss][2] = x;
            possibilities[len_of_poss][3] = y-1;
        }
        for (int i = 0; i < 100; i++)
        {
            if ((x == possibilities[i][0]) && (y == possibilities[i][1]))
            {
                int len_of_path = len_path();
                path[len_of_path][0] = possibilities[i][0];
                path[len_of_path][1] = possibilities[i][1];
                path[len_of_path][2] = possibilities[i][2];
                path[len_of_path][3] = possibilities[i][3];
                new_x = path[len_of_path][2];
                new_y = path[len_of_path][3];
                drawrobot(y*blockwidth, x*blocklength, possibilities[i][3]*blockwidth, possibilities[i][2]*blocklength);
                del_from_possibilities(i);
                break;
            }
        }
        algo(new_x, new_y);
    }
    else 
    {
        int num_poss = num_in_possibilities(x, y);
        if (num_poss==0)
        {
            backtrack(x, y);
        }
        else
        {
            //choose one of the available blocks and move the robot to it
            for (int i = 0; i < 100; i++)
            {
                if ((x == possibilities[i][0]) && (y == possibilities[i][1]))
                {
                    int len_of_path = len_path();
                    path[len_of_path][0] = possibilities[i][0];
                    path[len_of_path][1] = possibilities[i][1];
                    path[len_of_path][2] = possibilities[i][2];
                    path[len_of_path][3] = possibilities[i][3];
                    new_x = path[len_of_path][2];
                    new_y = path[len_of_path][3];
                    drawrobot(y*blockwidth, x*blocklength, possibilities[i][3]*blockwidth, possibilities[i][2]*blocklength);
                    del_from_possibilities(i);
                    break;
                }
            }
            algo(new_x, new_y);
        }
    }
}

int main(void)
{
    setWindowSize(windowwidth, windowlength);
    drawmaze();
    drawgrid();
    get_home_marker_coords();
    drawrobot(0, 0, homecoords[1]*blockwidth, homecoords[0]*blocklength);
    algo(homecoords[0], homecoords[1]);
    return 0;
}