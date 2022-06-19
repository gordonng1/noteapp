//
// Created by Gordon Ng on 6/19/22.
//

#include "Note.h"

#include <utility>

Note::Note() {
    name = "";
    content = "";
}

void Note::setName(std::string nameIn) {
    name = std::move(nameIn);
}

std::string Note::getName() {
    return name;
}

void Note::setContent(std::string contentIn) {
    content = std::move(contentIn);
}

std::string Note::getContent() {
    return content;
}