#include <iostream>
using namespace std;

const int Max_book = 100;
int bookids[Max_book];
string booktiltle[Max_book];
string bookauthors[Max_book];
bool Borrowed[Max_book];
int bookcounter = 0;

void add_book()
{
    if (bookcounter >= Max_book)
    {
        cout << "Library is full" << endl;
        return;
    }
    int id;
    string title, author;
    cout << "add new book" << endl;
    cout << "write the id" << endl;
    cin >> id;

    for (int i = 0; i < bookcounter; i++)
    {
        if (bookids[i] == id)
        {
            cout << "this id is exists" << endl;
            return;
        }
    }

    cout << "write the title of book" << endl;
    cin >> title;

    cout << "write the author of book" << endl;
    cin >> author;

    bookids[bookcounter] = id;
    bookauthors[bookcounter] = author;
    booktiltle[bookcounter] = title;
    Borrowed[bookcounter] = false;

    bookcounter++;
    cout << "book is add" << endl;
}

void display_book()
{
    if (bookcounter == 0)
    {
        cout << "There is no books to display" << endl;
    }
    cout << "List of books" << endl;
    cout << "*---------------------*" << endl;

    for (int i = 0; i < bookcounter; i++)
    {
        cout << "Book ID: " << bookids[i] << endl;
        cout << "Book title: " << booktiltle[i] << endl;
        cout << "Book Author: " << bookauthors[i] << endl;
        cout << "Status:" << (Borrowed[i] ? "borrowed" : "Avaible") << endl;
    }
}

void borrow_book()
{
        int id;
    cout << "Enter book ID to borrow: ";
    cin >> id;
    if (bookcounter == 0)
    {
        cout << "There is no book" << endl;
        return;
    }

    for (int i = 0; i < bookcounter; i++)
    {
        if (bookids[i] == id)
        {
            if (Borrowed[i])
            {
                cout << "The book is borrowed" << endl;
            }
            else
            {
                Borrowed[i] = true;
                cout << "the book borrowed succesfuly" << endl;
            }
            return;
        }
    }
    cout << "Book not found!" << endl;
}

void return_book()
{
        int id;
    cout << "Enter book ID to return: ";
    cin >> id;
    if (bookcounter == 0)
    {
        cout << "There is no book avaible" << endl;
        return;
    }

    for (int i = 0; i < bookcounter; i++)
    {
        if (bookids[i] == id)
        {
            if (Borrowed[i])
            {
                cout << "There no book to return" << endl;
            }
            else
            {
                Borrowed[i] = false;
                cout << "The book is returned " << endl;
            }
            return;
        }
    }
    cout << "Book not found!" << endl;
}
void menu()
{
    int choice;
    do
    {
        cout << "\nLibrary System" << endl;
        cout << "1.Add New Book" << endl;
        cout << "2.Display All Books" << endl;
        cout << "3. Borrow a Book" << endl;
        cout << "4. Return a Book" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_book();

            break;

        case 2:
            display_book();
            /* code */
            break;

        case 3:
            borrow_book();
            /* code */
            break;

        case 4:
            return_book();

            break;

        case 5:
            cout << "THX For using .";
            break;

        default:
            cout << "just from 1 to 5";
            break;
        }
    } while (choice != 5);
}
int main()
{
    menu();
    return 0;
}
