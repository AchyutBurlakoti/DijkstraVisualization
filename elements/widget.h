#pragma once
#ifndef WIDGET_H
#define WIDGET_H

#include "button.h"
#include <QWidget>
#include <QString>
#include <QCheckBox>

class widget : public QWidget
{
public:
    widget();
    void connection();
    void w_reset();
    void w_sort();
    void clear();
    void check_black(bool checked);
    void check_erase(bool checked);
    void check_start(bool checked);
    void check_goal(bool checked);
public:
    button *start_button;
    button *quit_button;
    button *reset_button;
    button *clear_button;
    QCheckBox *start_checkbox;
    QCheckBox *goal_checkbox;
    QCheckBox *erase_checkbox;
    QCheckBox *black_checkbox;
};

#endif // WIDGET_H
