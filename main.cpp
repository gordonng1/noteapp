#include <iostream>
#include <map>
#include "Note.h"
#include <vector>

using namespace std;

map<string, string> notes;
vector<string> noteNames;
bool quit = false;

void printOptions() {
    cout << "Options Menu\n";
    cout << "1. Create New Note\n";
    cout << "2. View Existing Note\n";
    cout << "3. Delete Note\n";
    cout << "4. View List of All Notes\n";
    cout << "5. Edit Existing Note\n";
    cout << "6. Quit Program\n\n";
}

string getStringInput() {
    string input;
    getline(cin, input);

    while (cin.fail()) {
        cout << "BAD" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // #ignore clears the rest of the input stream
        getline(cin, input);
    }
    return input;
}

// allows user to set the name of the note
void setNoteName(string &nameIn) {
    cout << "Name of note: \n";

    //grabs input from user and then clears input stream
    nameIn = getStringInput();

    cout << "Note has been named: " << nameIn << endl;
}

// allows user to set the contents of the note
void setNoteContent(string &contentIn) {
    cout << "Enter content of note: \n";

    //grabs input from user and then clears input stream
    contentIn = getStringInput();

    cout << "Your note reads: " << contentIn << endl;
}

int getIntInput() {
    int result;
    cin >> result; // if input cant be read, cin's failbit is set, ie., cant read from stream
    while (cin.fail()) {  // if cin is errored right now
        cout << "BAD" << endl;
        cin.clear(); // #clear will unset the failbit, ie., error state unset
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // #ignore clears the rest of the input stream
        cin >> result; // try to take another input
    }

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // #ignore clears the rest of the input stream
    return result;
}
// [] input stream


// creates note
void createNewNote() {
    Note n;
    string nameIn;
    string contentIn;

    setNoteName(nameIn);
    n.setName(nameIn);

    // adds note name into notes list
    noteNames.push_back(nameIn);

    setNoteContent(contentIn);
    n.setContent(contentIn);

    // inserts note into notes map
    notes.insert(pair<string, string>(n.getName(), n.getContent()));
}

void printNoteNames() {
    for (int i = 0; i < noteNames.size(); i++) {
        cout << noteNames[i] << endl;
    }
}

void viewNote() {
    string note;
    cout << "Which note would you like to view: \n";
    // prints out all note names
    printNoteNames();

    cin.clear();
    cin.ignore(256, '\n');

    getline(cin, note);

    if (notes.find(note) != notes.end()) {
        cout << notes.find(note)->second << endl;

        cin.clear();
        cin.ignore(256, '\n');
    }

    else {
        cout << "Note not found\n";
    }
}

void deleteNote() {
    string noteName;
    cout << "insert list of all notes\n";
    cout << "Which note would you like to delete: \n";
    cin >> noteName;

    if (notes.find(noteName) != notes.end()) {
        notes.erase(noteName);
    }
}

void takeInput() {
    int option;
    cout << "Enter Option: \n";
    cin >> option;
    cin.clear();
    cin.ignore(256, '\n');

    if (option == 1) {
        createNewNote();
    }
    else if (option == 2) {
        viewNote();

    }
    else if (option == 3) {
        deleteNote();

    }
    else if (option == 4) {
        printNoteNames();

    }
    else if (option == 5) {

    }
    else if (option == 6) {
        quit = true;
        cout << "Quitting Notes App\n";
    }

    else {
        cout << "Invalid Option";
    }
}



int main() {
    while (!quit) {
        printOptions();
        takeInput();
    }



    return 0;
}
