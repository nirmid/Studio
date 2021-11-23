#ifndef ACTION_CPP_
#define ACTION_CPP_
#include <../include/Action.h>
#include <../include/Trainer.h>
#include <../include/Studio.h>
#include <sstream>
#include <string>
#include <iostream>

using namespace  std;
// BaseAction
BaseAction::BaseAction() {}
ActionStatus BaseAction::getStatus() const {return status;}
void BaseAction::complete() {status = COMPLETED;}
string BaseAction::getErrorMsg() const {return errorMsg;}
void BaseAction::act(Studio &studio) {}
void BaseAction::error(std::string errorMsg){
    status = ERROR;
    this->errorMsg = errorMsg;
}
std::string BaseAction::toString() const {}

// OpenTrainer
OpenTrainer::OpenTrainer(int id, std::vector<Customer *> &customersList): trainerId(id)  {
    customers = customersList;
}
OpenTrainer::OpenTrainer(OpenTrainer &other): trainerId(other.trainerId) {
    for (auto & i:this->customers ){
        Customer& temp(*i);
        customers.push_back(&temp);
    }
}

void OpenTrainer::act(Studio &studio) {
    if( studio.getTrainer(trainerId) != nullptr && studio.getTrainer(trainerId)->isOpen() ){
        Trainer* t=studio.getTrainer(trainerId);
        int i=0;
        while(i<t->getCapacity() && i<customers.size()){
            t->addCustomer(customers[i]);
            i=i+1;
        }
    }
    else {
        BaseAction::error("Workout session does not exist or is already open");
        cout << getErrorMsg();
    }
}

std::string OpenTrainer::toString() const {
    stringstream ss;
    ss<<trainerId;
    string output = string("open")+string(" ")+ss.str()+string(" ");
    for(int i=0; i<customers.size();i=i+1){
        Customer& c = *customers[i];
        output = output+c.toString()+string(" ");
    }
    if(this->getStatus()==ERROR)
        output = output+string("Error: Trainer does not exist or is already open");
    else
        output=output+string("COMPLETE");
    return output;


}
// Order
Order :: Order(int id): trainerId(id)  {}
Order ::Order(Order &other): trainerId(other.trainerId) {
    if (other.getStatus() == COMPLETED)
        complete();
    else
        error(other.getErrorMsg());
}

void Order :: act (Studio& studio) {
    if (trainerId > studio.getNumOfTrainers() | !(studio.getTrainer(trainerId))->isOpen()) {
        error("Trainer does not exist or is not open");
        cout << "Trainer does not exist or is not open" << endl;
    }
    else{
        Trainer *cur = studio.getTrainer(trainerId);
        for(auto i = ((*cur).getCustomers()).begin() ; i != ((*cur).getCustomers()).end(); i++){
            (*cur).order((*i)->getId(), (*i)->order(studio.getWorkoutOptions()), studio.getWorkoutOptions());
        }
    }
}

std::string Order::toString() const {
    stringstream ss;
    ss<<trainerId;
    string output = "order " + ss.str()+string(" ");
    if(this->getStatus()== ERROR)
        output = output+string("Error:Trainer does not exist or not open");
    else
        output = output+string("COMPLETED");
    return output;

}
// MoveCustomer
MoveCustomer::MoveCustomer(int src, int dst, int customerId):srcTrainer(src),dstTrainer(dst), id(customerId) {}
MoveCustomer::MoveCustomer(MoveCustomer &other): srcTrainer(other.srcTrainer), dstTrainer(other.dstTrainer), id(other.id) {
    if (other.getStatus() == COMPLETED)
        complete();
    else
        error(other.getErrorMsg());
}
void MoveCustomer::act(Studio &studio) {
    if(studio.getTrainer(srcTrainer)!= nullptr && studio.getTrainer(dstTrainer)!= nullptr && studio.getTrainer(srcTrainer)->getCustomer(id)!=
                                                                                             nullptr && studio.getTrainer(dstTrainer)->getCapacity()>studio.getTrainer(dstTrainer)->getCustomers().size()){
        Trainer* src = studio.getTrainer(srcTrainer);
        Trainer* dst = studio.getTrainer(dstTrainer);
        Customer* c = src->getCustomer(id);
        src->removeCustomer(id);
        dst->addCustomer(c);
        dst->order(id,c->order(studio.getWorkoutOptions()),studio.getWorkoutOptions());
        if(src->getCustomers().size()==0)  // if source trainer is empty, then close
            Close close(srcTrainer); // activating Close class/action

    }
    else {
        error("Cannot move customer");
        cout << "Cannot move customer" << endl;    }
}

std::string MoveCustomer::toString() const {
    stringstream s,d,c;
    s<<srcTrainer;
    d<<dstTrainer;
    c<<id;
    string output = string("move ")+s.str()+string(" ")+d.str()+string(" ")+c.str()+string(" ");
    if(this->getStatus()==ERROR)
        output = output + string("Error:Cannot move customer");
    else
        output=output+string("COMPLETED");
    return output;
}
//Close
Close::Close(int id): trainerId(id) {}
Close::Close(Close &other): trainerId(other.trainerId) {
    if (other.getStatus() == COMPLETED)
        complete();
    else
        error(other.getErrorMsg());
}
void Close::act(Studio &studio) {
    if(studio.getTrainer(trainerId)!= nullptr && studio.getTrainer(trainerId)->isOpen()){
        Trainer* t=studio.getTrainer(trainerId);
        t->closeTrainer(); // close at trainer class should remove all customers from customer's vector
        cout << "Trainer " << trainerId << " closed. salary " << t->getSalary() << "NIS" << endl;
    }
    else {
        error("Trainer does not exist or is not open");
        cout << "Trainer does not exist or is not open" << endl;
    }
}

std::string Close::toString() const {
    stringstream ss;
    ss << trainerId;
    string output = string("close ") + ss.str() + string(" ");
    if (this->getStatus() == ERROR)
        output = output + string("Trainer does not exist or is not open");
    else
        output = output + string("COMPLETE");
    return output;

}
//CloseAll
CloseAll::CloseAll() {}
CloseAll::CloseAll(CloseAll &other)  {
    if (other.getStatus() == COMPLETED)
        complete();
    else
        error(other.getErrorMsg());
}

void CloseAll::act(Studio &studio) {
    for(int i=0;i<studio.getNumOfTrainers();i=i+1){
        Close c(i);
        c.act(studio);
    }
}

std::string CloseAll::toString() const {return string("closeall COMPLETE");}

// PrintWorkoutOptions
PrintWorkoutOptions :: PrintWorkoutOptions(){}
PrintWorkoutOptions ::PrintWorkoutOptions(PrintWorkoutOptions &other) {
    complete();
}
void PrintWorkoutOptions:: act(Studio& studio){
    for ( auto i = (studio.getWorkoutOptions()).begin(); i != (studio.getWorkoutOptions()).end(); i++){
        if((*i).getType() == 0)
            cout << (*i).getName() << ", " << "ANAEROBIC, " << (*i).getPrice() << "/n" ;
        if((*i).getType() == 1)
            cout << (*i).getName() << ", " << "MIXED, " << (*i).getPrice() << "/n" ;
        if((*i).getType() == 2)
            cout << (*i).getName() << ", " << "CARDIO, " << (*i).getPrice() << "/n" ;
    }
}

std::string PrintWorkoutOptions::toString() const {return string("workout_options COMPLETE");}

//PrintTrainerStatus
PrintTrainerStatus :: PrintTrainerStatus(int id): trainerId(id) {}
PrintTrainerStatus ::PrintTrainerStatus(PrintTrainerStatus &other): trainerId(other.trainerId){
    complete();
}
void PrintTrainerStatus:: act(Studio& studio){
    if (!studio.getTrainer(trainerId)->isOpen())
        cout << "Trainer " << trainerId << " status: closed" << "/n";
    else{
        cout << "Trainer " << trainerId << " status: open" << "/n" << "Customers:" << "/n";
        Trainer* cur = studio.getTrainer(trainerId);
        for (auto i = cur->getCustomers().begin(); i != cur->getCustomers().end(); i++)
            cout << (*i)->getId() << " " << (*i)->getName() << "/n";
        cout << "Orders:" <<endl;
        for (auto i = cur->getOrders().begin(); i != cur->getOrders().end(); i++)
            cout << (*i).second.getName() << " " << (*i).second.getPrice() << "NIS " <<  (*i).second.getId() << "/n";
        cout << "Current Trainer's Salary: " << (*cur).getSalary() << "NIS/n";
    }
    complete();
}

std::string PrintTrainerStatus::toString() const {
    stringstream ss;
    ss<<trainerId;
    return string("status ")+ss.str()+string(" COMPLETE");
}

//PrintActionLog
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

//BackupStudio
BackupStudio ::BackupStudio() {}

void BackupStudio::act(Studio &studio) {
    backup = &studio;
    this->complete();
}

std::string BackupStudio::toString() const {return string("backup COMPLETE");}

//RestoreStudio
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


std::string RestoreStudio::toString() const {}
#endif