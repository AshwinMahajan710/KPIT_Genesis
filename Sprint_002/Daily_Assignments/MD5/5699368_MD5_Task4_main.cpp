#include<string>
#include<functional>
#include<vector>
#include<iostream>
#include<memory>
#include"5699368_MD5_Task4_ACCRouter.h"
#include"5699368_MD5_Task4_Global.h"

int SafetyFunctor::counter = 0;

int main(){

    // all lambdas
    auto lambda1 = [=](const Event& e){ std::cout<<"\n[Lambda =] Logging: "<<e.label<<" Value: "<<e.value_<<std::endl;};
    auto lambda2 = [&](const Event& e){ std::cout<<"\n[Lambda &] Logging: "<<e.label<<" Value: "<<e.value_<<std::endl;};
    int base = 10;
    auto lambda3 = [threshold = base*1.2](const Event& e){ std::cout<<"\n[init-Lambda] Logging: "<<e.label<<" Value: "<<threshold<<std::endl;};
    int count = 0;
    auto lambda4 = [=, &count](const Event& e) mutable { std::cout<<"\n[Lambda mutable] Logging: "<<e.label<<" Value: "<<e.value_<<" Count: "<<++count<<std::endl;};

    // making unique ptr
    std::unique_ptr<Controller> controller = std::make_unique<Controller> ("Speed");
    auto func1 = std::bind(&Controller::onSpeed, controller.get(), std::placeholders::_1);

    // make shared ptr
    std::shared_ptr<SafetyFunctor> functor = std::make_unique<SafetyFunctor>();
    auto func2 = std::bind(&SafetyFunctor::operator(),functor.get(), std::placeholders::_1);
    
    // making std::ref to free function
    auto func3 = std::ref(logEvent);

    // Adding all in ACCRounter obj
    ACCRouter router;
    router.addHandler(func3);
    router.addHandler(lambda1);
    router.addHandler(lambda4);
    router.addHandler(func1);
    router.addHandler(func2);
    router.addHandler(lambda3);

    // dispatch
    Event e1{"SpeedAlert", 89.5};
    router.dispatch(e1);

    // Replace and remove
    router.replaceHandler(1, [](const Event& e){
        std::cout << "\n[Replaced Handler] --> " << e.label << " : " << e.value_ << std::endl;
    });
    router.removeHandler(2);

    // again dispatch
    Event e2{"PressureDrop", 42.3};
    router.dispatch(e2);

    return 0;
}