#include "gtest/gtest.h"
#include "../src/vec.h"

TEST(Vec2Test, Vec2Test_GLFloatConstructor_OneFloat_Test) {
    vec2 v = vec2(6.5f);

    ASSERT_FLOAT_EQ(6.5, v.x);
    ASSERT_FLOAT_EQ(6.5, v.y);
}

TEST(Vec2Test, Vec2Test_GLFloatConstructor_TwoFloat_Test) {
    vec2 v = vec2(2.3f, 5.4f);

    ASSERT_FLOAT_EQ(2.3, v.x);
    ASSERT_FLOAT_EQ(5.4, v.y);
}


TEST(Vec2Test, Vec2Test_Vec2Constuctor_Test) {
    vec2 aux = vec2(1.2f, -1.2f);
    vec2 v = vec2(aux);

    ASSERT_FLOAT_EQ(1.2f, v.x);
    ASSERT_FLOAT_EQ(-1.2f, v.y);
}


TEST(Vec2Test, Vec2Test_NegativeUnaryOperator_Test) {
    vec2 v = vec2(4.3f, -1.2f);
    v = -v;

    ASSERT_FLOAT_EQ(-4.3f, v.x);
    ASSERT_FLOAT_EQ(1.2f, v.y);
}


TEST(Vec2Test, Vec2Test_Vec2Addition_Test) {
    vec2 v1 = vec2(5.4, 1.2);
    vec2 v2 = vec2(-1.2f, -5.4f);
    vec2 v3 = v1 + v2;
    vec2 v4 = v2 + v1;

    ASSERT_FLOAT_EQ(4.2, v3.x);
    ASSERT_FLOAT_EQ(-4.2, v3.y);
    ASSERT_FLOAT_EQ(4.2, v4.x);
    ASSERT_FLOAT_EQ(-4.2, v4.y);
}


TEST(Vec2Test, Vec2Test_Vec2Subtraction_Test) {
    vec2 v1 = vec2(5.4, 1.2);
    vec2 v2 = vec2(-1.2f, -5.4f);
    vec2 v3 = v1 - v2;
    vec2 v4 = v2 - v1;

    ASSERT_FLOAT_EQ(6.6, v3.x);
    ASSERT_FLOAT_EQ(6.6, v3.y);
    ASSERT_FLOAT_EQ(-6.6, v4.x);
    ASSERT_FLOAT_EQ(-6.6, v4.y);
}


TEST(Vec2Test, Vec2Test_Vec2ScalarMultiplication_Test) {
    GLfloat s = 3;
    vec2 v = vec2(5, 4);
    vec2 v2 = v * s;
    vec2 v3 = s * v;

    ASSERT_FLOAT_EQ(15, v2.x);
    ASSERT_FLOAT_EQ(12, v2.y);
    ASSERT_FLOAT_EQ(15, v3.x);
    ASSERT_FLOAT_EQ(12, v3.y);
}

TEST(Vec2Test, Vec2Test_Vec2MultiplicationByVec2__Test) {
    vec2 v1 = vec2(4, 3);
    vec2 v2 = vec2(6, 7);
    vec2 v3 = v1 * v2;
    vec2 v4 = v2 * v1;

    ASSERT_FLOAT_EQ(24, v3.x);
    ASSERT_FLOAT_EQ(21, v3.y);
    ASSERT_FLOAT_EQ(24, v4.x);
    ASSERT_FLOAT_EQ(21, v4.y);
}

TEST(Vec2Test, Vec2Test_Vec2DivisionByFloat_Test) {
    GLfloat s = 5;
    vec2 v = vec2(12, 8);
    vec2 v1 = v / s;

    ASSERT_FLOAT_EQ(2.4, v1.x);
    ASSERT_FLOAT_EQ(1.6, v1.y);
}

TEST(Vec2Test, Vec2Test_Vec2AdditionIncrement_Test) {
    vec2 v1 = vec2(4, 3);
    vec2 v2 = vec2(-1, 4);

    v2 += v1;
    v1 += v2;

    ASSERT_FLOAT_EQ(3, v2.x);
    ASSERT_FLOAT_EQ(7, v2.y);
    ASSERT_FLOAT_EQ(7, v1.x);
    ASSERT_FLOAT_EQ(10, v1.y);
}

TEST(Vec2Test, Vec2Test_Vec2SubtractionIncrement_Test) {
    vec2 v1 = vec2(4, 3);
    vec2 v2 = vec2(-1, 4);

    v2 -= v1;
    v1 -= v2;

    ASSERT_FLOAT_EQ(-5, v2.x);
    ASSERT_FLOAT_EQ(1, v2.y);
    ASSERT_FLOAT_EQ(9, v1.x);
    ASSERT_FLOAT_EQ(2, v1.y);
}

TEST(Vec2Test, Vec2Test_Vec2MultiplicationIncrement_Test) {
    vec2 v1 = vec2(4, 3);
    vec2 v2 = vec2(-1, 4);

    v2 *= v1;
    v1 *= v2;

    ASSERT_FLOAT_EQ(-4, v2.x);
    ASSERT_FLOAT_EQ(12, v2.y);
    ASSERT_FLOAT_EQ(-16, v1.x);
    ASSERT_FLOAT_EQ(36, v1.y);
}

TEST(Vec2Test, Vec2Test_Vec2Dot_Test) {
    vec2 v1 = vec2(2, 3);
    vec2 v2 = vec2(4, 5);

    ASSERT_FLOAT_EQ(23, dot(v1, v2));
}

TEST(Vec2Test, Vec2Test_Vec2Length_Test) {
    vec2 v = vec2(4, -3);

    ASSERT_FLOAT_EQ(5, length(v));
}

TEST(Vec2Test, Vec2Test_Vec2Normalize_Test) {
    vec2 v = vec2(3, 4);
    vec2 n = normalize(v);

    ASSERT_FLOAT_EQ(0.6, n.x);
    ASSERT_FLOAT_EQ(0.8, n.y);
}

TEST(Vec3Test, Vec3Test_ConstructorOneFloat_Test) {
    vec3 v = vec3(8.3);

    ASSERT_FLOAT_EQ(8.3, v.x);
    ASSERT_FLOAT_EQ(8.3, v.y);
    ASSERT_FLOAT_EQ(8.3, v.z);
}

TEST(Vec3Test, Vec3Test_ConstructorThreeFloat_Test) {
    vec3 v = vec3(-3, 43, 1.2);

    ASSERT_FLOAT_EQ(-3, v.x);
    ASSERT_FLOAT_EQ(43, v.y);
    ASSERT_FLOAT_EQ(1.2, v.z);
}

TEST(Vec3Test, Vec3Test_ConstructorVec2_Test) {
    vec3 v1 = vec3(vec2(8, 3), 5);
    vec3 v2 = vec3(vec2(-4, 4.3));

    ASSERT_FLOAT_EQ(8, v1.x);
    ASSERT_FLOAT_EQ(3, v1.y);
    ASSERT_FLOAT_EQ(5, v1.z);
    ASSERT_FLOAT_EQ(-4, v2.x);
    ASSERT_FLOAT_EQ(4.3, v2.y);
    ASSERT_FLOAT_EQ(0, v2.z);
}

TEST(Vec3Test, Vec3Test_ConstructorVec3_Test) {
    vec3 aux = vec3(2, 3, 6);
    vec3 v = vec3(aux);

    ASSERT_FLOAT_EQ(2, v.x);
    ASSERT_FLOAT_EQ(3, v.y);
    ASSERT_FLOAT_EQ(6, v.z);
}

TEST(Vec3Test, Vec3Test_NegativeUnary_Test) {
    vec3 v = vec3(3, 4, -7.5f);
    v = -v;

    ASSERT_FLOAT_EQ(-3, v.x);
    ASSERT_FLOAT_EQ(-4, v.y);
    ASSERT_FLOAT_EQ(7.5, v.z);
}

TEST(Vec3Test, Vec3Test_Vec3Addition_Test) {
    vec3 v1 = vec3(-4, 3, 2.4);
    vec3 v2 = vec3(0.5, -2.3f, 7.5);

    vec3 v3 = v1 + v2;
    vec3 v4 = v2 + v1;

    ASSERT_FLOAT_EQ(-3.5f, v3.x);
    ASSERT_FLOAT_EQ(0.7f, v3.y);
    ASSERT_FLOAT_EQ(9.9f, v3.z);
    ASSERT_FLOAT_EQ(-3.5f, v4.x);
    ASSERT_FLOAT_EQ(0.7f, v4.y);
    ASSERT_FLOAT_EQ(9.9f, v4.z);
}

TEST(Vec3Test, Vec3Test_Vec3Subtraction_Test) {
    vec3 v1 = vec3(8, 3, -3);
    vec3 v2 = vec3(-9, 5, 4);

    vec3 v3 = v1 - v2;
    vec3 v4 = v2 - v1;

    ASSERT_FLOAT_EQ(17, v3.x);
    ASSERT_FLOAT_EQ(-2, v3.y);
    ASSERT_FLOAT_EQ(-7, v3.z);
    ASSERT_FLOAT_EQ(-17, v4.x);
    ASSERT_FLOAT_EQ(2, v4.y);
    ASSERT_FLOAT_EQ(7, v4.z);
}

TEST(Vec3Test, Vec3Test_Vec3ScalarMultiplication_Test) {
    GLfloat s = 5;
    vec3 v1 = vec3(3, 4, 5);

    vec3 v2 = s * v1;
    vec3 v3 = v1 * s;

    ASSERT_FLOAT_EQ(15, v2.x);
    ASSERT_FLOAT_EQ(20, v2.y);
    ASSERT_FLOAT_EQ(25, v2.z);
    ASSERT_FLOAT_EQ(15, v3.x);
    ASSERT_FLOAT_EQ(20, v3.y);
    ASSERT_FLOAT_EQ(25, v3.z);
}


TEST(Vec3Test, Vec3Test_Vec3Multiplication_Test) {
    vec3 v1 = vec3(-2, 4, 5);
    vec3 v2 = vec3(-8, -3, -4);

    vec3 v3 = v1 * v2;
    vec3 v4 = v2 * v1;

    ASSERT_FLOAT_EQ(16, v3.x);
    ASSERT_FLOAT_EQ(-12, v3.y);
    ASSERT_FLOAT_EQ(-20, v3.z);
    ASSERT_FLOAT_EQ(16, v4.x);
    ASSERT_FLOAT_EQ(-12, v4.y);
    ASSERT_FLOAT_EQ(-20, v4.z);
}

TEST(Vec3Test, Vec3Test_Vec3ScalarDivision_Test) {
    GLfloat s = 5;
    vec3 v1 = vec3(10, 11, 3);

    vec3 v2 = v1 / s;

    ASSERT_FLOAT_EQ(2, v2.x);
    ASSERT_FLOAT_EQ(2.2, v2.y);
    ASSERT_FLOAT_EQ(0.6, v2.z);
}

TEST(Vec3Test, Vec3Test_Vec3AdditionIncrement_Test) {
    vec3 v1 = vec3(3, 4, -9);
    vec3 v2 = vec3(-1, 2, 3);

    v1 += v2;
    v2 += v1;

    ASSERT_FLOAT_EQ(2, v1.x);
    ASSERT_FLOAT_EQ(6, v1.y);
    ASSERT_FLOAT_EQ(-6, v1.z);
    ASSERT_FLOAT_EQ(1, v2.x);
    ASSERT_FLOAT_EQ(8, v2.y);
    ASSERT_FLOAT_EQ(-3, v2.z);
}

TEST(Vec3Test, Vec3Test_Vec3SubtractionIncrement_Test) {
    vec3 v1 = vec3(2, -1, 3);
    vec3 v2 = vec3(-2, -3, -1);

    v1 -= v2;
    v2 -= v1;

    ASSERT_FLOAT_EQ(4, v1.x);
    ASSERT_FLOAT_EQ(2, v1.y);
    ASSERT_FLOAT_EQ(4, v1.z);
    ASSERT_FLOAT_EQ(-6, v2.x);
    ASSERT_FLOAT_EQ(-5, v2.y);
    ASSERT_FLOAT_EQ(-5, v2.z);
}

TEST(Vec3Test, Vec3Test_Vec3ScalarMultiplicationIncrement_Test) {
    GLfloat s = 3;
    vec3 v = vec3(1.2, 2.5, -9);

    v *= s;

    ASSERT_FLOAT_EQ(3.6, v.x);
    ASSERT_FLOAT_EQ(7.5, v.y);
    ASSERT_FLOAT_EQ(-27, v.z);
}

TEST(Vec3Test, Vec3Test_Vec3ScalarDivisionIncrement_Test) {
    GLfloat s = -2;
    vec3 v = vec3(1, 5, 4);

    v /= s;

    ASSERT_FLOAT_EQ(-0.5, v.x);
    ASSERT_FLOAT_EQ(-2.5, v.y);
    ASSERT_FLOAT_EQ(-2, v.z);
}

TEST(Vec3Test, Vec3Test_Vec3Dot_Test) {
    vec3 v1 = vec3(3, 5, 6);
    vec3 v2 = vec3(-1, 4, 5);

    GLfloat s = dot(v1, v2);

    ASSERT_FLOAT_EQ(47, s);
}


TEST(Vec3Test, Vec3Test_Vec3Length_Test) {
    vec3 v = vec3(-2, 4, 3);

    GLfloat s = length(v);

    ASSERT_FLOAT_EQ(5.385165, s);
}

TEST(Vec3Test, Vec3Test_Vec3Normalize_Test) {
    vec3 v = vec3(2, 5, 3);

    vec3 n = normalize(v);

    ASSERT_NEAR(0.324443, n.x, 0.000001);
    ASSERT_NEAR(0.811107, n.y, 0.000001);
    ASSERT_NEAR(0.486664, n.z, 0.000001);
}


TEST(Vec4Test, Vec4Test_Vec4ConstructorOneFloat_Test) {
    vec4 v = vec4(9.3);

    ASSERT_FLOAT_EQ(9.3, v.x);
    ASSERT_FLOAT_EQ(9.3, v.y);
    ASSERT_FLOAT_EQ(9.3, v.z);
    ASSERT_FLOAT_EQ(9.3, v.w);
}

TEST(Vec4Test, Vec4Test_Vec4ConstructorFourFloat_Test) {
    vec4 v = vec4(3, 4, 5, -1);

    ASSERT_FLOAT_EQ(3, v.x);
    ASSERT_FLOAT_EQ(4, v.y);
    ASSERT_FLOAT_EQ(5, v.z);
    ASSERT_FLOAT_EQ(-1, v.w);
}

TEST(Vec4Test, Vec4Test_Vec4ConstructorVec3_Test) {
    vec4 v1 = vec4(vec3(2, -0.4f, 1.2), 5);
    vec4 v2 = vec4(vec3(-9, 4, 3));

    ASSERT_FLOAT_EQ(2, v1.x);
    ASSERT_FLOAT_EQ(-0.4f, v1.y);
    ASSERT_FLOAT_EQ(1.2, v1.z);
    ASSERT_FLOAT_EQ(5, v1.w);
    ASSERT_FLOAT_EQ(-9, v2.x);
    ASSERT_FLOAT_EQ(4, v2.y);
    ASSERT_FLOAT_EQ(3, v2.z);
    ASSERT_FLOAT_EQ(0, v2.w);
}

TEST(Vec4Test, Vec4Test_Vec4ConstructorVec4_Test) {
    vec4 aux = vec4(3, -2, 0, 4);
    vec4 v = vec4(aux);

    ASSERT_FLOAT_EQ(3, v.x);
    ASSERT_FLOAT_EQ(-2, v.y);
    ASSERT_FLOAT_EQ(0, v.z);
    ASSERT_FLOAT_EQ(4, v.w);
}

TEST(Vec4Test, Vec4Test_Vec4NegativeUnary_Test) {
    vec4 v = vec4(3, 4, -5, 1);

    v = -v;

    ASSERT_FLOAT_EQ(-3, v.x);
    ASSERT_FLOAT_EQ(-4, v.y);
    ASSERT_FLOAT_EQ(5, v.z);
    ASSERT_FLOAT_EQ(-1, v.w);
}

TEST(Vec4Test, Vec4Test_Vec4Addition_Test) {
    vec4 v1 = vec4(2, -9, 3, 4);
    vec4 v2 = vec4(1, -4, -6, 8);

    vec4 v3 = v1 + v2;
    vec4 v4 = v2 + v1;

    ASSERT_FLOAT_EQ(3, v3.x);
    ASSERT_FLOAT_EQ(-13, v3.y);
    ASSERT_FLOAT_EQ(-3, v3.z);
    ASSERT_FLOAT_EQ(12, v3.w);
    ASSERT_FLOAT_EQ(3, v4.x);
    ASSERT_FLOAT_EQ(-13, v4.y);
    ASSERT_FLOAT_EQ(-3, v4.z);
    ASSERT_FLOAT_EQ(12, v4.w);
}

TEST(Vec4Test, Vec4Test_Vec4Subtration_Test) {
    vec4 v1 = vec4(2, -9, 3, 4);
    vec4 v2 = vec4(1, -4, -6, 8);

    vec4 v3 = v1 - v2;
    vec4 v4 = v2 - v1;

    ASSERT_FLOAT_EQ(1, v3.x);
    ASSERT_FLOAT_EQ(-5, v3.y);
    ASSERT_FLOAT_EQ(9, v3.z);
    ASSERT_FLOAT_EQ(-4, v3.w);
    ASSERT_FLOAT_EQ(-1, v4.x);
    ASSERT_FLOAT_EQ(5, v4.y);
    ASSERT_FLOAT_EQ(-9, v4.z);
    ASSERT_FLOAT_EQ(4, v4.w);
}


TEST(Vec4Test, Vec4Test_Vec4Multiplication_Test) {
    vec4 v1 = vec4(2, -9, 3, 4);
    vec4 v2 = vec4(1, -4, -6, 8);

    vec4 v3 = v1 * v2;
    vec4 v4 = v2 * v1;

    ASSERT_FLOAT_EQ(2, v3.x);
    ASSERT_FLOAT_EQ(36, v3.y);
    ASSERT_FLOAT_EQ(-18, v3.z);
    ASSERT_FLOAT_EQ(32, v3.w);
    ASSERT_FLOAT_EQ(2, v4.x);
    ASSERT_FLOAT_EQ(36, v4.y);
    ASSERT_FLOAT_EQ(-18, v4.z);
    ASSERT_FLOAT_EQ(32, v4.w);
}

TEST(Vec4Test, Vec4Test_Vec4ScalarMultiplication_Test) {
    GLfloat s = 2.5;
    vec4 v1 = vec4(3, 2, 1, 6);

    vec4 v2 = s * v1;
    vec4 v3 = v1 * s;

    ASSERT_FLOAT_EQ(7.5, v2.x);
    ASSERT_FLOAT_EQ(5, v2.y);
    ASSERT_FLOAT_EQ(2.5, v2.z);
    ASSERT_FLOAT_EQ(15, v2.w);
    ASSERT_FLOAT_EQ(7.5, v3.x);
    ASSERT_FLOAT_EQ(5, v3.y);
    ASSERT_FLOAT_EQ(2.5, v3.z);
    ASSERT_FLOAT_EQ(15, v2.w);
}

TEST(Vec4Test, Vec4Test_Vec4ScalarDivision_Test) {
    GLfloat s = 2;
    vec4 v1 = vec4(5, 4, -9, 8);

    vec4 v2 = v1 / s;

    ASSERT_FLOAT_EQ(2.5, v2.x);
    ASSERT_FLOAT_EQ(2, v2.y);
    ASSERT_FLOAT_EQ(-4.5, v2.z);
    ASSERT_FLOAT_EQ(4, v2.w);
}

TEST(Vec4Test, Vec4Test_Vec4AdditionIncrement_Test) {
    vec4 v1 = vec4(-3, -8, 2, 5);
    vec4 v2 = vec4(1, -3, -7, 11);

    v1 += v2;
    v2 += v1;

    ASSERT_FLOAT_EQ(-2, v1.x);
    ASSERT_FLOAT_EQ(-11, v1.y);
    ASSERT_FLOAT_EQ(-5, v1.z);
    ASSERT_FLOAT_EQ(16, v1.w);
    ASSERT_FLOAT_EQ(-1, v2.x);
    ASSERT_FLOAT_EQ(-14, v2.y);
    ASSERT_FLOAT_EQ(-12, v2.z);
    ASSERT_FLOAT_EQ(27, v2.w);
}

TEST(Vec4Test, Vec4Test_Vec4SubtractionIncrement_Test) {
    vec4 v1 = vec4(2, 3, 5, 4);
    vec4 v2 = vec4(-1, 9, 3, 2);

    v1 -= v2;
    v2 -= v1;

    ASSERT_FLOAT_EQ(3, v1.x);
    ASSERT_FLOAT_EQ(-6, v1.y);
    ASSERT_FLOAT_EQ(2, v1.z);
    ASSERT_FLOAT_EQ(2, v1.w);
    ASSERT_FLOAT_EQ(-4, v2.x);
    ASSERT_FLOAT_EQ(15, v2.y);
    ASSERT_FLOAT_EQ(1, v2.z);
    ASSERT_FLOAT_EQ(0, v2.w);
}

TEST(Vec4Test, Vec4Test_Vec4MultiplicationIncrement_Test) {
    vec4 v1 = vec4(2, -1, 3, -2);
    vec4 v2 = vec4(-3, 4, -2, 3);

    v1 *= v2;
    v2 *= v1;

    ASSERT_FLOAT_EQ(-6, v1.x);
    ASSERT_FLOAT_EQ(-4, v1.y);
    ASSERT_FLOAT_EQ(-6, v1.z);
    ASSERT_FLOAT_EQ(-6, v1.w);
    ASSERT_FLOAT_EQ(18, v2.x);
    ASSERT_FLOAT_EQ(-16, v2.y);
    ASSERT_FLOAT_EQ(12, v2.z);
    ASSERT_FLOAT_EQ(-18, v2.w);
}

TEST(Vec4Test, Vec4Test_Vec4ScalarMultiplicationIncrement_Test) {
    GLfloat s = 2;
    vec4 v = vec4(-2, 5, 4, -2.2f);

    v *= s;

    ASSERT_FLOAT_EQ(-4, v.x);
    ASSERT_FLOAT_EQ(10, v.y);
    ASSERT_FLOAT_EQ(8, v.z);
    ASSERT_FLOAT_EQ(-4.4f, v.w);
}

TEST(Vec4Test, Vec4Test_Vec4ScalarDivisionIncrement_Test) {
    GLfloat s = 5;
    vec4 v = vec4(2, 12, 15, 11);

    v /= s;

    ASSERT_FLOAT_EQ(0.4, v.x);
    ASSERT_FLOAT_EQ(2.4, v.y);
    ASSERT_FLOAT_EQ(3, v.z);
    ASSERT_FLOAT_EQ(2.2, v.w);
}

TEST(Vec4Test, Vec4Test_Vec4Dot_Test) {
    vec4 v1 = vec4(2, -1, 4, 3);
    vec4 v2 = vec4(-3, 5, 6, 2);

    GLfloat s = dot(v1, v2);

    ASSERT_FLOAT_EQ(19, s);
}

TEST(Vec4Test, Vec4Test_Vec4Length_Test) {
    vec4 v = vec4(5, 2, -1, 3);

    GLfloat l = length(v);

    ASSERT_NEAR(6.2449988, l, 0.000001);
}

TEST(Vec4Test, Vec4Test_Vec4NormalizeTest) {
    vec4 v = vec4(2, 1, 3, 4);

    vec4 n = normalize(v);

    ASSERT_NEAR(0.365148, n.x, 0.000001);
    ASSERT_NEAR(0.182574, n.y, 0.000001);
    ASSERT_NEAR(0.547723, n.z, 0.000001);
    ASSERT_NEAR(0.730297, n.w, 0.000001);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

