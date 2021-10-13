#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int n; scanf("%d", &n);
    double* arr = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) { scanf("%lf", &arr[i]); }
    double allTime = 0., v = 0.;
    for (int i = 0; i < n; i++)
    {
        double newA; scanf("%lf", &newA);
        if (fabs(newA) < 1e-6)
        {
            if (fabs(v) < 1e-6) { return 1; }
            allTime += arr[i] / v;
            continue;
        }
        //vt + at^2/2=s
        // необходимо решить квадратное уравнение
        double D = v * v + 2. * newA * arr[i];//arr[i] = S
        if (D < 0.) { return 1; }
        double curTime = (sqrt(D) - v) / newA;
        if (curTime < 0) { curTime = -(v + sqrt(D)) / newA; }
        allTime += curTime;
        v += curTime * newA;
    }
    printf("%.4lf", allTime);
    return 0;
}
