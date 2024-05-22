#include "solver.h"
#include "field.h"

namespace solver
{
    bool backtrack(Field &f, int row, int col)
    {
        // Max number of rows passed
        if (row == 9)
        {
            return true;
        }
        else
        {
            // next row
            if (col == 9)
            {
                return backtrack(f, row + 1, 0);
            }
            else
            {
                if (f.get_value(row, col) != 0)
                {
                    return backtrack(f, row, col + 1);
                }
                else
                {
                    for (int i = 1; i <= 9; i++)
                    {
                        if (f.check_valid(i, row, col))
                        {
                            f.assign(i, row, col);
                            //system("clear");
                            //f.print_field();
                            if (backtrack(f, row, col + 1))
                            {
                                return true;
                            }
                            f.assign(0, row, col);
                        }
                    }
                    return false;
                }
            }
        }
    }
}