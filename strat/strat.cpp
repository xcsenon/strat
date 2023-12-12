#include <iostream>

// Strategy
class Strategy {
public:
    virtual void execute() const = 0;
};

// ConcreteStrategyA
class ConcreteStrategyA : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing ConcreteStrategyA." << std::endl;
    }
};

// ConcreteStrategyB
class ConcreteStrategyB : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing ConcreteStrategyB." << std::endl;
    }
};

// Context
class Context {
private:
    Strategy* strategy;

public:
    Context(Strategy* initialStrategy) : strategy(initialStrategy) {}

    void setStrategy(Strategy* newStrategy) {
        strategy = newStrategy;
    }

    void executeStrategy() const {
        strategy->execute();
    }
};

int main() {
    ConcreteStrategyA strategyA;
    ConcreteStrategyB strategyB;

    Context context(&strategyA);

    // Context initially uses ConcreteStrategyA
    context.executeStrategy();

    // Change the strategy dynamically at runtime
    context.setStrategy(&strategyB);

    // Now the context uses ConcreteStrategyB
    context.executeStrategy();

    return 0;
}
