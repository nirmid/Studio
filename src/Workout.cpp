#ifndef WORKOUT_CPP_
#define WORKOUT_CPP_
using namespace std;
#include <../include/Workout.h>
Workout::Workout(int w_id, std::string w_name, int w_price, WorkoutType w_type):
id(w_id), name(w_name), price(w_price), type(w_type){}
Workout::Workout(const Workout &other):
id(other.getId()), name(other.getName()), price(other.getPrice()), type(other.getType()){}
int Workout::getId() const { return id ;}
string Workout::getName() const { return name;}
int Workout::getPrice() const {return price;}
WorkoutType Workout::getType() const {return type;}
Workout::~Workout(){}
bool operator>(const Workout& w1,const Workout& w2){
    if(w1.getPrice()>w2.getPrice())
        return true;
    else
        if(w1.getPrice()==w2.getPrice() && w1.getId()>w2.getId())
            return true;
     return false;
}
/*
bool operator<(const Workout& w1,const Workout& w2){
    return w1.getPrice() < w2.getPrice();
}
bool operator==(const Workout& w1,const Workout& w2){
    return w1.getPrice() == w2.getPrice();
}
 */


#endif