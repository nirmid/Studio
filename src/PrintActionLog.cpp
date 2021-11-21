#ifndef PRINTACTIONLOG_CPP_
#define PRINTACTIONLOG_CPP_
#include <../include/Action.h>
#include <../include/Studio.h>
#include <string>
#include <iostream>
using namespace std;
PrintActionsLog::PrintActionsLog() {}
void PrintActionsLog::act(Studio &studio) {
    const vector<string>& input =studio.getinputLog();
    const vector <BaseAction*>& actions = studio.getActionsLog();
    for(int i=0;i<input.size();i=i+1){
        cout << input[i];
        if(actions[i]->getStatus() == ERROR)
            cout << actions[i]->toString();
        cout << "/n";
    }
}

#endif