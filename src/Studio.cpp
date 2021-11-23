
#ifndef STUDIO_CPP_
#define STUDIO_CPP_

using namespace std;
#include "../include/Studio.h"
#include <vector>
#include <string>
#include <sstream>

enum string_action{
    open,order,emove,close,closeAll,workout_options,status,log,ebackup,restore
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
    if(s == "backup") return ebackup;
    if(s == "restore") return restore;

}
string_type hashType(string const& s) {
    if (s == "swt") return swt;
    if (s == "chp") return chp;
    if (s == "mcl") return mcl;
    if (s == "fbd") return fbd;
}

Studio::Studio(){}
Studio::Studio(const string &configFilePath){
    istringstream input(configFilePath);
    string line;
    while(getline(input,line)){

    }
}
Studio::Studio(Studio &other):open(other.open),trainers(),workout_options(),actionsLog() {
    for (auto &i: other.trainers) {
        Trainer t = *i;
        this->trainers.push_back(&t);
    }
    for (auto i: other.workout_options) {
        Workout w(i);
        this->workout_options.push_back(w);
    }
    for(auto & i:other.actionsLog) {
        BaseAction& b(*i);
        actionsLog.push_back(&b);
    }

}
void Studio::start() {
    open = true;
    int idCount = 0;
    cout << "Studio is now open!" << endl;
    string input,action;
    while(open){
        getline(cin,input); // read a line
        istringstream ss(input);
        ss>>action;
        switch(hashit(action)){
            case string_action::open: {
                string  name, type, arg1;
                int trainer;
                vector < Customer* > costumers;
                ss >> trainer >> arg1;
                istringstream iss(arg1);
                while (iss.good()) {
                    getline(iss, name, ',');
                    getline(iss, type, ',');
                    switch (hashType(type)) {
                        case swt:
                            costumers.push_back(new SweatyCustomer(name,idCount));
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

                OpenTrainer* o = new OpenTrainer(trainer,costumers);
                (*o).act(*this);
                actionsLog.push_back(o);
                break;
            }
            case string_action::order: {
                int trainerId=-1;
                ss>>trainerId;
                Order* o=new Order(trainerId);
                (*o).act(*this);
                actionsLog.push_back(o);
                break;
                }
            case string_action::emove:{
                int src,dst,costumerId;
                ss>>src>>dst>>costumerId;
                MoveCustomer* m=new MoveCustomer(src,dst,costumerId);
                (*m).act(*this);
                actionsLog.push_back(m);
                break;
            }
            case string_action::close:{
                int id;
                ss>>id;
                Close* c=new Close(id);
                (*c).act(*this);
                actionsLog.push_back(c);
                break;
            }
            case string_action::closeAll:{  // might need to call studio distractor
                CloseAll* c=new CloseAll();
                (*c).act(*this);
                open= false;
                actionsLog.push_back(c);
                break;
            }
            case string_action::workout_options:{
                PrintWorkoutOptions* p= new PrintWorkoutOptions();
                (*p).act(*this);
                actionsLog.push_back(p);
                break;
            }
            case string_action::status:{
                int trainerId;
                ss>>trainerId;
                PrintTrainerStatus* p=new PrintTrainerStatus(trainerId);
                (*p).act(*this);
                actionsLog.push_back(p);
                break;
            }
            case string_action::log:{
                PrintActionsLog* p = new PrintActionsLog();
                (*p).act(*this);
                actionsLog.push_back(p);
                break;
            }
            case string_action::ebackup:{
                BackupStudio* p = new BackupStudio();
                actionsLog.push_back(p);
                (*p).act(*this);
                break;
            }
            case string_action::restore:{
                RestoreStudio* p = new RestoreStudio();
                (*p).act(*this);
                actionsLog.push_back(p);
                break;
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
    for(auto i:trainers)
        delete i;
    for(auto i:actionsLog)
        delete i;
    workout_options.clear();
}
Studio::Studio(const Studio&& other):trainers(move(other.trainers)),workout_options(move(other.workout_options)),actionsLog(move(other.actionsLog)){}
Studio& Studio::operator= (const Studio& other){
   if(this != &other){
        for(auto i:this->actionsLog)
            delete i;
        this->workout_options.clear();
        for(auto i:this->trainers)
            delete i;
        for(auto i:other.actionsLog)
            this->actionsLog.push_back(i);
        for(auto i:other.workout_options)
            this->workout_options.push_back(i);
        for(auto i:other.trainers) {
            Trainer t = *i;
            this->trainers.push_back(&t);
        }

    }
    return *this;
}

#endif

