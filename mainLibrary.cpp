#include <iostream>
#include <cstring>
#include <cmath>

#include "master.cpp"

using namespace std;

#define MAX_CLIENTS 100
#define MAX_BOOKS 100
#define MAX_ORDERS 100

void menu_master(int *opt);


int main()
{
    int opt;
    char cont;
    struct Client *list_clients;
    struct Book *list_books;
    struct Order *list_orders;

    list_clients = new struct Client[MAX_CLIENTS];
    list_books = new struct Book[MAX_BOOKS];
    list_orders = new struct Order[MAX_ORDERS];

    do
    {
        menu_master(&opt);

        switch (opt)
        {
            case 1:     // clients
                menu_clients(&opt, list_clients);
                break;
            case 2:     // books
                menu_books(&opt, list_books);
                break;
            case 3:     // orders
                menu_orders(&opt, list_clients, list_books, list_orders);
                break;
            default:
                cout<<"\nInvalid option"<<endl;
                break;
        };

        // Request to user continue or not
        cout << "\nDo you want continue [Y|N]? "<< endl;
        cin>> cont;
    } while(cont == 'y' || cont == 'Y');

    cout << "The program is over!"<< endl;

    // cleaning of memory
    delete[] list_clients;
    delete[] list_books;
    delete[] list_orders;

    return 0;
}


void menu_master(int *opt){
    cout << "-----------------------------------------------"<<endl;
    cout<<"*** SYSTEM OF PRODUCT SALES ***"<<endl;
    cout << "-----------------------------------------------"<<endl;
    cout << "\nSelect an option from [1-3] according to the menu:" << endl;
    cout << "[1]. Managment of Clients"<<endl;
    cout << "[2]. Managment of Books"<<endl;
    cout << "[3]. Managment of Orders"<<endl;
    cout << "-----------------------------------------------"<<endl;
    cout << "Enter option: ";
    cin>> *opt;
    cout <<endl;
};