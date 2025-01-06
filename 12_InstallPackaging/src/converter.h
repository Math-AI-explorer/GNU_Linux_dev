#ifndef CONVERTER_H
#define CONVERTER_H

typedef enum {
    UNIT_CELSIUS,
    UNIT_FAHRENHEIT,
    UNIT_KELVIN,
    UNIT_UNKNOWN
} TempUnit;

TempUnit parse_unit(const char *str);

double convert_temperature(double value, TempUnit from, TempUnit to, int *err);

#endif