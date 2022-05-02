#include <bits/stdc++.h>
using namespace std;

class Librarian : public User
{

public:
    Librarian(string name, int id, string password, string userName)
    {
        this->name = name;
        this->id = id;
        this->password = password;
        this->role = "librarian";
        this->userName = userName;
    }
};