#include "cengine-vec4.h"
#include "cengine-vec2.h"
#include "cengine-vec3.h"

struct _CengineVec4 {
    GObject parent_instance;
    gdouble x;
    gdouble y;
    gdouble z;
    gdouble w;
};

static void cengine_vec4_reset(GObject *self) {
    CengineVec4 *vec = CENGINE_VEC4(self);
    vec->x = 0;
    vec->y = 0;
    vec->z = 0;
    vec->w = 0;
}

static void cengine_vec4_swap(GObject *self) {
    CengineVec4 *vec = CENGINE_VEC4(self);
    gdouble temp = vec->x;
    vec->x = vec->w;
    vec->w = temp;

    temp = vec->y;
    vec->y = vec->z;
    vec->z = temp;
}

static GArray* cengine_vec4_get_values(GObject *self) {
    CengineVec4 *vec = CENGINE_VEC4(self);
    GArray *values = g_array_new(FALSE, FALSE, sizeof(gdouble));
    g_array_append_val(values, vec->x);
    g_array_append_val(values, vec->y);
    g_array_append_val(values, vec->z);
    g_array_append_val(values, vec->w);
    return values;
}

static GObject* cengine_vec4_to_vec2(GObject *self) {
    CengineVec4 *vec = CENGINE_VEC4(self);
    return g_object_new(CENGINE_TYPE_VEC2, "x", vec->x, "y", vec->y, NULL);
}

static GObject* cengine_vec4_to_vec3(GObject *self) {
    CengineVec4 *vec = CENGINE_VEC4(self);
    return g_object_new(CENGINE_TYPE_VEC3, "x", vec->x, "y", vec->y, "z", vec->z, NULL);
}

static GObject* cengine_vec4_to_vec4(GObject *self) {
    return g_object_ref(self);
}

static void cengine_vec4_ivec_init(CengineIVecInterface *iface) {
    iface->reset = cengine_vec4_reset;
    iface->swap = cengine_vec4_swap;
    iface->get_values = cengine_vec4_get_values;
    iface->to_vec2 = cengine_vec4_to_vec2;
    iface->to_vec3 = cengine_vec4_to_vec3;
    iface->to_vec4 = cengine_vec4_to_vec4;
}

static void cengine_vec4_class_init(CengineVec4Class *klass) {
    /* Vacío, implementado por la interfaz */
}

static void cengine_vec4_init(CengineVec4 *self) {
    self->x = 0;
    self->y = 0;
    self->z = 0;
    self->w = 0;
}

CengineVec4* cengine_vec4_new(gdouble x, gdouble y, gdouble z, gdouble w) {
    return g_object_new(CENGINE_TYPE_VEC4, "x", x, "y", y, "z", z, "w", w, NULL);
}

gdouble cengine_vec4_get_x(CengineVec4 *self) {
    g_return_val_if_fail(CENGINE_IS_VEC4(self), 0.0);
    return self->x;
}

void cengine_vec4_set_x(CengineVec4 *self, gdouble value) {
    g_return_if_fail(CENGINE_IS_VEC4(self));
    self->x = value;
}

gdouble cengine_vec4_get_y(CengineVec4 *self) {
    g_return_val_if_fail(CENGINE_IS_VEC4(self), 0.0);
    return self->y;
}

void cengine_vec4_set_y(CengineVec4 *self, gdouble value) {
    g_return_if_fail(CENGINE_IS_VEC4(self));
    self->y = value;
}

gdouble cengine_vec4_get_z(CengineVec4 *self) {
    g_return_val_if_fail(CENGINE_IS_VEC4(self), 0.0);
    return self->z;
}

void cengine_vec4_set_z(CengineVec4 *self, gdouble value) {
    g_return_if_fail(CENGINE_IS_VEC4(self));
    self->z = value;
}

gdouble cengine_vec4_get_w(CengineVec4 *self) {
    g_return_val_if_fail(CENGINE_IS_VEC4(self), 0.0);
    return self->w;
}

void cengine_vec4_set_w(CengineVec4 *self, gdouble value) {
    g_return_if_fail(CENGINE_IS_VEC4(self));
    self->w = value;
}

