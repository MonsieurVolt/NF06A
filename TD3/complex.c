#include <stdio.h>
#include <math.h>

struct Rect
{
    double real;
    double imaginary;
};
struct Polar
{
    double modulus;
    double argument;
};
void RectToPolar(struct Rect number, struct Polar *result)
{
    result->modulus = sqrt(number.real * number.real + number.imaginary * number.imaginary);
    result->argument = atan2(number.real, number.imaginary);
};
void PolarToRect(struct Polar number, struct Rect *result)
{
    result->real = number.modulus * cos(number.argument);
    result->imaginary = number.modulus * sin(number.argument);
};
void sumCplx(struct Rect cplx1, struct Rect cplx2, struct Rect *result)
{
    result->real = cplx1.real + cplx2.real;
    result->imaginary = cplx1.imaginary + cplx2.imaginary;
};
void subCplx(struct Rect cplx1, struct Rect cplx2, struct Rect *result)
{
    result->real = cplx1.real - cplx2.real;
    result->imaginary = cplx1.imaginary - cplx2.imaginary;
};
void mulCplx(struct Rect cplx1, struct Rect cplx2, struct Rect *result)
{
    result->real = cplx1.real * cplx2.real - cplx1.imaginary * cplx2.imaginary;
    result->imaginary = cplx1.imaginary * cplx2.real + cplx1.real * cplx2.imaginary;
};
void divCplx(struct Rect cplx1, struct Rect cplx2, struct Rect *result)
{
    double mod = cplx2.real * cplx2.real + cplx2.imaginary * cplx2.imaginary;
    result->real = (cplx1.real * cplx2.real + cplx1.imaginary * cplx2.imaginary) / mod;
    result->imaginary = (cplx1.imaginary * cplx2.real + cplx1.real * -cplx2.imaginary) / mod;
};
void SecondDegree(struct Rect a, struct Rect b, struct Rect c, struct Rect *r1, struct Rect *r2)
{
    struct Rect delta;
    struct Rect bSquare;
    struct Rect ac;
    mulCplx(b, b, &bSquare);
    mulCplx(a, c, &ac);
    ac.real *= -4;
    ac.imaginary *= -4;
    sumCplx(bSquare, ac, &delta);
    double Deltamodulus = sqrt(delta.real * delta.real + delta.imaginary * delta.imaginary);
    double da, db;
    da = sqrt((delta.real + Deltamodulus) / 2);
    db = sqrt((Deltamodulus - delta.real) / 2.0);
    // printf("%lf", db);
    // printf("r : %lf, i : %lf\n", da.real, da.imaginary);
    struct Rect d1, d2;
    if (delta.imaginary > 0)
    {
        d1.real = da;
        d1.imaginary = db;
        d2.real = -da;
        d2.imaginary = -db;
    }
    else
    {
        d1.real = -da;
        d1.imaginary = db;
        d2.real = da;
        d2.imaginary = -db;
    }
    struct Rect twoa;
    twoa.real = 2 * a.real;
    twoa.imaginary = 2 * a.imaginary;
    struct Rect minusb;
    minusb.imaginary = -b.imaginary;
    minusb.real = -b.real;
    struct Rect top1;
    struct Rect top2;
    sumCplx(minusb, d1, &top1);
    sumCplx(minusb, d2, &top2);
    divCplx(top1, twoa, r1);
    divCplx(top2, twoa, r2);
};
int main()
{
    struct Rect number;
    number.real = 2;
    number.imaginary = 2;
    struct Polar result;
    RectToPolar(number, &result);
    struct Rect a = {1.0, 0.0};
    struct Rect b = {0.0, -1.0};
    struct Rect c = {-1.0, -1.0};
    struct Rect r1, r2;
    SecondDegree(a, b, c, &r1, &r2);
    printf("The number is : %0.2lf +  i%0.2lf\n", r1.real, r1.imaginary);
    printf("The number is : %0.2lf + i%0.2lf\n", r2.real, r2.imaginary);

    // printf("The argument is : %lf and the modulus is : %lf\n", result.argument, result.modulus);
    // printf("The number is : %lf+i%lf\n", number.real, number.imaginary);
};