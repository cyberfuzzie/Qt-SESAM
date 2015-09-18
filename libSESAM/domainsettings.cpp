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

#include "domainsettings.h"

#include <QtDebug>

#include <QByteArray>
#include <QJsonDocument>

const QByteArray DomainSettings::DefaultSalt = QString("pepper").toUtf8();
const QByteArray DomainSettings::DefaultSalt_base64 = DomainSettings::DefaultSalt.toBase64();
const int DomainSettings::DefaultIterations = 4096;
const int DomainSettings::DefaultPasswordLength = 10;
const int DomainSettings::DefaultSaltLength = 16;


const QString DomainSettings::DOMAIN_NAME = "domain";
const QString DomainSettings::URL = "url";
const QString DomainSettings::USER_NAME = "username";
const QString DomainSettings::LEGACY_PASSWORD = "legacyPassword";
const QString DomainSettings::NOTES = "notes";
const QString DomainSettings::ITERATIONS = "iterations";
const QString DomainSettings::SALT = "salt";
const QString DomainSettings::LENGTH = "length";
const QString DomainSettings::CDATE = "cDate";
const QString DomainSettings::MDATE = "mDate";
const QString DomainSettings::USED_CHARACTERS = "usedCharacters";
const QString DomainSettings::DELETED = "deleted";
const QString DomainSettings::EXTRAS = "extras";


DomainSettings::DomainSettings(void)
  : m_salt_base64(DefaultSalt_base64)
  , m_iterations(DefaultIterations)
  , m_length(DefaultPasswordLength)
  , m_deleted(false)
  , m_forceLowerCase(false)
  , m_forceUpperCase(false)
  , m_forceDigits(false)
  , m_forceExtra(false)
{ /* ... */ }


DomainSettings::DomainSettings(const DomainSettings &o)
  : m_domainName(o.m_domainName)
  , m_userName(o.m_userName)
  , m_url(o.m_url)
  , m_legacyPassword(o.m_legacyPassword)
  , m_notes(o.m_notes)
  , m_salt_base64(o.m_salt_base64)
  , m_iterations(o.m_iterations)
  , m_length(o.m_length)
  , m_usedCharacters(o.m_usedCharacters)
  , m_createdDate(o.m_createdDate)
  , m_modifiedDate(o.m_modifiedDate)
  , m_deleted(o.m_deleted)
  , m_extras(o.m_extras)
  , m_forceLowerCase(o.m_forceLowerCase)
  , m_forceUpperCase(o.m_forceUpperCase)
  , m_forceDigits(o.m_forceDigits)
  , m_forceExtra(o.m_forceExtra)
{ /* ... */ }


bool DomainSettings::isEmpty(void) const
{
  return m_domainName.isEmpty();
}



QVariantMap DomainSettings::toVariantMap(void) const
{
  QVariantMap map;
  map[DOMAIN_NAME] = m_domainName;
  if (m_deleted)
    map[DELETED] = true;
  map[CDATE] = m_createdDate;
  map[MDATE] = m_modifiedDate;
  if (!m_deleted) {
    if (!m_userName.isEmpty())
        map[USER_NAME] = m_userName;
    if (!m_url.isEmpty())
      map[URL] =m_url;
    if (!m_legacyPassword.isEmpty())
      map[LEGACY_PASSWORD] = m_legacyPassword;
    if (!m_notes.isEmpty())
      map[NOTES] = m_notes;
    map[ITERATIONS] = m_iterations;
    map[LENGTH] = m_length;
    map[SALT] = m_salt_base64;
    map[USED_CHARACTERS] = m_usedCharacters;
    if (!m_extras.isEmpty())
      map[EXTRAS] = m_extras;
  }
  return map;
}


DomainSettings DomainSettings::fromVariantMap(const QVariantMap &map)
{
  DomainSettings ds;
  ds.m_domainName = map[DOMAIN_NAME].toString();
  ds.m_userName = map[USER_NAME].toString();
  ds.m_url = map[URL].toString();
  ds.m_legacyPassword = map[LEGACY_PASSWORD].toString();
  ds.m_notes = map[NOTES].toString();
  ds.m_iterations = map[ITERATIONS].toInt();
  ds.m_length = map[LENGTH].toInt();
  ds.m_salt_base64 = map[SALT].toByteArray();
  ds.m_usedCharacters = map[USED_CHARACTERS].toString();
  ds.m_createdDate = QDateTime::fromString(map[CDATE].toString(), Qt::DateFormat::ISODate);
  ds.m_modifiedDate = QDateTime::fromString(map[MDATE].toString(), Qt::DateFormat::ISODate);
  ds.m_deleted = map[DELETED].toBool(); // XXX
  ds.m_extras = map[URL].toString();
  return ds;
}
