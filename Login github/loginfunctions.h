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
void operator<<(ostream &out, users temp);
void operator<<(ostream &out , vector<char> coded);
vector<users>  read(string name);
void write_encrypted_pass(string name, vector<users> uservector);
string cipher(string message);
string decipher( string message);
void encryption();
bool take_password(vector<users> uservector , int l);
bool take_id(vector<users> uservector);
void login_system();
users change_password();
#endif // LOGINFUNCTIONS_H_INCLUDED
