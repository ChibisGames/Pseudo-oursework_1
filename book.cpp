#include <iostream>
#include <cstring>
#include <iomanip>
#include "book.h"
#include "input_output.h"
using namespace std;

static int num_books = 0;
static int book_index = 0;


void menu_books(int *opt, struct Book *list_books){
    int pos;
    char search_title[40];
    char crit[40];
    struct Book b;


    do{
        read_file_books("book.txt", list_books);
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

        switch(*opt){
            case 1:     // insert
                insert_book(&list_books[get_num_books()]);
                print_books_in_file(list_books);
                break;
            case 2:     // read 
                print_lst_books(list_books, get_num_books());
                break;
            case 3:     // update
                update_book(search_title, list_books);
                clean_file("book.txt");
                print_books_in_file(list_books);
                break;
            case 4:     // delete book              
                delete_book(search_title, list_books);
                clean_file("book.txt");
                print_books_in_file(list_books);
                break;
            case 5:     // sort                
                choose_criterion_sort(list_books);
                clean_file("book.txt");
                print_books_in_file(list_books);
                print_lst_books(list_books, get_num_books());
                break;
            case 6:     // find books by criteria
                choose_criterion_find(list_books, crit);
                break;
            case 7:
                cout << "Exiting to main menu..." << endl;
                break;
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
    
    cout<<"Category (fantasy, fantastic, history, roman): ";
    cin>>b->category;
    
    num_books++;
}

int get_num_books(){
    return num_books;
}

void print_lst_books(struct Book *list_books, int num){
    cout<<"\n*** List of books ***"<<endl;
    cout<<left;
    cout<< setw(10) << "code" << setw(15) << "author" << setw(15) << "title"
        << setw(10) << "stock" << setw(10) <<"price"<< setw(10)<< "year"<< setw(10) << "category"<<endl;
    cout << "---------------------------------------------------------------------------" << endl;

    for(int i=0; i<num; i++){
        print_book(list_books[i]);
    }
}

void print_book(struct Book b){
    cout<< setw(10) << b.code << setw(15) << b.author << setw(15) << b.title
        << setw(10) << b.stock << setw(10) << b.price << setw(10)<< b.year << setw(10)
         << b.category <<endl;
}

void update_book(char *search_title, struct Book *list_books){
    int pos;    

    cout<< "\n*** Update Book ***"<<endl;

    pos = search_book(search_title, list_books);

    if(pos != -1){        
        cout<<"Author: ";
        cin>>list_books[pos].author;

        cout<<"Title: ";
        cin>>list_books[pos].title;

        cout<<"Stock: ";
        cin>>list_books[pos].stock;

        do{
            cout<<"Price: ";
            cin>>list_books[pos].price;
        }while(list_books[pos].price < 100 || list_books[pos].price > 50000);
        
        do{
            cout<<"Year: ";
            cin>>list_books[pos].year;
        }while(list_books[pos].year < 2000);
        
        cout<<"Category (fantasy, fantastic, history, roman): ";
        cin>>list_books[pos].category;
        

        cout<<"\nBook updated!"<<endl;
    }else{
        cout<<"\nBook not found!"<<endl;
    }    
}

void delete_book(char *search_title, struct Book *list_books){
    int pos;

    cout<<"\n***Delete Book***"<<endl;

    pos = search_book(search_title, list_books);

    if(pos != -1){
        for(int i=pos; i<get_num_books(); i++){
            list_books[i] = list_books[i+1];
        }
        num_books--;

        cout<<"\nBook deleted!"<<endl;
    }else{
        cout<<"\nBook not found"<<endl;
    }
}

int search_book(char *search_title, struct Book *list_books){
    int pos;

    cout<< "\n*** Search Book ***"<<endl;
    cout<<"\nWrite the title of the searched book: ";
    cin>>search_title;

    for(int i=0; i<get_num_books(); i++){
        if (strcmp(list_books[i].title, search_title) == 0){
            pos = i;
            break;
        }else{
            pos = -1;
        }
    }

    return pos;
}

void choose_criterion_sort(struct Book *b){
    int criterion;
    cout<<"Choose criterion for sort (author - 1, title - 2, price - 3, year - 4, category - 5): ";
    cin>>criterion;
    switch(criterion){
        case 1:
            sort_by_authors(b);
            break;
        case 2:
            sort_by_titles(b);
            break;
        case 3:
            sort_by_prices(b);
            break;
        case 4:
            sort_by_years(b);
            break;
        case 5:
            sort_by_categories(b);
            break;
        default:
            cout<<"Wrong criterion";
            break;

    }
}

void sort_by_authors(struct Book *list_books){
    struct Book aux;

    cout<<"\nList of books ordered by author"<<endl;
    for(int i=0; i<get_num_books()-1; i++){
        for(int j=i+1; j<get_num_books(); j++){
            if (strcmp(list_books[i].author, list_books[j].author) > 0){
                aux = list_books[i];
                list_books[i] = list_books[j];
                list_books[j] = aux;
            }
        }
    }
}

void sort_by_titles(struct Book *list_books){
    struct Book aux;

    cout<<"\nList of books ordered by title"<<endl;
    for(int i=0; i<get_num_books()-1; i++){
        for(int j=i+1; j<get_num_books(); j++){
            if (strcmp(list_books[i].title, list_books[j].title) > 0){
                aux = list_books[i];
                list_books[i] = list_books[j];
                list_books[j] = aux;
            }
        }
    }
}

void sort_by_prices(struct Book *list_books){
    struct Book aux;

    cout<<"\nList of books ordered by price"<<endl;
    for(int i=0; i<get_num_books()-1; i++){
        for(int j=i+1; j<get_num_books(); j++){
            if (list_books[i].price > list_books[j].price){
                aux = list_books[i];
                list_books[i] = list_books[j];
                list_books[j] = aux;
            }
        }
    }
}

void sort_by_years(struct Book *list_books){
    struct Book aux;

    cout<<"\nList of books ordered by authors"<<endl;
    for(int i=0; i<get_num_books()-1; i++){
        for(int j=i+1; j<get_num_books(); j++){
            if (list_books[i].year > list_books[j].year){
                aux = list_books[i];
                list_books[i] = list_books[j];
                list_books[j] = aux;
            }
        }
    }
}

void sort_by_categories(struct Book *list_books){
    struct Book aux;

    cout<<"\nList of books ordered by category"<<endl;
    for(int i=0; i<get_num_books()-1; i++){
        for(int j=i+1; j<get_num_books(); j++){
            if (list_books[i].category > list_books[j].category){
                aux = list_books[i];
                list_books[i] = list_books[j];
                list_books[j] = aux;
            }
        }
    }
}

void choose_criterion_find(struct Book *b, char *crit){
    int criterion;
    struct Book *crit_lst_books;
    cout<<"Choose criterion for find (author - 1, title - 2, price - 3, year - 4, category - 5): ";
    cin>>criterion;
    switch(criterion){
        case 1:
            find_author(b, crit_lst_books, crit);
            break;
        case 2:
            find_title(b, crit_lst_books, crit);
            break;
        case 3:
            find_price(b, crit_lst_books);
            break;
        case 4:
            find_year(b, crit_lst_books);
            break;
        case 5:
            find_category(b, crit_lst_books, crit);
            break;
        default:
            cout<<"Wrong criterion";
            break;

    }
}

void find_author(struct Book *b, struct Book *crit_lst_books, char *crit){
    int ind=0;
    cout<<"Author you want to find: ";
    cin>>crit;
    for (int i=0; i<get_num_books(); i++){
        if (strcmp(b[i].author, crit) == 0){
            crit_lst_books[ind] = b[i];
            ind++;
        }
    }
    print_lst_books(crit_lst_books, ind+1);
}

void find_title(struct Book *b, struct Book *crit_lst_books, char *crit){
    int ind=0;
    cout<<"Title you want to find: ";
    cin>>crit;
    for (int i; i<get_num_books(); i++){
        if (strcmp(b[i].title, crit) == 0){
            crit_lst_books[ind] = b[i];
            ind++;
        }
    }
    print_lst_books(crit_lst_books, ind+1);
}

void find_price(struct Book *b, struct Book *crit_lst_books){
    int ind=0;
    int crit;
    cout<<"Price you want to find: ";
    cin>>crit;
    for (int i; i<get_num_books(); i++){
        if (b[i].price == crit){
            crit_lst_books[ind] = b[i];
            ind++;
        }
    }
    print_lst_books(crit_lst_books, ind+1);
}

void find_year(struct Book *b, struct Book *crit_lst_books){
    int ind=0, crit;
    cout<<"Year you want to find: ";
    cin>>crit;
    for (int i; i<get_num_books(); i++){
        if (b[i].year == crit){
            crit_lst_books[ind] = b[i];
            ind++;
        }
    }
    print_lst_books(crit_lst_books, ind+1);
}

void find_category(struct Book *b, struct Book *crit_lst_books, char *crit){
    int ind=0;
    cout<<"Category you want to find: ";
    cin>>crit;
    for (int i; i<get_num_books(); i++){
        if(strcmp(b[i].title, crit) == 0){
            crit_lst_books[ind] = b[i];
            ind++;
        }
    }
    print_lst_books(crit_lst_books, ind+1);
}
