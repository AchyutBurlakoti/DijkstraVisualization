#include "renderer.h"
#include "window/Window.h"
#include "utility.h"
//#include "dijkstra.h"

extern Window *w;
extern grid box[40][50];

renderer::renderer()
{
    _canvas = new canvas;
    _widget = new widget;

    bottomlayout = new QHBoxLayout();
    toplayout = new QHBoxLayout();
    mainlayout = new QVBoxLayout();

    timer = new  QTimer;
    connect(timer, &QTimer::timeout, this, &renderer::drawrectangles);
    timer->start(5);
}

void renderer::start()
{
    _canvas->disableScrollBar();

    // Layout Management
    bottomlayout->addWidget(_canvas->view);

    toplayout->addWidget(_widget->start_button->b);
    toplayout->addWidget(_widget->reset_button->b);
    toplayout->addWidget(_widget->clear_button->b);
    toplayout->addWidget(_widget->quit_button->b);
    toplayout->addWidget(_widget->start_checkbox);
    toplayout->addWidget(_widget->goal_checkbox);
    toplayout->addWidget(_widget->erase_checkbox);
    toplayout->addWidget(_widget->black_checkbox);

    mainlayout->addLayout(toplayout);
    mainlayout->addLayout(bottomlayout);

    w->setLayout(mainlayout);

    _widget->connection();
    setDistanceFromSource();
    drawrectangles();
}

void renderer::drawrectangles()
{
    _canvas->clearScene();
    for(int i = 0; i < 40; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            rectangle *_rectangle = new rectangle;

            if(box[i][j].rect_color == RED)
            {
                _rectangle->setBrush("red");
            }
            if(box[i][j].rect_color == YELLOW)
            {
                _rectangle->setBrush("yellow");
            }
            if(box[i][j].rect_color == GREEN)
            {
                _rectangle->setBrush("green");
            }
            if(box[i][j].rect_color == BLUE)
            {
                _rectangle->setBrush("blue");
            }
            if(box[i][j].rect_color == BLACK)
            {
                _rectangle->setBrush("black");
            }

            _rectangle->setLocation(j * 16, i * 16);
            _rectangle->setSize(16, 16);
            _canvas->additemToscene(_rectangle);
        }
    }
}
