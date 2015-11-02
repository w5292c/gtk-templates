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