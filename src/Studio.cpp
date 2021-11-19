//
// Created by nir on 16/11/2021.
//
#ifndef STUDIO_CPP_
#define STUDIO_CPP_
using namespace std;

#include "../include/Studio.h"
#include <vector>
Studio::Studio(){}
Studio::Studio(const string &configFilePath){}
void Studio::start() {
    open = true;
    cout << "Studio is now open!" << endl;
    string input;
    while(open){
        getline(cin,input);
        istringstream ss(input);

    }
}
int Studio::getNumOfTrainers() const {
    return trainers.size();
}
Trainer *Studio::getTrainer(int tid) {
    if(tid>=0 && tid<trainers.size())
        return trainers[tid];
}
std::vector<Workout> &Studio::getWorkoutOptions() {}
const vector<BaseAction *> &Studio::getActionsLog() const {}
Studio::~Studio() {
    for(int i=0;i<trainers.size();i=i+1)
        delete trainers[i];
    for(int i=0;i<actionsLog.size();i=i+1)
        delete actionsLog[i];
    workout_options.clear();
}
void Studio::insertActionLog(BaseAction *baseAction) {
    actionsLog.push_back(baseAction);
}
Studio::Studio(const Studio&& other):trainers(move(other.trainers)),workout_options(move(other.workout_options)),actionsLog(move(other.actionsLog)) {}


#endif