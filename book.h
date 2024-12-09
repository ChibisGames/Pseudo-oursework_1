#ifndef BOOK_H
#define BOOK_H


struct Book
{
   int id;
   char *author[40];
   char *title[40];
   int number;
   float price;
   int year;
   int category;
   // Category?
};
#endif