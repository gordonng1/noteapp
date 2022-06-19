//
// Created by Gordon Ng on 6/19/22.
//

#ifndef NOTEAPP_NOTE_H
#define NOTEAPP_NOTE_H
#include <string>
#include <iostream>

class Note {
private:
    std::string name;
    std::string content;

public:
    Note();

    // names the note
    void setName(std::string nameIn);

    // gets the name of the note
    std::string getName();

    // writes content to the note
    void setContent(std::string contentIn);

    // returns content of the note
    std::string getContent();


};



#endif //NOTEAPP_NOTE_H
