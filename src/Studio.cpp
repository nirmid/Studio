//
// Created by nir on 16/11/2021.
//
#ifndef STUDIO_CPP_
#define STUDIO_CPP_
using namespace std;

#include "../include/Studio.h"
#include <vector>
#include <string>
#include <sstream>

Studio::Studio(){}
Studio::Studio(const string &configFilePath){}
enum string_action{
    open,order,emove,close,closeAll,workout_options,status,log,backup,restore
};
enum string_type {
    swt,chp,mcl,fbd
};
string_action hashit(string const& s){
    if(s == "open") return open;
    if(s == "order") return order;
    if(s == "move") return emove;
    if(s == "close") return close;
    if(s == "closeAll") return closeAll;
    if(s == "workout_options") return workout_options;
    if(s == "status") return status;
    if(s == "log") return log;
    if(s == "backup") return backup;
    if(s == "restore") return restore;

}
string_type hashType(string const& s) {
    if (s == "swt") return swt;
    if (s == "chp") return chp;
    if (s == "mcl") return mcl;
    if (s == "fbd") return fbd;
}


void Studio::start() {
    open = true;
    int idCount = 0;
    cout << "Studio is now open!" << endl;
    string input,action;
    while(open){
        getline(cin,input);
        istringstream ss(input);
        ss>>action;
        switch(hashit(action)){
            case string_action::open: {
                string trainer, name, type, arg1;
                vector < Customer * > costumers;
                ss >> trainer >> arg1;
                istringstream iss(arg1);
                while (iss.good()) {
                    getline(iss, name, ',');
                    getline(iss, type, ',');
                    switch (hashType(type)) {
                        case swt:
                            costumers.push_back(new SweatyCustomer(name, idCount));
                            idCount = idCount + 1;
                            break;
                        case chp:
                            costumers.push_back(new CheapCustomer(name, idCount));
                            idCount = idCount + 1;
                            break;
                        case mcl:
                            costumers.push_back(new HeavyMuscleCustomer(name, idCount));
                            idCount = idCount + 1;
                            break;
                        case fbd:
                            costumers.push_back(new FullBodyCustomer(name, idCount));
                            idCount = idCount + 1;
                            break;
                    }
                }

                // need to open object of openTrainer
                break;
            }
            case string_action::order: {
                int trainerId=-1;
                ss>>trainerId;
                // creating object of order
                break;
                }
            case string_action::emove:{
                int src,dst,costumerId;
                ss>>src>>dst>>costumerId;
                // creating object of move action
                break;
            }
            case string_action::close:{
                int trainerId;
                ss>>trainerId;
                // creating object of close action
                break;
            }
            case string_action::closeAll:{
                //creating object of closeAll action
                open= false;
                break;
            }
            case string_action::workout_options:{
                //creating object of action
                break;
            }
            case string_action::status:{
                int trainerId;
                ss>>trainerId;
                //creating object of printTrainerStatus
                break;
            }
            case string_action::log:{

            }


        }

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