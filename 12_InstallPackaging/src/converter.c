#include <string.h>
#include <ctype.h>
#include "converter.h"

static int strcaseequal(const char *a, const char *b)
{
    while (*a && *b) {
        if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) {
            return 0;
        }
        a++; b++;
    }
    return (*a == '\0' && *b == '\0');
}

TempUnit parse_unit(const char *str)
{
    if (!str) return UNIT_UNKNOWN;
    if (strcaseequal(str, "C")) return UNIT_CELSIUS;
    if (strcaseequal(str, "F")) return UNIT_FAHRENHEIT;
    if (strcaseequal(str, "K")) return UNIT_KELVIN;
    return UNIT_UNKNOWN;
}

/*
 * Формулы:
 *  C -> F: (C * 9/5) + 32
 *  F -> C: (F - 32) * 5/9
 *  C -> K: C + 273.15
 *  K -> C: K - 273.15
 *  F -> K: (F - 32) * 5/9 + 273.15
 *  K -> F: (K - 273.15) * 9/5 + 32
 */
double convert_temperature(double value, TempUnit from, TempUnit to, int *err)
{
    if (err) *err = 0;

    if (from == to) {
        return value;
    }

    if (from == UNIT_UNKNOWN || to == UNIT_UNKNOWN) {
        if (err) *err = 1;
        return 0.0;
    }

    double celsius = 0.0;

    switch (from) {
        case UNIT_CELSIUS:
            celsius = value;
            break;
        case UNIT_FAHRENHEIT:
            celsius = (value - 32.0) * 5.0 / 9.0;
            break;
        case UNIT_KELVIN:
            celsius = value - 273.15;
            break;
        default:
            if (err) *err = 1;
            return 0.0;
    }

    double result = 0.0;

    switch (to) {
        case UNIT_CELSIUS:
            result = celsius;
            break;
        case UNIT_FAHRENHEIT:
            result = (celsius * 9.0 / 5.0) + 32.0;
            break;
        case UNIT_KELVIN:
            result = celsius + 273.15;
            break;
        default:
            if (err) *err = 1;
            return 0.0;
    }

    return result;
}