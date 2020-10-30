#include "i18n.h"
#include <libintl.h>
#include <locale.h>
#include "common/params.h"
#include <string>
#include <sys/stat.h>

std::string geteonlocale(){
  std::string locale;
  const char *supported_languages[] = {"en_US", "fr_FR"};
  struct stat buffer;
  bool ANDROID = stat("/EON", &buffer) == 0;
  if (ANDROID) {
    locale = Params().get("AndroidLocale");
  } else {
    locale = "en_US";
  }
  for (int i = 0; i < sizeof(supported_languages) / sizeof(supported_languages[0]); i++){
    if (supported_languages[i] == locale.c_str()){
      return locale;
    }
  }
  locale = "en_US";
  return locale;
}

void i18n_init(){

  setlocale (LC_ALL, geteonlocale().c_str());
  // setlocale (LC_CTYPE, "");
  // setlocale (LC_MESSAGES, "");
  bindtextdomain ("messages", "../assets/locales");
  textdomain ("messages");
  return;
}
