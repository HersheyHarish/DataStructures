#include <iostream>
#include "currency.h"
#include "dollar.h"
#ifndef LINKNODE_H
#define LINKNODE_H

struct LinkNode{
    public:
    struct LinkNode *next;
    Currency *data;
};

#endif