//Strategy pattern
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() = default;
};


//Concrete Strategies
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid ₹" << amount << " using Credit Card" << endl;
    }
};

class PayPalPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid ₹" << amount << " using PayPal" << endl;
    }
};


class ShoppingCart {
private:
    PaymentStrategy* strategy;

public:
    void setStrategy(PaymentStrategy* s) {
        strategy = s;
    }

    void checkout(int amount) {
        if (strategy)
            strategy->pay(amount);
        else
            cout << "No payment strategy selected." << endl;
    }
};
