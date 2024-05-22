/*
Implementation of 3x3 Subgrid
*/

#include <set>
#include <memory>
using std::array;
using std::set;
using std::unique_ptr;

#ifndef SUBFIELDH
#define SUBFIELDH

class Subfield
{
public:
  Subfield();
  void assign(int n, int row, int col);
  void remove(int row, int col);
  bool check_row(int n, int row);
  bool check_col(int n, int col);
  bool check_presence(int n);
  void print_row(int row);
  int get_value(int row, int col);

private:
  set<int> nums;
  unique_ptr<array<array<int, 3>, 3>> subfield;
};

#endif