#pragma once

#include "client.h"
#include "order_detail.h"


struct Order
{
    int id;
    Client order;
    OrderDetail *detail;
    int num;
};
