/*
Implementation of 9x9 Grid, filled with Subgrids
*/
#include <memory>
#include "subfield.h"
using std::unique_ptr;
using std::array;
using std::string;

#ifndef FIELDH
#define FIELDH

class Field{
  public:
    Field();
    ~Field();
    void assign(int n, int row, int col);
    void remove(int row, int col);
    bool check_valid(int n, int row, int col);
    void fill_random();
    void print_field();
    int get_value(int row, int col);
    void to_file(string filename);
    bool from_file(string filename);


  private:
    bool check_line_validity(string line);
    int get_subfieldID(int i);
    unique_ptr<array<array<Subfield, 3>, 3>> field;
    set<char> valid = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
};

#endif