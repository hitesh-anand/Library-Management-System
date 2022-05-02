#include <bits/stdc++.h>
using namespace std;

class UserDB
{
public:
    vector<User *> users;
    int count_users;
    UserDB()
    {
        this->count_users = 0;
    }

    UserDB(vector<User *> u)
    {
        this->users = u;
        this->count_users = u.size();
    }

    void add_user()
    {
        cout << "Enter the details of the user to be added." << endl;
        cin.ignore();

        cout << "Enter the name of the user: ";
        string name;
        getline(cin, name);

        cout << "Enter the user name of the user: ";
        string userName;
        getline(cin, userName);
        int unique = 0;
        while (unique == 0)
        {
            unique = 1;
            for (int i = 0; i < count_users; i++)
            {
                if (users[i]->get_username() == userName)
                {
                    unique = 0;
                    cout << users[i]->get_username() << " and " << userName << endl;
                    cout << "This username already exists. Please choose another user name: " << endl;
                    cin >> userName;
                }
            }
        }

        cout << "Enter the password of the user: ";
        string password;
        getline(cin, password);

        cout << "Enter the id of the user: ";
        int id;
        cin >> id;
        unique = 0;
        while (unique == 0)
        {
            unique = 1;
            for (int i = 0; i < count_users; i++)
            {
                if (users[i]->get_id() == id)
                {
                    unique = 0;
                    cout << "This id already exists. Please choose another id: " << endl;
                    cin >> id;
                }
            }
        }
        cout << "Enter the role of the user (S for student, P for professor, L for librarian) :";
        char ch;
        cin >> ch;
        string role;
        if (ch == 'S')
            role = "student";
        else if (ch == 'P')
            role = "professor";
        else if (ch == 'L')
            role = "librarian";
        else
        {
            cout << "Invalid role. User could not be added!" << endl;
        }


        User *u = new User(name, id, password, role, userName);
        users.push_back(u);
        this->count_users++;
    }

    int get_users_count() // returns the number of users in the user_database
    {
        return count_users;
    }

    void show_all_users()
    {
        for (int i = 0; i < this->count_users; i++)
        {
            cout << i + 1 << ". ";
            users[i]->print_details();
            cout << endl;
        }
    }

    void delete_user_by_uname(string uname)
    {
        for (int i = 0; i < this->count_users; i++)
        {
            if (this->users[i]->get_username() == uname)
            {
                users.erase(users.begin() + i);
                cout << "The user with the username " << uname << " has been deleted successfully!" << endl;
                this->count_users--;
                return;
            }
        }
        cout << "No such user exists. Could not complete the operation!";
    }

    User *search_by_uname(string uname)
    {
        for (int i = 0; i < count_users; i++)
        {
            if (users[i]->get_username() == uname)
            {
                users[i]->print_details();
                cout << endl;
                return users[i];
            }
        }
        cout << "Sorry, but no such user exists!" << endl;
        return nullptr;
    }

    User *search_by_id(int id)
    {
        for (int i = 0; i < count_users; i++)
        {
            if (users[i]->get_id() == id)
            {
                users[i]->print_details();
                cout << endl;
                return users[i];
            }
        }
        cout << "Sorry, but no such user exists!" << endl;
        return nullptr;
    }

    void clear_user_database()
    {
        cout << "You cannot undo this operation. Type Y/y if you still want to continue" << endl;
        char t;
        cin >> t;
        if (t == 'Y' || t == 'y')
        {
            users.clear();
            cout << "user database cleared successfully!" << endl;
            this->count_users = 0;
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
};