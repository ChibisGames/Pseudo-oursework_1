#pragma once

#include "client.h"
#include "order_detail.h"


struct Order
{
    int code;
    Client order;
    OrderDetail *detail;
    int num;
};


static int num_orders = 0;
static int order_index = 0;

void menu_orders(int *opt, struct Client *list_clients, struct Book *list_books, struct Order *list_order)
{

};