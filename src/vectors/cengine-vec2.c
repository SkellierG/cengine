#include "cengine-vec2.h"
#include "cengine-vec3.h"
#include "cengine-vec4.h"

struct _CengineVec2 {
    GObject parent_instance;
    gdouble x;
    gdouble y;
};

G_DEFINE_TYPE(CengineVec2, cengine_vec2, G_TYPE_OBJECT);

void cengine_vec2_reset(CengineVec2 *self) {
    self->x = 0.0;
    self->y = 0.0;
}

void cengine_vec2_swap(CengineVec2 *self) {
    gdouble temp = self->x;
    self->x = self->y;
    self->y = temp;
}

GArray* cengine_vec2_get_values(CengineVec2 *self) {
    GArray *values = g_array_new(FALSE, FALSE, sizeof(gdouble));
    g_array_append_val(values, self->x);
    g_array_append_val(values, self->y);
    return values;
}

CengineVec2* cengine_vec2_to_vec2(CengineVec2 *self) {
    return g_object_ref(self);
}

CengineVec3* cengine_vec2_to_vec3(CengineVec2 *self) {
    return cengine_vec3_new(self->x, self->y, 0.0);
}

CengineVec4* cengine_vec2_to_vec4(CengineVec2 *self) {
    return cengine_vec4_new(self->x, self->y, 0.0, 0.0);
}

void cengine_vec2_ivec_init(CengineIVecInterface *iface) {
    iface->reset = (void (*)(GObject *))cengine_vec2_reset;
    iface->swap = (void (*)(GObject *))cengine_vec2_swap;
    iface->get_values = (GArray* (*)(GObject *))cengine_vec2_get_values;
    iface->to_vec2 = (GObject* (*)(GObject *))cengine_vec2_to_vec2;
    iface->to_vec3 = (GObject* (*)(GObject *))cengine_vec2_to_vec3;
    iface->to_vec4 = (GObject* (*)(GObject *))cengine_vec2_to_vec4;
}

void cengine_vec2_class_init(CengineVec2Class *klass) {

}

void cengine_vec2_init(CengineVec2 *self) {
    self->x = 0.0;
    self->y = 0.0;
}

CengineVec2* cengine_vec2_new(gdouble x, gdouble y) {
    CengineVec2 *vec2 = g_object_new(CENGINE_TYPE_VEC2, NULL);
    vec2->x = x;
    vec2->y = y;
    return vec2;
}

gdouble cengine_vec2_get_x(CengineVec2 *self) {
    g_return_val_if_fail(CENGINE_IS_VEC2(self), 0.0);
    return self->x;
}

void cengine_vec2_set_x(CengineVec2 *self, gdouble value) {
    g_return_if_fail(CENGINE_IS_VEC2(self));
    self->x = value;
}

gdouble cengine_vec2_get_y(CengineVec2 *self) {
    g_return_val_if_fail(CENGINE_IS_VEC2(self), 0.0);
    return self->y;
}

void cengine_vec2_set_y(CengineVec2 *self, gdouble value) {
    g_return_if_fail(CENGINE_IS_VEC2(self));
    self->y = value;
}

