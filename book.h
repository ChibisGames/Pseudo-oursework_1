#ifndef BOOK_H
#define BOOK_H

struct Book
{
   int code;
   char author[40];
   char title[40];
   int stock;
   float price;
   int year;
   int category;
   enum Category {FANTASY, FANTASTIC, ROMAN, HISTORY};
};


void menu_books(int *opt, struct Book *lst_books);
void insert_book(struct Book *b);
int get_num_books();
void print_lst_books(struct Book *list_books);
void print_book(struct Book b);

#endif