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


#ifndef __DOMAINSETTINGS_H_
#define __DOMAINSETTINGS_H_

#include <QObject>
#include <QString>
#include <QStringList>
#include <QVariantMap>
#include <QDateTime>

class DomainSettings : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString domainName READ domainName WRITE setDomainName)
  Q_PROPERTY(QString url READ url WRITE setUrl)
  Q_PROPERTY(QString extras READ extras WRITE setExtras)
  Q_PROPERTY(QString userName READ userName WRITE setUserName)
  Q_PROPERTY(QString legacyPassword READ legacyPassword WRITE setLegacyPassword)
  Q_PROPERTY(QString notes READ notes WRITE setNotes)
  Q_PROPERTY(QString salt_base64 READ salt_base64 WRITE setSalt_base64)
  Q_PROPERTY(int iterations READ iterations WRITE setIterations)
  Q_PROPERTY(int length READ length WRITE setLength)
  Q_PROPERTY(QString usedCharacters READ usedCharacters WRITE setUsedCharacters)
  Q_PROPERTY(QDateTime createdDate READ createdDate WRITE setCreatedDate)
  Q_PROPERTY(QDateTime modifiedDate READ modifiedDate WRITE setModifiedDate)
  Q_PROPERTY(bool deleted READ deleted WRITE setDeleted)
  Q_PROPERTY(bool forceLowerCase READ forceLowerCase WRITE setForceLowerCase)
  Q_PROPERTY(bool forceUpperCase READ forceUpperCase WRITE setForceUpperCase)
  Q_PROPERTY(bool forceDigits READ forceDigits WRITE setForceDigits)
  Q_PROPERTY(bool forceExtra READ forceExtra WRITE setForceExtra)

public:
  DomainSettings(void);
  DomainSettings(const DomainSettings &);
  ~DomainSettings() {}

  const QString &domainName(void) const { return m_domainName; }
  void setDomainName(const QString &v) { m_domainName = v; }

  const QString &url(void) const { return m_url; }
  void setUrl(const QString &v) { m_url = v; }

  const QString &extras(void) const { return m_extras; }
  void setExtras(const QString &v) { m_extras = v; }

  const QString &userName(void) const { return m_userName; }
  void setUserName(const QString &v) { m_userName = v; }

  const QString &legacyPassword(void) const { return m_legacyPassword; }
  void  setLegacyPassword(const QString &v) { m_legacyPassword = v; }

  const QString &notes(void) const { return m_notes; }
  void setNotes(const QString &v) { m_notes = v; }

  const QString &salt_base64(void) const { return m_salt_base64; }
  void setSalt_base64(const QString &v) { m_salt_base64 = v; }

  int iterations(void) const { return m_iterations; }
  void setIterations(int v) { m_iterations = v; }

  int length(void) const { return m_length; }
  void setLength(int v) { m_length = v; }

  const QString &usedCharacters(void) const { return m_usedCharacters; }
  void setUsedCharacters(const QString &v) { m_usedCharacters = v; }

  const QDateTime &createdDate(void) const { return m_createdDate; }
  void setCreatedDate(const QDateTime &dt) { m_createdDate = dt ; }

  const QDateTime &modifiedDate(void) const { return m_modifiedDate; }
  void setModifiedDate(const QDateTime &dt) { m_modifiedDate = dt ; }

  bool deleted(void) const { return m_deleted; }
  void setDeleted(bool d) { m_deleted = d; }

  bool forceLowerCase(void) const { return m_forceLowerCase; }
  void setForceLowerCase(bool f) { m_forceLowerCase = f; }

  bool forceUpperCase(void) const { return m_forceUpperCase; }
  void setForceUpperCase(bool f) { m_forceUpperCase = f; }

  bool forceDigits(void) const { return m_forceDigits; }
  void setForceDigits(bool f) { m_forceDigits = f;}

  bool forceExtra(void) const { return m_forceExtra; }
  void setForceExtra(bool f)  { m_forceExtra = f; }

  QVariantMap toVariantMap(void) const;
  bool isEmpty(void) const;

  static DomainSettings fromVariantMap(const QVariantMap &);

  static const QByteArray DefaultSalt;
  static const QByteArray DefaultSalt_base64;
  static const int DefaultIterations;
  static const int DefaultPasswordLength;
  static const int DefaultSaltLength;

  static const QString DOMAIN_NAME;
  static const QString URL;
  static const QString EXTRAS;
  static const QString USER_NAME;
  static const QString LEGACY_PASSWORD;
  static const QString NOTES;
  static const QString SALT;
  static const QString ITERATIONS;
  static const QString LENGTH;
  static const QString USED_CHARACTERS;
  static const QString CDATE;
  static const QString MDATE;
  static const QString DELETED;

private:
  QString m_domainName;
  QString m_url;
  QString m_extras;
  QString m_userName;
  QString m_legacyPassword;
  QString m_notes;
  QString m_salt_base64;
  int m_iterations;
  int m_length;
  QString m_usedCharacters;
  QDateTime m_createdDate;
  QDateTime m_modifiedDate;
  bool m_deleted;
  bool m_forceLowerCase;
  bool m_forceUpperCase;
  bool m_forceDigits;
  bool m_forceExtra;
};



#endif // __DOMAINSETTINGS_H_
