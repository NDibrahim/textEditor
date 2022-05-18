
#include "TextEditorFunc.h"
using namespace std;


void open_create_file();
void add_newtext();
void displaydata();
void Emptydata();
void encrypt();
void decrypt();
void merge_files();
void count_words(char filename[81]);
void count_chars(char filename[81]);
void count_lines(char filename[81]);
void search_for_word(char filename[81]);
void convertToUpper(char filename[81]);
void convertToLower(char filename[81]);
void firstCharConvert(char filename[81]);
void savefile(char filename[81]);
void count(char filename[81]);
fstream file;
    char filename[81];
int main(){
int choice;

    //The file that user enter
	cout << "Pls input an existing file name: ";
	cin.getline(filename, 100);
	//To open text file
	strcat(filename,".txt");
	//Open the file if exist and create new file if the file is not exist
	open_create_file();

        while (true) {  // user choose which one he/she needs to do
            cout << "\n1. Add new text to the end of the file\n"
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
                add_newtext();
            else if (choice == 2)
                displaydata();
            else if (choice == 3)
                Emptydata();
            else if (choice == 4)
                encrypt();
            else if (choice == 5)
                decrypt();
            else if (choice == 6)
                merge_files();
            else if (choice == 7)
                count_words(filename);
            else if (choice == 8)
                count_chars(filename);
            else if (choice == 9)
                count_lines(filename);
            else if (choice == 10)
                search_for_word(filename);
            else if (choice == 11)
                count(filename);
            else if (choice == 12)
                convertToUpper(filename);
            else if (choice == 13)
                convertToLower(filename);
            else if (choice == 14)
                firstCharConvert(filename);
            else if (choice == 15)
                savefile(filename);
            else if (choice == 16)
                break;

        }

    }




void open_create_file(){

    file.open(filename, ios::in);
	if (file.fail())
    {
        ofstream file(filename);
        cout<<"file could not be opened \n";
        cout<<"This is a new file. I created it for you \n";
    }
    else
    {
        cout << "File opened successful.\n";
        cout<<"This File Already exists. \n";
        file.close();
    }
}
void add_newtext(){ // adding new text to the file without remove the main content.

    string add;

    file.open(filename, ios_base::app); // append instead of overwrite
    cout<<"enter text u want to add to file:";

    cin.ignore();
    getline(cin, add);
    file<<" "<<add;

    file.close();
}
void displaydata(){ // display all data in file

    string ch;
    file.open(filename, ios::in);
    if(file){

        cout<<file.rdbuf();
    }

}
void Emptydata(){ // remove all data in file


 file.open(filename, ios::out | ios::trunc);
 file.close();


}
// Definition of encryption function
void encrypt(){

   char character;
    string word;
    //open file and read it to the end.
    file.open(filename, ios::in);
    while(!file.eof())
    {

        file.get(character);

        if (character=='32')
        {
            continue;
        }

        word += character + 1 ;



    }
    word.pop_back();
    file.close();
    file.open(filename, ios::out);
    //save the word in file.
    file<<word;
    file.close();
}
void decrypt(){

   char character;
    string word;
    //open file and read it to the end.
    file.open(filename, ios::in);
    while(!file.eof())
    {

        file.get(character);

        if (character=='32')
        {
            continue;
        }

        word += character - 1 ;

    }
    word.pop_back();
    file.close();
    file.open(filename, ios::out);
    //save the word in file.
    file<<word;
    file.close();
}
void merge_files()  // read to files at same time
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

void count_words(char filename[81]) // count the words that in the file
{
    int k = 0;
    ifstream inputFile;
    string word;

    cout << "Please, Enter your file name: ";
    while (true)
    {
        cin >> filename;
        inputFile.open(filename, ios::in);
        if (inputFile.fail())
        {
            cout << "File open error!" << endl;
            cout << "Please, Enter correct file name: ";
            cin >> filename;
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

void count_chars(char filename[81]) // count the characters in file
{
    int k = 0;
    ifstream inputFile;
    char ch;

    cout << "Please, Enter your file name: ";
    while (true)
    {
        cin >> filename;
        inputFile.open(filename, ios::in);
        if (inputFile.fail())
        {
            cout << "File open error!" << endl;
            cout << "Please, Enter correct file name: ";
            cin >> filename;
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

void count_lines(char filename[81]) // count number of lines
{
    int k = 0;
    ifstream inputFile;
    string line;

    cout << "Please, Enter your file name: ";
    while (true)
    {
        cin >> filename;
        inputFile.open(filename, ios::in);
        if (inputFile.fail())
        {
            cout << "File open error!" << endl;
            cout << "Please, Enter correct file name: ";
            cin >> filename;
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

void search_for_word(char filename[81])
{
    ifstream inputFile;
    string word, temp;
    char ser;
    bool isFound = 0;

    cout << "Please, Enter your file name: ";
    while (true)
    {
        cin >> filename;
        inputFile.open(filename, ios::in);
        if (inputFile.fail())
        {
            cout << "File open error!" << endl;
            cout << "Please, Enter correct file name: ";
            cin >> filename;
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



void count(char filename[81]) {
    char  word[81] = "";
    int sum = 0;
    string content;
    vector<char> text;
    fstream file;


    file.open(filename, ios::in);


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




void convertToUpper(char filename[81]){ // convert each character in file to upper case
    char ch;
    vector<char> text;
    fstream outFile;
    outFile.open(filename , ios:: in);


    while(!outFile.eof()){
        outFile.get(ch);

        text.push_back((ch));
    }
    outFile.close();
    outFile.open(filename ,  ios:: out);
    outFile.clear();

    for (int i=0; i< text.size()-1; i++){
        if(isalpha(text[i]))
            text[i] =toupper(text[i]);
        outFile.put(text[i]);


    }

    outFile.close();

}


void convertToLower(char filename[81]){ // convert each character to lower case
    char ch;
    vector<char> text;
    fstream outFile;
    outFile.open(filename , ios:: in);


    while(!outFile.eof()){
        outFile.get(ch);

        text.push_back((ch));
    }
    outFile.close();
    outFile.open(filename ,  ios:: out);
    outFile.clear();

    for (int i=0; i< text.size()-1; i++){
        if(isalpha(text[i]))
            text[i] =tolower(text[i]);
        outFile.put(text[i]);


    }

    outFile.close();

}




void firstCharConvert(char filename[81]){ // convert the first character
    char ch;
    vector<char> text;
    fstream file;
    file.open(filename , ios:: in);


    while(!file.eof()){
        file.get(ch);
        text.push_back(tolower(ch));
    }file.close();
    file.open(filename ,ios:: out);
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


void savefile(char filename[81]){

    fstream file; fstream newfile;
    char newName[81] , ch;
    int input;      string content;
    file.open(filename, ios::in);


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



