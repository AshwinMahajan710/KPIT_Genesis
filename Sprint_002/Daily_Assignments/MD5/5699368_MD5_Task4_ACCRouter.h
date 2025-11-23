#ifndef INC_5699368_MD5_TASK4_ACCROUTER_H
#define INC_5699368_MD5_TASK4_ACCROUTER_H

#include<string>
#include<functional>
#include<vector>

struct Event{std::string label; double value_;};

class ACCRouter{
    public:
        std::vector<std::function<void (const Event& )>> handlers;
        void addHandler(std::function<void (const Event& )> h); // to ad handler
        void removeHandler(size_t idx_); // to remove handler
        void dispatch(const Event& e); // calling all handlers
        void replaceHandler(size_t idx_, std::function<void (const Event& )> h);
};


#endif // INC_5699368_MD5_TASK4_ACCROUTER_H
