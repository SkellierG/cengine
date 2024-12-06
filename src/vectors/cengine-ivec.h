#ifndef CENGINE_IVEC_H
#define CENGINE_IVEC_H

#include <glib-2.0/glib-object.h>
#include <glib-2.0/glib.h>

typedef struct _CengineVec2 CengineVec2;
typedef struct _CengineVec3 CengineVec3;
typedef struct _CengineVec4 CengineVec4;

#define CENGINE_TYPE_IVEC (cengine_ivec_get_type())
G_DECLARE_INTERFACE(CengineIVec, cengine_ivec, CENGINE, IVEC, GObject)

struct _CengineIVecInterface {
    GTypeInterface parent_iface;

    void (*reset)(GObject *self);
    void (*swap)(GObject *self);
    GArray* (*get_values)(GObject *self);

    GObject* (*to_vec2)(GObject *self);
    GObject* (*to_vec3)(GObject *self);
    GObject* (*to_vec4)(GObject *self);
};

void cengine_ivec_reset(GObject *self);
void cengine_ivec_swap(GObject *self);
GArray* cengine_ivec_get_values(GObject *self);
GObject* cengine_ivec_to_vec2(GObject *self);
GObject* cengine_ivec_to_vec3(GObject *self);
GObject* cengine_ivec_to_vec4(GObject *self);

#endif

