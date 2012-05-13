#include "pgAreasBooks.h"

pgAreasBooks::pgAreasBooks(pgDriver *driver):pgModel(driver, "areas"){}
pgAreasBooks::pgAreasBooks(pgDriver *driver, string tname):pgModel(driver, tname){}
