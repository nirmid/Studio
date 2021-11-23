#ifndef PRINTACTIONLOG_CPP_
#define PRINTACTIONLOG_CPP_
#include <../include/Action.h>
#include <../include/Studio.h>
#include <string>
#include <iostream>
using namespace std;
PrintActionsLog::PrintActionsLog() {}
PrintActionsLog::PrintActionsLog(PrintActionsLog &other) {
    complete();
}
void PrintActionsLog::act(Studio &studio) {
    const vector <BaseAction*>& actions = studio.getActionsLog();
    for(int i=0; i<actions.size();i=i+1){
        cout << actions[i]->toString() << endl;
    }
}

std::string PrintActionsLog::toString() const {
    string output = string("log COMPLETE");
    return output;

}

#endif