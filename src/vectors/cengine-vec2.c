#include "cengine-vec2.h"
#include "cengine-vec3.h"
#include "cengine-vec4.h"

struct _CengineVec2 {
    GObject parent_instance;
    gdouble x;
    gdouble y;
};

/* Métodos de instancia */
static void cengine_vec2_reset(GObject *self) {
    CengineVec2 *vec = CENGINE_VEC2(self);
    vec->x = 0;
    vec->y = 0;
}

static void cengine_vec2_swap(GObject *self) {
    CengineVec2 *vec = CENGINE_VEC2(self);
    gdouble temp = vec->x;
    vec->x = vec->y;
    vec->y = temp;
}

static GArray* cengine_vec2_get_values(GObject *self) {
    CengineVec2 *vec = CENGINE_VEC2(self);
    GArray *values = g_array_new(FALSE, FALSE, sizeof(gdouble));
    g_array_append_val(values, vec->x);
    g_array_append_val(values, vec->y);
    return values;
}

/* Métodos de conversión */
static GObject* cengine_vec2_to_vec2(GObject *self) {
    return g_object_ref(self);
}

static GObject* cengine_vec2_to_vec3(GObject *self) {
    CengineVec2 *vec = CENGINE_VEC2(self);
    return G_OBJECT(cengine_vec3_new(vec->x, vec->y, 0.0));
}

static GObject* cengine_vec2_to_vec4(GObject *self) {
    CengineVec2 *vec = CENGINE_VEC2(self);
    return G_OBJECT(cengine_vec4_new(vec->x, vec->y, 0.0, 0.0));
}

/* Inicialización de la interfaz */
static void cengine_vec2_ivec_init(CengineIVecInterface *iface) {
    iface->reset = cengine_vec2_reset;
    iface->swap = cengine_vec2_swap;
    iface->get_values = cengine_vec2_get_values;
    iface->to_vec2 = cengine_vec2_to_vec2;
    iface->to_vec3 = cengine_vec2_to_vec3;
    iface->to_vec4 = cengine_vec2_to_vec4;
}

static void cengine_vec2_class_init(CengineVec2Class *klass) {
    /* Vacío */
}

static void cengine_vec2_init(CengineVec2 *self) {
    self->x = 0;
    self->y = 0;
}

CengineVec2* cengine_vec2_new(gdouble x, gdouble y) {
    return g_object_new(CENGINE_TYPE_VEC2, NULL);
}

gdouble cengine_vec2_get_x(CengineVec2 *self) {
    g_return_val_if_fail(CENGINE_IS_VEC3(self), 0.0);
    return self->x;
}

void cengine_vec2_set_x(CengineVec2 *self, gdouble value) {
    g_return_if_fail(CENGINE_IS_VEC3(self));
    self->x = value;
}

gdouble cengine_vec2_get_y(CengineVec2 *self) {
    g_return_val_if_fail(CENGINE_IS_VEC3(self), 0.0);
    return self->y;
}

void cengine_vec2_set_y(CengineVec2 *self, gdouble value) {
    g_return_if_fail(CENGINE_IS_VEC3(self));
    self->y = value;
}
