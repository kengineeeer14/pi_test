#include <gpiod.h>
#include <iostream>
#include <unistd.h>

int main() {
    const char* chipname = "gpiochip0";
    unsigned int line_num = 17;  // GPIO17

    gpiod_chip* chip = gpiod_chip_open_by_name(chipname);
    gpiod_line* line = gpiod_chip_get_line(chip, line_num);

    gpiod_line_request_output(line, "gpio_control", 0); // 初期値0 (OFF)
    gpiod_line_set_value(line, 1); // ON
    sleep(2);
    gpiod_line_set_value(line, 0); // OFF

    gpiod_line_release(line);
    gpiod_chip_close(chip);

    return 0;
}