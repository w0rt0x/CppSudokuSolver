#include "subfield.h"
#include <iostream>
#include <array>
#include <set>
using std::cout;
using std::make_unique;

Subfield::Subfield()
{
    subfield = make_unique<array<array<int, 3>, 3>>();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            (*subfield)[i][j] = 0;
        }
    }
}

void Subfield::assign(int n, int row, int col)
{
    /*
    Assigns number within subfield

    @param int n: Number that will be assigned
    @param int row: Row number
    @param int col: Column number
    */
    if (0 <= row <= 2 && 0 <= col <= 2)
    {
        nums.erase((*subfield)[row][col]);
        (*subfield)[row][col] = n;
        nums.insert(n);
    }
}

void Subfield::remove(int row, int col)
{
    /*
    Removes number within subfield

    @param int row: Row number
    @param int col: Column number
    */
    if (0 <= row <= 2 && 0 <= col <= 2)
    {
        int n = (*subfield)[row][col];
        (*subfield)[row][col] = 0;
        nums.erase(n);
    }
}

bool Subfield::check_row(int n, int row)
{
    /*
    Checks if number is present within row

    @param int n: number
    @param int row: Row number
    @return bool: True if present
    */
    if (0 <= row <= 2)
    {
        for (int i = 0; i < 3; i++)
        {
            if (n == (*subfield)[row][i])
            {
                return true;
            }
        }
    }
    return false;
}

bool Subfield::check_col(int n, int col)
{
    /*
    Checks if number is present within column

    @param int n: number
    @param int col: Column number
    @return bool: True if present
    */
    if (0 <= col <= 2)
    {
        for (int i = 0; i < 3; i++)
        {
            int t = (*subfield)[i][col];
            if (n == (*subfield)[i][col])
            {
                return true;
            }
        }
    }
    return false;
}

bool Subfield::check_presence(int n)
{
    /*
    Checks if number is present within subgrid

    @param int n: number
    @return bool: True if present
    */
    return nums.contains(n);
}

void Subfield::print_row(int row)
{
    /*
    Prints row of subfield to console

    @param int row: Row number
    */
    if (0 <= row <= 2)
    {
        cout << (*subfield)[row][0] << (*subfield)[row][1] << (*subfield)[row][2];
    }
}

int Subfield::get_value(int row, int col)
{
    /*
    Grabs numeric value in subfield and returns it, -1 if that fails.

    @param int row: Row number
    @param int col: Column number
    @return int: cell value
    */
    if (0 <= row <= 2 && 0 <= col <= 2)
    {
        return (*subfield)[row][col];
    }
    return -1;
}