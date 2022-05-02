#include <bits/stdc++.h>
using namespace std;

class Book
{
public:
    string title;
    string author;
    string isbn;
    string publication;
    bool can_be_issued;
    string issued_to;

    Book(string title, string author, string isbn, string publication)
    {
        this->title = title;
        this->author = author;
        this->isbn = isbn;
        this->publication = publication;
        this->can_be_issued = true; // initially every book can be issued
        this->issued_to = "no one";
    }

    void print_details()
    {
        cout << "The title of the book is: " << this->title << endl;
        cout << "This book is written by: " << this->author << " and published by " << this->publication << endl;
        cout << "The unique ISBN for this book is: " << this->isbn << "." << endl;
        if (can_be_issued)
            cout << "This book is available for issue!" << endl;
        else
            cout << "This book is not available for issue" << endl;
    }

    bool check_issueable()
    {
        return this->can_be_issued;
    }

    string get_title()
    {
        return this->title;
    }

    string get_author()
    {
        return this->author;
    }

    string get_publication()
    {
        return this->publication;
    }

    string get_isbn()
    {
        return isbn;
    }

    void change_issue_status() // used when user issues/returns a book
    {
        if (this->can_be_issued == false)
            this->issued_to = "no one";
        this->can_be_issued = !(this->can_be_issued);
    }
};