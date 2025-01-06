#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <libintl.h>
#include "converter.h"
#define LOCALEDIR "/usr/local/share/locale"

#define _(STRING) gettext(STRING)

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    bindtextdomain("temp_converter", LOCALEDIR);
    textdomain("temp_converter");

    if (argc < 4) {
        printf(_("Usage: %s <value> <from_unit> <to_unit>\n"), argv[0]);
        printf(_("Supported units: C, F, K\n\n"));
        printf(_("Please provide all arguments in the correct order.\n"));
        return 1;
    }

    double value = atof(argv[1]);
    TempUnit from = parse_unit(argv[2]);
    TempUnit to   = parse_unit(argv[3]);

    int err = 0;
    double result = convert_temperature(value, from, to, &err);
  if (err) {
        printf(_("Error: invalid unit or conversion\n"));
        printf(_("Make sure <from_unit> and <to_unit> are one of: C, F, K.\n"));
        return 1;
    }

    printf(_("%.2f %s -> %.2f %s\n"), value, argv[2], result, argv[3]);
    printf(_("\nConversion completed successfully.\n"));
    return 0;
}