#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

enum employeeAccess
{
	FULL_ACCESS, 
	PARTIAL_ACCESS,
	NO_ACCESS;
};

enum class OperationResult
{
	SUCCESS, 
	EMPLOYEE_NOT_FOUND, 
	EMPLOYEE_ALREADY_EXIST, 
	INVALID_DATA
};

class Employee {
public:
    int empId;
    string empName;
    int dateOfJoining;
    employeeAccess access;

    Employee(int id, const string &name, int date)
        : empId(id), empName(name), dateOfJoining(date), access(NO_ACCESS) {}
};

class EmployeeFactory {
public:
    // Factory method with validation, optional means the function may or may not return the value
    static optional<Employee> createEmployee(int id, const string& name, int date) {
        // Validation logic
        if (id <= 0) {
            cout << "Error: Invalid employee ID" << endl;
            return nullopt;
        }
        if (name.empty()) {
            cout << "Error: Employee name cannot be empty" << endl;
            return nullopt;
        }
        if (date < 20000101 || date > 20301231) {  // Basic date validation
            cout << "Error: Invalid date" << endl;
            return nullopt;
        }
        
        cout << "Creating employee: " << name << " (ID: " << id << ")" << endl;
        return Employee(id, name, date);
    }
    
    // Overloaded factory method for different creation strategies
    static optional<Employee> createEmployeeWithAccess(int id, const string& name, int date, employeeAccess access) {
        auto employee = createEmployee(id, name, date);
        if (employee.has_value()) {
            employee->access = access;
        }
        return employee;
    }
};



//abstraction
class IEmployeeDatabase
{
	public:
    virtual bool hasEmployee(int id) const = 0;
    virtual bool updateAccess(int id, employeeAccess accessType) = 0;
    virtual ~IEmployeeDatabase() = default;
}


class IAccessManager
{
public:
	virtual bool grant(int empId, employeeAccess accessType) = 0;
	virtual bool revoke(int empId) = 0;
	virtual employeeAccess get(int empId)  const =0;
	virtual ~IEmployeeDatabase() = default;
}


class EmployeeDatabase: public IEmployeeDatabase
{
	unordered_map <int, Employee> empData; 

    OperationResult createEmployee(int id, const string &name, int date) {
        if (empData.count(id)) {
            return OperationResult::EMPLOYEE_ALREADY_EXISTS;
        }
        
        // Use factory to create employee
        auto employee = EmployeeFactory::createEmployee(id, name, date);
        if (!employee.has_value()) {
            return OperationResult::INVALID_DATA;
        }
        
        empData.emplace(id, employee.value());
        return OperationResult::SUCCESS;
    }

    employeeAccess getAccess(int id) const override {
        auto it = empData.find(id);
        if (it == empData.end()) return NO_ACCESS;
        return it->second.access;
    }

    void printAll() const {
        cout << "\n--- Employee Database ---" << endl;
        for (const auto &p : empData) {
            cout << "ID: " << p.second.empId << " | "
                 << "Name: " << p.second.empName << " | "
                 << "DOJ: " << p.second.dateOfJoining << " | "
                 << "Access: " << getAccessString(p.second.access) << endl;
        }
        cout << "------------------------\n" << endl;
    }

private:
    string getAccessString(employeeAccess access) const {
        switch(access) {
            case FULL_ACCESS: return "FULL";
            case PARTIAL_ACCESS: return "PARTIAL";
            case NO_ACCESS: return "NONE";
            default: return "UNKNOWN";
        }
    }
};


// ---- Concrete Access Manager ----
class EmpAccessManager : public IAccessManager {
    IEmployeeDatabase &db; // depends on abstraction, not concrete class
public:
    EmpAccessManager(IEmployeeDatabase &database) : db(database) {}

    bool grant(int empId, employeeAccess accessType) override {
        if (!db.hasEmployee(empId)) {
            cout << "Cannot grant access: Employee " << empId << " not found" << endl;
            return false;
        }
        bool result = db.updateAccess(empId, accessType);
        if (result) {
            cout << "Access granted to employee " << empId << endl;
        }
        return result;
    }

    bool revoke(int empId) override {
        if (!db.hasEmployee(empId)) {
            cout << "Cannot revoke access: Employee " << empId << " not found" << endl;
            return false;
        }
        bool result = db.updateAccess(empId, NO_ACCESS);
        if (result) {
            cout << "Access revoked for employee " << empId << endl;
        }
        return result;
    }

    employeeAccess get(int empId) const override {
        return db.getAccess(empId);
    }
};

// ---- Example Usage ----
int main() {
    EmployeeDatabase db;
   
    cout << "=== Creating Employees ===" << endl;
    auto result1 = db.createEmployee(1, "Alice", 20200101);
    auto result2 = db.createEmployee(2, "Bob", 20210315);
    auto result3 = db.createEmployeeWithAccess(3, "Charlie", 20220101, PARTIAL_ACCESS);
    
    // Test error cases
    auto result4 = db.createEmployee(1, "Duplicate Alice", 20230101); // Should fail
    auto result5 = db.createEmployee(-1, "Invalid ID", 20230101);     // Should fail

    EmpAccessManager am(db); // works on abstraction

    am.grant(1, FULL_ACCESS);
    am.grant(2, PARTIAL_ACCESS);
    am.revoke(2);

    cout << "\n=== Testing Access Retrieval ===" << endl;
    cout << "Employee 1 access level: " << am.get(1) << endl;
    cout << "Employee 2 access level: " << am.get(2) << endl;
    cout << "Employee 3 access level: " << am.get(3) << endl;

    db.printAll();

    return 0;
}
