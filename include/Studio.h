#ifndef STUDIO_H_
#define STUDIO_H_

#include <vector>
#include <string>
#include "Workout.h"
#include "Trainer.h"
#include "Action.h"
#include "Customer.h"

extern Studio* backup;
class Studio{
public:
	Studio();
    Studio ( Studio& other);
    Studio(const std::string &configFilePath);
    Studio(const Studio& other);
    void start();
    int getNumOfTrainers() const;
    Trainer* getTrainer(int tid);  // if trainer doesnt exist , return nullptr
	const std::vector<BaseAction*>& getActionsLog() const; // Return a reference to the history of actions
    std::vector<Workout>& getWorkoutOptions();
    ~Studio();
    Studio(const Studio&& other);
    Studio& operator=(const Studio& other);

private:
    bool open;
    std::vector<Trainer*> trainers;
    std::vector<Workout> workout_options;
    std::vector<BaseAction*> actionsLog;
};

#endif