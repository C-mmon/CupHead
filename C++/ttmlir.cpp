#include <iostream>
#include <string>

namespace mlir {

// Simulate a basic MLIR value type
class Value {
public:
  std::string name;
  Value(std::string n) : name(std::move(n)) {}
  void dump() const { std::cout << "Value: " << name << "\n"; }
};

// Simulate a simple MLIR operation
class Operation {
public:
  virtual void run() const = 0;
};

namespace tt {

// Custom dialect-specific op
class DotGeneralOp : public mlir::Operation {
  mlir::Value lhs;
  mlir::Value rhs;

public:
  DotGeneralOp(mlir::Value l, mlir::Value r) : lhs(l), rhs(r) {}

  void run() const override {
    std::cout << "Running DotGeneralOp on: ";
    lhs.dump();
    rhs.dump();
  }
};

} // namespace tt
} // namespace mlir

// === Main Usage ===

using namespace mlir;
using namespace mlir::tt;

int main() {
  Value a("A");
  Value b("B");

  DotGeneralOp op(a, b); // because of 'using namespace mlir::tt'
  op.run();              // prints details
}
