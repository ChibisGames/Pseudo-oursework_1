#pragma once


struct Client
{   
    int code;
    char name[40];
    unsigned int age;
    double salary;
};

struct Client default_client()
{
    struct Client c;

    c.code = 0;
    c.name[0] = '\0';

    return c;
};

void menu_clients(int *opt, struct Client *list_clients);
void insert_client(struct Client *c);
int get_num_clients();
int search_client(char *search_name, struct Client *list_clients);
void print_client(struct Client c);
void print_list_clients(struct Client *list_clients);
void update_client(char *search_name, struct Client *list_clients);
void delete_client(char *search_name, struct Client *list_clients);
void sort_clients(struct Client *list_clients);
struct Client get_client_by_code(int client_code, struct Client *list_clients);
struct Client get_client();
