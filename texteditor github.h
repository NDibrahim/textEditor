//
// Created by DELL on 5/14/2022.
//

#ifndef TEXTEDITOR_TEXTEDITOR_HEADERS_H
#define TEXTEDITOR_TEXTEDITOR_HEADERS_H

#include<bits/stdc++.h>
using namespace std;





void add_content(char name[81])
{

}

void display(char name[81])
{

}


void clearall(char name[81])
{

}

void encrypt(char name[81])
{

}

void decrypt(char name[81])
{

}

void merge_files()
{
    fstream inputFile1, inputFile2;
    char name1[81], name2[81];

    cout << "Please, Enter your first file name: ";
    while (true)
    {
        cin >> name1;
        inputFile1.open(name1, ios::in);
        if (inputFile1.fail())
        {
            cout << "File open error!" << endl;
            cout << "Please, Enter correct file name: ";
            cin >> name1;
        }
        else
        {
            cout << "File opened successful.\n";
            cout << "Now reading information.\n";
            break;
        }
    }

    cout << "Please, Enter your secound file name : ";
    while (true)
    {
        cin >> name2;
        inputFile2.open(name2, ios::in);
        if (inputFile2.fail())
        {
            cout << "File open error!" << endl;
            cout << "Please, Enter correct file name: ";
            cin >> name2;
        }
        else
        {
            cout << "File opened successful.\n";
            cout << "Now reading information.\n";
            break;
        }
    }

    while (!inputFile1.eof())
    {
        inputFile1.getline(name1, 256, '\n');
        cout << name1 << endl;
    }

    inputFile1.close();

    while (!inputFile2.eof())
    {
        inputFile2.getline(name2, 256, '\n');
        cout << name2 << endl;
    }
    inputFile2.close();
}

void count_words(char name[81])
{
    int k = 0;
    ifstream inputFile;
    string word;

    cout << "Please, Enter your file name: ";
    while (true)
    {
        cin >> name;
        inputFile.open(name, ios::in);
        if (inputFile.fail())
        {
            cout << "File open error!" << endl;
            cout << "Please, Enter correct file name: ";
            cin >> name;
        }
        else
        {
            cout << "File opened successful.\n";
            cout << "Now reading information.\n";
            break;
        }
    }

    while (!inputFile.eof())
    {
        inputFile >> word;
        k++;
    }
    cout << "Number of words = " << k;
    inputFile.close();
}

void count_chars(char name[81])
{
    int k = 0;
    ifstream inputFile;
    char ch;

    cout << "Please, Enter your file name: ";
    while (true)
    {
        cin >> name;
        inputFile.open(name, ios::in);
        if (inputFile.fail())
        {
            cout << "File open error!" << endl;
            cout << "Please, Enter correct file name: ";
            cin >> name;
        }
        else
        {
            cout << "File opened successful.\n";
            cout << "Now reading information.\n";
            break;
        }
    }

    while (!inputFile.eof())
    {
        inputFile >> ch;
        if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
        k++;
    }
    k -= 1;
    cout << "Number of letters = " << k;
    inputFile.close();
}

void count_lines(char name[81])
{
    int k = 0;
    ifstream inputFile;
    string line;

    cout << "Please, Enter your file name: ";
    while (true)
    {
        cin >> name;
        inputFile.open(name, ios::in);
        if (inputFile.fail())
        {
            cout << "File open error!" << endl;
            cout << "Please, Enter correct file name: ";
            cin >> name;
        }
        else
        {
            cout << "File opened successful.\n";
            cout << "Now reading information.\n";
            break;
        }
    }

    while (!inputFile.eof())
    {
        getline(inputFile, line);
        k++;
    }
    cout << "Number of lines = " << k;
    inputFile.close();
}

void search_for_word(char name[81])
{
    ifstream inputFile;
    string word, temp;
    char ser;
    bool isFound = 0;

    cout << "Please, Enter your file name: ";
    while (true)
    {
        cin >> name;
        inputFile.open(name, ios::in);
        if (inputFile.fail())
        {
            cout << "File open error!" << endl;
            cout << "Please, Enter correct file name: ";
            cin >> name;
        }
        else
        {
            cout << "File opened successful.\n";
            cout << "Now reading information.\n";
            break;
        }
    }

    cout << "Please, Enter the word you want to search for: ";
    cin >> word;

    while (getline(inputFile, temp))
    {
        if (temp.find(word) != string::npos)
        {
            isFound = 1;
        }
        else if (temp.find(word) != string::npos)
        {
            isFound = 0;
        }
    }

    if (isFound == 1)
    {
        cout << "Word was found in the file";
    }
    else if (isFound == 0)
    {
        cout << "Word was not found in the file";
    }

    inputFile.close();
}



void count(char name[81]) {
    char  word[81] = "";
    int sum = 0;
    string content;
    vector<char> text;
    fstream file;


    file.open(name, ios::in);


    while (!file.eof()) {
        getline(file , content);

    }
    for(int i=0; i<content.size(); i++){
        content[i]= tolower(content[i]);
        word[i]= tolower(word[i]);
    }

    istringstream textnew(content);
    while(textnew){
        string sub;
        textnew >> (sub);
        if (sub == word)
            sum++;

    }
    cout<<"The word you searched for was found "<< sum << "  times in the file\n";

}




void convertToUpper(char name[81]){
    char ch;
    vector<char> text;
    fstream outFile;
    outFile.open(name , ios:: in);


    while(!outFile.eof()){
        outFile.get(ch);

        text.push_back((ch));
    }
    outFile.close();
    outFile.open(name ,  ios:: out);
    outFile.clear();

    for (int i=0; i< text.size()-1; i++){
        if(isalpha(text[i]))
            text[i] =toupper(text[i]);
        outFile.put(text[i]);


    }

    outFile.close();

}


void convertToLower(char name[81]){
    char ch;
    vector<char> text;
    fstream outFile;
    outFile.open(name , ios:: in);


    while(!outFile.eof()){
        outFile.get(ch);

        text.push_back((ch));
    }
    outFile.close();
    outFile.open(name ,  ios:: out);
    outFile.clear();

    for (int i=0; i< text.size()-1; i++){
        if(isalpha(text[i]))
            text[i] =tolower(text[i]);
        outFile.put(text[i]);


    }

    outFile.close();

}




void firstCharConvert(char name[81]){
    char ch;
    vector<char> text;
    fstream file;
    file.open(name , ios:: in);


    while(!file.eof()){
        file.get(ch);
        text.push_back(tolower(ch));
    }file.close();
    file.open(name ,ios:: out);
    file.clear();
    for(int i=0 ; i<text.size()-1; i++) {

        text[0] = toupper(text[0]);
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '.' || text[i] == '!' || text[i] == '?') {
            if(isalpha(text[i+1])) {
                text[i + 1] = toupper(text[i + 1]);

            }
        }

        file<< text[i];
    }
    file.close();

}


void savefile(char name[81]){

    fstream file; fstream newfile;
    char newName[81] , ch;
    int input;      string content;
    file.open(name, ios::in);


    cout<<"1- save in the same file\n"
          "2- save in a new file\n";
    cin >> input;
    if(input == 2){
        cout<<"what is the new filename\n";
        cin>>newName;
        newfile.open(newName, ios:: out);
        while(!file.eof()){
            file.get(ch);
            newfile<<ch;
        }

    }
    else{exit ;}
    file.close();
    newfile.close();
}






#endif //TEXTEDITOR_TEXTEDITOR_HEADERS_H

