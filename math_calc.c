/* Practice 2: Math calculations
 * Variant 1
 * Calculating the values for z1 and z2 functions in radians
 */

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

double z1_calc(const double a)
{
    return 2.0 * pow(sin(3.0 * M_PI - 2.0 * a), 2) * pow(cos(5.0 * M_PI + 2.0 * a), 2);
}

double z2_calc(const double a)
{
    return (1.0 / 4.0) - (1.0 / 4.0) * sin((5.0 / 2.0) * M_PI - 8.0 * a);
}

int main()
{
    double z1 = 0.0;
    double z2 = 0.0;
    const double step = 0.1; // rad
    const double end = 1.0;

    for (double a = 0.0; a < end; a += step)
    {
        z1 = z1_calc(a);
        printf("z1(%.2f radians) = %f\n", a, z1);
        z2 = z2_calc(a);
        printf("z2(%.2f radians) = %f\n", a, z2);
        printf("\n");
    }
    return 0;
}