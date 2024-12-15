#pragma once


struct Client
{   
    int code;
    char name[40];
    unsigned int age;
    double salary;
};


void menu_clients(int *opt, struct Client *list_clients);
void insert_client(struct Client *c);
int get_num_clients();
int search_client(char *search_name, struct Client *list_clients);
void print_client(struct Client c);
void print_list_clients(struct Client *list_clients);
void update_client(char *search_name, struct Client *list_clients);
void delete_client(char *search_name, struct Client *list_clients);