#ifndef LOGINFUNCTIONS_H_INCLUDED
#define LOGINFUNCTIONS_H_INCLUDED
#include <conio.h>
#include <iostream>
#include<fstream>
#include<string>
#include<bits/stdc++.h>
#include <regex>
#include <cstring>

struct Profile{
    string name, gender , country , username ,  email, age , id , mobilenumber;

};

string userfullname(Profile newUser);
string userage(Profile newUser);
string usergender(Profile newUser);
string usercountry(Profile newUser);
string user_mobilenumber(Profile newUser);
string useremail(Profile newUser);
string userid(Profile newUser);
string check_email(Profile newUser);
void conditions_message();
std::string takePasswdAgainFromUser(string enpass);
void add_profile_to_system(string &pass);
string ensure_password(string pass, string enpass);
std::string takePasswdFromUser(string pass);
string check_strong_password(string& pass);
#endif // LOGINFUNCTIONS_H_INCLUDED
