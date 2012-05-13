#include "pgAreasBooks.h"

pgAreasBooks::pgAreasBooks(pgDriver *driver):pgModel(driver, "areas_books"){}
pgAreasBooks::pgAreasBooks(pgDriver *driver, string tname):pgModel(driver, tname){}
