#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string>
#include <cctype>
#include "TextEditorFunc.h"
using namespace std;

int main(){

    fstream file;
    char name[81];
    cout<<"pls enter the file name\n";
    cin>>name;
    file.open(name, ios::in);
    if (file.is_open()){
        cout<<"this file already exists\n";
    }
    else{
        cout<<"this file does not exist\n"
              "creating new file with the same name\n";
    }

    if (file.fail())
        cout << "File open error!" << endl;
    else {
        int choice;
        while (true) {
            cout << "1. Add new text to the end of the file\n"
                    "2. Display the content of the file\n"
                    "3. Empty the file\n"
                    "4. Encrypt the file content\n"
                    "5. Decrypt the file content\n"
                    "6. Merge another file\n"
                    "7. Count the number of words in the file.\n"
                    "8. Count the number of characters in the file\n"
                    "9. Count the number of lines in the file\n"
                    "10. Search for a word in the file\n"
                    "11. Count the number of times a word exists in the file\n"
                    "12. Turn the file content to upper case.\n"
                    "13. Turn the file content to lower case.\n"
                    "14. Turn file content to 1st caps (1st char of each word is capital)\n"
                    "15. Save\n"
                    "16. Exit\n";
            cin>>choice;
            if (choice == 1)
                add_content(name);
            else if (choice == 2)
                display(name);
            else if (choice == 3)
                clearall(name);
            else if (choice == 4)
                encrypt(name);
            else if (choice == 5)
                decrypt(name);
            else if (choice == 6)
                merge_files();
            else if (choice == 7)
                count_words(name);
            else if (choice == 8)
                count_chars(name);
            else if (choice == 9)
                count_lines(name);
            else if (choice == 10)
                search_for_word(name);
            else if (choice == 11)
                count(name);
            else if (choice == 12)
                convertToUpper(name);
            else if (choice == 13)
                convertToLower(name);
            else if (choice == 14)
                firstCharConvert(name);
            else if (choice == 15)
                savefile(name);
            else if (choice == 16)
                break;

        }

    }
}

