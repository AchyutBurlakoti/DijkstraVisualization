#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "utility.h"
#include "quicksort.h"
#include <vector>
#include <iostream>
#include <future>
#include <chrono>

std::vector<grid> t_grid;

extern grid box[40][50];
extern grid start;
extern grid goal;
extern bool goal_set;
extern bool start_set;

extern bool dijkstra_running;

std::future<void> thread;

int countX, countY;
bool stop = false;

inline void Dijkstra()
{
    stop = false;

    // set the variable to starting node
    countX = start.x;
    countY = start.y;

    while(countX != goal.x || countY != goal.y)
    {
        // Distance between two adjacent box is 1.

        // Check for left box
        if (countX > 0)
        {
            if((countX - 1) > -1 && box[countX - 1][countY].rect_color != BLACK)
            {
                if(box[countX - 1][countY].distance_v > (box[countX][countY].distance_v + 1))
                {
                    box[countX - 1][countY].distance_v = box[countX][countY].distance_v + 1;
                    box[countX - 1][countY].parent = &box[countX][countY];
                    t_grid.push_back(box[countX - 1][countY]);
                }
            }
        }

        // Check for right box
        if((countX + 1) <= 39 && box[countX + 1][countY].rect_color != BLACK)
        {
            if(box[countX + 1][countY].distance_v > (box[countX][countY].distance_v + 1))
            {
                box[countX + 1][countY].distance_v = box[countX][countY].distance_v + 1;
                box[countX + 1][countY].parent = &box[countX][countY];
                t_grid.push_back(box[countX + 1][countY]);
            }
        }

        // Check for up box
        if (countY > 0)
        {
            if((countY - 1) > -1 && box[countX][countY - 1].rect_color != BLACK)
            {
                if(box[countX][countY - 1].distance_v > (box[countX][countY].distance_v + 1))
                {
                    box[countX][countY - 1].distance_v = box[countX][countY].distance_v + 1;
                    box[countX][countY - 1].parent = &box[countX][countY];
                    t_grid.push_back(box[countX][countY - 1]);
                }
            }
        }

        // Check for down box
        if((countY + 1) < 50 && box[countX][countY + 1].rect_color != BLACK)
        {
            if(box[countX][countY + 1].distance_v > (box[countX][countY].distance_v + 1))
            {
                box[countX][countY + 1].distance_v = box[countX][countY].distance_v + 1;
                box[countX][countY + 1].parent = &box[countX][countY];
                t_grid.push_back(box[countX][countY + 1]);
            }
        }

        quickSort(0, t_grid.size() - 1);

        // sentinel
        if(!t_grid.empty())
        {
            grid temp = t_grid.back();
            countX = temp.x;
            countY = temp.y;
            t_grid.pop_back();
        }
        else
        {
            stop = true;
            std::cout << "out of space!!!\n";
            break;
        }

        if(stop) break;

        // Set the color of visited box BLUE
        if(countX != goal.x || countY != goal.y)
        {
            box[countX][countY].rect_color = BLUE;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    if(!stop)
    {
        // Trace the parent of box to get to the starting box to color shortest path
        grid *mover = &box[countX][countY];

        while(mover->parent->x != start.x || mover->parent->y != start.y)
        {
            mover->parent->rect_color = YELLOW;
            mover = mover->parent;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}

inline void Animation()
{
    if(goal_set && start_set)
    {
        thread = std::async(std::launch::async, Dijkstra);
    }
}

template<typename T>
inline void thread_is_completed(std::future<T>& t)
{
    if(t.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
    {
        dijkstra_running = false;
    }
}

inline void Okay()
{
    thread_is_completed(thread);
}

#endif // DIJKSTRA_H
