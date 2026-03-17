#include "top-it-vector.hpp"

bool testDefaultVector() {
  Vector< int > v:
  return v.isEmpty();
}

int main()
{
  using test_t = bool(*)();
  test_t tests[] = {
    testDefaultVector
  };
  const size_t count = sizeof(tests) / sizeof(test_t);
  for (size_t i = 0; i < count; ++i) {
    bool res = tests[i]();
    std::cout << "Result: " << res << "\n";
  }
}



