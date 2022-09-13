/*
 * Copyright (C) 2021-2022 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <multipass/file_ops.h>

namespace mp = multipass;
namespace fs = mp::fs;

mp::FileOps::FileOps(const Singleton<FileOps>::PrivatePass& pass) noexcept : Singleton<FileOps>::Singleton{pass}
{
}

bool mp::FileOps::exists(const QDir& dir) const
{
    return dir.exists();
}

bool mp::FileOps::isReadable(const QDir& dir) const
{
    return dir.isReadable();
}

bool mp::FileOps::mkpath(const QDir& dir, const QString& dirName) const
{
    return dir.mkpath(dirName);
}

bool mp::FileOps::rmdir(QDir& dir, const QString& dirName) const
{
    return dir.rmdir(dirName);
}

bool mp::FileOps::exists(const QFile& file) const
{
    return file.exists();
}

bool mp::FileOps::is_open(const QFile& file) const
{
    return file.isOpen();
}

bool mp::FileOps::open(QFileDevice& file, QIODevice::OpenMode mode) const
{
    return file.open(mode);
}

QFileDevice::Permissions mp::FileOps::permissions(const QFile& file) const
{
    return file.permissions();
}

qint64 mp::FileOps::read(QFile& file, char* data, qint64 maxSize) const
{
    return file.read(data, maxSize);
}

QByteArray mp::FileOps::read_all(QFile& file) const
{
    return file.readAll();
}

QString mp::FileOps::read_line(QTextStream& text_stream) const
{
    return text_stream.readLine();
}

bool mp::FileOps::remove(QFile& file) const
{
    return file.remove();
}

bool mp::FileOps::rename(QFile& file, const QString& newName) const
{
    return file.rename(newName);
}

bool mp::FileOps::resize(QFile& file, qint64 sz) const
{
    return file.resize(sz);
}

bool mp::FileOps::seek(QFile& file, qint64 pos) const
{
    return file.seek(pos);
}

bool mp::FileOps::setPermissions(QFile& file, QFileDevice::Permissions permissions) const
{
    return file.setPermissions(permissions);
}

qint64 mp::FileOps::size(QFile& file) const
{
    return file.size();
}

qint64 mp::FileOps::write(QFile& file, const char* data, qint64 maxSize) const
{
    return file.write(data, maxSize);
}

qint64 mp::FileOps::write(QFileDevice& file, const QByteArray& data) const
{
    return file.write(data);
}

bool mp::FileOps::commit(QSaveFile& file) const
{
    return file.commit();
}

void mp::FileOps::open(std::fstream& stream, const char* filename, std::ios_base::openmode mode) const
{
    stream.open(filename, mode);
}

std::unique_ptr<std::ostream> mp::FileOps::open_write(const fs::path& path) const
{
    return std::make_unique<std::ofstream>(path);
}

std::unique_ptr<std::istream> mp::FileOps::open_read(const fs::path& path) const
{
    return std::make_unique<std::ifstream>(path);
}

bool mp::FileOps::exists(const fs::path& path, std::error_code& err) const
{
    return fs::exists(path, err);
}

bool mp::FileOps::is_directory(const fs::path& path, std::error_code& err) const
{
    return fs::is_directory(path, err);
}

bool mp::FileOps::create_directory(const fs::path& path, std::error_code& err) const
{
    return fs::create_directory(path, err);
}

bool mp::FileOps::remove(const fs::path& path, std::error_code& err) const
{
    return fs::remove(path, err);
}

void mp::FileOps::create_symlink(const fs::path& to, const fs::path& path, std::error_code& err) const
{
    fs::create_symlink(to, path, err);
}

fs::path mp::FileOps::read_symlink(const fs::path& path, std::error_code& err) const
{
    return fs::read_symlink(path, err);
}

void mp::FileOps::permissions(const fs::path& path, fs::perms perms, std::error_code& err) const
{
    fs::permissions(path, perms, err);
}

fs::file_status mp::FileOps::status(const fs::path& path, std::error_code& err) const
{
    return fs::status(path, err);
}

std::unique_ptr<mp::RecursiveDirIterator> mp::FileOps::recursive_dir_iterator(const fs::path& path,
                                                                              std::error_code& err) const
{
    return std::make_unique<mp::RecursiveDirIterator>(path, err);
}
