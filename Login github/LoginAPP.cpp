#include"loginfunctions.h"
using namespace std;



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

 }

file.close();

return 0;
}
string userfullname(Profile newUser){


    cout << "Enter your full name : ";
    getline(cin , newUser.name) ;
    regex n("([a-zA-Z]+[-]?[ ]?[a-zA-Z]+)");

         if (regex_match(newUser.name.begin(), newUser.name.end(), n) ){
        cout << "Hello " << newUser.name << "\n" ;

            file << newUser.name << "\n" ;

    }
    else {
        cout << "Wrong name please try again \n" << "restart your program \n" ;
        getline(cin , newUser.name);
    }
    cout << endl ;
    return newUser.name;


}
string userage(Profile newUser){
    cout<<"Enter your age: ";
    cin>>newUser.age;
    regex a("([0-9]+)");
    while(true){
        if(regex_match(newUser.age.begin(),newUser.age.end(),a)){
            cout<<"Valid age \n";
            file << newUser.age << "\n" ;
            break;
        }
        else{
            cout<<"Wrong age ,try again and enter only numbers \n";
            cout<<"Enter your age: \n";
            cin>>newUser.age;
        }
    }


   return newUser.age;
}
string usergender(Profile newUser){
    cout<<"\nEnter your gender(Male or Female): ";
    cin>>newUser.gender;
    regex g("([male]*[female]*)");
    while(true){
        if(regex_match(newUser.gender.begin(),newUser.gender.end(),g)){
            cout<<"Valid gender \n";
            file<<newUser.gender<<"\n";
            break;
        }
        else{
            cout<<"Wrong gender,try again and enter only male or female \n";
            cout<<"Enter your gender: ";
            cin>>newUser.gender;
        }
    }
    return newUser.gender;
}
string usercountry(Profile newUser){
    cout<<"\nEnter your country: ";
    cin>>newUser.country;
    regex c("([a-zA-Z]+)");
    while(true){
        if(regex_match(newUser.country.begin(),newUser.country.end(),c)){
            cout<<"Valid country \n";
            file<<newUser.country<<"\n" ;
            break;
        }
        else{
            cout<<"wrong country, try again \n";
            cout<<"Enter your country: ";
            cin>>newUser.country;
        }
    }
    return newUser.country;
}
string user_mobilenumber(Profile newUser){
    cout<<"\nyour mobile number should be like(01*********): "<<"\n"<<"Enter your mobile number>> ";
    cin>>newUser.mobilenumber;
    regex m("([01]{2}[0-9]{9})");
    while(true){
        if(regex_match(newUser.mobilenumber.begin(),newUser.mobilenumber.end(),m)){
            cout<<"valid mobile number \n";
            file<<newUser.mobilenumber<<"\n";
            break;
        }
        else{
            cout<<"invalid mobile number, please try again"<<"\n"<<"enter your mobile number like:01*********";
            cin>>newUser.mobilenumber;
        }
    }

    return newUser.mobilenumber;
}
string check_email(Profile newUser){
    char character;
    //fstream file;
    string word;
    //cin>>newUser.email;
    file.open("test1.txt" ,ios::in);
    while (!file.eof())
    {
        //cout<<email<<"\n";
        file.get(character);
        if(character=='\n'||file.eof())
        {
           if(word==newUser.email)
           {
            cout<<"you have registered this email before";
            break;
           }
           word.clear();
        }
        else
        {
            word+=character;

        }

    }
}
string useremail(Profile newUser){

    cout<<"\nYour email should be like:example@gmail.com"<<"\n"<<"Enter your email: ";
    cin>>newUser.email;

    regex e("[[:w:]]+@[[:w:]]+.com");
    while(true){
        if(regex_match(newUser.email.begin(),newUser.email.end(),e)){
            cout<<"Valid email"<<"\n";

            file<<newUser.email<<"\n";

            break;
        }
        else{
            cout<<"\nInvalid email"<<"\n"<<"Your email should be like:example@gmail.com"<<"\n";
            cout<<"Enter your email: ";
            cin>>newUser.email;
        }
    }

    return newUser.email;
}

string userid(Profile newUser){
    cout<<"Enter your ID: ";
    cin>>newUser.id;
    regex i("([0-9]+)");
    while(true){
        if(regex_match(newUser.id.begin(),newUser.id.end(),i)){
            cout<<"Valid ID \n";
            file << newUser.id << "\n" ;
            break;
        }
        else{
            cout<<"Wrong id ,try again and enter only numbers \n";
            cout<<"Enter your id: \n";
            cin>>newUser.id;
        }
    }


   return newUser.id;
}
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



