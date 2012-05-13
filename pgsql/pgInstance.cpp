#include "pgInstance.h"

pgInstance::pgInstance(pgDriver *driver):pgModel(driver, "instances"){}
pgInstance::pgInstance(pgDriver *driver, string tname):pgModel(driver, tname){}
