#ifndef INC_5699368_MD5_TASK2_ALERTMANAGER_H
#define INC_5699368_MD5_TASK2_ALERTMANAGER_H

#include<vector>
#include<functional>
#include<string>

class AltertManager{
    public:
        std::vector<std::function<void(std::string, double)>> handler;
        void dispatch(const std::string& label_, double value_);
};


#endif // INC_5699368_MD5_TASK2_ALERTMANAGER_H
