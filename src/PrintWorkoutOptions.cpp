//
// Created by spl211 on 16/11/2021.
//
#ifndef ORDER_CPP_
#define ORDER_CPP_
using namespace std;
#include <../include/Action.h>
#include <vector>
#include <iostream>
#include <../include/Trainer.h>
#include <../include/Studio.h>

PrintWorkoutOptions :: PrintWorkoutOptions(){}

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














#endif