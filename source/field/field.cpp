#include "field.h"
#include "subfield.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
#include <chrono>
#include <array>
using std::array;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::make_unique;
using std::string;
using std::filesystem::exists;

Field::Field()
{
    field = make_unique<array<array<Subfield, 3>, 3>>();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            (*field)[i][j] = Subfield();
        }
    }
}

int Field::get_subfieldID(int j)
{
    /*
    Takes in row or col in range [0..8] and boils it down to subfield number.

    @param int j: Row or Column number
    @return int: Number of subfield
    */
    switch (j)
    {
    case 0 ... 2:
        return 0;
    case 3 ... 5:
        return 1;
    case 6 ... 8:
        return 2;
    default:
        return -1;
    }
}

void Field::assign(int n, int row, int col)
{
    /*
    Assigns number within correct subfield.

    @param int n: Number that will be assigned
    @param int row: Row number
    @param int col: Column number
    */
    if (0 <= row <= 8 && 0 <= col <= 8)
    {
        int sfRow = get_subfieldID(row);
        int sfCol = get_subfieldID(col);
        (*field)[sfRow][sfCol].assign(n, row % 3, col % 3);
    }
}

void Field::remove(int row, int col)
{
    /*
    Removes number within subfield.

    @param int row: Row number
    @param int col: Column number
    */
    if (0 <= row <= 8 && 0 <= col <= 8)
    {
        int sfRow = get_subfieldID(row);
        int sfCol = get_subfieldID(col);
        (*field)[sfRow][sfCol].remove(row % 3, col % 3);
    }
}

bool Field::check_valid(int n, int row, int col)
{
    /*
    Checks ifsetting number within a field is a valid operation.

    @param int n: Number that will be assigned
    @param int row: Row number
    @param int col: Column number
    @return bool: True if Operation is valid
    */
    if (0 <= row <= 8 && 0 <= col <= 8)
    {
        int sfRow = get_subfieldID(row);
        int sfCol = get_subfieldID(col);

        // number already present in subfield
        if ((*field)[sfRow][sfCol].check_presence(n))
        {
            return false;
        }

        // number already present in row or column
        for (int i = 0; i <= 2; i++)
        {
            if ((*field)[sfRow][i].check_row(n, row % 3))
            {
                return false;
            }
            if ((*field)[i][sfCol].check_col(n, col % 3))
            {
                return false;
            }
        }
        // not present in subfield, row and column
        return true;
    }
    return false;
}

void Field::fill_random()
{
    /*
    Creates random filling for field.
    */
    array<int, 9> rows = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    array<int, 9> cols = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(rows.begin(), rows.end(), std::default_random_engine(seed1));
    unsigned seed2 = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(cols.begin(), cols.end(), std::default_random_engine(seed2));

    for (int i = 0; i <= 8; i++)
    {
        assign(i+1, rows[i], cols[i]);
    }
}

void Field::print_field()
{
    /*
    Prints field to console.
    */
    for (int i = 0; i <= 2; i++)
    {
        for (int row = 0; row <= 2; row++)
        {
            (*field)[i][0].print_row(row);
            cout << " ";
            (*field)[i][1].print_row(row);
            cout << " ";
            (*field)[i][2].print_row(row);
            cout << "\n";
        }
        cout << "\n";
    }
    cout << "\n";
}

int Field::get_value(int row, int col)
{
    /*
    Gets value from specific cell

    @param int row: Row number
    @param int col: Column number
    @return int: cell value, -1 if invalid
    */
    if (0 <= row <= 8 && 0 <= col <= 8)
    {
        int sfRow = get_subfieldID(row);
        int sfCol = get_subfieldID(col);
        return (*field)[sfRow][sfCol].get_value(row % 3, col % 3);
    }
    return -1;
}

void Field::to_file(string filename)
{
  ofstream output (filename);
  if (output.is_open())
  {
    for(int row = 0; row <= 8; row++){
        for(int col = 0; col <= 8; col++){
            output << get_value(row, col);
        }
        output << "\n";
    }
    output.close();
  }
}

bool Field::check_line_validity(string line){
    /*
    Checks if line from file only contains numbers and has correct length

    @param string line: Line of file
    @return bool: true if valid, false if not
    */
    for (char& c : line){
        if(!valid.contains(c)){
            return false;
        }
    }
    if (line.size() != 9){
        return false;
    }
    return true;
}

bool Field::from_file(string filename)
{
    /*
    Reads in .txt file that contains 9x9 field in human readable form

    @param string filename: file path and name
    @return bool: returns True if successful
    */
    if (!exists(filename))
    {
        // file does not exist
        return false;
    }

    ifstream file(filename); 
    string line; 
    int row = 0;

    if (file.is_open()) { 
        while (getline(file, line)) { 
            // Check if line only contains valid values
            if (!check_line_validity(line)){
                return false;
            }
            // convert valid line to row
            for (int col=0; col <= 8; col++){
                int number = int(line.at(col)) - 48;
                assign(number, row, col);
            }
            ++row;

        } 
        file.close(); 
    } 
    else { 
        return false;
    } 

    return true;
}

Field::~Field() = default;
