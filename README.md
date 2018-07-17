# gnome-keyring-tools
Tools To Check And Control Gnome Keyring State

- Lock Keyring - gkey-lock.c
- Unlock Keyring - gkey-unlock.c
- Check Keyring State - gkey-check.c
- Check With Python - gkey-check.py

**How to build :**

    cc gkey-lock.c -o gkey-lock -Wall -I/usr/include/gnome-keyring-1 -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -lgnome-keyring -lglib-2.0
    cc gkey-unlock.c -o gkey-unlock -Wall -I/usr/include/gnome-keyring-1 -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -lgnome-keyring -lglib-2.0
    cc gkey-check.c -o gkey-check -Wall -I/usr/include/gnome-keyring-1 -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -lgnome-keyring -lglib-2.0
    python gkey-check.py

**Note :**
The tools check the default keyring storage, if you want to check a different keyring just replace NULL with the name of your keyring 

**Bonus - Monitor Gnome Keyring State In KDE Taskbar/Tray :**
I made gkey-check return error when its unlocked in addition to the string unlocked i could then use KDE Server Status widget to monitor keyring state locked/unlocked with a visual icon :) with the command gkey-check
