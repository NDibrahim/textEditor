#include <iostream>
#include<fstream>
#include<string>
#include<bits/stdc++.h>
#include <regex>
#include <conio.h>
#include"loginfunctions.h"
using namespace std;
int main(){
string pass, enpass, profilepass;
char ch;
 Profile newUser;
vector<Profile>umail;
cout << "       <<<                        Hello                          >>>            \n" << endl ;
cout<<"         <<<              Welcome to your regestration form        >>>          \n";
file.open("test1.txt", ios_base::app);
 if (file.is_open()){
        cout<<"file is opened"<<"\n";

  userfullname(newUser) ;
  userid(newUser);
  userage(newUser);
  usergender(newUser);
  usercountry(newUser);
  useremail(newUser);
  user_mobilenumber(newUser);
  conditions_message();
  pass = check_strong_password(pass);
  add_profile_to_system(pass);
cout<<"      login      ";
login_system();
 }

file.close();

return 0;
}
