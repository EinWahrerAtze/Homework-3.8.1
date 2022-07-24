#include "Bad_length.h"

Bad_length::Bad_length(const std::string & what) : std::domain_error(what.c_str()) { }