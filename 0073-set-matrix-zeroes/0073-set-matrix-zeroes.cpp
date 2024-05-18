#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<int> rows, cols; // Corrected

        // Corrected loop to find all rows and columns that have zeros
        for (int i = 0; i < matrix.size(); i++) // Loop over rows
        {
            for (int j = 0; j < matrix[0].size(); j++) // Loop over columns
            {
                if (matrix[i][j] == 0) // Fixed by declaring 'i'
                {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        // Corrected loop to set entire rows to zero
        for (int i = 0; i < rows.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[rows[i]][j] = 0;
            }
        }

        // Corrected loop to set entire columns to zero
        for (int j = 0; j < cols.size(); j++)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][cols[j]] = 0; // Corrected assignment
            }
        }
    }
};

