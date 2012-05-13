#include "pgArea.h"

pgArea::pgArea(pgDriver *driver):pgModel(driver, "areas"){}
pgArea::pgArea(pgDriver *driver, string tname):pgModel(driver, tname){}
