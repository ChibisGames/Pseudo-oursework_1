#include <iostream>
#include <cstring>
#include <iomanip>
#include "order_detail.h"
using namespace std;


void insert_order_detail(OrderDetail *detail, Book *list_books)
{
    char book_title[40];
    int book_index;

    cout << "\n--- INSERT ORDER DETAIL ---\n";
    //cout << "Enter Book Title: ";
    //cin >> book_title;

    book_index = search_book(book_title, list_books);
    if (book_index == -1) {
        cout << "Book not found.\n";
        return;
    }
    detail->book = get_book(book_index, list_books);

    do {
        cout << "Enter Quantity: ";
        cin >> detail->quantity;
        if (detail->quantity > detail->book.stock) {
            cout << "Not enough stock available. Try again.\n";
        }
    } while (detail->quantity > detail->book.stock);

    detail->subtotal = detail->quantity * detail->book.price;
    detail->book.stock -= detail->quantity;

    // Уменьшение запаса книги
    list_books[book_index].stock -= detail->quantity;

    cout << "Order detail added successfully.\n";
}
