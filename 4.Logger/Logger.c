#include "Logger.h"
#include <string.h>
#include <stdlib.h>

static Loglevel current = LOG_DEBUG;
static FILE *log_file   = NULL;
