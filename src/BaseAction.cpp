//
// Created by nir on 14/11/2021.
//
#ifndef BASEACTION_CPP_
#define BASEACTION_CPP_
#include <../include/Action.h>
using namespace  std;
BaseAction::BaseAction() {}
ActionStatus BaseAction::getStatus() const {return status;}
void BaseAction::complete() {status = COMPLETED;}
string BaseAction::getErrorMsg() const {return errorMsg;}
void BaseAction::act(Studio &studio) {}
void BaseAction::error(std::string errorMsg){this->errorMsg = errorMsg;}
std::string BaseAction::toString() const {}



#endif