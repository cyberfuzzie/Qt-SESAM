/*

    Copyright (c) 2015 Oliver Lau <ola@ct.de>, Heise Medien GmbH & Co. KG

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/


#ifndef __CRYPTER_H_
#define __CRYPTER_H_

#include <QObject>
#include <QByteArray>
#include <QString>
#include "securebytearray.h"
#include "util.h"
#include "filters.h"
#include "aes.h"

class Crypter : public QObject
{
  Q_OBJECT
public:
  static Crypter *instance(void);
  static const int AESKeySize;
  static const int AESBlockSize;
  enum FormatFlags {
    ObsoleteDefaultEncryptionFormat = 0x00,
    AES256EncryptedMasterkeyFormat = 0x01
  };
  Q_INVOKABLE SecureByteArray makeKeyFromPassword(const SecureByteArray &masterPassword, const QByteArray &salt) const;
  Q_INVOKABLE void makeKeyAndIVFromPassword(const SecureByteArray &masterPassword, const QByteArray &salt, SecureByteArray &key, SecureByteArray &IV) const;
  Q_INVOKABLE QByteArray encode(const SecureByteArray &key, const SecureByteArray &IV, const QByteArray &salt, const SecureByteArray &KGK, const QByteArray &data, bool compress) const;
  Q_INVOKABLE QByteArray decode(const SecureByteArray &masterPassword, QByteArray cipher, bool uncompress, SecureByteArray &KGK) const;
  Q_INVOKABLE QByteArray randomBytes(const int size) const;
  Q_INVOKABLE SecureByteArray generateKGK(void) const;
  Q_INVOKABLE QByteArray generateSalt(void) const;
  Q_INVOKABLE QByteArray encrypt(const SecureByteArray &key, const SecureByteArray &IV, const QByteArray &plain, CryptoPP::StreamTransformationFilter::BlockPaddingScheme padding) const;
  Q_INVOKABLE SecureByteArray decrypt(const SecureByteArray &key, const SecureByteArray &IV, const QByteArray &cipher, CryptoPP::StreamTransformationFilter::BlockPaddingScheme padding) const;

private:
  static const int KGKSize;
  static const int SaltSize;
  static const int KGKIterations;
  static const int DomainIterations;
  static const int CryptDataSize;

  Crypter(void) {}
  ~Crypter() {}
};

#endif // __CRYPTER_H_
