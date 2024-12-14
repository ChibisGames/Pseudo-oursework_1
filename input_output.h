#pragma once


/* Clients */
void print_client_in_file(const char file_name[30], struct Client c);
void clean_file(const char file_name[30]);
void print_num_clients(const char file_name[30], int num_cl);
void print_clients_in_file(struct Client *list_clients);
void read_file_client(const char file_name[30], struct Client *list_clients);