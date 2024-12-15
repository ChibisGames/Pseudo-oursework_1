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
void read_file_books(const char file_name[30], struct Book *list_clients);