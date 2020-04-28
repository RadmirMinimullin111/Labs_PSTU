#pragma once
#include "Object.h"
#include "Event.h"
class Vector
{
public:
    Vector(void);
    Vector(int);
public:
    ~Vector(void);
    void Add();
    void Del();
    void Show();
    int operator()();
    virtual void HandleEvent(const TEvent& e);
protected:
    Object** beg;
    int size;
    int cur;
};
