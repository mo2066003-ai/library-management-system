#include <iostream>
#include <vector>
#include <string>

using namespace std;


// ================= BOOK CLASS =================

class Book
{
public:

    string title;
    string author;
    bool borrowed;

    // Constructor
    Book(string t, string a)
    {
        title = t;
        author = a;
        borrowed = false;
    }

    // Display book information
    void display()
    {
        cout << "Title: " << title;
        cout << " | Author: " << author;

        if (borrowed)
            cout << " | Status: Borrowed";
        else
            cout << " | Status: Available";

        cout << endl;
    }
};


// ================= MAIN =================

int main()
{
    vector<Book> books;

    int choice;

    do
    {
        cout << "\n=== Library Management System ===\n";

        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search Book\n";
        cout << "6. Display All Books\n";
        cout << "7. Exit\n";

        cout << "Choose an option: ";
        cin >> choice;


        // ================= ADD BOOK =================

        if (choice == 1)
        {
            string title;  
            string author;

            cout << "Enter book title: ";
            cin >> title;

            cout << "Enter author: ";
            cin >> author;

            Book newBook(title, author);

            books.push_back(newBook);

            cout << "Book \"" << title << "\" added.\n";
        }


        // ================= REMOVE BOOK =================

        else if (choice == 2)
        {
            string title;
            bool found = false ;

            cout << "Enter book title to remove: ";
            cin >> title;

            for (int i = 0; i < books.size(); i++)
            {
                if (books[i].title == title)
                {
                    books.erase(books.begin() + i);

                    cout << "Book \"" << title << "\" removed.\n";
                    found = true ;
                    break;
                }
            }
            if (found == false)

    {

        cout << "Book \"" << title << "\" not found.\n";

    }
        }


        // ================= BORROW BOOK =================

        else if (choice == 3)
        {
            string title;
            bool found = false ;

            cout << "Enter book title to borrow: ";
            cin >> title;

            for (int i = 0; i < books.size(); i++)
            {
                if (books[i].title == title)
                {
                    found = true ;
                    if (books[i].borrowed == false)
                    {
                        books[i].borrowed = true;

                        cout << "\"" << title
                             << "\" borrowed successfully.\n";
                    }
                    else
                    {
                        cout << "Book is already borrowed.\n";
                    }

                    break;
                }
            }
            if (found == false)

    {

        cout << "Book \"" << title << "\" not found.\n";

    }
        }


        // ================= RETURN BOOK =================

        else if (choice == 4)
        {
            string title;
            bool found = false ;

            cout << "Enter book title to return: ";
            cin >> title;

            for (int i = 0; i < books.size(); i++)
            {
                if (books[i].title == title)
                {
                    found = true ;
                    books[i].borrowed = false;

                    cout << "\"" << title
                         << "\" returned successfully.\n";

                    break;
                }
            }
            if (found == false)

    {

        cout << "Book \"" << title << "\" not found.\n";

    }
        }


        // ================= SEARCH BOOK =================

        else if (choice == 5)
        {
            string title;
            bool found = false ;

            cout << "Enter book title to search: ";
            cin >> title;

            for (int i = 0; i < books.size(); i++)
            {
                if (books[i].title == title)
                {
                    found = true ;
                    books[i].display();

                    break;
                }
            }
            if (found == false)

    {

        cout << "Book \"" << title << "\" not found.\n";

    }
        }


        // ================= DISPLAY ALL BOOKS =================

        else if (choice == 6)
        {
            cout << "\n--- All Books ---\n";

            for (int i = 0; i < books.size(); i++)
            {
                books[i].display();
            }
        }


    } while (choice != 7);


    cout << "Goodbye!\n";

    return 0;
}