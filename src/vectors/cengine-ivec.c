#include "cengine-ivec.h"

void cengine_ivec_reset(GObject *self) {
    CengineIVecInterface *iface = CENGINE_IVEC_GET_IFACE(self);
    g_return_if_fail(iface->reset != NULL);
    iface->reset(self);
}

void cengine_ivec_swap(GObject *self) {
    CengineIVecInterface *iface = CENGINE_IVEC_GET_IFACE(self);
    g_return_if_fail(iface->swap != NULL);
    iface->swap(self);
}

GArray* cengine_ivec_get_values(GObject *self) {
    CengineIVecInterface *iface = CENGINE_IVEC_GET_IFACE(self);
    g_return_val_if_fail(iface->get_values != NULL, NULL);
    return iface->get_values(self);
}

GObject* cengine_ivec_to_vec2(GObject *self) {
    CengineIVecInterface *iface = CENGINE_IVEC_GET_IFACE(self);
    g_return_val_if_fail(iface->to_vec2 != NULL, NULL);
    return iface->to_vec2(self);
}

GObject* cengine_ivec_to_vec3(GObject *self) {
    CengineIVecInterface *iface = CENGINE_IVEC_GET_IFACE(self);
    g_return_val_if_fail(iface->to_vec3 != NULL, NULL);
    return iface->to_vec3(self);
}

GObject* cengine_ivec_to_vec4(GObject *self) {
    CengineIVecInterface *iface = CENGINE_IVEC_GET_IFACE(self);
    g_return_val_if_fail(iface->to_vec4 != NULL, NULL);
    return iface->to_vec4(self);
}

