#include <iostream>
#include <cstdio>
#include <string.h>

#include "input_output.h"
#include "book.h"
#include "client.h"
#include "order.h"
#include "order_detail.h"

using namespace std;

/* Clients */
void print_client_in_file(const char file_name[30], struct Client c)
{
    FILE *file;
    char file_path[100];

    strcpy(file_path, "data/");
    strcat(file_path, file_name);

    file = fopen(file_path, "a");

    if (file)
    {   
        fprintf(file, "%d %s %d %.1f\n", c.code, c.name, c.age, c.salary);
    }
    else {cout<< "Error to open file\n" << endl;};

    fclose(file);
};


void clean_file(const char file_name[30])
{
    FILE *file;
    char file_path[100];

    strcpy(file_path, "data/");
    strcat(file_path, file_name);

    file = fopen(file_path, "w");
    fclose(file);
};


void print_num_clients(const char file_name[30], int num_cl)
{
    FILE *file;
    char file_path[100];

    strcpy(file_path, "data/");
    strcat(file_path, file_name);

    file = fopen(file_path, "w");

    if (file) {fprintf(file, "%d\n", num_cl);}
    else {cout<< "Error to open file\n" << endl;};

    fclose(file);
};


void print_clients_in_file(struct Client *list_clients)
{
    clean_file("client.txt");

    print_num_clients("client.txt", get_num_clients());
    
    for (int i = 0; i < get_num_clients(); i++)
    {
        print_client_in_file("client.txt", list_clients[i]);
    };
};


void read_file_client(const char file_name[30], struct Client *list_clients)
{
    FILE *file;
    char file_path[100];
    //struct Client c;
    int num_cl;

    strcpy(file_path, "data/");
    strcat(file_path, file_name);

    file = fopen(file_path, "r");

    if (file)
    {   
        fscanf(file, "%d\n", &num_clients);
        
        for (int i = 0; i < num_clients; i++)
        {
            fscanf(file, "%d %s %d %.1f\n", &(list_clients[i].code), &(list_clients[i].name), &(list_clients[i].age), &(list_clients[i].salary));
        };
    }
    else {cout<< "Error to open file\n" << endl;};

    fclose(file);
};