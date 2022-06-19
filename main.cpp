#include <iostream>
#include "Note.h"
using namespace std;

void printOptions() {
    cout << "Options Menu\n";
    cout << "1. Create New Note\n";
    cout << "2. View Existing Note\n";
    cout << "3. Delete Note\n";
    cout << "4. View List of All Notes\n";
    cout << "5. Edit Existing Note\n";
    cout << "6. Quit Program\n\n";
}

void promptNoteName(string &nameIn) {
    cout << "Name of New Note: \n";
    cin >> nameIn;
}

void promptNoteContent(string &contentIn) {
    cout << "Content of Note: \n";
    cin >> contentIn;
}

void takeInput() {
    int option;
    cout << "Enter Option: \n";
    cin >> option;

    if (option == 1) {
        Note n;
        string nameIn;
        string contentIn;
        promptNoteName(nameIn);
        promptNoteContent(contentIn);
        n.setName(nameIn);
        n.setContent(contentIn);
    }
    else if (option == 2) {

    }
    else if (option == 3) {

    }
    else if (option == 4) {

    }
    else if (option == 5) {

    }
    else if (option == 6) {

    }
    else {
        cout << "Invalid Option";
    }
}



int main() {
    printOptions();
    Note n1;

    cout << n1.getName() << endl;
    cout << n1.getContent() << endl;

    n1.setName("note 1");
    n1.setContent("this is note 1");

    cout << n1.getName() << endl;
    cout << n1.getContent() << endl;

    return 0;
}
