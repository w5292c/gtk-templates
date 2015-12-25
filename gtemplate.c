#include "udm-application.h"

typedef struct {
  gint mExample;
} UdmApplicationPrivate;

static void udm_application_init(UdmApplication *self);
static void udm_application_class_init(UdmApplicationClass *klass);
static void udm_application_dispose(GObject *gobject);
static void udm_application_finalize(GObject *gobject);

G_DEFINE_TYPE_WITH_PRIVATE (UdmApplication, udm_application, G_TYPE_OBJECT)

UdmApplication *udm_application_new(void)
{
  return UDM_APPLICATION(g_object_new(udm_application_get_type(), NULL));
}

void udm_application_init(UdmApplication *self)
{
  g_print("Init\n");
}

void udm_application_class_init(UdmApplicationClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);

  object_class->dispose = udm_application_dispose;
  object_class->finalize = udm_application_finalize;
  g_print("Class init\n");
}

void udm_application_dispose(GObject *gobject)
{
  g_print("Dispose\n");
}

void udm_application_finalize(GObject *gobject)
{
  g_print("Finalize\n");
}

gint udm_application_get_example(UdmApplication *self)
{
  g_return_val_if_fail(self, 0);
  UdmApplicationPrivate *const priv = udm_application_get_instance_private(self);
  g_return_val_if_fail(priv, 0);

  return priv->mExample;
}

void udm_application_set_example(UdmApplication *self, gint value)
{
  g_return_if_fail(self);
  UdmApplicationPrivate *const priv = udm_application_get_instance_private(self);
  g_return_if_fail(priv);

  priv->mExample = value;
}
