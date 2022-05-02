#include <bits/stdc++.h>
#include "user.cpp"
#include "userDB.cpp"
#include "book.cpp"
#include "bookDB.cpp"
#include "student.cpp"
#include "professor.cpp"
#include "librarian.cpp"
using namespace std;

void initialize_user_database(vector<User *> &initial_users)
{
    initial_users.push_back(new User("Hitesh Anand", 0, "hitesh03", "student", "hitesh"));
    initial_users.push_back(new User("Suresh Kumar", 1, "suresh1975", "student", "suresh"));
    initial_users.push_back(new User("Indranil Saha", 2, "indranil74", "professor", "indranil"));
    initial_users.push_back(new User("Subhajit Roy", 3, "iitkanpur202", "professor", "subhajit"));
    initial_users.push_back(new User("Kritya Anand", 4, "kritya0110", "librarian", "kritya"));
}

void initialize_book_database(vector<Book *> &initial_books)
{
    initial_books.push_back(new Book("Advanced Calculus", "G. Tewani", "1234567654321", "Cengage"));
    initial_books.push_back(new Book("Optics and Modern Physics", "D C Pandey", "1234543211122", "Arihant"));
    initial_books.push_back(new Book("Intro to Trigonometry", "Amit Aggarwal", "2341719292923", "Arihant"));
    initial_books.push_back(new Book("Physical Chemistry", "N Avasthi", "1092736181910", "Balaji"));
    initial_books.push_back(new Book("General Knowledge", "H Anand", "1828399192245", "Lucent's"));
}

void show_catalog(string role)
{
    if (role == "student")
    {
        cout << "1 -> see all books" << endl;
        cout << "2 -> see issued books" << endl;
        cout << "3 -> check whether you can issue another book" << endl;
        cout << "4 -> issue a new book" << endl;
        cout << "5 -> return a book"<<endl;
        cout << "6 -> search a book" << endl;
        cout << "7 -> logout" << endl;
    }
    else if (role == "professor")
    {
        cout << "1 -> see all books" << endl;
        cout << "2 -> see issued books" << endl;
        cout << "3 -> issue a new book" << endl;
        cout << "4 -> return a book"<<endl;
        cout << "5 -> search a book" << endl;
        cout << "6 -> logout" << endl;
    }
    else
    {
        cout << "1 -> see all users" << endl;
        cout << "2 -> see all books" << endl;
        cout << "3 -> see which book is issued to which user" << endl;
        cout << "4 -> see which books have been issued" << endl;
        cout << "5 -> add a new user" << endl;
        cout << "6 -> delete a user" << endl;
        cout << "7 -> add a new book" << endl;
        cout << "8 -> delete a book" << endl;
        cout<< "9 -> search for a user" <<endl;
        cout<<"10 -> update details of a user"<<endl;
        cout<<"11 -> clear the book database"<<endl;
        cout<<"12 -> clear the user database"<<endl;
        cout << "13 -> logout" << endl;
    }
}

void play_student(BookDB *book_database, User *user)
{
    Student *s = new Student(user->get_name(), user->get_id(), user->get_password(), user->get_username());
    show_catalog(user->get_role());
    cout << "Press a key from 1-7 according to the catalog: " << endl;
    int key;
    cin >> key;
    while (key != 7)
    {
        if (key == 1)
        {
            book_database->show_all_books();
        }
        else if (key == 2)
        {
            s->show_issued_books();
        }
        else if (key == 3)
        {
            if (s->can_issue_another_book())
                cout << "Yes, you can issue another book!" << endl;
            else
                cout << "Sorry, but you have already issued 5 books!" << endl;
        }
        else if (key == 4)
        {
            if (s->can_issue_another_book())
            {
                cout << "Enter the isbn of the book you want to issue: ";
                string isbn;
                cin >> isbn;
                Book *book_issue = book_database->search_by_isbn(isbn);
                if (book_issue == nullptr)
                {
                    cout << "Sorry, the book is not available!" << endl;
                }
                else
                {
                    s->issue_book(book_issue);
                }
            }
            else
            {
                cout << "Sorry, but you cannot issue another book." << endl;
            }
        }
        else if(key == 5)
        {
            s->return_book();
        }
        else if (key == 6)
        {
            cout << "1 -> search by ISBN" << endl;
            cout << "2 -> search by title" << endl;
            cout << "3 -> search by author" << endl;
            int k;
            cin >> k;
            if (k == 1)
            {
                cin.ignore();
                cout << "Enter the isbn of the book you want to search: " << endl;
                string isbn;
                getline(cin, isbn);
                Book *b = book_database->search_by_isbn(isbn);
                if (b == nullptr)
                    cout << "Sorry, No such book exists!" << endl;
                else
                {
                    b->print_details();
                    cout << endl;
                }
            }
            else if (k == 2)
            {
                cin.ignore();
                cout << "Enter the title of the book you want to search: " << endl;
                string title;
                getline(cin, title);
                vector<Book *> res = book_database->search_by_title(title);
                if (res.size() == 0)
                {
                    cout << "No book exists with the specified title!" << endl;
                }
                else
                {
                    for (int i = 0; i < res.size(); i++)
                    {
                        res[i]->print_details();
                        cout << endl;
                    }
                }
            }

            else if (k == 3)
            {
                cin.ignore();
                cout << "Enter the author of the book you want to search: " << endl;
                string author;
                getline(cin, author);
                vector<Book *> res = book_database->search_by_author(author);
                if (res.size() == 0)
                {
                    cout << "No book exists with the specified author name!" << endl;
                }
                else
                {
                    for (int i = 0; i < res.size(); i++)
                    {
                        res[i]->print_details();
                        cout << endl;
                    }
                }
            }
            else
            {
                cout << "Invalid key entered. Operation aborted!" << endl;
            }
        }
        show_catalog(user->get_role());
        cout << "Press another key for next operation : ";
        cin >> key;
        cout << endl;
    }
}

void play_professor(BookDB *book_database, User *user)
{
    Professor *p = new Professor(user->get_name(), user->get_id(), user->get_password(), user->get_username());
    show_catalog(user->get_role());
    cout << "Press a key from 1-6 according to the catalog: " << endl;
    int key;
    cin >> key;
    while (key != 6)
    {
        if (key == 1)
        {
            book_database->show_all_books();
        }
        else if (key == 2)
        {
            p->show_issued_books();
        }
        else if (key == 3)
        {
            cout << "Enter the isbn of the book you want to issue: ";
            string isbn;
            cin >> isbn;
            Book *book_issue = book_database->search_by_isbn(isbn);
            if (book_issue == nullptr)
            {
                cout << "Sorry, the book is not available!" << endl;
            }
            else
            {
                p->issue_book(book_issue);
            }
        }
        else if(key == 4)
        {
            p->return_book();
        }
        else if (key == 5)
        {
            cout << "1 -> search by ISBN" << endl;
            cout << "2 -> search by title" << endl;
            cout << "3 -> search by author" << endl;
            int k;
            cin >> k;
            if (k == 1)
            {
                cin.ignore();
                cout << "Enter the isbn of the book you want to search: " << endl;
                string isbn;
                getline(cin, isbn);
                Book *b = book_database->search_by_isbn(isbn);
                if (b == nullptr)
                    cout << "Sorry, No such book exists!" << endl;
                else
                {
                    b->print_details();
                    cout << endl;
                }
            }
            else if (k == 2)
            {
                cin.ignore();
                cout << "Enter the title of the book you want to search: " << endl;
                string title;
                getline(cin, title);
                vector<Book *> res = book_database->search_by_title(title);
                if (res.size() == 0)
                {
                    cout << "No book exists with the specified title!" << endl;
                }
                else
                {
                    for (int i = 0; i < res.size(); i++)
                    {
                        res[i]->print_details();
                        cout << endl;
                    }
                }
            }

            else if (k == 3)
            {
                cin.ignore();
                cout << "Enter the author of the book you want to search: " << endl;
                string author;
                getline(cin, author);
                vector<Book *> res = book_database->search_by_author(author);
                if (res.size() == 0)
                {
                    cout << "No book exists with the specified author name!" << endl;
                }
                else
                {
                    for (int i = 0; i < res.size(); i++)
                    {
                        res[i]->print_details();
                        cout << endl;
                    }
                }
            }
            else
            {
                cout << "Invalid key entered. Operation aborted!" << endl;
            }
        }
        show_catalog(user->get_role());
        cout << "Press another key for next operation : ";
        cin >> key;
        cout << endl;
    }
}

void play_librarian(BookDB *book_database, UserDB *user_database, User *user)
{
    Librarian *s = new Librarian(user->get_name(), user->get_id(), user->get_password(), user->get_username());
    show_catalog(user->get_role());
    cout << "Press a key from 1-13 according to the catalog: " << endl;
    int key;
    cin >> key;
    while (key != 13)
    {
        if (key == 1)
        {
            user_database->show_all_users();
        }
        else if (key == 2)
        {
            book_database->show_all_books();
        }
        else if (key == 3)
        {
            book_database->show_book_issued_by_user();
        }
        else if (key == 4)
        {
            book_database->show_all_issued_books();
        }
        else if (key == 5)
        {
            user_database->add_user();
        }
        else if (key == 6)
        {
            string uname;
            cout << "Enter the userName of the user you want to delete: ";
            cin >> uname;
            cout << endl;
            user_database->delete_user_by_uname(uname);
        }
        else if (key == 7)
        {
            book_database->add_book();
        }
        else if (key == 8)
        {
            string isbn;
            cout << "Enter the ISBN of the book you want to delete: ";
            cin >> isbn;
            cout << endl;
            book_database->delete_book_by_isbn(isbn);
        }
        else if(key == 9)
        {
            string uname;
            cout<<"Enter the user name of the user you want to search for: ";
            cin>>uname;
            cout<<endl;
            user_database->search_by_uname(uname);
        }
        else if(key == 10)
        {
            cout<<"You can change the name, role, password for a user"<<endl;
            cout<<"Enter the id of the user you want to update: "<<endl;
            int id;
            cin>>id;
            User* u = user_database->search_by_id(id);
            if(u)
            {
                cout<<"1-> change name"<<endl;
                cout<<"2-> change role"<<endl;
                cout<<"3-> change password"<<endl;
                int k;
                cin>>k;
                if(k == 1)
                {
                    string nname;
                    cout<<"The new name should not be same as the current one!"<<endl;
                    cin.ignore();
                    cout<<"Enter new name"<<endl;
                    getline(cin, nname);
                    u->set_name(nname);
                    cout<<"The name has been updated"<<endl;
                }
                else if(k == 2)
                {
                    string nrole;
                    cout<<"The new role should not be same as the current one!"<<endl;
                    cin.ignore();
                    cout<<"Enter new role"<<endl;
                    getline(cin, nrole);
                    u->set_role(nrole);
                    cout<<"The role has been updated"<<endl;
                }
                else if(k == 3)
                {
                    string pword;
                    cout<<"The new password should not be same as the current one!"<<endl;
                    cin.ignore();
                    cout<<"Enter new password"<<endl;
                    getline(cin, pword);
                    u->set_pword(pword);
                    cout<<"The password has been updated"<<endl;
                }
                else if(key == 4)
                {
                    cout<<"Invalid key entered. Operation aborted!"<<endl;
                }
            }
        }

        else if(key == 11)
        {
            book_database->clear_book_database();
        }
        else if(key == 12)
        {
            user_database->clear_user_database();
        }
        show_catalog(user->get_role());
        cout << "Press another key for next operation : ";
        cin >> key;
        cout << endl;
    }
}

bool valid_user(UserDB *user_database, string userName, string userPassword)
{
    for (int i = 0; i < user_database->count_users; i++)
    {
        if (user_database->users[i]->get_username() == userName)
        {
            if (user_database->users[i]->get_password() == userPassword)
                return true;
            else
            {
                cout << "Password Incorrect!" << endl;
                return false;
            }
        }
    }
    cout << "No such username exists in the user_database!" << endl;
    return false;
}

User *get_user(UserDB *user_database, string userName)
{
    User *u;
    for (int i = 0; i < user_database->count_users; i++)
    {
        if (user_database->users[i]->get_username() == userName)
        {
            u = user_database->users[i];
            break;
        }
    }
    return u;
}

void play_login(UserDB *user_database, BookDB *book_database)
{
    string userName;
    string userPassword;
    int loginAttempt = 0;
    User *user;

    while (loginAttempt < 5)
    {
        cout << "Please enter your user name: ";
        cin >> userName;
        cout << "Please enter your password: ";
        cin >> userPassword;

        if (valid_user(user_database, userName, userPassword))
        {
            user = get_user(user_database, userName);
            cout << "Welcome " << userName << "! As per our user_database, you can access all the functions for the role " << user->get_role() << endl;
            break;
        }
        else
        {
            cout << "Invalid login attempt. Please try again.\n"
                 << '\n';
            loginAttempt++;
        }
    }
    if (loginAttempt == 5)
    {
        cout << "Too many login attempts! The program will now terminate.";
        return;
    }
    string role = user->get_role();
    string name = user->get_name();
    int id = user->get_id();
    if (role == "student")
    {
        play_student(book_database, user);
    }

    else if (role == "Professor" || role == "professor")
    {
        play_professor(book_database, user);
    }

    else if (role == "Librarian" || role == "librarian")
    {
        play_librarian(book_database, user_database, user);
    }
}

int main()
{

    vector<User *> initial_users;
    initialize_user_database(initial_users);
    UserDB *user_database = new UserDB(initial_users);

    vector<Book *> initial_books;
    initialize_book_database(initial_books);
    BookDB *book_database = new BookDB(initial_books);
    cout << "Welcome to the Library!. How can we help you?" << endl;
    cout << "1 ->login" << endl;
    cout << "2 -> exit" << endl;
    int key;
    cin >> key;
    if (key == 2)
    {
        cout << "Thanks for visiting the library. Hope to see you soon!" << endl;
        return 0;
    }
    while (key != 2)
    {
        play_login(user_database, book_database);
        cout << "Welcome to the Library!. How can we help you?" << endl;
        cout << "1 ->login" << endl;
        cout << "2 -> exit" << endl;
        cin >> key;
    }
    cout << "Thanks for visiting the library. Hope to see you soon!" << endl;
    return 0;
}