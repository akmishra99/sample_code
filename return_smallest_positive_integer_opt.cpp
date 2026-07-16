/*
** given an array of N integers, returns the smallest positive integer
**  (greater than 0) that does not occur in A.
**  Please see sample run of the program at the end of this comment.
** here is sample values of A for which the program is tested:
** 1. A = {1, 3, 6, 4, 1, 2} => returns 5
** 2. A = {1, 2, 3} => returns 4    
** 3. A = {-1, -3} => returns 1
** this file is return_smallest_positive_integer_opt.cpp
** Author: Alok Kumar Mishra
** e-mail: akmishra_99@yahoo.com
** Thursday July 16,2026
** here is command to compile the program:
C:\Users\akmis\scratch_july_16_2026>g++ -g -o return_smallest_positive_integer_opt return_smallest_positive_integer_opt.cpp
** here is command to run the program: and results
C:\Users\akmis\scratch_july_16_2026>.\return_smallest_positive_integer_opt.exe
Result for test case 1: 5
Result for test case 2: 4
Result for test case 3: 1

C:\Users\akmis\scratch_july_16_2026>

*/

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution( vector<int> &A) {
    vector<int> result;    
    sort(A.begin(), A.end()); // Sort the input array A in ascending order so that we can easily find the smallest positive integer that does not occur in A.
    for ( int i = 0; i < A.size(); i++) {     
        if (std::find(A.begin(), A.end(), i) != A.end()) { // If the current integer i is found in the sorted array A, we continue to the next iteration of the loop to check for the next integer.

			continue;
        }
        else {
            result.push_back(i);           
        }
        
    }
    if ((result.size() == 1) && (result[0] == 0)) {
        result.push_back(A.back() + 1);
    }
    return result;
}
int main(int argc, char* argv[], char* envp[]) {
    vector<int> A[3] = {{1, 3, 6, 4, 1, 2}, {1, 2, 3}, {-1,-3}};
    vector<int> result[3];
    for (int j = 0; j < 3; j++) {
         result[j]= solution(A[j]);
         cout << "Result for test case " << j + 1 << ": ";
        for (int i = 0; i < result[j].size(); i++) {
            if (result[j][i] == 0) {
                continue;
            }
            else
                cout << result[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}