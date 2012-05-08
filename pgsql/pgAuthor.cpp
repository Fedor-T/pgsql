#include "pgAuthor.h"

pgAuthor::pgAuthor(pgDriver *driver):pgModel(driver, "authors"){}
pgAuthor::pgAuthor(pgDriver *driver, string tname):pgModel(driver, tname){}
