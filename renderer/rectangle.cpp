#include "rectangle.h"
#include "utility.h"

#include <iostream>
extern grid box[40][50];
rectangle::rectangle()
{

}

void rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = return_dimension();
    painter->fillRect(rec,Brush);
    painter->drawRect(rec);
}

QRectF rectangle::boundingRect() const
{
    return return_dimension();
}

QRectF rectangle::return_dimension() const
{
    return QRect(position_x, position_y, r_width, r_height);
}

void rectangle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // To select the square and color it when mouse is clicked
    if(!dijkstra_running)
    {
        if(obstacle_checked)
        {
            box[position_y/16][position_x/16].rect_color = BLACK;
        }
        else if(start_checked && !start_set)
        {
            box[position_y/16][position_x/16].rect_color = RED;
            start.x = position_y / 16;
            start.y = position_x / 16;
            box[start.x][start.y].distance_v = 0;
            start_set = true;
            setDistanceFromSource();
        }
        else if(goal_checked && !goal_set)
        {
            box[position_y/16][position_x/16].rect_color = GREEN;
            goal.x = position_y / 16;
            goal.y = position_x / 16;
            goal_set = true;
        }
        else if(clear_checked)
        {
            box[position_y/16][position_x/16].rect_color = WHITE;
            if(position_y/16 == start.x && position_x/16 == start.y) start_set = false;
            if(position_y/16 == goal.x && position_x/16 == goal.y) goal_set = false;
        }
    }
}

void rectangle::setBrush(QString &&str)
{
    if(str == "red")
    {
        Brush = QBrush(Qt::red);
    }
    else if(str == "green")
    {
        Brush = QBrush(Qt::green);
    }
    else if(str == "blue")
    {
        Brush = QBrush(Qt::blue);
    }
    else if(str == "black")
    {
        Brush = QBrush(Qt::black);
    }
    else if(str == "yellow")
    {
        Brush = QBrush(Qt::yellow);
    }
}

void rectangle::setLocation(int xpos, int ypos)
{
    position_x = xpos;
    position_y = ypos;
}

void rectangle::setSize(int width, int height)
{
    r_width = width;
    r_height = height;
}

void rectangle::advance(int phase)
{
    if(!phase) return;
}
