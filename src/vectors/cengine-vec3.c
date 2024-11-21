#include "cengine-vec2.h"
#include "cengine-vec3.h"
#include "cengine-vec4.h"

struct _CengineVec3 {
    GObject parent_instance;
    gdouble x;
    gdouble y;
    gdouble z;
};

static void cengine_vec3_reset(GObject *self) {
    CengineVec3 *vec = CENGINE_VEC3(self);
    vec->x = 0;
    vec->y = 0;
    vec->z = 0;
}

static void cengine_vec3_swap(GObject *self) {
    CengineVec3 *vec = CENGINE_VEC3(self);
    gdouble temp = vec->x;
    vec->x = vec->z;
    vec->z = temp;
}

static GArray* cengine_vec3_get_values(GObject *self) {
    CengineVec3 *vec = CENGINE_VEC3(self);
    GArray *values = g_array_new(FALSE, FALSE, sizeof(gdouble));
    g_array_append_val(values, vec->x);
    g_array_append_val(values, vec->y);
    g_array_append_val(values, vec->z);
    return values;
}


static GObject* cengine_vec3_to_vec2(GObject *self) {
    CengineVec3 *vec = CENGINE_VEC3(self);
    return g_object_new(CENGINE_TYPE_VEC2, "x", vec->x, "y", vec->y, NULL);
}

static GObject* cengine_vec3_to_vec3(GObject *self) {
    return g_object_ref(self);
}

static GObject* cengine_vec3_to_vec4(GObject *self) {
    CengineVec3 *vec = CENGINE_VEC3(self);
    return g_object_new(CENGINE_TYPE_VEC4, "x", vec->x, "y", vec->y, "z", vec->z, "w", 0.0, NULL);
}

static void cengine_vec3_ivec_init(CengineIVecInterface *iface) {
    iface->reset = cengine_vec3_reset;
    iface->swap = cengine_vec3_swap;
    iface->get_values = cengine_vec3_get_values;
    iface->to_vec2 = cengine_vec3_to_vec2;
    iface->to_vec3 = cengine_vec3_to_vec3;
    iface->to_vec4 = cengine_vec3_to_vec4;
}

static void cengine_vec3_class_init(CengineVec3Class *klass) {
    /* Vacío, implementado por la interfaz */
}

static void cengine_vec3_init(CengineVec3 *self) {
    self->x = 0;
    self->y = 0;
    self->z = 0;
}

CengineVec3* cengine_vec3_new(gdouble x, gdouble y, gdouble z) {
    return g_object_new(CENGINE_TYPE_VEC3, "x", x, "y", y, "z", z, NULL);
}

gdouble cengine_vec3_get_x(CengineVec3 *self) {
    g_return_val_if_fail(CENGINE_IS_VEC3(self), 0.0);
    return self->x;
}

void cengine_vec3_set_x(CengineVec3 *self, gdouble value) {
    g_return_if_fail(CENGINE_IS_VEC3(self));
    self->x = value;
}

gdouble cengine_vec3_get_y(CengineVec3 *self) {
    g_return_val_if_fail(CENGINE_IS_VEC3(self), 0.0);
    return self->y;
}

void cengine_vec3_set_y(CengineVec3 *self, gdouble value) {
    g_return_if_fail(CENGINE_IS_VEC3(self));
    self->y = value;
}

gdouble cengine_vec3_get_z(CengineVec3 *self) {
    g_return_val_if_fail(CENGINE_IS_VEC3(self), 0.0);
    return self->z;
}

void cengine_vec3_set_z(CengineVec3 *self, gdouble value) {
    g_return_if_fail(CENGINE_IS_VEC3(self));
    self->z = value;
}
