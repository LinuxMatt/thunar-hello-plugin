AM_CPPFLAGS =									\
	-I$(top_builddir)							\
	-I$(top_srcdir)							\
	-DEXO_API_SUBJECT_TO_CHANGE					\
	-DLIBEXECDIR=\"$(libexecdir)\"			\
	-DG_LOG_DOMAIN=\"thunar-hello\"			\
	-DPACKAGE_LOCALE_DIR=\"$(localedir)\"	\
	$(PLATFORM_CPPFLAGS)

extensionsdir = $(libdir)/thunarx-2
extensions_LTLIBRARIES =	\
	thunar-hello.la

thunar_hello_la_SOURCES =		\
	thunar-hello-plugin.c		\
	thunar-hello-provider.c	\
	thunar-hello-provider.h

thunar_hello_la_CFLAGS =	\
	$(EXIF_CFLAGS)			\
	$(EXO_CFLAGS)			\
	$(GLIB_CFLAGS)			\
	$(GTK_CFLAGS)			\
	$(LIBX11_CFLAGS)		\
	$(PCRE_CFLAGS)			\
	$(THUNARX_CFLAGS)		\
	$(LIBXFCE4UTIL_CFLAGS)	\
	$(PLATFORM_CFLAGS)

thunar_hello_la_LDFLAGS =	\
	-avoid-version			\
	-export-dynamic			\
	-no-undefined			\
	-export-symbols-regex "^thunar_extension_(shutdown|initialize|list_types)" \
	-module					\
	$(PLATFORM_LDFLAGS)

thunar_hello_la_LIBADD = \
	$(PLATFORM_LIBS)	\
	$(THUNARX_LIBS)	\
	$(EXIF_LIBS)		\
	$(EXO_LIBS)		\
	$(GLIB_LIBS)		\
	$(GTK_LIBS)		\
	$(LIBX11_LIBS)		\
	$(LIBXFCE4UTIL_LIBS)	\
	$(PCRE_LIBS)

