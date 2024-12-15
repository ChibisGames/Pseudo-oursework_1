#include <iostream>
#include <cstring>
#include <iomanip>
#include "book.h"
using namespace std;

static int num_books = 0;
static int book_index = 0;

void menu_books(int *opt, struct Book *list_books){
    int pos;
    //char search_prod[40];
    struct Book b;

    do{
        /*cout<<left;
        cout << setw(20) << "\n --- MANAGMENT OF BOOKS ---"<<endl;    
        cout << "\nSelect an option from [1-8] according to the menu:" << endl;
        cout << "[1]. Insert book"<<endl;
        cout << "[2]. Read list of books"<<endl;
        cout << "[3]. Search product"<<endl;
        cout << "[4]. Sort by unit price"<<endl;
        cout << "[5]. Update product"<<endl;
        cout << "[6]. Delete product"<<endl;
        cout << "[7]. Find product with lowest price"<<endl;
        cout << "[8]. Exit"<<endl;
        cout << "------------------------------------------------"<<endl;
        cout << "Enter option: ";
        cin>> *opt;*/

        cout<<left;
        cout << setw(20) << "\n --- MANAGMENT OF BOOKS ---"<<endl;    
        cout << "\nSelect an option from [1-8] according to the menu:" << endl;
        cout << "[1]. Insert book"<<endl;
        cout << "[2]. Read list of books"<<endl;
        cout << "[3]. Update book"<<endl;
        cout << "[4]. Delete product"<<endl;
        cout << "[5]. Sort bookd by criteria"<<endl;
        cout << "[6]. Find books by criteria"<<endl;
        cout << "[7]. Exit"<<endl;
        cout << "------------------------------------------------"<<endl;
        cout << "Enter option: ";
        cin>> *opt;

        /*switch(*opt){
            case 1:     // insert
                insert_book(&lst_books[get_num_books()]);
                break;
            case 2:     // read 
                print_lst_products(lst_products);
                break;
            case 3:     // search                
                // get the position
                pos = search_product(search_prod, lst_products);
                
                // get the client
                p = get_product(pos, lst_products);

                if(p.code != 0){
                    // print the client
                    cout<<"\nSearched product: "<<endl;
                    print_product(p);
                }else{
                    cout<<"\nProduct not found"<<endl;
                }
                
                // clean the memory of client
                memset(&p, 0, sizeof(p));
                break;
            case 4:     // sort data by price
                cout<<"\nList of products ordered by price"<<endl;
                sort_by_prices(lst_products);
                print_lst_products(lst_products);
                break;
            case 5:     // update client                
                update_product(search_prod, lst_products);
                break;
            case 6:     // delete client                
                delete_product(search_prod, lst_products);
                break;
            case 7:     // get client with cheapest cost
                pos = get_cheapest_product(lst_products);
                p = get_product(pos, lst_products);
                cout<<"\nProduct with cheapest price: "<<endl;
                print_product(p);
                break;
            case 8:
                cout << "Exiting to main menu..." << endl;
                break;
            default:
                cout << "\nInvalid option" << endl;
                break;
        }

    }while(*opt != 8);
}*/

        switch(*opt){
            case 1:     // insert
                insert_book(&list_books[get_num_books()]);
                break;
            case 2:     // read 
                print_lst_books(list_books);
                break;
            /*case 3:     // sort by price
                cout<<"\nList of products ordered by price"<<endl;
                //sort_by_prices(lst_products);
                //print_lst_products(lst_products);
                break;
            case 4:     // update client                
                //update_product(search_prod, lst_products);
                break;
            case 5:     // delete client                
                //delete_product(search_prod, lst_products);
                break;
            case 6:     // get client with cheapest cost
                /*pos = get_cheapest_product(lst_products);
                p = get_product(pos, lst_products);
                cout<<"\nProduct with cheapest price: "<<endl;
                print_product(p);
                break;
            case 7:
                cout << "Exiting to main menu..." << endl;
                break;*/
            default:
                cout << "\nInvalid option" << endl;
                break;
        }

    }while(*opt != 7);
}

void insert_book(struct Book *b){
    cout<< "\n*** Insert new book ***"<<endl;
    book_index++;
    b->code = book_index;
    cout<<"Author: ";
    cin>>b->author;

    cout<<"Title: ";
    cin>>b->title;

    cout<<"Stock: ";
    cin>>b->stock;

    do{
        cout<<"Price: ";
        cin>>b->price;
    }while(b->price < 100 || b->price > 50000);
    
    do{
        cout<<"Year: ";
        cin>>b->year;
    }while(b->year < 2000);
    
    cout<<"Category: ";
    cin>>b->category;
    
    num_books++;
}

int get_num_books(){
    return num_books;
}

void print_lst_books(struct Book *list_books){
    cout<<"\n*** List of books ***"<<endl;
    cout<<left;
    cout<< setw(10) << "code" << setw(15) << "author" << setw(15) << "title"
        << setw(10) << "stock" << setw(10) <<"price"<< setw(10)<< "year"<< setw(10) << "category"<<endl;
    cout << "---------------------------------------------------------------------------" << endl;

    for(int i=0; i<get_num_books(); i++){
        print_book(list_books[i]);
    }
}

void print_book(struct Book b){
    cout<< setw(10) << b.code << setw(15) << b.author << setw(15) << b.title
        << setw(10) << b.stock << setw(10) << b.price << setw(10)<< b.year << setw(10)
         << b.category <<endl;
}