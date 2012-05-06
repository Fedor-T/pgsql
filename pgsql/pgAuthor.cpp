#include "pgAuthor.h"

pgAuthor::pgAuthor(pgDriver *driver):pgModel(driver, "authors"){}
pgAuthor::pgAuthor(pgDriver *driver, char *tname):pgModel(driver, tname){}
pgAuthor::~pgAuthor(void){}
