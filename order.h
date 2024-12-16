#pragma once

#include "client.h"
#include "order_detail.h"
#define MAX 1828

// order attributes
struct Order{
    int code;
    Client client;
    OrderDetail details[MAX];
    int num_details;
    double total;

    Order():
        num_details(0), total(0.0){}
};

// methods
void menu_orders(int *opt, struct Client *list_clients, struct Book *list_books, struct Order *list_orders);
void insert_order(struct Order *ord, struct Client *list_clients, struct Book *list_books);
int get_num_orders();
void print_list_orders(struct Order *list_orders);
void print_order(struct Order ord);
