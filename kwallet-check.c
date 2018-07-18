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
