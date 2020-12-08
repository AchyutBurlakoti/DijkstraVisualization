#ifndef UTILITY_H
#define UTILITY_H

enum color
{
    RED,
    YELLOW,
    BLACK,
    WHITE,
    BLUE,
    GREEN
};

struct grid
{
public:
    int x;
    int y;
    grid *parent;
    int distance_v;
    color rect_color = WHITE;
};

extern grid box[40][50];
extern grid start;
extern grid goal;

extern bool dijkstra_running;
extern bool goal_set;
extern bool start_set;

// flags to check the status of checkbox
extern bool goal_checked;
extern bool start_checked;
extern bool clear_checked;
extern bool obstacle_checked;

void setObstacles();
void clearAll();
void setDistanceFromSource();

#endif // UTILITY_H
