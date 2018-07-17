cc gkey-lock.c -o gkey-lock -Wall -I/usr/include/gnome-keyring-1 -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -lgnome-keyring -lglib-2.0
cc gkey-unlock.c -o gkey-unlock -Wall -I/usr/include/gnome-keyring-1 -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -lgnome-keyring -lglib-2.0
cc gkey-check.c -o gkey-check -Wall -I/usr/include/gnome-keyring-1 -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -lgnome-keyring -lglib-2.0

