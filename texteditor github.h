//
// Created by DELL on 5/14/2022.
//

#ifndef TEXTEDITOR_TEXTEDITOR_HEADERS_H
#define TEXTEDITOR_TEXTEDITOR_HEADERS_H

#include<bits/stdc++.h>
using namespace std;





void add_content(char name[81]) {

}

void display(char name[81]){

}


void clearall(char name[81]){


}

void encrypt(char name[81]){
}
void decrypt(char name[81]){}
void merge(char name[81]){}
void count_words(char name[81]){}
void count_chars(char name[81]){}
void count_lines(char name[81]){}
void search(char name[81]){}



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

