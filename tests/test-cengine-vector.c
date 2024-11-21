#include "../src/vectors/cengine-vector.h"
#include "../src/vectors/cengine-ivec.h"
#include "../src/vectors/cengine-vec2.h"    
#include "../src/vectors/cengine-vec3.h"   
#include "../src/vectors/cengine-vec4.h" 

static void test_vec2_creation() {
    CengineVec2 *vec2 = cengine_vec2_new(1.0, 2.0);

    g_assert_cmpfloat(cengine_vec2_get_x(vec2), ==, 1.0);
    g_assert_cmpfloat(cengine_vec2_get_y(vec2), ==, 2.0);

    cengine_vec2_reset(CENGINE_VEC2(vec2));
    g_assert_cmpfloat(cengine_vec2_get_x(vec2), ==, 0.0);
    g_assert_cmpfloat(cengine_vec2_get_y(vec2), ==, 0.0);

    g_object_unref(vec2);
}

static void test_vec3_creation() {
    CengineVec3 *vec3 = cengine_vec3_new(1.0, 2.0, 3.0);

    g_assert_cmpfloat(cengine_vec3_get_x(vec3), ==, 1.0);
    g_assert_cmpfloat(cengine_vec3_get_y(vec3), ==, 2.0);
    g_assert_cmpfloat(cengine_vec3_get_z(vec3), ==, 3.0);

    cengine_vec3_reset(CENGINE_VEC3(vec3));
    g_assert_cmpfloat(cengine_vec3_get_x(vec3), ==, 0.0);
    g_assert_cmpfloat(cengine_vec3_get_y(vec3), ==, 0.0);
    g_assert_cmpfloat(cengine_vec3_get_z(vec3), ==, 0.0);

    cengine_vec3_swap(CENGINE_VEC3(vec3));
    g_assert_cmpfloat(cengine_vec3_get_x(vec3), ==, 0.0); 
    g_assert_cmpfloat(cengine_vec3_get_y(vec3), ==, 0.0);
    g_assert_cmpfloat(cengine_vec3_get_z(vec3), ==, 0.0);

    g_object_unref(vec3);
}

static void test_vec4_creation() {
    CengineVec4 *vec4 = cengine_vec4_new(1.0, 2.0, 3.0, 4.0);

    g_assert_cmpfloat(cengine_vec4_get_x(vec4), ==, 1.0);
    g_assert_cmpfloat(cengine_vec4_get_y(vec4), ==, 2.0);
    g_assert_cmpfloat(cengine_vec4_get_z(vec4), ==, 3.0);
    g_assert_cmpfloat(cengine_vec4_get_w(vec4), ==, 4.0);

    cengine_vec4_reset(CENGINE_VEC4(vec4));
    g_assert_cmpfloat(cengine_vec4_get_x(vec4), ==, 0.0);
    g_assert_cmpfloat(cengine_vec4_get_y(vec4), ==, 0.0);
    g_assert_cmpfloat(cengine_vec4_get_z(vec4), ==, 0.0);
    g_assert_cmpfloat(cengine_vec4_get_w(vec4), ==, 0.0);

    cengine_vec4_swap(CENGINE_VEC4(vec4));
    g_assert_cmpfloat(cengine_vec4_get_x(vec4), ==, 0.0);
    g_assert_cmpfloat(cengine_vec4_get_y(vec4), ==, 0.0);
    g_assert_cmpfloat(cengine_vec4_get_z(vec4), ==, 0.0);
    g_assert_cmpfloat(cengine_vec4_get_w(vec4), ==, 0.0);

    g_object_unref(vec4);
}

static void test_vec_conversions() {
    CengineVec3 *vec3 = cengine_vec3_new(1.0, 2.0, 3.0);
    CengineVec4 *vec4 = cengine_vec3_to_vec4(CENGINE_VEC3(vec3));

    g_assert_cmpfloat(cengine_vec4_get_x(vec4), ==, 1.0);
    g_assert_cmpfloat(cengine_vec4_get_y(vec4), ==, 2.0);
    g_assert_cmpfloat(cengine_vec4_get_z(vec4), ==, 3.0);
    g_assert_cmpfloat(cengine_vec4_get_w(vec4), ==, 0.0); 

    CengineVec2 *vec2 = cengine_vec3_to_vec2(CENGINE_VEC3(vec3));
    g_assert_cmpfloat(cengine_vec2_get_x(vec2), ==, 1.0);
    g_assert_cmpfloat(cengine_vec2_get_y(vec2), ==, 2.0);

    g_object_unref(vec3);
    g_object_unref(vec4);
    g_object_unref(vec2);
}

static void test_vector_operations() {
    CengineVec4 *vec4 = cengine_vec4_new(1.0, 2.0, 3.0, 4.0);
    CengineVec3 *vec3 = cengine_vec4_to_vec3(CENGINE_VEC4(vec4));
    g_assert_cmpfloat(cengine_vec3_get_x(vec3), ==, 1.0);
    g_assert_cmpfloat(cengine_vec3_get_y(vec3), ==, 2.0);
    g_assert_cmpfloat(cengine_vec3_get_z(vec3), ==, 3.0);

    g_object_unref(vec4);
    g_object_unref(vec3);
}

int main(int argc, char *argv[]) {
    g_test_init(&argc, &argv, NULL);

    g_test_add_func("/vector/vec2/creation", test_vec2_creation);
    g_test_add_func("/vector/vec3/creation", test_vec3_creation);
    g_test_add_func("/vector/vec4/creation", test_vec4_creation);
    g_test_add_func("/vector/conversions", test_vec_conversions);
    g_test_add_func("/vector/operations", test_vector_operations);

    return g_test_run();
}

