#include "pgAuthorsBooks.h"

pgAuthorsBooks::pgAuthorsBooks(pgDriver *driver):pgModel(driver, "authors_books"){}
pgAuthorsBooks::pgAuthorsBooks(pgDriver *driver, string tname):pgModel(driver, tname){}
