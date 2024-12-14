#pragma once

struct Book
{
   int code;
   char *author[40];
   char *title[40];
   int number;
   float price;
   int year;
   int category;
   enum Category {FANTASY, FANTASTIC, ROMAN, HISTORY};
};


static int num_books = 0;
//static int index = 0;

void menu_books(int *opt, struct Book *list_books)
{

};