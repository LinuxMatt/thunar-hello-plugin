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

#ifndef __HELLO_PROVIDER_H__
#define __HELLO_PROVIDER_H__
#include <thunarx/thunarx.h>
G_BEGIN_DECLS;
typedef struct _HelloProviderClass HelloProviderClass;
typedef struct _HelloProvider      HelloProvider;
#define HELLO_TYPE_PROVIDER            (hello_provider_get_type ())
#define HELLO_PROVIDER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), HELLO_TYPE_PROVIDER, HelloProvider))
#define HELLO_PROVIDER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), HELLO_TYPE_PROVIDER, HelloProviderClass))
#define HELLO_IS_PROVIDER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), HELLO_TYPE_PROVIDER))
#define HELLO_IS_PROVIDER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), HELLO_TYPE_PROVIDER))
#define HELLO_PROVIDER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), HELLO_TYPE_PROVIDER, HelloProviderClass))
GType hello_provider_get_type      (void) G_GNUC_CONST;
void  hello_provider_register_type (ThunarxProviderPlugin *plugin);
G_END_DECLS;
#endif /* !__HELLO_PROVIDER_H__ */
