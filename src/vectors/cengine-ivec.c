#include "cengine-ivec.h"


GType cengine_ivec_get_type(void) {
    static GType type = 0;
    if (type == 0) {
        static const GTypeInfo info = {
            sizeof(CengineIVecInterface),
            NULL,
            NULL,
            (GClassInitFunc)NULL,
            NULL,
            NULL,
            sizeof(CengineIVecInterface),
            0,
            (GInstanceInitFunc)NULL
        };
        type = g_type_register_static(G_TYPE_OBJECT, "CengineIVec", &info, 0);
    }
    return type;
}

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

