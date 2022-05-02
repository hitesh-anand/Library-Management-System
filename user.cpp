#include <bits/stdc++.h>
using namespace std;

class User
{
protected:
    string name;
    int id;
    string password;
    string role;
    string userName;

public:
    User(string name, int id, string password, string role, string userName)
    {
        this->name = name;
        this->id = id;
        this->password = password;
        this->role = role;
        this->userName = userName;
    }

    User()
    {
        this->name = "Unknown User";
    }

    string get_name()
    {
        return this->name;
    }

    int get_id()
    {
        return this->id;
    }

    string get_password()
    {
        return this->password;
    }

    string get_role()
    {
        return this->role;
    }

    string get_username()
    {
        return this->userName;
    }

    void set_name(string nname)
    {
        if (this->name == nname)
            cout << "The name is already equal to the entered value!" << endl;
        else
            this->name = nname;
    }

    void set_role(string nrole)
    {
        if (this->role == nrole)
            cout << "The role is already equal to the entered value!" << endl;
        else
            this->role = nrole;
    }

    void set_pword(string pword)
    {
        if (this->password == pword)
            cout << "The password is already equal to the entered value!" << endl;
        else
            this->password = pword;
    }

    void print_details()
    {
        cout << "The name of the user is: " << this->name << endl;
        cout << "The username of the user is: " << this->userName << endl;
        cout << "The id of the user is: " << this->id << " and role is: " << this->role << endl;
    }
};