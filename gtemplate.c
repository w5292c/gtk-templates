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
#include "gtemplate.h"

#define APD_GOBJ_TEMPLATE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), APD_TYPE_GOBJ_TEMPLATE, ApdGObjectTemplatePrivate))

typedef struct
{
  gchar *m_pExample;
  gboolean m_bExample;
} ApdGObjectTemplatePrivate;

G_DEFINE_TYPE (ApdGObjectTemplate, apd_gobj_template, G_TYPE_OBJECT);

static void apd_gobj_template_finalize (GObject *pSelf);

ApdGObjectTemplate* apd_gobj_template_new (void)
{
  return APD_GOBJ_TEMPLATE (g_object_new (APD_TYPE_GOBJ_TEMPLATE, NULL));
}

static void apd_gobj_template_class_init (ApdGObjectTemplateClass *klass)
{
  GObjectClass *const pGObjectClass = G_OBJECT_CLASS (klass);
  g_debug ("apd_gobj_template_class_init: %p, %p", pGObjectClass, klass);

  pGObjectClass->finalize = apd_gobj_template_finalize;

  g_type_class_add_private (klass, sizeof (ApdGObjectTemplatePrivate));
}

void apd_gobj_template_finalize (GObject *pSelf)
{
  g_debug ("apd_gobj_template_finalize: %p", pSelf);
  ApdGObjectTemplatePrivate *const pPriv = APD_GOBJ_TEMPLATE_GET_PRIVATE (pSelf);
  g_return_if_fail (pPriv);

  g_free (pPriv->m_pDriver);
  g_free (pPriv->m_pSerial);
  g_free (pPriv->m_pFirmware);
  g_free (pPriv->m_pLastError);
  g_free (pPriv->m_pDevicePath);

  if (G_OBJECT_CLASS (apd_gobj_template_parent_class)->finalize)
  {
    (*G_OBJECT_CLASS (apd_gobj_template_parent_class)->finalize) (pSelf);
  }
}

static void apd_gobj_template_init (ApdGObjectTemplate *pSelf)
{
  ApdGObjectTemplatePrivate *const pPriv = APD_GOBJ_TEMPLATE_GET_PRIVATE (pSelf);
  g_return_if_fail (pPriv);
  g_debug ("apd_gobj_template_class_init: %p, %p", pSelf, pPriv);

  pPriv->m_pExample = NULL;
  pPriv->m_bExample = FALSE;
}

const char *apd_gobj_template_get_sexample (ApdGObjectTemplate *pSelf)
{
  g_debug ("apd_gobj_template_get_sexample: %p", pSelf);
  ApdGObjectTemplatePrivate *const pPriv = APD_GOBJ_TEMPLATE_GET_PRIVATE (pSelf);
  g_return_val_if_fail (pPriv, NULL);

  return pPriv->m_pDevicePath;
}

void apd_gobj_template_set_sexample (ApdGObjectTemplate *pSelf, const char *pExample)
{
  g_debug ("apd_gobj_template_set_sexample: %p, %s", pSelf, pExample);
  ApdGObjectTemplatePrivate *const pPriv = APD_GOBJ_TEMPLATE_GET_PRIVATE (pSelf);
  g_return_if_fail (pPriv);

  if (pPriv->m_pExample)
  {
    g_free (pPriv->m_pExample);
  }

  pPriv->m_pExample = g_strdup (pExample);
}

gboolean apd_gobj_template_get_bexample (ApdGObjectTemplate *pSelf)
{
  g_debug ("apd_gobj_template_get_bexample: %p", pSelf);
  ApdGObjectTemplatePrivate *const pPriv = APD_GOBJ_TEMPLATE_GET_PRIVATE (pSelf);
  g_return_val_if_fail (pPriv, FALSE);

  return pPriv->m_bExample;
}

void apd_gobj_template_set_bexample (ApdGObjectTemplate *pSelf, gboolean bExample)
{
  g_debug ("apd_gobj_template_set_bexample: %p, %d", pSelf, bSeated);
  ApdGObjectTemplatePrivate *const pPriv = APD_GOBJ_TEMPLATE_GET_PRIVATE (pSelf);
  g_return_if_fail (pPriv);

  pPriv->m_bExample = bExample;
}
