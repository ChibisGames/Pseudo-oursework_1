#ifndef ORDER_H
#define ORDER_H

#include "client.h"
#include "order_detail.h"


struct Order
{
    int id;
    Client order;
    OrderDetail *detail;
    int num;
};

#endif