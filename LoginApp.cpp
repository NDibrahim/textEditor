#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <cstring>
#include <regex>
#include <conio.h>

using namespace std;

void conditions_message()
{
    cout << "Please, Enter a password with [12-20] character contans capital letter, small letter, numbers and special character:\n";
}


      // Function that accepts the password
std::string takePasswdAgainFromUser(string enpass)
{
    // Stores the password;
    char sp = '*';
    char ch;
    // Until condition is true
    while (true)
    {

        ch = getch();
        // if the ch_ipt
        if (ch == 13)
        {
            cout << endl;
            return enpass;
        }
        else if (ch == 8 && enpass.length() != 0)
        {
            enpass.pop_back();

            // Cout statement is very
            // important as it will erase
            // previously printed character
            cout << "\b \b";

            continue;
        }

        // Without using this, program
        // will crash as \b can't be
        // print in beginning of line
        else if (ch == 8 && enpass.length() == 0)
        {
            continue;
        }

        enpass.push_back(ch);
        cout << sp;
    }
}

void add_profile_to_system(string &pass)
{
    //string pass;
    fstream inputfile;

    inputfile.open("users.txt", ios::app);
    //pass = takePasswdFromUser(pass);

    inputfile << pass << endl;

    inputfile.close();
    //cout << profilepass;
}

string ensure_password(string pass, string enpass)
{
    enpass = takePasswdAgainFromUser(enpass);
    for (int i = 0; i < pass.length(); i++)
    {
        if (pass[i] == enpass[i])
        {
             cout << "Welcome!";
             break;
        }
        else
        {
            cout << "please, Enter password again:\n";
            ensure_password(pass, enpass);
        }
    }
    return pass;

}


    // Function that accepts the password
std::string takePasswdFromUser(string pass)
{
    // Stores the password;
    string profilepass;
    char ch, sp = '*';
    int i = 0;
    // Until condition is true
    while (true)
    {

        ch = getch();

        // if the ch_ipt
        if (ch == 13)
        {
            cout << endl;
            return pass;
        }
        else if (ch == 8 && pass.length() != 0)
        {
            pass.pop_back();

            // Cout statement is very
            // important as it will erase
            // previously printed character
            cout << "\b \b";

            continue;
        }

        // Without using this, program
        // will crash as \b can't be
        // print in beginning of line
        else if (ch == 8 && pass.length() == 0)
        {
            continue;
        }
        pass.push_back(ch);
        cout << sp;
    }
}



string check_strong_password(string& pass)
{
    string enpass, profilepass;
    pass = takePasswdFromUser(pass);
    int upper = 0, lower = 0, number = 0, spicialchar = 0;
    for (int i = 0; i < pass.length(); i++)
    {
        if (pass[i] >= 'A' && pass[i] <= 'Z')
            upper++;
        else if (pass[i] >= 'a' && pass[i] <= 'z')
            lower++;
        else if (pass[i] >= '0' && pass[i] <= '9')
            number++;
        else
            spicialchar++;
    }
    if (upper == 0 || lower == 0 || number == 0 || spicialchar == 0 || pass.length() < 12)
    {
        cout << "Please, Enter correct password" << endl;
        pass = check_strong_password(pass);;
    }
    cout << "Please, Ensure password:\n";
    ensure_password(pass, enpass);
    return pass;
}


int main()
{
    string pass, enpass, profilepass;
    char ch;
    conditions_message();
    pass = check_strong_password(pass);
    add_profile_to_system(pass);
    return 0;
}
