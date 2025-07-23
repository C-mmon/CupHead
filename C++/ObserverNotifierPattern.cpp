#include <iostream>
#include <vector>
#include <algorithm>

// === Observer Interface ===
class IObserver {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~IObserver() = default;
};

// === Concrete Observers ===
class EmailNotifier : public IObserver {
public:
    void update(const std::string& message) override {
        std::cout << "📧 Email received: " << message << std::endl;
    }
};

class SMSNotifier : public IObserver {
public:
    void update(const std::string& message) override {
        std::cout << "📱 SMS received: " << message << std::endl;
    }
};

// === Subject Interface ===
class ISubject {
public:
    virtual void attach(IObserver* observer) = 0;
    virtual void detach(IObserver* observer) = 0;
    virtual void notify(const std::string& message) = 0;
    virtual ~ISubject() = default;
};

// === Concrete Subject ===
class NotificationSystem : public ISubject {
private:
    std::vector<IObserver*> observers;

public:
    void attach(IObserver* observer) override {
        observers.push_back(observer);
    }

    void detach(IObserver* observer) override {
        observers.erase(
            std::remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }

    void notify(const std::string& message) override {
        for (IObserver* observer : observers) {
            observer->update(message);
        }
    }
};

// === Main Usage ===
int main() {
    NotificationSystem system;

    EmailNotifier email1;
    EmailNotifier email2;
    SMSNotifier sms;

    // Attaching multiple email services
    system.attach(&email1);
    system.attach(&email2);
    system.attach(&sms);

    // Send a notification
    system.notify("New blog post published!");

    return 0;
}
