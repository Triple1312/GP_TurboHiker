/*
 * This is where the model of the project starts
 */

#ifndef GP_WIDGET_H
#define GP_WIDGET_H

/*
 * this class is useless without graphics
 */
class Widget {
public:
    virtual void display(){}

    bool active;

};


#endif //GP_WIDGET_H
