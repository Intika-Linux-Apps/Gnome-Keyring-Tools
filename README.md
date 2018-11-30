# gnome-keyring-tools (& kde kwallet)
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

# Alternative Method :
As gnome_keyring_lock_all_sync is depreciated we can use dbus to lock gnome-keyring with this command :

    qdbus org.gnome.keyring /org/freedesktop/secrets org.freedesktop.Secret.Service.LockService


# kde-kwallet-tools
The equivalent of this tool for KDE Wallet is :

**Check Command** :

    qdbus org.kde.kwalletd /modules/kwalletd org.kde.KWallet.isOpen kdewallet
    
**Open Command** :

    qdbus org.kde.kwalletd /modules/kwalletd org.kde.KWallet.open kdewallet 0 command
    
**Close Command** :

    qdbus org.kde.kwalletd /modules/kwalletd closeAllWallets
    
**Equivalent of gkey-ckeck.c kwallet-check.c** :

    #include <stdio.h>
    #include <stdlib.h>

    int main( int argc, char *argv[] )
    {

      FILE *fp;
      char path[7];

      /* Open the command for reading. */
      fp = popen("qdbus org.kde.kwalletd /modules/kwalletd org.kde.KWallet.isOpen kdewallet", "r");
      if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
      }

      /* Read the output a line at a time - output it. */
      while (fgets(path, sizeof(path)-1, fp) != NULL) {
        printf("%s", path);
        if (strcmp ("false", path) == 0) {
          printf(" - Ok\n");
          return 0;
        }
        else {
          printf("Nok \n");
          return -1;
        }
      }

      /* close */
      pclose(fp);
      return -1;
    }

Just 'cc kwallet-check.c -o kwallet-check' to build

    
