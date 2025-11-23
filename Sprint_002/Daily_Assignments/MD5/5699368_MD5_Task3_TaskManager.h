#ifndef INC_5699368_MD5_TASK1_TASKMANAGER_H
#define INC_5699368_MD5_TASK1_TASKMANAGER_H

#include<vector>
#include<functional>

class TaskManager{
    public:
        std::vector<std::function<void()>> tasks;
        void addtask(std::function<void()>);
        void runAll();
};

#endif // INC_5699368_MD5_TASK1_TASKMANAGER_H
