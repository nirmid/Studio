//
// Created by nir on 16/11/2021.
//
#ifndef MOVECUSTOMER_CPP_
#define MOVECUSTOMER_CPP_
#include <../include/Action.h>
#include <../include/Studio.h>
#include <string>
#include <iostream>
using namespace std;
MoveCustomer::MoveCustomer(int src, int dst, int customerId):srcTrainer(src),dstTrainer(dst), id(customerId) {}
void MoveCustomer::act(Studio &studio) {
    BaseAction::error("Trainer does not exist or is not open");
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

#endif