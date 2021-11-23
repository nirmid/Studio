#ifndef ACTION_CPP_
#define ACTION_CPP_
#include <../include/Action.h>
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
    BaseAction::error("Cannot move customer");
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
//Move
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
//
#endif