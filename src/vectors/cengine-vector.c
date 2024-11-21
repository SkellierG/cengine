#include "cengine-vector.h"

GObject* cengine_vector_new_from_array(const gdouble *values, guint size) {
    switch (size) {
        case 2:
            return G_OBJECT(cengine_vec2_new(values[0], values[1]));
        case 3:
            return G_OBJECT(cengine_vec3_new(values[0], values[1], values[2]));
        case 4:
            return G_OBJECT(cengine_vec4_new(values[0], values[1], values[2], values[3]));
        default:
            g_warning("Unsupported vector size: %u", size);
            return NULL;
    }
}

void cengine_vector_print(GObject *vector) {
    if (!CENGINE_IS_IVEC(vector)) {
        g_warning("Object is not a valid vector implementing CengineIVector");
        return;
    }

    GArray *values = cengine_ivec_get_values(vector);
    g_print("[");
    for (guint i = 0; i < values->len; i++) {
        g_print("%f", g_array_index(values, gdouble, i));
        if (i < values->len - 1) {
            g_print(", ");
        }
    }
    g_print("]\n");
    g_array_unref(values);
}

