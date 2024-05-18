#include "VectorOperations.h"
#include <cassert>
#include <vector>

using namespace std;
using namespace myVectUtils;

const vector<int> v1{6, 2, 4};
const vector<int> v2{4, -3, 0};

void test_sum() {
  vector<int> calculated{v1 + v2};
  const vector<int> expected{10, -1, 4};
  Print(calculated);

  for (size_t i{}; i < calculated.size(); ++i) {
    assert(calculated[i] == expected[i]);
  }
}

void test_diff() {
  vector<int> calculated{v1 - v2};
  // Implement all the checks
  Print(calculated);
}

void test_vector_diff() {
  vector<int> calculated{v1 - v2};
  // Implement all the checks
  Print(calculated);
}

void test_scalar_mul() {
  vector<int> calculated1{3 * v1};
  // Implement all the checks
  Print(calculated1);

  vector<int> calculated2{v1 * 3};
  // Implement again the same checks
  Print(calculated2);
}

void test_scalar_div() {
  // Note that all the members of v2 are even numbers
  vector<int> calculated{v1 / 2};
  // Implement all the checks
  Print(calculated);
}

void test_inplace_sum() {
  vector<int> v{1, 7, 5};

  v += v1;
  Print(v);

  vector<int> expected{7, 9, 9};
  // Implement all the checks
}

void test_inplace_diff() {
  vector<int> v{1, 7, 5};

  v -= v1;
  Print(v);

  vector<int> expected{-5, 5, 1};
  // Implement all the checks
}

int main(void) {
  test_sum();
  test_diff();
  test_vector_diff();
  test_scalar_mul();
  test_scalar_div();
  test_inplace_sum();
  test_inplace_diff();
  return 0;
}
