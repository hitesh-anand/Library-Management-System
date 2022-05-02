#include <bits/stdc++.h>
using namespace std;

class BookDB
{
    vector<Book *> books;
    int count;

public:
    BookDB(vector<Book *> v)
    {
        this->books = v;
        this->count = v.size();
    }
    BookDB()
    {
        this->count = 0;
    }
    void show_all_books()
    {
        for (int i = 0; i < count; i++)
        {
            cout << i + 1 << ". ";
            books[i]->print_details();
            cout << endl;
        }
    }
    void add_book()
    {

        // getline(cin, title);
        cout << "Enter the details of the book to be added." << endl;
        cin.ignore();

        cout << "Enter the title of the book: ";
        string title;
        getline(cin, title);

        cout << "Enter the author of the book: ";
        string author;
        getline(cin, author);

        cout << "Enter the ISBN of the book: ";
        string isbn;
        getline(cin, isbn);
        int unique = 0;
        while (unique == 0)
        {
            unique = 1;
            for (int i = 0; i < count; i++)
            {
                if (books[i]->isbn == isbn)
                {
                    unique = 0;
                    cout << "Another book with same ISBN already exists. Please enter a unique ISBN: " << endl;
                    getline(cin, isbn);
                }
                else if(isbn.size() != 13)
                {
                    unique = 0;
                    cout<<"Invalid ISBN. The ISBN must be exactly 13 digits long. Please enter a valid ISBN: "<<endl;
                    getline(cin, isbn);
                }
            }
        }

        cout << "Enter the publication of the book: ";
        string publication;
        getline(cin, publication);

        Book *b = new Book(title, author, isbn, publication);
        books.push_back(b);
        count++;
    }

    int get_count() // returns the number of books in the user_database
    {
        return count;
    }

    void delete_book(Book *b)
    {
        auto it = find(books.begin(), books.end(), b);
        if (it == books.end())
        {
            cout << "The book doesn't exist in the library!" << endl;
        }
        else
        {
            books.erase(it);
            cout << "Book deleted successfully!" << endl;
            count--;
        }
    }

    void delete_book_with_title(string title)
    {
        int ind = -1;
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i]->get_title() == title)
            {
                ind = i;
                break;
            }
        }
        if (ind == -1)
        {
            cout << "The book doesn't exist in the library!" << endl;
        }
        else
        {
            books.erase(books.begin() + ind);
            cout << "Book deleted successfully!" << endl;
            count--;
        }
    }

    void delete_book_by_isbn(string isbn)
    {
        for (int i = 0; i < count; i++)
        {
            if (books[i]->isbn == isbn)
            {
                books.erase(books.begin() + i);
                count--;
                cout << "The book with ISBN = " << isbn << " has been deleted successfully!" << endl;
                return;
            }
        }
        cout << "No such book exists. Could not complete the operation!" << endl;
    }
    void clear_book_database()
    {
        cout << "You cannot undo this operation. Type Y/y if you still want to continue" << endl;
        char t;
        cin >> t;
        if (t == 'Y' || t == 'y')
        {
            books.clear();
            cout << "book database cleared successfully!" << endl;
            count = 0;
        }
        else if (t == 'N' || t == 'n')
        {
            cout << "Operation aborted!" << endl;
        }
        else
        {
            cout << "Invalid key entered!" << endl;
        }
    }

    Book *search(Book *b)
    {
        auto it = find(books.begin(), books.end(), b);
        if (it == books.end())
        {
            cout << "Oops, the book could not be found!" << endl;
            return nullptr;
        }
        else
        {
            cout << "The book exists in the library!" << endl;
            cout << "The details of the book are as follows:" << endl;
            int index = it - books.begin();
            books[index]->print_details();
            return books[index];
        }
    }

    Book *search_by_isbn(string id)
    {
        for (int i = 0; i < this->count; i++)
        {
            if (books[i]->isbn == id)
            {
                return books[i];
            }
        }
        return nullptr;
    }

    vector<Book*> search_by_title(string title)
    {
        vector<Book*> res;
        for (int i = 0; i < this->count; i++)
        {
            if (books[i]->title == title)
            {
                res.push_back(books[i]);
            }
        }
        return res;        
    }

    vector<Book*> search_by_author(string author)
    {
        vector<Book*> res;
        for (int i = 0; i < this->count; i++)
        {
            if (books[i]->author == author)
            {
                res.push_back(books[i]);
            }
        }
        return res;        
    }

    void show_book_issued_by_user()
    {
        if (this->count == 0)
        {
            cout << "No book has been issued as of now!" << endl;
        }
        for (int i = 0; i < this->count; i++)
        {
            if (this->books[i]->can_be_issued == false)
            {
                cout << i + 1 << ". ";
                cout << "The book with the title " << this->books[i]->title << " has been issued to " << this->books[i]->issued_to << endl;
            }
        }
    }

    void show_all_issued_books()
    {
        if (this->count == 0)
            cout << "No book has been issued as of now!" << endl;
        for (int i = 0; i < this->count; i++)
        {
            if (this->books[i]->can_be_issued == false)
            {
                cout << i + 1 << ". ";
                this->books[i]->print_details();
            }
        }
    }
};