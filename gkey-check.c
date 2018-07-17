#include <stdio.h>
#include <gnome-keyring.h>

int main() {

  GnomeKeyringInfo *info;
  GnomeKeyringResult gkr;

  gkr = gnome_keyring_get_info_sync(NULL, &info);
  if (gkr != GNOME_KEYRING_RESULT_OK) {
    printf("error\n");
    return -1;
  }
  if (gnome_keyring_info_get_is_locked(info)) {
    printf("locked\n");
    return 0;
  }
  else {
    printf("unlocked\n");
    return -1;
  }
  gnome_keyring_info_free(info);

}

