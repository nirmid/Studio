//
// Created by nir on 16/11/2021.
//
#ifndef MOVECUSTOMER_CPP_
#define MOVECUSTOMER_CPP_
#include <../include/Action.h>
#include <../include/Studio.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
MoveCustomer::MoveCustomer(int src, int dst, int customerId):srcTrainer(src),dstTrainer(dst), id(customerId) {}
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
    else
        cout << getErrorMsg() ;
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

#endif