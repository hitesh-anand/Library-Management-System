#include <bits/stdc++.h>
using namespace std;

class Student : public User
{

public:
    int num_issued_books;
    vector<pair<Book *, int>> issued_books;
    Student(string name, int id, string password, string userName)
    {
        this->name = name;
        this->id = id;
        this->password = password;
        this->userName = userName;
        this->role = "student";
        this->num_issued_books = 0;
    }

    bool can_issue_another_book()
    {
        if (this->num_issued_books < 5)
            return true;
        return false;
    }

    void show_issued_books()
    {
        if (num_issued_books == 0)
            cout << "You haven't issued any books yet!" << endl;
        for (int i = 0; i < issued_books.size(); i++)
        {
            cout << i + 1 << ". ";
            issued_books[i].first->print_details();
            cout << endl;
        }
    }

    void issue_book(Book *b)
    {
        if (!b->check_issueable())
            cout << "Sorry, the book cannot be issued!" << endl;
        else
        {
            issued_books.push_back(make_pair(b, 0));
            b->change_issue_status();
            b->issued_to = this->userName;
            num_issued_books++;
            cout << "The book has been successfully issued to your name. Kindly return the book before 30 days to avoid any fine amount." << endl;
        }
    }

    int calculate_single_fine(int days)
    {
        return max(2*(days-30),0);
    }


    void return_book()
    {
        cout << "Enter the ISBN of the book you want to return: ";
        string isbn;
        cin >> isbn;
        for (int i = 0; i < num_issued_books; i++)
        {
            if (issued_books[i].first->isbn == isbn)
            {
                issued_books[i].first->change_issue_status();
                issued_books.erase(issued_books.begin() + i);
                num_issued_books--;
                cout << "Number of days that you have kept this book: ";
                int due_days;
                cin >> due_days;
                int fine = calculate_single_fine(due_days);
                if(fine == 0)
                    cout<<"You have returned your book before the due date. There is no fine!"<<endl;
                else
                    cout<<"You have to pay a fine of: "<<fine<<" rupees"<<endl;

                cout << "Thanks for returning the book! Hope you enjoyed your read :)" << endl;
                return;
            }
        }
        cout << "No such book has been issued by you!" << endl;
    }
};