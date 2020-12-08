#include "widget.h"
#include "window/Window.h"
#include "utility.h"
#include "dijkstra.h"

extern Window *w;
extern bool dijkstra_running;

widget::widget()
{
    start_button = new button("Start");
    start_button->setSize(110, 60);
    start_button->b->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    quit_button = new button("Quit");
    quit_button->setSize(110, 60);
    quit_button->b->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    reset_button = new button("Reset");
    reset_button->setSize(110, 60);
    reset_button->b->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    clear_button = new button("Clear");
    clear_button->setSize(110, 60);
    clear_button->b->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    goal_checkbox = new QCheckBox(": Goal");
    goal_checkbox->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    erase_checkbox = new QCheckBox(": Erase");
    erase_checkbox->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    black_checkbox = new QCheckBox(": Obstacle");
    black_checkbox->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    start_checkbox = new QCheckBox(": Start");
    start_checkbox->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
}

void widget::w_reset()
{
    if(!dijkstra_running)
    {
        clearAll();
        setObstacles();
    }
    else
    {
        Okay();
    }
}

void widget::w_sort()
{
    if(!dijkstra_running)
    {
        Animation();
        dijkstra_running = true;
    }
    else
    {
        Okay();
    }
}

void widget::clear()
{
    if(!dijkstra_running)
    {
        clearAll();
    }
    else
    {
        Okay();
    }
}

// To Synchronize the checkbox

void widget::check_erase(bool checked)
{
    if(erase_checkbox->isChecked())
    {
        obstacle_checked = false;
        goal_checked = false;
        start_checked = false;
        clear_checked = true;

        goal_checkbox->setCheckState(Qt::Unchecked);
        start_checkbox->setCheckState(Qt::Unchecked);
        black_checkbox->setCheckState(Qt::Unchecked);
    }
}

void widget::check_start(bool checked)
{
    if(start_checkbox->isChecked())
    {
        obstacle_checked = false;
        goal_checked = false;
        start_checked = true;
        clear_checked = false;

        goal_checkbox->setCheckState(Qt::Unchecked);
        black_checkbox->setCheckState(Qt::Unchecked);
        erase_checkbox->setCheckState(Qt::Unchecked);
    }
}

void widget::check_goal(bool checked)
{
    if(goal_checkbox->isChecked())
    {
        obstacle_checked = false;
        goal_checked = true;
        start_checked = false;
        clear_checked = false;

        black_checkbox->setCheckState(Qt::Unchecked);
        start_checkbox->setCheckState(Qt::Unchecked);
        erase_checkbox->setCheckState(Qt::Unchecked);
    }
}

void widget::check_black(bool checked)
{
    if(black_checkbox->isChecked())
    {
        obstacle_checked = true;
        goal_checked = false;
        start_checked = false;
        clear_checked = false;

        goal_checkbox->setCheckState(Qt::Unchecked);
        start_checkbox->setCheckState(Qt::Unchecked);
        erase_checkbox->setCheckState(Qt::Unchecked);
    }
}

void widget::connection()
{
    connect(start_button->b, &QPushButton::clicked, this, &widget::w_sort);
    connect(reset_button->b, &QPushButton::clicked, this, &widget::w_reset);
    connect(quit_button->b, &QPushButton::clicked, w, &QWidget::close);
    connect(clear_button->b, &QPushButton::clicked, this, &widget::clear);
    connect(black_checkbox, &QCheckBox::toggled, this, &widget::check_black);
    connect(erase_checkbox, &QCheckBox::toggled, this, &widget::check_erase);
    connect(start_checkbox, &QCheckBox::toggled, this, &widget::check_start);
    connect(goal_checkbox, &QCheckBox::toggled, this, &widget::check_goal);
}
