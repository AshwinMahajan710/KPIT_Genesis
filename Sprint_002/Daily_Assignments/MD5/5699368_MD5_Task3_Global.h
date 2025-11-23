#ifndef INC_5699368_MD5_TASK3_GLOBAL_H
#define INC_5699368_MD5_TASK3_GLOBAL_H

// free function --> logging a message
void logTask();

// class --> perform work with id
class Worker{
    public:
        void doWork(int id_);
};

// functor
struct TaskFunctor
{
    void operator()();
};


#endif // INC_5699368_MD5_TASK3_GLOBAL_H
