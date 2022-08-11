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

void printNoteNames(const map<string,string>& map) {
    for (const auto &it : map) {
        cout << it.first << endl;
    }
}

void viewNote() {
    string note;
    cout << "Which note would you like to view: \n";
    // prints out all note names
    printNoteNames(notes);

    getline(cin, note);

    if (notes.find(note) != notes.end()) {
        cout << notes.find(note)->second << endl;
    }

    else {
        cout << "Note not found\n";
    }
}

void deleteNote() {
    printNoteNames(notes);
    cout << "Which note would you like to delete: \n";
    string noteName = getStringInput();

    if (notes.find(noteName) != notes.end()) {
        notes.erase(noteName);
    }
    else {
        cout << "Note not found\n";
    }

}

void editNote() {
    printNoteNames(notes);
    cout << "Which note would you like to edit: \n";
    string noteName = getStringInput();

    if (notes.find(noteName) != notes.end()) {
        cout << "Enter new content for " << noteName << ": \n";
        notes[noteName] = getStringInput();
    }
    else {
        cout << "Note not found\n";
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
        printNoteNames(notes);

    }
    else if (option == 5) {
        editNote();

    }
    else if (option == 6) {
        quit = true;
        cout << "Quitting Notes App\n";
    }

    else {
        cout << "Invalid Option\n";
    }
}



int main() {
    while (!quit) {
        printOptions();
        takeInput();
    }



    return 0;
}
