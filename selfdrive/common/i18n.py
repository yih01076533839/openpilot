import gettext
import re
from common.params import Params
from common.hardware import HARDWARE, ANDROID, PC

supported_language = ['en_US', 'fr_FR']
localedir = '../assets/locales'

if ANDROID:
  locale = Params().get('AndroidLocale').decode('utf8')
else:
  locale = "en_US"
if locale not in supported_language:
  locale = "en_US"

i18n = gettext.translation('messages', localedir=localedir, fallback=True, languages=locale)

i18n.install()

number_to_symbol = False
symbol_map = {'ar_EG':['٠','١','٢','٣','٤','٥','٦','٧','٨','٩',],}
def symble_lookup(re_match):
  return symbol_map[local][int(re_match.group(0))]
def numtosym(text):
  if number_to_symbol and local in symbol_map:
    return re.sub("\d", symble_lookup, text)
  else:
    return num

def _(message):
  return numtosym(i18n.gettext(message))
