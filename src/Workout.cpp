//
// Created by nirmid@wincs.cs.bgu.ac.il on 09/11/2021.
//
#ifndef WORKOUT_CPP_
#define WORKOUT_CPP_
using namespace std;
#include <../include/Workout.h>
Workout::Workout(int w_id, std::string w_name, int w_price, WorkoutType w_type):
id(w_id), name(w_name), price(w_price), type(w_type){}
int Workout::getId() const { return id ;}
string Workout::getName() const { return name;}
int Workout::getPrice() const {return price;}
WorkoutType Workout::getType() const {return type;}
bool operator>(const Workout& w1,const Workout& w2){ return w1.getPrice() > w2.getPrice();}
bool operator<(const Workout& w1,const Workout& w2){ return w1.getPrice() < w2.getPrice();}
bool operator==(const Workout& w1,const Workout& w2){ return w1.getPrice() == w2.getPrice();}


#endif