#ifndef I18N_H
#define I18N_H

#include <libintl.h>
#include <string>

std::string geteonlocale();
void i18n_init();

#define _(STRING) gettext(STRING)

#endif
