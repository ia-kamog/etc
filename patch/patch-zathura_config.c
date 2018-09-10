--- zathura/config.c.org	2018-08-20 18:45:38.383845000 +0300
+++ zathura/config.c	2018-08-20 18:48:35.401535000 +0300
@@ -298,8 +298,8 @@
   girara_shortcut_add(gsession, 0,                GDK_KEY_L,          NULL, sc_scroll,                  (mode),     PAGE_BOTTOM,            NULL); \
   girara_shortcut_add(gsession, 0,                GDK_KEY_Right,      NULL, sc_scroll,                  (mode),     RIGHT,                  NULL); \
   girara_shortcut_add(gsession, GDK_CONTROL_MASK, GDK_KEY_t,          NULL, sc_scroll,                  (mode),     HALF_LEFT,              NULL); \
-  girara_shortcut_add(gsession, GDK_CONTROL_MASK, GDK_KEY_d,          NULL, sc_scroll,                  (mode),     HALF_DOWN,              NULL); \
-  girara_shortcut_add(gsession, GDK_CONTROL_MASK, GDK_KEY_u,          NULL, sc_scroll,                  (mode),     HALF_UP,                NULL); \
+  girara_shortcut_add(gsession, 0,                GDK_KEY_d,          NULL, sc_scroll,                  (mode),     HALF_DOWN,              NULL); \
+  girara_shortcut_add(gsession, 0,                GDK_KEY_u,          NULL, sc_scroll,                  (mode),     HALF_UP,                NULL); \
   girara_shortcut_add(gsession, GDK_CONTROL_MASK, GDK_KEY_y,          NULL, sc_scroll,                  (mode),     HALF_RIGHT,             NULL); \
   girara_shortcut_add(gsession, 0,                GDK_KEY_t,          NULL, sc_scroll,                  (mode),     FULL_LEFT,              NULL); \
   girara_shortcut_add(gsession, GDK_CONTROL_MASK, GDK_KEY_f,          NULL, sc_scroll,                  (mode),     FULL_DOWN,              NULL); \
@@ -320,7 +320,7 @@
   girara_shortcut_add(gsession, 0,                GDK_KEY_Tab,        NULL, sc_toggle_index,            (mode),     0,                      NULL); \
   girara_shortcut_add(gsession, GDK_CONTROL_MASK, GDK_KEY_n,          NULL, girara_sc_toggle_statusbar, (mode),     0,                      NULL); \
   girara_shortcut_add(gsession, GDK_CONTROL_MASK, GDK_KEY_m,          NULL, girara_sc_toggle_inputbar,  (mode),     0,                      NULL); \
-  girara_shortcut_add(gsession, 0,                GDK_KEY_d,          NULL, sc_toggle_page_mode,        (mode),     0,                      NULL); \
+  girara_shortcut_add(gsession, GDK_CONTROL_MASK, GDK_KEY_d,          NULL, sc_toggle_page_mode,        (mode),     0,                      NULL); \
 \
   girara_shortcut_add(gsession, 0,                GDK_KEY_q,          NULL, sc_quit,                    (mode),     0,                      NULL); \
 \
