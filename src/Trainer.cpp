//
// Created by spl211 on 13/11/2021.
//
#ifndef TRAINER_CPP_
#define TRAINER_CPP_
using namespace std;
#include <../include/Trainer.h>
#include <vector>
#include <iostream>

Trainer :: Trainer(int t_capacity):
    capacity(t_capacity), open{false}, salary{0}{}

Trainer :: Trainer ( Trainer& other):
    capacity(other.capacity), open(other.open) ,salary(other.salary), customersList(), orderList(){}

Trainer :: Trainer( Trainer&& other):
    capacity{other.capacity}, open{other.open}, salary{other.salary}, customersList{other.customersList}, orderList{other.orderList}{
        other.customersList.clear();
        other.orderList.clear();
    }
Trainer& Trainer ::  operator = ( Trainer& other) {
    if (this == &other)
        return *this;
    capacity =other.capacity;
    open = other.open;
    salary = other.salary;
    customersList = other.customersList;
    for(int  i = 0; i < other.orderList.size(); i++) {
        orderList.push_back((other.orderList)[i]);
    }
}
Trainer& Trainer :: operator = ( Trainer&& other) noexcept{
    if (this == &other)
        return *this;
    capacity =other.capacity;
    open = other.open;
    salary = other.salary;
    customersList = other.customersList;
    for(int  i = 0; i < other.orderList.size(); i++) {
        orderList.push_back((other.orderList)[i]);
    }
    other.customersList.clear();
    other.orderList.clear();
}

Trainer :: ~Trainer() {
    customersList.clear();
    orderList.clear();
}

int Trainer :: getCapacity() const {
    return capacity;
}
void Trainer ::addCustomer(Customer *customer) {
    customersList.push_back(customer);
}
void Trainer ::removeCustomer(int id) {
    bool found = false;
    for (auto i = customersList.begin(); i != customersList.end() | found; ++i)
        if ((*i)->getId() == id){
            customersList.erase(i);
            found = true;
        }
    for (auto i = orderList.begin(); i != orderList.end() ; ++i)
        if ((*i).first == id) {
            while ((*i).first == id) {
                salary = salary - (*i).second.getPrice();
                (*i).first = -1;
                i++;
            }
            return;
        }
}
Customer* Trainer ::getCustomer(int id) {
    for (auto i = customersList.begin(); i != customersList.end(); ++i)
        if ((*i)->getId() == id){
            return *i;
        }
}
std::vector<Customer*>& Trainer ::getCustomers() {
    return customersList;
}
std::vector<OrderPair>& Trainer :: getOrders(){
    return orderList;
}
void Trainer :: order(const int customer_id, const std::vector<int> workout_ids, const std::vector<Workout>& workout_options){
    for (auto i = customersList.begin(); i != customersList.end(); ++i)
        if ((*i)->getId() == customer_id){
            for (auto j = workout_ids.begin(); j != workout_ids.end(); ++j) {
                orderList.push_back( OrderPair (  customer_id ,workout_options[*j]));
                salary = salary + workout_options[*j].getPrice();
                cout << (*i)->getName() << " is doing " << (workout_options.begin() + (*j))->getName() << "/n";
            }
            return;
        }
}
void Trainer :: openTrainer(){
    open = true;
}
void Trainer :: closeTrainer(){
    open = false;
    customersList.clear();
    orderList.clear();
}
int Trainer :: getSalary(){
    return salary;
}
bool Trainer :: isOpen(){
    return open;
}





#endif