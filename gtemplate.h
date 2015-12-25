#ifndef UDM_APPLICATION_H
#define UDM_APPLICATION_H

#include <glib-object.h>

G_BEGIN_DECLS

#define UDM_TYPE_APPLICATION              (udm_application_get_type ())
#define UDM_APPLICATION(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), UDM_TYPE_APPLICATION, UdmApplication))
#define UDM_APPLICATION_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), UDM_TYPE_APPLICATION, UdmApplicationClass))
#define UDM_IS_APPLICATION(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), UDM_TYPE_APPLICATION))
#define UDM_IS_APPLICATION_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), UDM_TYPE_APPLICATION))
#define UDM_APPLICATION_GET_CLASS(object) (G_TYPE_INSTANCE_GET_CLASS ((object), UDM_TYPE_APPLICATION, UdmApplicationClass))

struct _UdmApplication {
  GObject parent;
};

struct _UdmApplicationClass {
  GObjectClass parent;
};

typedef struct _UdmApplication UdmApplication;
typedef struct _UdmApplicationClass UdmApplicationClass;

GType udm_application_get_type(void);
UdmApplication *udm_application_new(void);

gint udm_application_get_example(UdmApplication *self);
void udm_application_set_example(UdmApplication *self, gint value);

G_END_DECLS

#endif /* UDM_APPLICATION_H */
