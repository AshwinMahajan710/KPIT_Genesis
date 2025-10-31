#ifndef ENGINE_H
#define ENGINE_H

class Engine{
    private:
        int m_horsePower;
    public:
        // constructor
        Engine();
        Engine(int horsePower_);
        // getter
        int getHP() const noexcept;
};

#endif // ENGINE_H
