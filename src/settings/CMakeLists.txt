# Copyright (C) Canonical, Ltd.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 3 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

add_library(settings STATIC
        basic_setting_spec.cpp
        bool_setting_spec.cpp
        custom_setting_spec.cpp
        persistent_settings_handler.cpp
        settings.cpp)

target_link_libraries(settings
        fmt::fmt-header-only
        utils
        Qt6::Core)
