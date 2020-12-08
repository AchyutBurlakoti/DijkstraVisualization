#pragma once
#ifndef RENDERER_H
#define RENDERER_H

#include <QTimer>
#include "renderer/canvas.h"
#include "elements/widget.h"
#include <QHBoxLayout>

class renderer : public QWidget
{
private:
    canvas *_canvas;
    QTimer *timer;
    widget *_widget;
    QHBoxLayout *toplayout;
    QHBoxLayout *bottomlayout;
    QVBoxLayout *mainlayout;
public:
    renderer();
    void start();
    void drawrectangles();
};

#endif // RENDERER_H
