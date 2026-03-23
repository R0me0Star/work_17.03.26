#include <iostream>
#include <utility>
#include "top-it-vector.hpp"

bool testDefaultVector()
{
  topit::Vector< int > v;
  return v.isEmpty();
}

bool testVectorWithValue()
{
  topit::Vector< int > v;
  v.pushBack(1);
  return !v.isEmpty();
}

bool testElementAccess()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  return v[0] == 1 && v[1] == 2;
}

bool testCopyConstructor()
{
  topit::Vector< int > v;
  v.pushBack(1);
  topit::Vector< int > yav = v;
  bool isAllEqual = v.getSize() == yav.getSize();
  for (size_t i = 0; isAllEqual && i < v.getSize(); ++i) {
    isAllEqual = isAllEqual && (v[i] == yav[i]);
  }
  return isAllEqual;
}

bool testPushFront()
{
  topit::Vector< int > v;
  v.pushBack(2);
  v.pushBack(3);
  v.pushFront(1);

  return v.getSize() == 3 && v[0] == 1 && v[1] == 2 && v[2] == 3;
}

bool testPopBack()
{
  topit::Vector< int > v;
  v.pushBack(10);
  v.pushBack(20);
  v.popBack();

  return v.getSize() == 1 && v[0] == 10;
}

bool testCapacityGrowth()
{
  topit::Vector< int > v;
  bool cap0 = (v.getCapacity() == 0);

  v.pushBack(1);
  bool cap1 = (v.getCapacity() == 1);

  v.pushBack(2);
  bool cap2 = (v.getCapacity() == 2);

  v.pushBack(3);
  bool cap4 = (v.getCapacity() == 4);

  return cap0 && cap1 && cap2 && cap4;
}

int main()
{
  using test_t = bool (*)();
  using pair_t = std::pair< const char *, test_t >;

  pair_t tests[] = {{"Default vector should be empty", testDefaultVector},
                    {"Vector with any value is not empty", testVectorWithValue},
                    {"Inbound access elements", testElementAccess},
                    {"Sizes must be equal as elements", testCopyConstructor},
                    {"Push front shifts elements correctly", testPushFront},
                    {"Pop back reduces size correctly", testPopBack},
                    {"Capacity doubles when full", testCapacityGrowth}};

  const size_t count = sizeof(tests) / sizeof(pair_t);
  std::cout << std::boolalpha;
  bool pass = true;

  for (size_t i = 0; i < count; ++i) {
    bool res = tests[i].second();
    std::cout << res << ": " << tests[i].first << '\n';
    pass = pass && res;
  }

  std::cout << pass << ": RESULT\n";

  return 0;
}
