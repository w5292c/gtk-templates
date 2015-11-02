#ifndef APD_GOBJ_TEMPLATE_H
#define APD_GOBJ_TEMPLATE_H

#include <glib-object.h>

G_BEGIN_DECLS

#define APD_TYPE_GOBJ_TEMPLATE            (apd_gobj_template_get_type ())
#define APD_GOBJ_TEMPLATE(object)         (G_TYPE_CHECK_INSTANCE_CAST ((object), APD_TYPE_GOBJ_TEMPLATE, ApdGObjectTemplate))
#define APD_GOBJ_TEMPLATE_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), APD_TYPE_GOBJ_TEMPLATE, ApdGObjectTemplateClass))
#define APD_IS_GOBJ_TEMPLATE(widget)      (G_TYPE_CHECK_INSTANCE_TYPE ((widget), APD_TYPE_GOBJ_TEMPLATE))
#define APD_IS_GOBJ_TEMPLATE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), APD_TYPE_GOBJ_TEMPLATE))
#define APD_GOBJ_TEMPLATE_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), APD_TYPE_GOBJ_TEMPLATE, ApdGObjectTemplateClass))

typedef struct _ApdGObjectTemplate       ApdGObjectTemplate;
typedef struct _ApdGObjectTemplateClass  ApdGObjectTemplateClass;

struct _ApdGObjectTemplate
{
  GObject widget;
};

struct _ApdGObjectTemplateClass
{
  GObjectClass parent_class;
};

void apd_gobj_template_early_init (void);

GType apd_gobj_template_get_type(void) G_GNUC_CONST;
ApdGObjectTemplate* apd_gobj_template_new(void);

const gchar *apd_gobj_template_get_sexample (ApdGObjectTemplate *pSelf);
void apd_gobj_template_set_sexample (ApdGObjectTemplate *pSelf, const gchar *pExample);

gboolean apd_gobj_template_get_bexample (ApdGObjectTemplate *pSelf);
void apd_gobj_template_set_bexample (ApdGObjectTemplate *pSelf, gboolean bExample);

G_END_DECLS

#endif /* APD_GOBJ_TEMPLATE_H */
