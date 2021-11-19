//
// Created by nir on 16/11/2021.
//
#ifndef CLOSE_CPP_
#define CLOSE_CPP_
#include <../include/Action.h>
#include <../include/Studio.h>
#include <string>
#include <iostream>
using namespace std;
Close::Close(int id): trainerId(id) {}
void Close::act(Studio &studio) {
    if(studio.getTrainer(trainerId)!= nullptr && studio.getTrainer(trainerId)->isOpen()){
        Trainer* t=studio.getTrainer(trainerId);
        t->closeTrainer(); // close at trainer class should remove all customers from customer's vector
        Close::toString();
    }
    else
        Close::error("Trainer does not exist or is not open");
}


}



#endif