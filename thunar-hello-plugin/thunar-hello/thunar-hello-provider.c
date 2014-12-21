/*-
 * Copyright (c) 2014 <your name> <your e-mail>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <gio/gio.h>
#include <gdk/gdkx.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <glib/gi18n.h>
#include <thunar-hello/thunar-hello-provider.h>

static void   hello_provider_menu_provider_init (ThunarxMenuProviderIface *iface);
static void   hello_provider_finalize           (GObject *object);
static GList* hello_provider_get_file_actions   (ThunarxMenuProvider *menu_provider, GtkWidget *window, GList *files);
static void   hello_action_hello                (GtkAction *action, gpointer user_data);

struct _HelloProviderClass
{
  GObjectClass __parent__;
};
struct _HelloProvider
{
  GObject __parent__;
  gchar   *child_watch_path;
  gint    child_watch_id;
};

THUNARX_DEFINE_TYPE_WITH_CODE (HelloProvider, hello_provider, G_TYPE_OBJECT,
	THUNARX_IMPLEMENT_INTERFACE (THUNARX_TYPE_MENU_PROVIDER, hello_provider_menu_provider_init));

static void hello_provider_class_init (HelloProviderClass *klass)
{
  GObjectClass *gobject_class;
  gobject_class = G_OBJECT_CLASS (klass);
  gobject_class->finalize = hello_provider_finalize;
  g_message ("hello_provider_class_init");
}
static void hello_provider_menu_provider_init (ThunarxMenuProviderIface *iface)
{
  iface->get_file_actions = hello_provider_get_file_actions;
}
static void hello_provider_init (HelloProvider *hello_provider)
{
  g_message ("hello_provider_init");
}
static void hello_provider_finalize (GObject *object)
{
  g_message ("hello_provider_finalize");
  G_OBJECT_CLASS (hello_provider_parent_class)->finalize (object);
}
static GList* hello_provider_get_file_actions (ThunarxMenuProvider *menu_provider, GtkWidget *window, GList *files)
{
	GList *actions = NULL;
	GFile *location = NULL;
	GtkWidget *action = NULL;

	/* we can only work on a single */
	if (files->next != NULL) {
		return actions;
	}
	/* get the location of the file */
	location = thunarx_file_info_get_location (files->data);
	/* unable to handle non-local files */
	if (G_UNLIKELY (!g_file_has_uri_scheme (location, "file"))) {
		g_object_unref (location);
		return NULL;
	}
	/* release the location */
	g_object_unref (location);

	if (thunarx_file_info_is_directory (files->data)) {
		return actions;
	}
	/* we work on JPEG and PNG files */
	if (thunarx_file_info_has_mime_type (files->data, "image/jpeg")
			||thunarx_file_info_has_mime_type (files->data, "image/png"))
	{
		action = g_object_new (GTK_TYPE_ACTION,	"name", "Hello::hello", "icon-name", "background", "label", _("HELLO plugin says Hello !"), NULL);
		g_signal_connect (action, "activate", G_CALLBACK (hello_action_hello), files->data);
		actions = g_list_append (actions, action);
	}
	return actions;
}
static void hello_action_hello (GtkAction *action, gpointer user_data)
{
	g_message("Hello, World !");
}
