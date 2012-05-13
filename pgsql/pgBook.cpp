#include "pgBook.h"

pgBook::pgBook(pgDriver *driver):pgModel(driver, "books"){}
pgBook::pgBook(pgDriver *driver, string tname):pgModel(driver, tname){}