/*  Copyright (C) 2012-2020 by László Nagy
    This file is part of Bear.

    Bear is a tool to generate compilation database for clang tooling.

    Bear is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Bear is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "Resolver.h"

#include "gmock/gmock.h"

class ResolverMock : public el::Resolver {
public:
    MOCK_METHOD(
        int,
        execve,
        (const char* path, char* const argv[], char* const envp[]),
        (const, noexcept, override)
    );

    MOCK_METHOD(
        int,
        posix_spawn,
        (   pid_t* pid,
            const char* path,
            const posix_spawn_file_actions_t* file_actions,
            const posix_spawnattr_t* attrp,
            char* const argv[],
            char* const envp[]),
        (const, noexcept, override)
    );

    MOCK_METHOD(
        int,
        access,
        (const char *pathname, int mode),
        (const, noexcept, override)
    );

    MOCK_METHOD(
        char*,
        realpath,
        (const char* path, char* resolved_path),
        (const, noexcept, override)
    );

    MOCK_METHOD(
        size_t,
        confstr,
        (int name, char* buf, size_t len),
        (const, noexcept, override)
    );

    MOCK_METHOD(
        const char**,
        environment,
        (),
        (const, noexcept, override)
    );

    MOCK_METHOD(
        int,
        error_code,
        (),
        (const, noexcept, override)
    );
};