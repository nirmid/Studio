//
// Created by nir on 16/11/2021.
//
#ifndef CLOSE_CPP_
#define CLOSE_CPP_
#include <../include/Action.h>
#include <../include/Studio.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
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
    ss<<trainerId;
    string output= string("close ")+ss.str()+string(" ");
    if(this->getStatus()==ERROR)
        output=output+string("Trainer does not exist or is not open");
    else
        output= output+string("COMPLETE");
    return output;
}



#endif