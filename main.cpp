// Base code written by Jan Allbeck, Chris Czyzewicz, Cory Boatright, Tiantian Liu, Benedict Brown, and Adam Mally
// University of Pennsylvania

// At least some C++ compilers do funny things
// to C's math.h header if you don't define this
#define _USE_MATH_DEFINES

#include "vec4.h"
#include "mat4.h"
#include <iostream>
#include <math.h>
using namespace std;

void vec4AddTest() {
	vec4 a = vec4(1.f, 2.f, 3.f, 4.f);
	vec4 b = vec4(2.f, 4.f, 6.f, 8.f);
    std::cout << "vec4 + vec4 expected value: (3.0, 6.0, 9.0, 12.0)" << std::endl;
    std::cout << "vec4 + vec4 actual value: " << (a + b) << std::endl;
}

// -----------------------------------------------------------------------------
// vec4 Tests
// -----------------------------------------------------------------------------

void vec4ConstructorTests()
{
    std::cout << "\n=== vec4 Constructor Tests ===\n";

    vec4 a;

    std::cout << "Default Constructor" << std::endl;
    std::cout << "Expected: (0, 0, 0, 0)" << std::endl;
    std::cout << "Actual:   " << a << std::endl;


    vec4 b(1.0f, 2.0f, 3.0f, 4.0f);

    std::cout << "\nFour-Value Constructor" << std::endl;
    std::cout << "Expected: (1, 2, 3, 4)" << std::endl;
    std::cout << "Actual:   " << b << std::endl;


    vec4 c(b);

    std::cout << "\nCopy Constructor" << std::endl;
    std::cout << "Expected: (1, 2, 3, 4)" << std::endl;
    std::cout << "Actual:   " << c << std::endl;
}


void vec4AssignmentTest()
{
    std::cout << "\n=== vec4 Assignment Test ===\n";

    vec4 a(1.0f, 2.0f, 3.0f, 4.0f);
    vec4 b;

    b = a;

    std::cout << "Expected: (1, 2, 3, 4)" << std::endl;
    std::cout << "Actual:   " << b << std::endl;
}


void vec4EqualityTests()
{
    std::cout << "\n=== vec4 Equality Tests ===\n";

    vec4 a(1.0f, 2.0f, 3.0f, 4.0f);
    vec4 b(1.0f, 2.0f, 3.0f, 4.0f);
    vec4 c(5.0f, 6.0f, 7.0f, 8.0f);

    std::cout << boolalpha;

    std::cout << "a == b expected: true" << std::endl;
    std::cout << "a == b actual:   " << (a == b) << std::endl;

    std::cout << "a != c expected: true" << std::endl;
    std::cout << "a != c actual:   " << (a != c) << std::endl;
}


void vec4ArithmeticTests()
{
    std::cout << "\n=== vec4 Arithmetic Tests ===\n";

    vec4 a(1.0f, 2.0f, 3.0f, 4.0f);
    vec4 b(2.0f, 4.0f, 6.0f, 8.0f);

    std::cout << "a + b expected: (3, 6, 9, 12)" << std::endl;
    std::cout << "a + b actual:   " << (a + b) << std::endl;

    std::cout << "b - a expected: (1, 2, 3, 4)" << std::endl;
    std::cout << "b - a actual:   " << (b - a) << std::endl;

    std::cout << "a * 2 expected: (2, 4, 6, 8)" << std::endl;
    std::cout << "a * 2 actual:   " << (a * 2.0f) << std::endl;

    std::cout << "b / 2 expected: (1, 2, 3, 4)" << std::endl;
    std::cout << "b / 2 actual:   " << (b / 2.0f) << std::endl;
}


void vec4DotTest()
{
    std::cout << "\n=== Dot Product Test ===\n";

    vec4 a(1.0f, 2.0f, 3.0f, 4.0f);
    vec4 b(2.0f, 3.0f, 4.0f, 5.0f);

    std::cout << "Expected: 40" << std::endl;
    std::cout << "Actual:   " << dot(a, b) << std::endl;
}


void vec4CrossTest()
{
    std::cout << "\n=== Cross Product Test ===\n";

    vec4 xAxis(1.0f, 0.0f, 0.0f, 0.0f);
    vec4 yAxis(0.0f, 1.0f, 0.0f, 0.0f);

    std::cout << "Expected: (0, 0, 1, 0)" << std::endl;
    std::cout << "Actual:   " << cross(xAxis, yAxis) << std::endl;
}


void vec4NormalizeTest()
{
    std::cout << "\n=== Normalize Test ===\n";

    vec4 a(3.0f, 0.0f, 0.0f, 4.0f);

    std::cout << "Expected: approximately (0.6, 0, 0, 0.8)" << std::endl;
    std::cout << "Actual:   " << normalize(a) << std::endl;

    std::cout << "Expected normalized length: approximately 1" << std::endl;
    std::cout << "Actual normalized length:   "
         << length(normalize(a))
         << std::endl;
}


// -----------------------------------------------------------------------------
// mat4 Tests
// -----------------------------------------------------------------------------

void mat4ConstructorTests()
{
    std::cout << "\n=== mat4 Constructor Tests ===\n";

    mat4 a;

    std::cout << "\nDefault Constructor Expected:" << std::endl;
    std::cout << "[ 1 0 0 0 ]" << std::endl;
    std::cout << "[ 0 1 0 0 ]" << std::endl;
    std::cout << "[ 0 0 1 0 ]" << std::endl;
    std::cout << "[ 0 0 0 1 ]" << std::endl;

    std::cout << "Actual:" << std::endl;
    std::cout << a << std::endl;


    mat4 b(2.0f);

    std::cout << "\nDiagonal Constructor Expected:" << std::endl;
    std::cout << "[ 2 0 0 0 ]" << std::endl;
    std::cout << "[ 0 2 0 0 ]" << std::endl;
    std::cout << "[ 0 0 2 0 ]" << std::endl;
    std::cout << "[ 0 0 0 2 ]" << std::endl;

    std::cout << "Actual:" << std::endl;
    std::cout << b << std::endl;


    vec4 c0(1, 2, 3, 4);
    vec4 c1(5, 6, 7, 8);
    vec4 c2(9, 10, 11, 12);
    vec4 c3(13, 14, 15, 16);

    mat4 c(c0, c1, c2, c3);

    std::cout << "\nColumn Constructor Expected:" << std::endl;
    std::cout << "[ 1 5 9 13 ]" << std::endl;
    std::cout << "[ 2 6 10 14 ]" << std::endl;
    std::cout << "[ 3 7 11 15 ]" << std::endl;
    std::cout << "[ 4 8 12 16 ]" << std::endl;

    std::cout << "Actual:" << std::endl;
    std::cout << c << std::endl;


    mat4 d(c);

    std::cout << "\nCopy Constructor Expected:" << std::endl;
    std::cout << c << std::endl;

    std::cout << "Actual:" << std::endl;
    std::cout << d << std::endl;
}


void mat4AssignmentTest()
{
    std::cout << "\n=== mat4 Assignment Test ===\n";

    mat4 a(3.0f);
    mat4 b;

    b = a;

    std::cout << "Expected:" << std::endl;
    std::cout << "[ 3 0 0 0 ]" << std::endl;
    std::cout << "[ 0 3 0 0 ]" << std::endl;
    std::cout << "[ 0 0 3 0 ]" << std::endl;
    std::cout << "[ 0 0 0 3 ]" << std::endl;

    std::cout << "Actual:" << std::endl;
    std::cout << b << std::endl;
}


void mat4EqualityTests()
{
    std::cout << "\n=== mat4 Equality Tests ===\n";

    mat4 a;
    mat4 b;
    mat4 c(2.0f);

    std::cout << boolalpha;

    std::cout << "a == b expected: true" << std::endl;
    std::cout << "a == b actual:   " << (a == b) << std::endl;

    std::cout << "a != c expected: true" << std::endl;
    std::cout << "a != c actual:   " << (a != c) << std::endl;
}


void rotationTest1()
{
    std::cout << "\n=== Rotation Test 1: 90 Degrees Around Z ===\n";

    mat4 rotation = mat4::rotate(
        90.0f,
        0.0f,
        0.0f,
        1.0f
        );

    std::cout << "Expected approximately:" << std::endl;
    std::cout << "[ 0 -1 0 0 ]" << std::endl;
    std::cout << "[ 1  0 0 0 ]" << std::endl;
    std::cout << "[ 0  0 1 0 ]" << std::endl;
    std::cout << "[ 0  0 0 1 ]" << std::endl;

    std::cout << "Actual:" << std::endl;
    std::cout << rotation << std::endl;
}


void rotationTest2()
{
    std::cout << "\n=== Rotation Test 2: 180 Degrees Around X ===\n";

    mat4 rotation = mat4::rotate(
        180.0f,
        1.0f,
        0.0f,
        0.0f
        );

    std::cout << "Expected approximately:" << std::endl;
    std::cout << "[ 1  0  0 0 ]" << std::endl;
    std::cout << "[ 0 -1  0 0 ]" << std::endl;
    std::cout << "[ 0  0 -1 0 ]" << std::endl;
    std::cout << "[ 0  0  0 1 ]" << std::endl;

    std::cout << "Actual:" << std::endl;
    std::cout << rotation << std::endl;
}


void translationTest()
{
    std::cout << "\n=== Translation Test ===\n";

    mat4 t = mat4::translate(2.0f, 3.0f, 4.0f);

    std::cout << "Expected:" << std::endl;
    std::cout << "[ 1 0 0 2 ]" << std::endl;
    std::cout << "[ 0 1 0 3 ]" << std::endl;
    std::cout << "[ 0 0 1 4 ]" << std::endl;
    std::cout << "[ 0 0 0 1 ]" << std::endl;

    std::cout << "Actual:" << std::endl;
    std::cout << t << std::endl;
}


void scaleTest()
{
    std::cout << "\n=== Scale Test ===\n";

    mat4 s = mat4::scale(2.0f, 3.0f, 4.0f);

    std::cout << "Expected:" << std::endl;
    std::cout << "[ 2 0 0 0 ]" << std::endl;
    std::cout << "[ 0 3 0 0 ]" << std::endl;
    std::cout << "[ 0 0 4 0 ]" << std::endl;
    std::cout << "[ 0 0 0 1 ]" << std::endl;

    std::cout << "Actual:" << std::endl;
    std::cout << s << std::endl;
}


void matrixMatrixMultiplicationTest()
{
    std::cout << "\n=== Matrix * Matrix Test ===\n";

    mat4 a = mat4::scale(2.0f, 3.0f, 4.0f);
    mat4 b = mat4::translate(1.0f, 2.0f, 3.0f);

    mat4 result = a * b;

    std::cout << "Expected:" << std::endl;
    std::cout << "[ 2 0 0 2 ]" << std::endl;
    std::cout << "[ 0 3 0 6 ]" << std::endl;
    std::cout << "[ 0 0 4 12 ]" << std::endl;
    std::cout << "[ 0 0 0 1 ]" << std::endl;

    std::cout << "Actual:" << std::endl;
    std::cout << result << std::endl;
}


void matrixVectorMultiplicationTest()
{
    std::cout << "\n=== Matrix * Vector Test ===\n";

    mat4 m = mat4::translate(10.0f, 20.0f, 30.0f);

    vec4 v(
        1.0f,
        2.0f,
        3.0f,
        1.0f
        );

    std::cout << "Expected: (11, 22, 33, 1)" << std::endl;
    std::cout << "Actual:   " << (m * v) << std::endl;
}


void vectorMatrixMultiplicationTest()
{
    std::cout << "\n=== Vector * Matrix Test ===\n";

    mat4 m = mat4::scale(
        2.0f,
        3.0f,
        4.0f
        );

    vec4 v(
        1.0f,
        2.0f,
        3.0f,
        1.0f
        );

    std::cout << "Expected: (2, 6, 12, 1)" << std::endl;
    std::cout << "Actual:   " << (v * m) << std::endl;
}


void transposeTest()
{
    std::cout << "\n=== Transpose Test ===\n";

    mat4 m(
        vec4(1, 2, 3, 4),
        vec4(5, 6, 7, 8),
        vec4(9, 10, 11, 12),
        vec4(13, 14, 15, 16)
        );

    std::cout << "Original:" << std::endl;
    std::cout << m << std::endl;

    std::cout << "Expected transpose:" << std::endl;
    std::cout << "[ 1 2 3 4 ]" << std::endl;
    std::cout << "[ 5 6 7 8 ]" << std::endl;
    std::cout << "[ 9 10 11 12 ]" << std::endl;
    std::cout << "[ 13 14 15 16 ]" << std::endl;

    std::cout << "Actual:" << std::endl;
    std::cout << transpose(m) << std::endl;
}

int main() {
	// Example test (won't work until you implement vec4's operator+ and operator<<)
	vec4AddTest();
	// Add your own tests here

    vec4ConstructorTests();
    vec4AssignmentTest();
    vec4EqualityTests();
    vec4ArithmeticTests();
    vec4DotTest();
    vec4CrossTest();
    vec4NormalizeTest();

    mat4ConstructorTests();
    mat4AssignmentTest();
    mat4EqualityTests();
    rotationTest1();
    rotationTest2();
    translationTest();
    scaleTest();
    matrixMatrixMultiplicationTest();
    matrixVectorMultiplicationTest();
    vectorMatrixMultiplicationTest();
    transposeTest();
}
