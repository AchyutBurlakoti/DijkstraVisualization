#pragma once
#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "renderer/rectangle.h"

class canvas
{
public:
    canvas();
    void disableScrollBar();
    void setSize(int xpos, int ypos, int width, int height);
    void additemToscene(rectangle *rect);
    void clearScene();
public:
    QGraphicsScene *scene;
    QGraphicsView *view;
};

#endif // CANVAS_H
