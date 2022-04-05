//
// Created by Edin on 29. 03. 2022.
//

#ifndef INC_003_FOUR_IN_LINE_OOP_UTILS_H
#define INC_003_FOUR_IN_LINE_OOP_UTILS_H

#if defined(_WIN32)
#define UTILS_PLATFORM_NUMBER 0 // Windows
#elif defined(_WIN64)
#define UTILS_PLATFORM_NUMBER 0 // Windows
#elif defined(__linux__)
#define UTILS_PLATFORM_NUMBER 1 // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
#endif

int utils_get_platform_number();

#endif //INC_003_FOUR_IN_LINE_OOP_UTILS_H
