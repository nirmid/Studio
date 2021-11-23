#ifndef RESTORESTUDIO_CPP_
#define RESTORESTUDIO_CPP_
#include <../include/Action.h>
#include <../include/Studio.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
extern Studio* backup;
RestoreStudio::RestoreStudio() {}

void RestoreStudio::act(Studio &studio) {
    backup = &studio;
    this->complete();
}

std::string BackupStudio::toString() const {}

#endif

