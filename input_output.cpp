#include <iostream>
#include <cstdio>
#include <string.h>

#include "input_output.h"
#include "book.h"
#include "client.h"
#include "order.h"
#include "order_detail.h"

using namespace std;


/* Unnamed */
void clean_file(const char file_name[30])
{
    FILE *file;
    char file_path[100];

    strcpy(file_path, "data/");
    strcat(file_path, file_name);

    file = fopen(file_path, "w");
    fclose(file);
};

void print_num_object(const char file_name[30], int num_obj)
{
    FILE *file;
    char file_path[100];

    strcpy(file_path, "data/");
    strcat(file_path, file_name);

    file = fopen(file_path, "w");

    if (file) {fprintf(file, "%d\n", num_obj);}
    else {cout<< "Error to open file\n" << endl;};

    fclose(file);
};


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
        fprintf(file, "%d %s %d %lf\n", c.code, c.name, c.age, c.salary);
    }
    else {cout<< "Error to open file\n" << endl;};

    fclose(file);
};

void print_clients_in_file(struct Client *list_clients)
{
    clean_file("client.txt");

    print_num_object("client.txt", get_num_clients());
    
    for (int i = 0; i < get_num_clients(); i++)
    {
        print_client_in_file("client.txt", list_clients[i]);
    };
};

void read_file_client(const char file_name[30], struct Client *list_clients)
{
    FILE *file;
    char file_path[100];

    strcpy(file_path, "data/");
    strcat(file_path, file_name);

    file = fopen(file_path, "r");

    if (file)
    {   
        fscanf(file, "%d\n", &num_clients);
        
        for (int i = 0; i < num_clients; i++)
        {
            fscanf(file, "%d %s %d %lf\n", &(list_clients[i].code), &(list_clients[i].name), &(list_clients[i].age), &(list_clients[i].salary));
        };
    }
    else {cout<< "Error to open file\n" << endl;};

    fclose(file);
};


/* Books */
void print_book_in_file(const char file_name[30], struct Book c)
{
    FILE *file;
    char file_path[100];

    strcpy(file_path, "data/");
    strcat(file_path, file_name);

    file = fopen(file_path, "a");

    if (file)
    {   
        fprintf(file, "%d %s %s %d %f %d %d\n", 
        c.code, c.author, c.title, c.stock, c.price, c.year, c.category);
    }
    else {cout<< "Error to open file\n" << endl;};

    fclose(file);
};

void print_books_in_file(struct Book *list_books)
{
    clean_file("book.txt");

    print_num_object("book.txt", get_num_books());
    
    for (int i = 0; i < get_num_books(); i++)
    {
        print_book_in_file("book.txt", list_books[i]);
    };
};

void read_file_book(const char file_name[30], struct Book *list_books)
{
    FILE *file;
    char file_path[100];

    strcpy(file_path, "data/");
    strcat(file_path, file_name);

    file = fopen(file_path, "r");

    if (file)
    {   
        fscanf(file, "%d\n", &num_books);
        
        for (int i = 0; i < num_books; i++)
        {
            fscanf(file, "%d %s %s %d %f %d %d\n", &(list_books[i].code), &(list_books[i].author), &(list_books[i].title), 
            &(list_books[i].stock), &(list_books[i].price), &(list_books[i].year), &(list_books[i].category));
        };
    }
    else {cout<< "Error to open file\n" << endl;};

    fclose(file);
};


/* Order */
void print_order_in_file(const char file_name[30], struct Order c)
{
    FILE *file;
    char file_path[100];

    strcpy(file_path, "data/");
    strcat(file_path, file_name);

    file = fopen(file_path, "a");

    if (file)
    {   
        fprintf(file, "%d %d %d\n", c.code, c.client.code, c.num_details);
    }
    else {cout<< "Error to open file\n" << endl;};

    fclose(file);
};

void print_orders_in_file(struct Order *list_orders)
{
    clean_file("order.txt");
    clean_file("order_detail.txt");

    print_num_object("order.txt", get_num_orders());

    for (int i = 0; i < get_num_orders(); i++)
    {
        print_order_in_file("order.txt", list_orders[i]);
        for (int j = 0; j < list_orders[i].num_details; j++)
        {
            print_order_detail_in_file("order_detail.txt", &(list_orders[i]), j);
        }  
    };
};

void read_file_order(const char file_name[30], struct Order *list_orders,
    struct Book *list_books, struct Client *list_clients)
{
    FILE *file;
    char file_path[100];

    strcpy(file_path, "data/");
    strcat(file_path, file_name);

    file = fopen(file_path, "r");

    if (file)
    {   
        fscanf(file, "%d\n", &num_orders);
        
        for (int i = 0; i < num_orders; i++)
        {
            fscanf(file, "%d %d %d\n", &(list_orders[i].code), &(list_orders[i].client.code), &(list_orders[i].num_details));

            read_file_order_detail("order_detail.txt", &(list_orders[i]), list_books, list_clients);
        };
    }
    else {cout<< "Error to open file\n" << endl;};

    fclose(file);
};


/* Order_Detail */
void print_order_detail_in_file(const char file_name[30], Order *o, int i)
{
    FILE *file;
    char file_path[100];

    strcpy(file_path, "data/");
    strcat(file_path, file_name);

    file = fopen(file_path, "a");

    if (file)
    {   
        fprintf(file, "%d %d %d\n", o->code, o->details[i].book.code, o->details[i].quantity);
    }
    else {cout<< "Error to open file\n" << endl;};

    fclose(file);
};

void read_file_order_detail(const char file_name[30], struct Order *o,
    struct Book *list_books, struct Client *list_clients)
{
    FILE *file;
    char file_path[100];

    strcpy(file_path, "data/");
    strcat(file_path, file_name);

    file = fopen(file_path, "r");

    if (file)
    {      
        o->total = 0;
        for (int j = 0; j < o->num_details; j++)
        {
            fscanf(file, "%d %d %d\n", &(o->code), &(o->details[j].book.code), &(o->details[j].quantity));

            o->details[j].book = get_book_by_id(o->details[j].book.code, list_books);
            o->details[j].subtotal = o->details[j].quantity * o->details[j].book.price;
            o->total += o->details[j].subtotal;
        };
    }
    else
    {
        cout<< "Error to open file\n" << endl;
    };

    o->client = get_client_by_code(o->client.code, list_clients);
    
    fclose(file);
};
