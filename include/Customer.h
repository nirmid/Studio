#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <vector>
#include <string>
#include "Workout.h"
enum string_type {
    swt,chp,mcl,fbd
};
class Customer{
public:
    Customer(std::string c_name, int c_id);
    Customer(Customer& other);
    string_type getType();
    virtual std::vector<int> order(const std::vector<Workout> &workout_options)=0;
    virtual std::string toString() const = 0;
    std::string getName() const;
    int getId() const;
protected:
    string_type t = swt;
private:
    const std::string name;
    const int id;
};


class SweatyCustomer : public Customer {
public:
	SweatyCustomer(std::string name, int id);
    SweatyCustomer(SweatyCustomer& other);
    std::vector<int> order(const std::vector<Workout> &workout_options);
    std::string toString() const;
protected:
    string_type t = swt;
private:

};


class CheapCustomer : public Customer {
public:
	CheapCustomer(std::string name, int id);
    CheapCustomer(CheapCustomer& other);
    std::vector<int> order(const std::vector<Workout> &workout_options);
    std::string toString() const;
protected:
    string_type t = chp;

private:
};


class HeavyMuscleCustomer : public Customer {
public:
	HeavyMuscleCustomer(std::string name, int id);
    HeavyMuscleCustomer(HeavyMuscleCustomer& other);
    std::vector<int> order(const std::vector<Workout> &workout_options);
    std::string toString() const;
protected:
    string_type t = mcl;
private:
};


class FullBodyCustomer : public Customer {
public:
	FullBodyCustomer(std::string name, int id);
    FullBodyCustomer(FullBodyCustomer& other);
    std::vector<int> order(const std::vector<Workout> &workout_options);
    std::string toString() const;
protected:
    string_type t = fbd;
private:
};


#endif