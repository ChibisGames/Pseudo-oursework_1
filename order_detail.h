#pragma once

#include "book.h"

struct OrderDetail
{
   Book book;
   int quantity;
   float subtotal;
};

void insert_order_detail(OrderDetail *detail, Book *list_books);
void delete_order_detail(struct Order *list_orders);
