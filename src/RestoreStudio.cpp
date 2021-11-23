#ifndef RESTORESTUDIO_CPP_
#define RESTORESTUDIO_CPP_
#include <../include/Action.h>
#include <../include/Studio.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
RestoreStudio::RestoreStudio() {}

RestoreStudio::RestoreStudio(RestoreStudio &other) {
    if(other.getStatus() == ERROR)
        this->error(other.getErrorMsg());
    else
        this->complete();
}

void RestoreStudio::act(Studio &studio) {
    if(backup == nullptr) {
        this->error("No backup available");
    }
    else
        studio = *backup;

}


std::string BackupStudio::toString() const {}

#endif

