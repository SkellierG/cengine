#include "cengine-vec2.h"
#include "cengine-vec3.h"
#include "cengine-vec4.h"

struct _CengineVec3 {
    GObject parent_instance;
    gdouble x;
    gdouble y;
    gdouble z;
};

void cengine_vec3_reset(CengineVec3 *self) {
    self->x = 0;
    self->y = 0;
    self->z = 0;
}

void cengine_vec3_swap(CengineVec3 *self) {
    gdouble temp = self->x;
    self->x = self->z;
    self->z = temp;
}

G_DEFINE_TYPE(CengineVec3, cengine_vec3, G_TYPE_OBJECT);

GArray* cengine_vec3_get_values(CengineVec3 *self) {
    GArray *values = g_array_new(FALSE, FALSE, sizeof(gdouble));
    g_array_append_val(values, self->x);
    g_array_append_val(values, self->y);
    g_array_append_val(values, self->z);
    return values;
}

CengineVec2* cengine_vec3_to_vec2(CengineVec3 *self) {
    return cengine_vec2_new(self->x, self->y);
}

CengineVec3* cengine_vec3_to_vec3(CengineVec3 *self) {
    return g_object_ref(self);
}

CengineVec4* cengine_vec3_to_vec4(CengineVec3 *self) {
    return cengine_vec4_new(self->x, self->y, self->z, 0.0);
}

void cengine_vec3_ivec_init(CengineIVecInterface *iface) {
    iface->reset = (void (*)(GObject *)) cengine_vec3_reset;
    iface->swap = (void (*)(GObject *)) cengine_vec3_swap;
    iface->get_values = (GArray* (*)(GObject *)) cengine_vec3_get_values;
    iface->to_vec2 = (GObject* (*)(GObject *)) cengine_vec3_to_vec2;
    iface->to_vec3 = (GObject* (*)(GObject *)) cengine_vec3_to_vec3;
    iface->to_vec4 = (GObject* (*)(GObject *)) cengine_vec3_to_vec4;
}

void cengine_vec3_class_init(CengineVec3Class *klass) {
    /* Vacío, implementado por la interfaz */
}

void cengine_vec3_init(CengineVec3 *self) {
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

