/*
 The MIT License (MIT)
 Copyright (c) 2015 Alexander Chumakov

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */
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
