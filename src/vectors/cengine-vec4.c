#include "cengine-vec2.h"
#include "cengine-vec3.h"
#include "cengine-vec4.h"

struct _CengineVec4 {
    GObject parent_instance;
    gdouble x;
    gdouble y;
    gdouble z;
    gdouble w;
};

G_DEFINE_TYPE(CengineVec4, cengine_vec4, G_TYPE_OBJECT);

void cengine_vec4_reset(CengineVec4 *self) {
    self->x = 0;
    self->y = 0;
    self->z = 0;
    self->w = 0;
}

void cengine_vec4_swap(CengineVec4 *self) {
    gdouble temp = self->x;
    self->x = self->w;
    self->w = temp;

    temp = self->y;
    self->y = self->z;
    self->z = temp;
}

GArray* cengine_vec4_get_values(CengineVec4 *self) {
    GArray *values = g_array_new(FALSE, FALSE, sizeof(gdouble));
    g_array_append_val(values, self->x);
    g_array_append_val(values, self->y);
    g_array_append_val(values, self->z);
    g_array_append_val(values, self->w);
    return values;
}

CengineVec2* cengine_vec4_to_vec2(CengineVec4 *self) {
    return cengine_vec2_new(self->x, self->y);
}

CengineVec3* cengine_vec4_to_vec3(CengineVec4 *self) {
    return cengine_vec3_new(self->x, self->y, self->z);
}

CengineVec4* cengine_vec4_to_vec4(CengineVec4 *self) {
    return g_object_ref(self);
}

void cengine_vec4_ivec_init(CengineIVecInterface *iface) {
    iface->reset = (void (*)(GObject *)) cengine_vec4_reset;
    iface->swap = (void (*)(GObject *)) cengine_vec4_swap;
    iface->get_values = (GArray* (*)(GObject *)) cengine_vec4_get_values;
    iface->to_vec2 = (GObject* (*)(GObject *)) cengine_vec4_to_vec2;
    iface->to_vec3 = (GObject* (*)(GObject *)) cengine_vec4_to_vec3;
    iface->to_vec4 = (GObject* (*)(GObject *)) cengine_vec4_to_vec4;
}

void cengine_vec4_class_init(CengineVec4Class *klass) {
    /* Vacío, implementado por la interfaz */
}

void cengine_vec4_init(CengineVec4 *self) {
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

