#include "gtest/gtest.h"
#include "../src/mat.h"

TEST(Mat2Test, Mat2Test_ConstructorOneGLfloat_Test) {
    mat2 m = mat2(5.4);

    ASSERT_NEAR(5.4, m[0].x, 0.01);
    ASSERT_NEAR(0.0, m[0].y, 0.01);
    ASSERT_NEAR(0.0, m[1].x, 0.01);
    ASSERT_NEAR(5.4, m[1].y, 0.01);
}

TEST(Mat2Test, Mat2Test_ConstructorVec2_Test) {
     vec2 v0 = vec2(2.1, -1.5f);
     vec2 v1 = vec2(1, 2);

    mat2 m = mat2(v0, v1);

    ASSERT_NEAR(2.1, m[0].x, 0.01);
    ASSERT_NEAR(-1.5, m[0].y, 0.01);
    ASSERT_NEAR(1, m[1].x, 0.01);
    ASSERT_NEAR(2, m[1].y, 0.01);
}

TEST(Mat2Test, Mat2Test_ConstructorFourGLfloat_Test) {
    mat2 m = mat2(4.5, 2.3,
                  1.1, 0.2);

    ASSERT_NEAR(4.5, m[0].x, 0.01);
    ASSERT_NEAR(2.3, m[0].y, 0.01);
    ASSERT_NEAR(1.1, m[1].x, 0.01);
    ASSERT_NEAR(0.2, m[1].y, 0.01);
}

TEST(Mat2Test, Mat2Test_ConstructorMat2_Test) {
    mat2 aux = mat2(2, 3,
                    1, 4);

    mat2 m = mat2(aux);

    ASSERT_NEAR(2, m[0].x, 0.01);
    ASSERT_NEAR(3, m[0].y, 0.01);
    ASSERT_NEAR(1, m[1].x, 0.01);
    ASSERT_NEAR(4, m[1].y, 0.01);
}

TEST(Mat2Test, Mat2Test_Additon_Test) {
    mat2 m1 = mat2(vec2(3, 1), vec2(-5, 3));
    mat2 m2 = mat2(vec2(-1, 5), vec2(0, 9));

    mat2 m3 = m1 + m2;
    mat2 m4 = m2 + m1;

    ASSERT_NEAR(2, m3[0].x, 0.01);
    ASSERT_NEAR(6, m3[0].y, 0.01);
    ASSERT_NEAR(-5, m3[1].x, 0.01);
    ASSERT_NEAR(12, m3[1].y, 0.01);

    ASSERT_NEAR(2, m4[0].x, 0.01);
    ASSERT_NEAR(6, m4[0].y, 0.01);
    ASSERT_NEAR(-5, m4[1].x, 0.01);
    ASSERT_NEAR(12, m4[1].y, 0.01);
}

TEST(Mat2Test, Mat2Test_Subtraction_Test) {
    mat2 m1 = mat2(vec2(3, 1), vec2(-5, 3));
    mat2 m2 = mat2(vec2(-1, 5), vec2(0, 9));

    mat2 m3 = m1 - m2;
    mat2 m4 = m2 - m1;

    ASSERT_NEAR(4, m3[0].x, 0.01);
    ASSERT_NEAR(-4, m3[0].y, 0.01);
    ASSERT_NEAR(-5, m3[1].x, 0.01);
    ASSERT_NEAR(-6, m3[1].y, 0.01);

    ASSERT_NEAR(-4, m4[0].x, 0.01);
    ASSERT_NEAR(4, m4[0].y, 0.01);
    ASSERT_NEAR(5, m4[1].x, 0.01);
    ASSERT_NEAR(6, m4[1].y, 0.01);
}

TEST(Mat2Test, Mat2Test_ScalarMultiplication_Test) {
    mat2 m0 = mat2(vec2(4, 5), vec2(-3, -2));
    GLfloat s = 1.5;

    mat2 m1 = m0 * s;
    mat2 m2 = s * m0;

    ASSERT_NEAR(6, m1[0].x, 0.01);
    ASSERT_NEAR(7.5, m1[0].y, 0.01);
    ASSERT_NEAR(-4.5, m1[1].x, 0.01);
    ASSERT_NEAR(-3, m1[1].y, 0.01);

    ASSERT_NEAR(6, m2[0].x, 0.01);
    ASSERT_NEAR(7.5, m2[0].y, 0.01);
    ASSERT_NEAR(-4.5, m2[1].x, 0.01);
    ASSERT_NEAR(-3, m2[1].y, 0.01);
}

TEST(Mat2Test, Mat2Test_MatrixMultiplication_Test) {
    mat2 m1 = mat2(vec2(3, 2), vec2(4, 5));
    mat2 m2 = mat2(vec2(-2, 3), vec2(2, 6));

    mat2 a1 = m1 * m2;
    mat2 a2 = m2 * m1;

    ASSERT_NEAR(-2, a1[0].x, 0.01);
    ASSERT_NEAR(21, a1[0].y, 0.01);
    ASSERT_NEAR(2, a1[1].x, 0.01);
    ASSERT_NEAR(42, a1[1].y, 0.01);

    ASSERT_NEAR(6, a2[0].x, 0.01);
    ASSERT_NEAR(11, a2[0].y, 0.01);
    ASSERT_NEAR(30, a2[1].x, 0.01);
    ASSERT_NEAR(34, a2[1].y, 0.01);
}

TEST(Mat2Test, Mat2Test_ScalarDivision_Test) {
    mat2 m = mat2(vec2(3, 2), vec2(6, 5));
    GLfloat s = 2;

    mat2 a = m / s;

    ASSERT_NEAR(1.5, a[0].x, 0.01);
    ASSERT_NEAR(1, a[0].y, 0.01);
    ASSERT_NEAR(3, a[1].x, 0.01);
    ASSERT_NEAR(2.5, a[1].y, 0.01);
}

TEST(Mat2Test, Mat2Test_AdditionIncrement_Test) {
    mat2 m1 = mat2(vec2(3, 4), vec2(-5, 7));
    mat2 m2 = mat2(vec2(6, -3), vec2(8, 3));

    m1 += m2;
    m2 += m1;

    ASSERT_NEAR(9, m1[0].x, 0.01);
    ASSERT_NEAR(1, m1[0].y, 0.01);
    ASSERT_NEAR(3, m1[1].x, 0.01);
    ASSERT_NEAR(10, m1[1].y, 0.01);

    ASSERT_NEAR(15, m2[0].x, 0.01);
    ASSERT_NEAR(-2, m2[0].y, 0.01);
    ASSERT_NEAR(11, m2[1].x, 0.01);
    ASSERT_NEAR(13, m2[1].y, 0.01);
}

TEST(Mat2Test, Mat2Test_SubtractionIncrement_Test) {
    mat2 m1 = mat2(vec2(2, 4), vec2(-2, 3));
    mat2 m2 = mat2(vec2(-4, 5), vec2(8, 5));

    m1 -= m2;
    m2 -= m1;

    ASSERT_NEAR(6, m1[0].x, 0.01);
    ASSERT_NEAR(-1, m1[0].y, 0.01);
    ASSERT_NEAR(-10, m1[1].x, 0.01);
    ASSERT_NEAR(-2, m1[1].y, 0.01);

    ASSERT_NEAR(-10, m2[0].x, 0.01);
    ASSERT_NEAR(6, m2[0].y, 0.01);
    ASSERT_NEAR(18, m2[1].x, 0.01);
    ASSERT_NEAR(7, m2[1].y, 0.01);
}

TEST(Mat2Test, Mat2Test_ScalarMultiplicationIncrement_Test) {
    mat2 m = mat2(vec2(5, -1.5f), vec2(3.6, -1.7f));
    GLfloat s = 5;

    m *= s;

    ASSERT_NEAR(25, m[0].x, 0.01);
    ASSERT_NEAR(-7.5, m[0].y, 0.01);
    ASSERT_NEAR(18, m[1].x, 0.01);
    ASSERT_NEAR(-8.5, m[1].y, 0.01);
}

TEST(Mat2Test, Mat2Test_ScalarDivisionIncrement_Test) {
    mat2 m = mat2(vec2(5, 11), vec2(-9, -7));
    GLfloat s = 5;

    m /= s;

    ASSERT_NEAR(1, m[0].x, 0.01);
    ASSERT_NEAR(2.2, m[0].y, 0.01);
    ASSERT_NEAR(-1.8, m[1].x, 0.01);
    ASSERT_NEAR(-1.4, m[1].y, 0.01);
}

TEST(Mat2Test, Mat2Test_Vec2Multiplication_Test) {
    mat2 m = mat2(vec2(3, 5), vec2(6, 4));
    vec2 v = vec2(3, -1);

    vec2 a = m * v;

    ASSERT_NEAR(4, a.x, 0.01);
    ASSERT_NEAR(14, a.y, 0.01);
}

TEST(Mat2Test, Mat2Test_MatrixCompMult_Test) {
    mat2 m1 = mat2(vec2(5, 4), vec2(2, 3));
    mat2 m2 = mat2(vec2(3, 2), vec2(-2, -4));

    mat2 a = matrixCompMult(m1, m2);

    ASSERT_NEAR(15, a[0].x, 0.01);
    ASSERT_NEAR(8, a[0].y, 0.01);
    ASSERT_NEAR(-4, a[1].x, 0.01);
    ASSERT_NEAR(-12, a[1].y, 0.01);
}

TEST(Mat2Test, Mat2Test_Transpose_Test) {
    mat2 m = mat2 (vec2(3, 7), vec2(-2, 4));

    mat2 t = transpose(m);

    ASSERT_NEAR(3, t[0].x, 0.01);
    ASSERT_NEAR(-2, t[0].y, 0.01);
    ASSERT_NEAR(7, t[1].x, 0.01);
    ASSERT_NEAR(4, t[1].y, 0.01);
}


TEST(Mat3Test, Mat3Test_ConstructorOneGLfloat_Test) {
    mat3 m = mat3(3.4);

    ASSERT_NEAR(3.4, m[0].x, 0.01);
    ASSERT_NEAR(0.0, m[0].y, 0.01);
    ASSERT_NEAR(0.0, m[0].z, 0.01);
    ASSERT_NEAR(0.0, m[1].x, 0.01);
    ASSERT_NEAR(3.4, m[1].y, 0.01);
    ASSERT_NEAR(0.0, m[1].z, 0.01);
    ASSERT_NEAR(0.0, m[2].x, 0.01);
    ASSERT_NEAR(0.0, m[2].y, 0.01);
    ASSERT_NEAR(3.4, m[2].z, 0.01);
}

TEST(Mat3Test, Mat3Test_ConstructorVec3_Test) {
    mat3 m = mat3(vec3(3, 4, 5), vec3(-1, 2, 3), vec3(-8, 11, 13));

    ASSERT_NEAR(3, m[0].x, 0.01);
    ASSERT_NEAR(4, m[0].y, 0.01);
    ASSERT_NEAR(5, m[0].z, 0.01);
    ASSERT_NEAR(-1, m[1].x, 0.01);
    ASSERT_NEAR(2, m[1].y, 0.01);
    ASSERT_NEAR(3, m[1].z, 0.01);
    ASSERT_NEAR(-8, m[2].x, 0.01);
    ASSERT_NEAR(11, m[2].y, 0.01);
    ASSERT_NEAR(13, m[2].z, 0.01);
}

TEST(Mat3Test, Mat3Test_ConstructorFourGLfloat_Test) {
    mat3 m = mat3( 3,  4,  5,
                  -1,  5, 11,
                   0, 17, -5);

    ASSERT_NEAR(3, m[0].x, 0.01);
    ASSERT_NEAR(4, m[0].y, 0.01);
    ASSERT_NEAR(5, m[0].z, 0.01);
    ASSERT_NEAR(-1, m[1].x, 0.01);
    ASSERT_NEAR(5, m[1].y, 0.01);
    ASSERT_NEAR(11, m[1].z, 0.01);
    ASSERT_NEAR(0, m[2].x, 0.01);
    ASSERT_NEAR(17, m[2].y, 0.01);
    ASSERT_NEAR(-5, m[2].z, 0.01);
}

TEST(Mat3Test, Mat3Test_ConstructorMat3_Test) {
    mat3 m = mat3(vec3(3, 4, 5), vec3(-1, 2, 3), vec3(-8, 11, 13));
    mat3 a = mat3(m);

    ASSERT_NEAR(3, a[0].x, 0.01);
    ASSERT_NEAR(4, a[0].y, 0.01);
    ASSERT_NEAR(5, a[0].z, 0.01);
    ASSERT_NEAR(-1, a[1].x, 0.01);
    ASSERT_NEAR(2, a[1].y, 0.01);
    ASSERT_NEAR(3, a[1].z, 0.01);
    ASSERT_NEAR(-8, a[2].x, 0.01);
    ASSERT_NEAR(11, a[2].y, 0.01);
    ASSERT_NEAR(13, a[2].z, 0.01);
}

TEST(Mat3Test, Mat3Test_Addition_Test) {
    mat3 m1 = mat3(vec3(5, 1, 3), vec3(2, 4, 6), vec3(-3, -2, -1));
    mat3 m2 = mat3(vec3(-2, -3, 0), vec3(5, 6, 7), vec3(9, 10, 3));

    mat3 a1 = m1 + m2;
    mat3 a2 = m2 + m1;

    ASSERT_NEAR(3, a1[0].x, 0.01);
    ASSERT_NEAR(-2, a1[0].y, 0.01);
    ASSERT_NEAR(3, a1[0].z, 0.01);
    ASSERT_NEAR(7, a1[1].x, 0.01);
    ASSERT_NEAR(10, a1[1].y, 0.01);
    ASSERT_NEAR(13, a1[1].z, 0.01);
    ASSERT_NEAR(6, a1[2].x, 0.01);
    ASSERT_NEAR(8, a1[2].y, 0.01);
    ASSERT_NEAR(2, a1[2].z, 0.01);

    ASSERT_NEAR(3, a2[0].x, 0.01);
    ASSERT_NEAR(-2, a2[0].y, 0.01);
    ASSERT_NEAR(3, a2[0].z, 0.01);
    ASSERT_NEAR(7, a2[1].x, 0.01);
    ASSERT_NEAR(10, a2[1].y, 0.01);
    ASSERT_NEAR(13, a2[1].z, 0.01);
    ASSERT_NEAR(6, a2[2].x, 0.01);
    ASSERT_NEAR(8, a2[2].y, 0.01);
    ASSERT_NEAR(2, a2[2].z, 0.01);
}

TEST(Mat3Test, Mat3Test_Subtraction_Test) {
    mat3 m1 = mat3(vec3(5, 1, 3), vec3(2, 4, 6), vec3(-3, -2, -1));
    mat3 m2 = mat3(vec3(-2, -3, 0), vec3(5, 6, 7), vec3(9, 10, 3));

    mat3 a1 = m1 - m2;
    mat3 a2 = m2 - m1;

    ASSERT_NEAR(7, a1[0].x, 0.01);
    ASSERT_NEAR(4, a1[0].y, 0.01);
    ASSERT_NEAR(3, a1[0].z, 0.01);
    ASSERT_NEAR(-3, a1[1].x, 0.01);
    ASSERT_NEAR(-2, a1[1].y, 0.01);
    ASSERT_NEAR(-1, a1[1].z, 0.01);
    ASSERT_NEAR(-12, a1[2].x, 0.01);
    ASSERT_NEAR(-12, a1[2].y, 0.01);
    ASSERT_NEAR(-4, a1[2].z, 0.01);

    ASSERT_NEAR(-7, a2[0].x, 0.01);
    ASSERT_NEAR(-4, a2[0].y, 0.01);
    ASSERT_NEAR(-3, a2[0].z, 0.01);
    ASSERT_NEAR(3, a2[1].x, 0.01);
    ASSERT_NEAR(2, a2[1].y, 0.01);
    ASSERT_NEAR(1, a2[1].z, 0.01);
    ASSERT_NEAR(12, a2[2].x, 0.01);
    ASSERT_NEAR(12, a2[2].y, 0.01);
    ASSERT_NEAR(4, a2[2].z, 0.01);
}

TEST(Mat3Test, Mat3Test_ScalarMultiplication_Test) {
    mat3 m = mat3(vec3(5, 1, 3), vec3(2, 4, 6), vec3(-3, -2, -1));
    GLfloat s = 2;

    mat3 a1 = m * s;
    mat3 a2 = s * m;

    ASSERT_NEAR(10, a1[0].x, 0.01);
    ASSERT_NEAR(2, a1[0].y, 0.01);
    ASSERT_NEAR(6, a1[0].z, 0.01);
    ASSERT_NEAR(4, a1[1].x, 0.01);
    ASSERT_NEAR(8, a1[1].y, 0.01);
    ASSERT_NEAR(12, a1[1].z, 0.01);
    ASSERT_NEAR(-6, a1[2].x, 0.01);
    ASSERT_NEAR(-4, a1[2].y, 0.01);
    ASSERT_NEAR(-2, a1[2].z, 0.01);

    ASSERT_NEAR(10, a2[0].x, 0.01);
    ASSERT_NEAR(2, a2[0].y, 0.01);
    ASSERT_NEAR(6, a2[0].z, 0.01);
    ASSERT_NEAR(4, a2[1].x, 0.01);
    ASSERT_NEAR(8, a2[1].y, 0.01);
    ASSERT_NEAR(12, a2[1].z, 0.01);
    ASSERT_NEAR(-6, a2[2].x, 0.01);
    ASSERT_NEAR(-4, a2[2].y, 0.01);
    ASSERT_NEAR(-2, a2[2].z, 0.01);
}

TEST(Mat3Test, Mat3Test_MatrixMultiplication_Test) {
mat3 m1 = mat3(vec3(5, 1, 3), vec3(2, 4, 6), vec3(-3, -2, -1));
mat3 m2 = mat3(vec3(-2, -3, 0), vec3(5, 6, 7), vec3(9, 10, 3));

mat3 a1 = m1 * m2;
mat3 a2 = m2 * m1;

ASSERT_NEAR(22, a1[0].x, 0.01);
ASSERT_NEAR(21, a1[0].y, 0.01);
ASSERT_NEAR(16, a1[0].z, 0.01);
ASSERT_NEAR(70, a1[1].x, 0.01);
ASSERT_NEAR(78, a1[1].y, 0.01);
ASSERT_NEAR(46, a1[1].z, 0.01);
ASSERT_NEAR(-13, a1[2].x, 0.01);
ASSERT_NEAR(-13, a1[2].y, 0.01);
ASSERT_NEAR(-17, a1[2].z, 0.01);

ASSERT_NEAR(-16, a2[0].x, 0.01);
ASSERT_NEAR(-14, a2[0].y, 0.01);
ASSERT_NEAR(-24, a2[0].z, 0.01);
ASSERT_NEAR(16, a2[1].x, 0.01);
ASSERT_NEAR(15, a2[1].y, 0.01);
ASSERT_NEAR(44, a2[1].z, 0.01);
ASSERT_NEAR(56, a2[2].x, 0.01);
ASSERT_NEAR(43, a2[2].y, 0.01);
ASSERT_NEAR(84, a2[2].z, 0.01);
}

TEST(Mat3Test, Mat3Test_ScalarDivision_Test) {
    mat3 m1 = mat3(vec3(5, 1, 3), vec3(2, 4, 6), vec3(-3, -2, -1));
    GLfloat s = 5;

    mat3 a = m1 / s;


    ASSERT_NEAR(1, a[0].x, 0.01);
    ASSERT_NEAR(0.2, a[0].y, 0.01);
    ASSERT_NEAR(0.6, a[0].z, 0.01);
    ASSERT_NEAR(0.4, a[1].x, 0.01);
    ASSERT_NEAR(0.8, a[1].y, 0.01);
    ASSERT_NEAR(1.2, a[1].z, 0.01);
    ASSERT_NEAR(-0.6, a[2].x, 0.01);
    ASSERT_NEAR(-0.4, a[2].y, 0.01);
    ASSERT_NEAR(-0.2, a[2].z, 0.01);
}

TEST(Mat3Test, Mat3Test_AdditionIncrement_Test) {
    mat3 m1 = mat3(vec3(5, 1, 3), vec3(2, 4, 6), vec3(-3, -2, -1));
    mat3 m2 = mat3(vec3(-2, -3, 0), vec3(5, 6, 7), vec3(9, 10, 3));

    m1 += m2;
    m2 += m1;

    ASSERT_NEAR(3, m1[0].x, 0.01);
    ASSERT_NEAR(-2, m1[0].y, 0.01);
    ASSERT_NEAR(3, m1[0].z, 0.01);
    ASSERT_NEAR(7, m1[1].x, 0.01);
    ASSERT_NEAR(10, m1[1].y, 0.01);
    ASSERT_NEAR(13, m1[1].z, 0.01);
    ASSERT_NEAR(6, m1[2].x, 0.01);
    ASSERT_NEAR(8, m1[2].y, 0.01);
    ASSERT_NEAR(2, m1[2].z, 0.01);

    ASSERT_NEAR(1, m2[0].x, 0.01);
    ASSERT_NEAR(-5, m2[0].y, 0.01);
    ASSERT_NEAR(3, m2[0].z, 0.01);
    ASSERT_NEAR(12, m2[1].x, 0.01);
    ASSERT_NEAR(16, m2[1].y, 0.01);
    ASSERT_NEAR(20, m2[1].z, 0.01);
    ASSERT_NEAR(15, m2[2].x, 0.01);
    ASSERT_NEAR(18, m2[2].y, 0.01);
    ASSERT_NEAR(5, m2[2].z, 0.01);
}

TEST(Mat3Test, Mat3Test_SubtractionIncrement_Test) {
    mat3 m1 = mat3(vec3(5, 1, 3), vec3(2, 4, 6), vec3(-3, -2, -1));
    mat3 m2 = mat3(vec3(-2, -3, 0), vec3(5, 6, 7), vec3(9, 10, 3));

    m1 -= m2;
    m2 -= m1;

    ASSERT_NEAR(7, m1[0].x, 0.01);
    ASSERT_NEAR(4, m1[0].y, 0.01);
    ASSERT_NEAR(3, m1[0].z, 0.01);
    ASSERT_NEAR(-3, m1[1].x, 0.01);
    ASSERT_NEAR(-2, m1[1].y, 0.01);
    ASSERT_NEAR(-1, m1[1].z, 0.01);
    ASSERT_NEAR(-12, m1[2].x, 0.01);
    ASSERT_NEAR(-12, m1[2].y, 0.01);
    ASSERT_NEAR(-4, m1[2].z, 0.01);

    ASSERT_NEAR(-9, m2[0].x, 0.01);
    ASSERT_NEAR(-7, m2[0].y, 0.01);
    ASSERT_NEAR(-3, m2[0].z, 0.01);
    ASSERT_NEAR(8, m2[1].x, 0.01);
    ASSERT_NEAR(8, m2[1].y, 0.01);
    ASSERT_NEAR(8, m2[1].z, 0.01);
    ASSERT_NEAR(21, m2[2].x, 0.01);
    ASSERT_NEAR(22, m2[2].y, 0.01);
    ASSERT_NEAR(7, m2[2].z, 0.01);
}

TEST(Mat3Test, Mat3Test_ScalarMultiplicationIncrement_Test) {
    mat3 m1 = mat3(vec3(5, 1, 3), vec3(2, 4, 6), vec3(-3, -2, -1));
    GLfloat s = 3;

    m1 *= s;

    ASSERT_NEAR(15, m1[0].x, 0.01);
    ASSERT_NEAR(3, m1[0].y, 0.01);
    ASSERT_NEAR(9, m1[0].z, 0.01);
    ASSERT_NEAR(6, m1[1].x, 0.01);
    ASSERT_NEAR(12, m1[1].y, 0.01);
    ASSERT_NEAR(18, m1[1].z, 0.01);
    ASSERT_NEAR(-9, m1[2].x, 0.01);
    ASSERT_NEAR(-6, m1[2].y, 0.01);
    ASSERT_NEAR(-3, m1[2].z, 0.01);
}

TEST(Mat3Test, Mat3Test_ScalarDivisionIncrement_Test) {
    mat3 m1 = mat3(vec3(5, 1, 3), vec3(2, 4, 6), vec3(-3, -2, -1));
    GLfloat s = 2;

    m1 /= s;

    ASSERT_NEAR(2.5, m1[0].x, 0.01);
    ASSERT_NEAR(0.5, m1[0].y, 0.01);
    ASSERT_NEAR(1.5, m1[0].z, 0.01);
    ASSERT_NEAR(1, m1[1].x, 0.01);
    ASSERT_NEAR(2, m1[1].y, 0.01);
    ASSERT_NEAR(3, m1[1].z, 0.01);
    ASSERT_NEAR(-1.5, m1[2].x, 0.01);
    ASSERT_NEAR(-1, m1[2].y, 0.01);
    ASSERT_NEAR(-0.5, m1[2].z, 0.01);
}

TEST(Mat3Test, Mat3Test_Vec3Multiplication_Test) {
    mat3 m = mat3(vec3(4, 2, -1), vec3(2, 4, 9), vec3(-8, 3, 4));
    vec3 v = vec3(5, 7, 9);

    vec3 a = m * v;

    ASSERT_NEAR(25, a.x, 0.01);
    ASSERT_NEAR(119, a.y, 0.01);
    ASSERT_NEAR(17, a.z, 0.01);
}

TEST(Mat3Test, Mat3Test_Transpose_Test) {
    mat3 m = mat3(vec3(5, 1, 3), vec3(2, 4, 6), vec3(-3, -2, -1));

    mat3 m1 = transpose(m);

    ASSERT_NEAR(5, m1[0].x, 0.01);
    ASSERT_NEAR(2, m1[0].y, 0.01);
    ASSERT_NEAR(-3, m1[0].z, 0.01);
    ASSERT_NEAR(1, m1[1].x, 0.01);
    ASSERT_NEAR(4, m1[1].y, 0.01);
    ASSERT_NEAR(-2, m1[1].z, 0.01);
    ASSERT_NEAR(3, m1[2].x, 0.01);
    ASSERT_NEAR(6, m1[2].y, 0.01);
    ASSERT_NEAR(-1, m1[2].z, 0.01);
}

TEST(Mat3Test, Mat3Test_CompMult_Test) {
    mat3 m1 = mat3(vec3(5, 1, 3), vec3(2, 4, 6), vec3(-3, -2, -1));
    mat3 m2 = mat3(vec3(2, 3, 5), vec3(1, 3, 4), vec3(5, 6, 7));

    mat3 a1 = matrixCompMult(m1, m2);

    ASSERT_NEAR(10, a1[0].x, 0.01);
    ASSERT_NEAR(3, a1[0].y, 0.01);
    ASSERT_NEAR(15, a1[0].z, 0.01);
    ASSERT_NEAR(2, a1[1].x, 0.01);
    ASSERT_NEAR(12, a1[1].y, 0.01);
    ASSERT_NEAR(24, a1[1].z, 0.01);
    ASSERT_NEAR(-15, a1[2].x, 0.01);
    ASSERT_NEAR(-12, a1[2].y, 0.01);
    ASSERT_NEAR(-7, a1[2].z, 0.01);
}

TEST(Mat4Test, Mat4Test_ConstructorOneGLfloat_Test) {
    mat4 m = mat4(2.4);

    ASSERT_NEAR(2.4, m[0].x, 0.01);
    ASSERT_NEAR(0.0, m[0].y, 0.01);
    ASSERT_NEAR(0.0, m[0].z, 0.01);
    ASSERT_NEAR(0.0, m[0].w, 0.01);
    ASSERT_NEAR(0.0, m[1].x, 0.01);
    ASSERT_NEAR(2.4, m[1].y, 0.01);
    ASSERT_NEAR(0.0, m[1].z, 0.01);
    ASSERT_NEAR(0.0, m[1].w, 0.01);
    ASSERT_NEAR(0.0, m[2].x, 0.01);
    ASSERT_NEAR(0.0, m[2].y, 0.01);
    ASSERT_NEAR(2.4, m[2].z, 0.01);
    ASSERT_NEAR(0.0, m[2].w, 0.01);
    ASSERT_NEAR(0.0, m[3].x, 0.01);
    ASSERT_NEAR(0.0, m[3].y, 0.01);
    ASSERT_NEAR(0.0, m[3].z, 0.01);
    ASSERT_NEAR(2.4, m[3].w, 0.01);
}

TEST(Mat4Test, Mat4Test_ConstructorVec4_Test) {
    mat4 m = mat4(vec4(1, 2, 3, 4), vec4(-2, 3, -4, 5), vec4(9, 8, 7, 6), vec4(12, 15, 17, 19));

    ASSERT_NEAR(1, m[0].x, 0.01);
    ASSERT_NEAR(2, m[0].y, 0.01);
    ASSERT_NEAR(3, m[0].z, 0.01);
    ASSERT_NEAR(4, m[0].w, 0.01);
    ASSERT_NEAR(-2, m[1].x, 0.01);
    ASSERT_NEAR(3, m[1].y, 0.01);
    ASSERT_NEAR(-4, m[1].z, 0.01);
    ASSERT_NEAR(5, m[1].w, 0.01);
    ASSERT_NEAR(9, m[2].x, 0.01);
    ASSERT_NEAR(8, m[2].y, 0.01);
    ASSERT_NEAR(7, m[2].z, 0.01);
    ASSERT_NEAR(6, m[2].w, 0.01);
    ASSERT_NEAR(12, m[3].x, 0.01);
    ASSERT_NEAR(15, m[3].y, 0.01);
    ASSERT_NEAR(17, m[3].z, 0.01);
    ASSERT_NEAR(19, m[3].w, 0.01);
}

TEST(Mat4Test, Mat4Test_ConstructorFourGLfloat_Test) {
    mat4 m = mat4(2.4, 1.2, 3.6, 8,
                  7, 9, 10, 11,
                  -19, -21, 33, 55,
                  1.9, 5.9, -0.5f, 56);

    ASSERT_NEAR(2.4, m[0].x, 0.01);
    ASSERT_NEAR(1.2, m[0].y, 0.01);
    ASSERT_NEAR(3.6, m[0].z, 0.01);
    ASSERT_NEAR(8, m[0].w, 0.01);
    ASSERT_NEAR(7, m[1].x, 0.01);
    ASSERT_NEAR(9, m[1].y, 0.01);
    ASSERT_NEAR(10, m[1].z, 0.01);
    ASSERT_NEAR(11, m[1].w, 0.01);
    ASSERT_NEAR(-19, m[2].x, 0.01);
    ASSERT_NEAR(-21, m[2].y, 0.01);
    ASSERT_NEAR(33, m[2].z, 0.01);
    ASSERT_NEAR(55, m[2].w, 0.01);
    ASSERT_NEAR(1.9, m[3].x, 0.01);
    ASSERT_NEAR(5.9, m[3].y, 0.01);
    ASSERT_NEAR(-0.5, m[3].z, 0.01);
    ASSERT_NEAR(56, m[3].w, 0.01);
}

TEST(Mat4Test, Mat4Test_ConstructorMat4_Test) {
    mat4 aux = mat4(vec4(1, 2, 3, 4), vec4(-2, -3, -1, -9), vec4(7, 8, 9, 10), vec4(11, -4, -7, 13));
    mat4 m = mat4(aux);

    ASSERT_NEAR(1, m[0].x, 0.01);
    ASSERT_NEAR(2, m[0].y, 0.01);
    ASSERT_NEAR(3, m[0].z, 0.01);
    ASSERT_NEAR(4, m[0].w, 0.01);
    ASSERT_NEAR(-2, m[1].x, 0.01);
    ASSERT_NEAR(-3, m[1].y, 0.01);
    ASSERT_NEAR(-1, m[1].z, 0.01);
    ASSERT_NEAR(-9, m[1].w, 0.01);
    ASSERT_NEAR(7, m[2].x, 0.01);
    ASSERT_NEAR(8, m[2].y, 0.01);
    ASSERT_NEAR(9, m[2].z, 0.01);
    ASSERT_NEAR(10, m[2].w, 0.01);
    ASSERT_NEAR(11, m[3].x, 0.01);
    ASSERT_NEAR(-4, m[3].y, 0.01);
    ASSERT_NEAR(-7, m[3].z, 0.01);
    ASSERT_NEAR(13, m[3].w, 0.01);
}

TEST(Mat4Test, Mat4Test_Addition_Test) {
    mat4 m1 = mat4(vec4(1, 3, 5, 7), vec4(2, 4, 6, 8), vec4(-1, -2, -3, -4), vec4(5, 4, 3, 2));
    mat4 m2 = mat4(vec4(-4, -5, -6, -7), vec4(2, 1, 0 ,-1), vec4(8, 9, 10, 11), vec4(-9, -8, -11, -13));
    
    mat4 a1 = m1 + m2;
    mat4 a2 = m2 + m1;

    ASSERT_NEAR(-3, a1[0].x, 0.01);
    ASSERT_NEAR(-2, a1[0].y, 0.01);
    ASSERT_NEAR(-1, a1[0].z, 0.01);
    ASSERT_NEAR(0, a1[0].w, 0.01);
    ASSERT_NEAR(4, a1[1].x, 0.01);
    ASSERT_NEAR(5, a1[1].y, 0.01);
    ASSERT_NEAR(6, a1[1].z, 0.01);
    ASSERT_NEAR(7, a1[1].w, 0.01);
    ASSERT_NEAR(7, a1[2].x, 0.01);
    ASSERT_NEAR(7, a1[2].y, 0.01);
    ASSERT_NEAR(7, a1[2].z, 0.01);
    ASSERT_NEAR(7, a1[2].w, 0.01);
    ASSERT_NEAR(-4, a1[3].x, 0.01);
    ASSERT_NEAR(-4, a1[3].y, 0.01);
    ASSERT_NEAR(-8, a1[3].z, 0.01);
    ASSERT_NEAR(-11, a1[3].w, 0.01);

    ASSERT_NEAR(-3, a2[0].x, 0.01);
    ASSERT_NEAR(-2, a2[0].y, 0.01);
    ASSERT_NEAR(-1, a2[0].z, 0.01);
    ASSERT_NEAR(0, a2[0].w, 0.01);
    ASSERT_NEAR(4, a2[1].x, 0.01);
    ASSERT_NEAR(5, a2[1].y, 0.01);
    ASSERT_NEAR(6, a2[1].z, 0.01);
    ASSERT_NEAR(7, a2[1].w, 0.01);
    ASSERT_NEAR(7, a2[2].x, 0.01);
    ASSERT_NEAR(7, a2[2].y, 0.01);
    ASSERT_NEAR(7, a2[2].z, 0.01);
    ASSERT_NEAR(7, a2[2].w, 0.01);
    ASSERT_NEAR(-4, a2[3].x, 0.01);
    ASSERT_NEAR(-4, a2[3].y, 0.01);
    ASSERT_NEAR(-8, a2[3].z, 0.01);
    ASSERT_NEAR(-11, a2[3].w, 0.01);
}

TEST(Mat4Test, Mat4Test_Subtraction_Test) {
    mat4 m1 = mat4(vec4(1, 3, 5, 7), vec4(2, 4, 6, 8), vec4(-1, -2, -3, -4), vec4(5, 4, 3, 2));
    mat4 m2 = mat4(vec4(-4, -5, -6, -7), vec4(2, 1, 0 ,-1), vec4(8, 9, 10, 11), vec4(-9, -8, -11, -13));

    mat4 a1 = m1 - m2;
    mat4 a2 = m2 - m1;

    ASSERT_NEAR(5, a1[0].x, 0.01);
    ASSERT_NEAR(8, a1[0].y, 0.01);
    ASSERT_NEAR(11, a1[0].z, 0.01);
    ASSERT_NEAR(14, a1[0].w, 0.01);
    ASSERT_NEAR(0, a1[1].x, 0.01);
    ASSERT_NEAR(3, a1[1].y, 0.01);
    ASSERT_NEAR(6, a1[1].z, 0.01);
    ASSERT_NEAR(9, a1[1].w, 0.01);
    ASSERT_NEAR(-9, a1[2].x, 0.01);
    ASSERT_NEAR(-11, a1[2].y, 0.01);
    ASSERT_NEAR(-13, a1[2].z, 0.01);
    ASSERT_NEAR(-15, a1[2].w, 0.01);
    ASSERT_NEAR(14, a1[3].x, 0.01);
    ASSERT_NEAR(12, a1[3].y, 0.01);
    ASSERT_NEAR(14, a1[3].z, 0.01);
    ASSERT_NEAR(15, a1[3].w, 0.01);

    ASSERT_NEAR(-5, a2[0].x, 0.01);
    ASSERT_NEAR(-8, a2[0].y, 0.01);
    ASSERT_NEAR(-11, a2[0].z, 0.01);
    ASSERT_NEAR(-14, a2[0].w, 0.01);
    ASSERT_NEAR(0, a2[1].x, 0.01);
    ASSERT_NEAR(-3, a2[1].y, 0.01);
    ASSERT_NEAR(-6, a2[1].z, 0.01);
    ASSERT_NEAR(-9, a2[1].w, 0.01);
    ASSERT_NEAR(9, a2[2].x, 0.01);
    ASSERT_NEAR(11, a2[2].y, 0.01);
    ASSERT_NEAR(13, a2[2].z, 0.01);
    ASSERT_NEAR(15, a2[2].w, 0.01);
    ASSERT_NEAR(-14, a2[3].x, 0.01);
    ASSERT_NEAR(-12, a2[3].y, 0.01);
    ASSERT_NEAR(-14, a2[3].z, 0.01);
    ASSERT_NEAR(-15, a2[3].w, 0.01);
}

TEST(Mat4Test, Mat4Test_ScalarMultiplication_Test) {
    mat4 m1 = mat4(vec4(1, 3, 5, 7), vec4(2, 4, 6, 8), vec4(-1, -2, -3, -4), vec4(5, 4, 3, 2));
    GLfloat s = 3;

    mat4 a1 = m1 * s;
    mat4 a2 = s * m1;

    ASSERT_NEAR(3, a1[0].x, 0.01);
    ASSERT_NEAR(9, a1[0].y, 0.01);
    ASSERT_NEAR(15, a1[0].z, 0.01);
    ASSERT_NEAR(21, a1[0].w, 0.01);
    ASSERT_NEAR(6, a1[1].x, 0.01);
    ASSERT_NEAR(12, a1[1].y, 0.01);
    ASSERT_NEAR(18, a1[1].z, 0.01);
    ASSERT_NEAR(24, a1[1].w, 0.01);
    ASSERT_NEAR(-3, a1[2].x, 0.01);
    ASSERT_NEAR(-6, a1[2].y, 0.01);
    ASSERT_NEAR(-9, a1[2].z, 0.01);
    ASSERT_NEAR(-12, a1[2].w, 0.01);
    ASSERT_NEAR(15, a1[3].x, 0.01);
    ASSERT_NEAR(12, a1[3].y, 0.01);
    ASSERT_NEAR(9, a1[3].z, 0.01);
    ASSERT_NEAR(6, a1[3].w, 0.01);

    ASSERT_NEAR(3, a2[0].x, 0.01);
    ASSERT_NEAR(9, a2[0].y, 0.01);
    ASSERT_NEAR(15, a2[0].z, 0.01);
    ASSERT_NEAR(21, a2[0].w, 0.01);
    ASSERT_NEAR(6, a2[1].x, 0.01);
    ASSERT_NEAR(12, a2[1].y, 0.01);
    ASSERT_NEAR(18, a2[1].z, 0.01);
    ASSERT_NEAR(24, a2[1].w, 0.01);
    ASSERT_NEAR(-3, a2[2].x, 0.01);
    ASSERT_NEAR(-6, a2[2].y, 0.01);
    ASSERT_NEAR(-9, a2[2].z, 0.01);
    ASSERT_NEAR(-12, a2[2].w, 0.01);
    ASSERT_NEAR(15, a2[3].x, 0.01);
    ASSERT_NEAR(12, a2[3].y, 0.01);
    ASSERT_NEAR(9, a2[3].z, 0.01);
    ASSERT_NEAR(6, a2[3].w, 0.01);
}

TEST(Mat4Test, Mat4Test_MatrixMultiplication_Test) {
    mat4 m1 = mat4(vec4(1, 3, 5, 7), vec4(2, 4, 6, 8), vec4(-1, -2, -3, -4), vec4(5, 4, 3, 2));
    mat4 m2 = mat4(vec4(-4, -5, -6, -7), vec4(2, 1, 0 ,-1), vec4(8, 9, 10, 11), vec4(-9, -8, -11, -13));

    mat4 a1 = m1 * m2;
    mat4 a2 = m2 * m1;

    ASSERT_NEAR(-21, a1[0].x, 0.01);
    ASSERT_NEAR(-13, a1[0].y, 0.01);
    ASSERT_NEAR(-33, a1[0].z, 0.01);
    ASSERT_NEAR(-46, a1[0].w, 0.01);
    ASSERT_NEAR(-24, a1[1].x, 0.01);
    ASSERT_NEAR(-16, a1[1].y, 0.01);
    ASSERT_NEAR(-40, a1[1].z, 0.01);
    ASSERT_NEAR(-56, a1[1].w, 0.01);
    ASSERT_NEAR(12, a1[2].x, 0.01);
    ASSERT_NEAR(8, a1[2].y, 0.01);
    ASSERT_NEAR(20, a1[2].z, 0.01);
    ASSERT_NEAR(28, a1[2].w, 0.01);
    ASSERT_NEAR(-6, a1[3].x, 0.01);
    ASSERT_NEAR(-10, a1[3].y, 0.01);
    ASSERT_NEAR(-22, a1[3].z, 0.01);
    ASSERT_NEAR(-32, a1[3].w, 0.01);

    ASSERT_NEAR(-43, a2[0].x, 0.01);
    ASSERT_NEAR(-48, a2[0].y, 0.01);
    ASSERT_NEAR(-53, a2[0].z, 0.01);
    ASSERT_NEAR(-58, a2[0].w, 0.01);
    ASSERT_NEAR(-1, a2[1].x, 0.01);
    ASSERT_NEAR(6, a2[1].y, 0.01);
    ASSERT_NEAR(13, a2[1].z, 0.01);
    ASSERT_NEAR(20, a2[1].w, 0.01);
    ASSERT_NEAR(71, a2[2].x, 0.01);
    ASSERT_NEAR(84, a2[2].y, 0.01);
    ASSERT_NEAR(97, a2[2].z, 0.01);
    ASSERT_NEAR(110, a2[2].w, 0.01);
    ASSERT_NEAR(-79, a2[3].x, 0.01);
    ASSERT_NEAR(-89, a2[3].y, 0.01);
    ASSERT_NEAR(-99, a2[3].z, 0.01);
    ASSERT_NEAR(-109, a2[3].w, 0.01);
}

TEST(Mat4Test, Mat4Test_ScalarDivision_Test) {
    mat4 m1 = mat4(vec4(1, 3, 5, 7), vec4(2, 4, 6, 8), vec4(-1, -2, -3, -4), vec4(5, 4, 3, 2));
    GLfloat s = 5;

    mat4 a1 = m1 / s;

    ASSERT_NEAR(0.2, a1[0].x, 0.01);
    ASSERT_NEAR(0.6, a1[0].y, 0.01);
    ASSERT_NEAR(1, a1[0].z, 0.01);
    ASSERT_NEAR(1.4, a1[0].w, 0.01);
    ASSERT_NEAR(0.4, a1[1].x, 0.01);
    ASSERT_NEAR(0.8, a1[1].y, 0.01);
    ASSERT_NEAR(1.2, a1[1].z, 0.01);
    ASSERT_NEAR(1.6, a1[1].w, 0.01);
    ASSERT_NEAR(-0.2, a1[2].x, 0.01);
    ASSERT_NEAR(-0.4, a1[2].y, 0.01);
    ASSERT_NEAR(-0.6, a1[2].z, 0.01);
    ASSERT_NEAR(-0.8, a1[2].w, 0.01);
    ASSERT_NEAR(1, a1[3].x, 0.01);
    ASSERT_NEAR(0.8, a1[3].y, 0.01);
    ASSERT_NEAR(0.6, a1[3].z, 0.01);
    ASSERT_NEAR(0.4, a1[3].w, 0.01);
}

TEST(Mat4Test, Mat4Test_AdditionIncrement_Test) {
    mat4 a1 = mat4(vec4(1, 3, 5, 7), vec4(2, 4, 6, 8), vec4(-1, -2, -3, -4), vec4(5, 4, 3, 2));
    mat4 a2 = mat4(vec4(-4, -5, -6, -7), vec4(2, 1, 0 ,-1), vec4(8, 9, 10, 11), vec4(-9, -8, -11, -13));

    a1 += a2;
    a2 += a1;

    ASSERT_NEAR(-3, a1[0].x, 0.01);
    ASSERT_NEAR(-2, a1[0].y, 0.01);
    ASSERT_NEAR(-1, a1[0].z, 0.01);
    ASSERT_NEAR(0, a1[0].w, 0.01);
    ASSERT_NEAR(4, a1[1].x, 0.01);
    ASSERT_NEAR(5, a1[1].y, 0.01);
    ASSERT_NEAR(6, a1[1].z, 0.01);
    ASSERT_NEAR(7, a1[1].w, 0.01);
    ASSERT_NEAR(7, a1[2].x, 0.01);
    ASSERT_NEAR(7, a1[2].y, 0.01);
    ASSERT_NEAR(7, a1[2].z, 0.01);
    ASSERT_NEAR(7, a1[2].w, 0.01);
    ASSERT_NEAR(-4, a1[3].x, 0.01);
    ASSERT_NEAR(-4, a1[3].y, 0.01);
    ASSERT_NEAR(-8, a1[3].z, 0.01);
    ASSERT_NEAR(-11, a1[3].w, 0.01);

    ASSERT_NEAR(-7, a2[0].x, 0.01);
    ASSERT_NEAR(-7, a2[0].y, 0.01);
    ASSERT_NEAR(-7, a2[0].z, 0.01);
    ASSERT_NEAR(-7, a2[0].w, 0.01);
    ASSERT_NEAR(6, a2[1].x, 0.01);
    ASSERT_NEAR(6, a2[1].y, 0.01);
    ASSERT_NEAR(6, a2[1].z, 0.01);
    ASSERT_NEAR(6, a2[1].w, 0.01);
    ASSERT_NEAR(15, a2[2].x, 0.01);
    ASSERT_NEAR(16, a2[2].y, 0.01);
    ASSERT_NEAR(17, a2[2].z, 0.01);
    ASSERT_NEAR(18, a2[2].w, 0.01);
    ASSERT_NEAR(-13, a2[3].x, 0.01);
    ASSERT_NEAR(-12, a2[3].y, 0.01);
    ASSERT_NEAR(-19, a2[3].z, 0.01);
    ASSERT_NEAR(-24, a2[3].w, 0.01);
}

TEST(Mat4Test, Mat4Test_SubtractionIncrement_Test) {
    mat4 a1 = mat4(vec4(1, 3, 5, 7), vec4(2, 4, 6, 8), vec4(-1, -2, -3, -4), vec4(5, 4, 3, 2));
    mat4 a2 = mat4(vec4(-4, -5, -6, -7), vec4(2, 1, 0 ,-1), vec4(8, 9, 10, 11), vec4(-9, -8, -11, -13));

    a1 -= a2;
    a2 -= a1;

    ASSERT_NEAR(5, a1[0].x, 0.01);
    ASSERT_NEAR(8, a1[0].y, 0.01);
    ASSERT_NEAR(11, a1[0].z, 0.01);
    ASSERT_NEAR(14, a1[0].w, 0.01);
    ASSERT_NEAR(0, a1[1].x, 0.01);
    ASSERT_NEAR(3, a1[1].y, 0.01);
    ASSERT_NEAR(6, a1[1].z, 0.01);
    ASSERT_NEAR(9, a1[1].w, 0.01);
    ASSERT_NEAR(-9, a1[2].x, 0.01);
    ASSERT_NEAR(-11, a1[2].y, 0.01);
    ASSERT_NEAR(-13, a1[2].z, 0.01);
    ASSERT_NEAR(-15, a1[2].w, 0.01);
    ASSERT_NEAR(14, a1[3].x, 0.01);
    ASSERT_NEAR(12, a1[3].y, 0.01);
    ASSERT_NEAR(14, a1[3].z, 0.01);
    ASSERT_NEAR(15, a1[3].w, 0.01);

    ASSERT_NEAR(-9, a2[0].x, 0.01);
    ASSERT_NEAR(-13, a2[0].y, 0.01);
    ASSERT_NEAR(-17, a2[0].z, 0.01);
    ASSERT_NEAR(-21, a2[0].w, 0.01);
    ASSERT_NEAR(2, a2[1].x, 0.01);
    ASSERT_NEAR(-2, a2[1].y, 0.01);
    ASSERT_NEAR(-6, a2[1].z, 0.01);
    ASSERT_NEAR(-10, a2[1].w, 0.01);
    ASSERT_NEAR(17, a2[2].x, 0.01);
    ASSERT_NEAR(20, a2[2].y, 0.01);
    ASSERT_NEAR(23, a2[2].z, 0.01);
    ASSERT_NEAR(26, a2[2].w, 0.01);
    ASSERT_NEAR(-23, a2[3].x, 0.01);
    ASSERT_NEAR(-20, a2[3].y, 0.01);
    ASSERT_NEAR(-25, a2[3].z, 0.01);
    ASSERT_NEAR(-28, a2[3].w, 0.01);
}

TEST(Mat4Test, Mat4Test_ScalarMultiplicationIncrement_Test) {
    mat4 a1 = mat4(vec4(1, 3, 5, 7), vec4(2, 4, 6, 8), vec4(-1, -2, -3, -4), vec4(5, 4, 3, 2));
    GLfloat s = 3;

    a1 *= s;

    ASSERT_NEAR(3, a1[0].x, 0.01);
    ASSERT_NEAR(9, a1[0].y, 0.01);
    ASSERT_NEAR(15, a1[0].z, 0.01);
    ASSERT_NEAR(21, a1[0].w, 0.01);
    ASSERT_NEAR(6, a1[1].x, 0.01);
    ASSERT_NEAR(12, a1[1].y, 0.01);
    ASSERT_NEAR(18, a1[1].z, 0.01);
    ASSERT_NEAR(24, a1[1].w, 0.01);
    ASSERT_NEAR(-3, a1[2].x, 0.01);
    ASSERT_NEAR(-6, a1[2].y, 0.01);
    ASSERT_NEAR(-9, a1[2].z, 0.01);
    ASSERT_NEAR(-12, a1[2].w, 0.01);
    ASSERT_NEAR(15, a1[3].x, 0.01);
    ASSERT_NEAR(12, a1[3].y, 0.01);
    ASSERT_NEAR(9, a1[3].z, 0.01);
    ASSERT_NEAR(6, a1[3].w, 0.01);
}

TEST(Mat4Test, Mat4Test_ScalarDivisionIncrement_Test) {
    mat4 a1 = mat4(vec4(1, 3, 5, 7), vec4(2, 4, 6, 8), vec4(-1, -2, -3, -4), vec4(5, 4, 3, 2));
    GLfloat s = 2;

    a1 /= s;

    ASSERT_NEAR(0.5, a1[0].x, 0.01);
    ASSERT_NEAR(1.5, a1[0].y, 0.01);
    ASSERT_NEAR(2.5, a1[0].z, 0.01);
    ASSERT_NEAR(3.5, a1[0].w, 0.01);
    ASSERT_NEAR(1, a1[1].x, 0.01);
    ASSERT_NEAR(2, a1[1].y, 0.01);
    ASSERT_NEAR(3, a1[1].z, 0.01);
    ASSERT_NEAR(4, a1[1].w, 0.01);
    ASSERT_NEAR(-0.5, a1[2].x, 0.01);
    ASSERT_NEAR(-1, a1[2].y, 0.01);
    ASSERT_NEAR(-1.5, a1[2].z, 0.01);
    ASSERT_NEAR(-2, a1[2].w, 0.01);
    ASSERT_NEAR(2.5, a1[3].x, 0.01);
    ASSERT_NEAR(2, a1[3].y, 0.01);
    ASSERT_NEAR(1.5, a1[3].z, 0.01);
    ASSERT_NEAR(1, a1[3].w, 0.01);
}

TEST(Mat4Test, Mat4Test_VectorMultiplication_Test) {
    mat4 m1 = mat4(vec4(1, 3, 5, 7), vec4(2, 4, 6, 8), vec4(-1, -2, -3, -4), vec4(5, 4, 3, 2));
    vec4 v = vec4(3, 4, 5, 6);

    vec4 a1 = m1 * v;

    ASSERT_NEAR(82, a1.x, 0.01);
    ASSERT_NEAR(100, a1.y, 0.01);
    ASSERT_NEAR(-50, a1.z, 0.01);
    ASSERT_NEAR(58, a1.w, 0.01);
}

TEST(Mat4Test, Mat4Test_CompMult_Test) {
    mat4 m1 = mat4(vec4(1, 3, 5, 7), vec4(2, 4, 6, 8), vec4(-1, -2, -3, -4), vec4(5, 4, 3, 2));
    mat4 m2 = mat4(vec4(-4, -5, -6, -7), vec4(2, 1, 0 ,-1), vec4(8, 9, 10, 11), vec4(-9, -8, -11, -13));

    mat4 a1 = matrixCompMult(m1, m2);

    ASSERT_NEAR(-4, a1[0].x, 0.01);
    ASSERT_NEAR(-15, a1[0].y, 0.01);
    ASSERT_NEAR(-30, a1[0].z, 0.01);
    ASSERT_NEAR(-49, a1[0].w, 0.01);
    ASSERT_NEAR(4, a1[1].x, 0.01);
    ASSERT_NEAR(4, a1[1].y, 0.01);
    ASSERT_NEAR(0, a1[1].z, 0.01);
    ASSERT_NEAR(-8, a1[1].w, 0.01);
    ASSERT_NEAR(-8, a1[2].x, 0.01);
    ASSERT_NEAR(-18, a1[2].y, 0.01);
    ASSERT_NEAR(-30, a1[2].z, 0.01);
    ASSERT_NEAR(-44, a1[2].w, 0.01);
    ASSERT_NEAR(-45, a1[3].x, 0.01);
    ASSERT_NEAR(-32, a1[3].y, 0.01);
    ASSERT_NEAR(-33, a1[3].z, 0.01);
    ASSERT_NEAR(-26, a1[3].w, 0.01);
}

TEST(Mat4Test, Mat4Test_Transpose_Test) {
    mat4 m1 = mat4(vec4(1, 3, 5, 7), vec4(2, 4, 6, 8), vec4(-1, -2, -3, -4), vec4(5, 4, 3, 2));

    mat4 a1 = transpose(m1);

    ASSERT_NEAR(1, a1[0].x, 0.01);
    ASSERT_NEAR(2, a1[0].y, 0.01);
    ASSERT_NEAR(-1, a1[0].z, 0.01);
    ASSERT_NEAR(5, a1[0].w, 0.01);
    ASSERT_NEAR(3, a1[1].x, 0.01);
    ASSERT_NEAR(4, a1[1].y, 0.01);
    ASSERT_NEAR(-2, a1[1].z, 0.01);
    ASSERT_NEAR(4, a1[1].w, 0.01);
    ASSERT_NEAR(5, a1[2].x, 0.01);
    ASSERT_NEAR(6, a1[2].y, 0.01);
    ASSERT_NEAR(-3, a1[2].z, 0.01);
    ASSERT_NEAR(3, a1[2].w, 0.01);
    ASSERT_NEAR(7, a1[3].x, 0.01);
    ASSERT_NEAR(8, a1[3].y, 0.01);
    ASSERT_NEAR(-4, a1[3].z, 0.01);
    ASSERT_NEAR(2, a1[3].w, 0.01);
}

TEST(RotateTest, RotateTest_RotateX_Test) {
    GLfloat theta = 50;

    mat4 a = RotateX(theta);

    ASSERT_NEAR(1, a[0].x, 0.01);
    ASSERT_NEAR(0, a[0].y, 0.01);
    ASSERT_NEAR(0, a[0].z, 0.01);
    ASSERT_NEAR(0, a[0].w, 0.01);
    ASSERT_NEAR(0, a[1].x, 0.01);
    ASSERT_NEAR(0.6427876, a[1].y, 0.000001);
    ASSERT_NEAR(-0.7660444, a[1].z, 0.000001);
    ASSERT_NEAR(0, a[1].w, 0.01);
    ASSERT_NEAR(0, a[2].x, 0.01);
    ASSERT_NEAR(0.7660444, a[2].y, 0.000001);
    ASSERT_NEAR(0.6427876, a[2].z, 0.000001);
    ASSERT_NEAR(0, a[2].w, 0.01);
    ASSERT_NEAR(0, a[3].x, 0.01);
    ASSERT_NEAR(0, a[3].y, 0.01);
    ASSERT_NEAR(0, a[3].z, 0.01);
    ASSERT_NEAR(1, a[3].w, 0.01);
}

TEST(RotateTest, RotateTest_RotateY_Test) {
    GLfloat theta = 50;

    mat4 a = RotateY(theta);

    ASSERT_NEAR(0.6427876, a[0].x, 0.000001);
    ASSERT_NEAR(0, a[0].y, 0.01);
    ASSERT_NEAR(0.766044, a[0].z, 0.000001);
    ASSERT_NEAR(0, a[0].w, 0.01);
    ASSERT_NEAR(0, a[1].x, 0.01);
    ASSERT_NEAR(1, a[1].y, 0.000001);
    ASSERT_NEAR(0, a[1].z, 0.000001);
    ASSERT_NEAR(0, a[1].w, 0.01);
    ASSERT_NEAR(-0.7660444, a[2].x, 0.000001);
    ASSERT_NEAR(0, a[2].y, 0.000001);
    ASSERT_NEAR(0.6427876, a[2].z, 0.000001);
    ASSERT_NEAR(0, a[2].w, 0.01);
    ASSERT_NEAR(0, a[3].x, 0.01);
    ASSERT_NEAR(0, a[3].y, 0.01);
    ASSERT_NEAR(0, a[3].z, 0.01);
    ASSERT_NEAR(1, a[3].w, 0.01);
}


TEST(RotateTest, RotateTest_RotateZ_Test) {
    GLfloat theta = 50;

    mat4 a = RotateZ(theta);

    ASSERT_NEAR(0.6427876, a[0].x, 0.000001);
    ASSERT_NEAR(-0.766044, a[0].y, 0.000001);
    ASSERT_NEAR(0, a[0].z, 0.01);
    ASSERT_NEAR(0, a[0].w, 0.01);
    ASSERT_NEAR(0.766044, a[1].x, 0.000001);
    ASSERT_NEAR(0.6427876, a[1].y, 0.000001);
    ASSERT_NEAR(0, a[1].z, 0.01);
    ASSERT_NEAR(0, a[1].w, 0.01);
    ASSERT_NEAR(0, a[2].x, 0.01);
    ASSERT_NEAR(0, a[2].y, 0.01);
    ASSERT_NEAR(1, a[2].z, 0.01);
    ASSERT_NEAR(0, a[2].w, 0.01);
    ASSERT_NEAR(0, a[3].x, 0.01);
    ASSERT_NEAR(0, a[3].y, 0.01);
    ASSERT_NEAR(0, a[3].z, 0.01);
    ASSERT_NEAR(1, a[3].w, 0.01);
}

TEST(ScaleTest, ScaleTest_ThreeGLfloat_Test) {
    mat4 a = Scale(2, 4, 5);

    ASSERT_NEAR(2, a[0].x, 0.01);
    ASSERT_NEAR(0, a[0].y, 0.01);
    ASSERT_NEAR(0, a[0].z, 0.01);
    ASSERT_NEAR(0, a[0].w, 0.01);
    ASSERT_NEAR(0, a[1].x, 0.01);
    ASSERT_NEAR(4, a[1].y, 0.01);
    ASSERT_NEAR(0, a[1].z, 0.01);
    ASSERT_NEAR(0, a[1].w, 0.01);
    ASSERT_NEAR(0, a[2].x, 0.01);
    ASSERT_NEAR(0, a[2].y, 0.01);
    ASSERT_NEAR(5, a[2].z, 0.01);
    ASSERT_NEAR(0, a[2].w, 0.01);
    ASSERT_NEAR(0, a[3].x, 0.01);
    ASSERT_NEAR(0, a[3].y, 0.01);
    ASSERT_NEAR(0, a[3].z, 0.01);
    ASSERT_NEAR(1, a[3].w, 0.01);
}


TEST(ScaleTest, ScaleTest_Vec3_Test) {
    vec3 v = vec3(2, 4, 5);
    mat4 a = Scale(v);

    ASSERT_NEAR(2, a[0].x, 0.01);
    ASSERT_NEAR(0, a[0].y, 0.01);
    ASSERT_NEAR(0, a[0].z, 0.01);
    ASSERT_NEAR(0, a[0].w, 0.01);
    ASSERT_NEAR(0, a[1].x, 0.01);
    ASSERT_NEAR(4, a[1].y, 0.01);
    ASSERT_NEAR(0, a[1].z, 0.01);
    ASSERT_NEAR(0, a[1].w, 0.01);
    ASSERT_NEAR(0, a[2].x, 0.01);
    ASSERT_NEAR(0, a[2].y, 0.01);
    ASSERT_NEAR(5, a[2].z, 0.01);
    ASSERT_NEAR(0, a[2].w, 0.01);
    ASSERT_NEAR(0, a[3].x, 0.01);
    ASSERT_NEAR(0, a[3].y, 0.01);
    ASSERT_NEAR(0, a[3].z, 0.01);
    ASSERT_NEAR(1, a[3].w, 0.01);
}


TEST(TranslateTest, TranslateTest_FourGLFloat_Test) {
    mat4 a = Translate(2, 7, -1);

    ASSERT_NEAR(1, a[0].x, 0.01);
    ASSERT_NEAR(0, a[0].y, 0.01);
    ASSERT_NEAR(0, a[0].z, 0.01);
    ASSERT_NEAR(2, a[0].w, 0.01);
    ASSERT_NEAR(0, a[1].x, 0.01);
    ASSERT_NEAR(1, a[1].y, 0.01);
    ASSERT_NEAR(0, a[1].z, 0.01);
    ASSERT_NEAR(7, a[1].w, 0.01);
    ASSERT_NEAR(0, a[2].x, 0.01);
    ASSERT_NEAR(0, a[2].y, 0.01);
    ASSERT_NEAR(1, a[2].z, 0.01);
    ASSERT_NEAR(-1, a[2].w, 0.01);
    ASSERT_NEAR(0, a[3].x, 0.01);
    ASSERT_NEAR(0, a[3].y, 0.01);
    ASSERT_NEAR(0, a[3].z, 0.01);
    ASSERT_NEAR(1, a[3].w, 0.01);
}

TEST(TranslateTest, TranslateTest_Vec3_Test) {
    vec3 v = vec3(2, 7, -1);
    mat4 a = Translate(v);

    ASSERT_NEAR(1, a[0].x, 0.01);
    ASSERT_NEAR(0, a[0].y, 0.01);
    ASSERT_NEAR(0, a[0].z, 0.01);
    ASSERT_NEAR(2, a[0].w, 0.01);
    ASSERT_NEAR(0, a[1].x, 0.01);
    ASSERT_NEAR(1, a[1].y, 0.01);
    ASSERT_NEAR(0, a[1].z, 0.01);
    ASSERT_NEAR(7, a[1].w, 0.01);
    ASSERT_NEAR(0, a[2].x, 0.01);
    ASSERT_NEAR(0, a[2].y, 0.01);
    ASSERT_NEAR(1, a[2].z, 0.01);
    ASSERT_NEAR(-1, a[2].w, 0.01);
    ASSERT_NEAR(0, a[3].x, 0.01);
    ASSERT_NEAR(0, a[3].y, 0.01);
    ASSERT_NEAR(0, a[3].z, 0.01);
    ASSERT_NEAR(1, a[3].w, 0.01);
}

TEST(TranslateTest, TranslateTest_Vec4_Test) {
    vec4 v = vec4(2, 7, -1, 11);
    mat4 a = Translate(v);

    ASSERT_NEAR(1, a[0].x, 0.01);
    ASSERT_NEAR(0, a[0].y, 0.01);
    ASSERT_NEAR(0, a[0].z, 0.01);
    ASSERT_NEAR(2, a[0].w, 0.01);
    ASSERT_NEAR(0, a[1].x, 0.01);
    ASSERT_NEAR(1, a[1].y, 0.01);
    ASSERT_NEAR(0, a[1].z, 0.01);
    ASSERT_NEAR(7, a[1].w, 0.01);
    ASSERT_NEAR(0, a[2].x, 0.01);
    ASSERT_NEAR(0, a[2].y, 0.01);
    ASSERT_NEAR(1, a[2].z, 0.01);
    ASSERT_NEAR(-1, a[2].w, 0.01);
    ASSERT_NEAR(0, a[3].x, 0.01);
    ASSERT_NEAR(0, a[3].y, 0.01);
    ASSERT_NEAR(0, a[3].z, 0.01);
    ASSERT_NEAR(1, a[3].w, 0.01);
}

TEST(OrthoTest, OrthoTest_Ortho_Test) {
    mat4 a = Ortho(-1, 2, -2, 3, -4, 5);

    ASSERT_NEAR(0.667, a[0].x, 0.01);
    ASSERT_NEAR(0, a[0].y, 0.01);
    ASSERT_NEAR(0, a[0].z, 0.01);
    ASSERT_NEAR(-0.333, a[0].w, 0.01);
    ASSERT_NEAR(0, a[1].x, 0.01);
    ASSERT_NEAR(0.4, a[1].y, 0.01);
    ASSERT_NEAR(0, a[1].z, 0.01);
    ASSERT_NEAR(-0.2, a[1].w, 0.01);
    ASSERT_NEAR(0, a[2].x, 0.01);
    ASSERT_NEAR(0, a[2].y, 0.01);
    ASSERT_NEAR(-0.222, a[2].z, 0.01);
    ASSERT_NEAR(-0.111, a[2].w, 0.01);
    ASSERT_NEAR(0, a[3].x, 0.01);
    ASSERT_NEAR(0, a[3].y, 0.01);
    ASSERT_NEAR(0, a[3].z, 0.01);
    ASSERT_NEAR(1, a[3].w, 0.01);
}

TEST(OrthoTest, OrthoTest_Ortho2D_Test) {
    mat4 a = Ortho2D(-1, 2, -2, 3);

    ASSERT_NEAR(0.667, a[0].x, 0.01);
    ASSERT_NEAR(0, a[0].y, 0.01);
    ASSERT_NEAR(0, a[0].z, 0.01);
    ASSERT_NEAR(-0.333, a[0].w, 0.01);
    ASSERT_NEAR(0, a[1].x, 0.01);
    ASSERT_NEAR(0.4, a[1].y, 0.01);
    ASSERT_NEAR(0, a[1].z, 0.01);
    ASSERT_NEAR(-0.2, a[1].w, 0.01);
    ASSERT_NEAR(0, a[2].x, 0.01);
    ASSERT_NEAR(0, a[2].y, 0.01);
    ASSERT_NEAR(-1, a[2].z, 0.01);
    ASSERT_NEAR(0, a[2].w, 0.01);
    ASSERT_NEAR(0, a[3].x, 0.01);
    ASSERT_NEAR(0, a[3].y, 0.01);
    ASSERT_NEAR(0, a[3].z, 0.01);
    ASSERT_NEAR(1, a[3].w, 0.01);
}

TEST(PerspectiveTest, PerspectiveTest_Perspective_Test) {
    mat4 a = Perspective(30.0f, 2.5f, -2.0f, 1.0f);

    ASSERT_NEAR(1.493, a[0].x, 0.01);
    ASSERT_NEAR(0, a[0].y, 0.01);
    ASSERT_NEAR(0, a[0].z, 0.01);
    ASSERT_NEAR(0, a[0].w, 0.01);
    ASSERT_NEAR(0, a[1].x, 0.01);
    ASSERT_NEAR(3.732, a[1].y, 0.01);
    ASSERT_NEAR(0, a[1].z, 0.01);
    ASSERT_NEAR(0, a[1].w, 0.01);
    ASSERT_NEAR(0, a[2].x, 0.01);
    ASSERT_NEAR(0, a[2].y, 0.01);
    ASSERT_NEAR(0.333, a[2].z, 0.01);
    ASSERT_NEAR(1.333, a[2].w, 0.01);
    ASSERT_NEAR(0, a[3].x, 0.01);
    ASSERT_NEAR(0, a[3].y, 0.01);
    ASSERT_NEAR(-1.0f, a[3].z, 0.01);
    ASSERT_NEAR(0, a[3].w, 0.01);
}


