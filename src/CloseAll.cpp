//
// Created by nir on 16/11/2021.
//
#ifndef CLOSEALL_CPP_
#define CLOSEALL_CPP_
#include <../include/Action.h>
#include <../include/Studio.h>
#include <string>
#include <iostream>
using namespace std;
CloseAll::CloseAll() {}
void CloseAll::act(Studio &studio) {
    for(int i=0;i<studio.getNumOfTrainers();i=i+1){
        Close c(i);  // need implementation of closing studio , how to close studio ?
    }
}
#endif