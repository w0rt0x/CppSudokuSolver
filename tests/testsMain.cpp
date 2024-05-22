#include <gtest/gtest.h>
#include "field.h"
#include "solver.h"


TEST(SolverTest, Solveable) {
  Field f = Field();
  f.from_file("./../../tests/fields/Solvable/field1.txt");
  EXPECT_EQ(solver::backtrack(f, 0, 0), true);
}

TEST(SolverTest, NotSolveable) {
  Field f = Field();
  f.from_file("./../../tests/fields/NotSolvable/field1.txt");
  EXPECT_EQ(solver::backtrack(f, 0, 0), false);
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
