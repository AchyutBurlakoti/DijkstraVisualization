
#include "utility.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>

grid box[40][50];
grid start;
grid goal;

bool dijkstra_running = false;
bool start_set = false;
bool goal_set = false;

bool goal_checked = false;
bool start_checked = false;
bool clear_checked = false;
bool obstacle_checked = false;

void setObstacles()
{
    srand(time(NULL));
    for(int i = 0; i < 40; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if (j < 0)
            {
                int random = rand() % 10;
                box[i][random].rect_color = BLACK;
            }
            else
            {
                int random = (rand() % 100);
                box[i][random].rect_color = BLACK;
            }
        }
    }
}

void setDistanceFromSource()
{
    for(int i = 0; i < 40; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            if(i != start.x || j != start.y)
            {
                box[i][j].distance_v = 100000;
            }
            box[i][j].x = i;
            box[i][j].y = j;
        }
    }
}

void clearAll()
{
    for(int i = 0; i < 40; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            box[i][j].rect_color = WHITE;
            box[i][j].parent = nullptr;
            box[i][j].x = i;
            box[i][j].y = j;
        }
    }
    start_set = false;
    goal_set = false;
}
