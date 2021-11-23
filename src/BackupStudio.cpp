
#ifndef BACKUPSTUDIO_CPP_
#define BACKUPSTUDIO_CPP_
#include <../include/Action.h>
#include <../include/Studio.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
extern Studio* backup;
BackupStudio ::BackupStudio() {}

void BackupStudio::act(Studio &studio) {
    backup = &studio;
    this->complete();
}

std::string BackupStudio::toString() const {return string("backup COMPLETE");}

















#endif