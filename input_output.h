#pragma once


/* Unnamed */
void clean_file(const char file_name[30]);
void print_num_object(const char file_name[30], int num_cl);

/* Clients */
void print_client_in_file(const char file_name[30], struct Client c);
void print_clients_in_file(struct Client *list_clients);
void read_file_client(const char file_name[30], struct Client *list_clients);

/* Books */
void print_book_in_file(const char file_name[30], struct Book c);
void print_books_in_file(struct Book *list_clients);
void read_file_book(const char file_name[30], struct Book *list_clients);


/* Order */
void print_order_in_file(const char file_name[30], struct Order c);
void print_orders_in_file(struct Order *list_orders);
void read_file_order(const char file_name[30], struct Order *list_orders,
    struct Book *list_books, struct Client *list_clients);


/* Order_Detail */
void print_order_detail_in_file(const char file_name[30], struct Order *o, int i);
void read_file_order_detail(const char file_name[30], struct Order *o,
    struct Book *list_books, struct Client *list_clients);