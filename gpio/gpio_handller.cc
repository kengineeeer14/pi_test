#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string>

void write_to(const std::string& path, const std::string& value) {
    int fd = open(path.c_str(), O_WRONLY);
    if (fd < 0) {
        std::cerr << "Failed to open " << path << std::endl;
        return;
    }
    write(fd, value.c_str(), value.size());
    close(fd);
}

int main() {
    write_to("/sys/class/gpio/export", "17");
    sleep(1);
    write_to("/sys/class/gpio/gpio17/direction", "out");
    write_to("/sys/class/gpio/gpio17/value", "1");
    sleep(2);
    write_to("/sys/class/gpio/unexport", "17");
    return 0;
}