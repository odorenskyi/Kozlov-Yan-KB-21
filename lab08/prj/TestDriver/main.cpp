#include <iostream>
#include <iomanip>
#include <cmath>
#include "ModulesKozlov.h"

using namespace std;

int main()
{
    cout << fixed << "\t\tTestDriver of ModulesKozlov.a" << endl;
    cout << "TC_01: |x = 0,\t  y = 0,    z = 0    | - result: " << s_calculation(0, 0, 0) << "   - " <<
            ((round(s_calculation(0, 0, 0)*1000000.0)/1000000.0 == 1) ? "passed" : "failed") << endl;
    cout << "TC_02: |x = 1,\t  y = 0,    z = 0    | - result: " << s_calculation(1, 0, 0) << "   - " <<
            ((round(s_calculation(1, 0, 0)*1000000.0)/1000000.0 == 4.141593) ? "passed" : "failed") << endl;
    cout << "TC_03: |x = 0,\t  y = 1,    z = 0    | - result: " << s_calculation(0, 1, 0) << "   - " <<
            ((round(s_calculation(0, 1, 0)*1000000.0)/1000000.0 == 1.718282) ? "passed" : "failed") << endl;
    cout << "TC_04: |x = 0,\t  y = 0,    z = 1    | - result: " << s_calculation(0, 0, 1) << "   - " <<
            ((round(s_calculation(0, 0, 1)*1000000.0)/1000000.0 == 0) ? "passed" : "failed") << endl;
    cout << "TC_05: |x = -2.5, y = 3,    z = 0    | - result: " << s_calculation(-2.5, 3, 0) << "  - " <<
            ((round(s_calculation(-2.5, 3, 0)*1000000.0)/1000000.0 == 10.499504) ? "passed" : "failed") << endl;
    cout << "TC_06: |x = -2.5, y = 0,    z = -3.12| - result: " << s_calculation(-2.5, 0, -3.12) << "  - " <<
            ((round(s_calculation(-2.5, 0, -3.12)*1000000.0)/1000000.0 == -9.973982) ? "passed" : "failed") << endl;
    cout << "TC_07: |x = 0,\t  y = 4,    z = -2   | - result: " << s_calculation(0, 4, -2) << "  - " <<
            ((round(s_calculation(0, 4, -2)*1000000.0)/1000000.0 == 54.59815) ? "passed" : "failed") << endl;
    cout << "TC_08: |x = 4.65, y = 1.1   z = 0    | - result: " << s_calculation(4.65, 1.1, 0) << "  - " <<
            ((round(s_calculation(4.65, 1.1, 0)*1000000.0)/1000000.0 == 16.563763) ? "passed" : "failed") << endl;
    cout << "TC_09: |x = 2,\t  y = 5,    z = 6    | - result: " << s_calculation(2, 5, 6) << " - " <<
            ((round(s_calculation(2, 5, 6)*1000000.0)/1000000.0 == 149.12858) ? "passed" : "failed") << endl;
    cout << "TC_10: |x = -11,  y = 2.28, z = -9   | - result: " << s_calculation(-11, 2.28, -9) << " - " <<
            ((round(s_calculation(-11, 2.28, -9)*1000000.0)/1000000.0 == -33.653268) ? "passed" : "failed") << endl;
    return 0;
}
