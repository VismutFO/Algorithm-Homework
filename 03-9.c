#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 03-9: Биссектрисы треугольника
На вход программе подаются координаты вершин треугольника ABC (сначала координаты вершины A, затем B, затем C).
Выведите координаты пересечения биссектрисы ∠ACB со стороной AB, затем координаты точки пересечения биссектрисы ∠BAC со стороной BC,
затем координаты точки пересечения биссектрисы ∠ABC со стороной AC. Все координаты выводите с точностью до 5 знаков после запятой.
*/

double det(double a, double b, double c, double d)
{
    return a * d - b * c;
}

void intersect(double A1, double B1, double C1, double A2, double B2, double C2)
{
    double zn = det(A1, B1, A2, B2);
    double resX = -det(C1, B1, C2, B2) / zn;
    double resY = -det(A1, C1, A2, C2) / zn;
    printf("%.5lf %.5lf\n", resX, resY);
}

void solveOneBis(double Ax, double Ay, double Bx, double By, double Cx, double Cy)
{
    double ABx = Bx - Ax, ACx = Cx - Ax;
    double ABy = By - Ay, ACy = Cy - Ay;
    double len1 = sqrt(ABx * ABx + ABy * ABy);
    double len2 = sqrt(ACx * ACx + ACy * ACy);
    ABx /= len1, ABy /= len1;
    ACx /= len2, ACy /= len2;

    double Dx = Ax + (ABx + ACx), Dy = Ay + (ABy + ACy);// вторая точка, принадлежащая биссектрисе

    double A1 = Ay - Dy, B1 = Dx - Ax, C1 = det(Ax, Ay, Dx, Dy);

    double A2 = By - Cy, B2 = Cx - Bx, C2 = det(Bx, By, Cx, Cy);

    intersect(A1, B1, C1, A2, B2, C2);
}

int main(int argc, char** argv)
{
    double Ax, Ay, Bx, By, Cx, Cy;
    scanf("%lf %lf", &Ax, &Ay);
    scanf("%lf %lf", &Bx, &By);
    scanf("%lf %lf", &Cx, &Cy);
    
    solveOneBis(Cx, Cy, Ax, Ay, Bx, By);
    solveOneBis(Ax, Ay, Bx, By, Cx, Cy);
    solveOneBis(Bx, By, Ax, Ay, Cx, Cy);
    return 0;
}
