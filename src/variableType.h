#pragma once

#include <variant>
#include <bits/types.h>


#define float32_t float
#define float64_t double
typedef std::variant<signed int,signed long, float32_t, float64_t> VariableType;