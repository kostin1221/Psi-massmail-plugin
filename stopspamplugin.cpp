/*
 * stopspamplugin.cpp - plugin
 * Copyright (C) 2009-2011  Khryukin Evgeny
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#include <QAction>
#include <QStandardItemModel>

#include "psiplugin.h"
#include "optionaccessor.h"
#include "optionaccessinghost.h"
#include "stanzafilter.h"
#include "stanzasender.h"
#include "stanzasendinghost.h"
#include "accountinfoaccessor.h"
#include "accountinfoaccessinghost.h"
#include "applicationinfoaccessor.h"
#include "applicationinfoaccessinghost.h"
#include "popupaccessor.h"
#include "popupaccessinghost.h"
#include "iconfactoryaccessor.h"
#include "iconfactoryaccessinghost.h"
#include "plugininfoprovider.h"
#include "eventfilter.h"
#include "contactinfoaccessinghost.h"
#include "contactinfoaccessor.h"
#include "menuaccessor.h"

#include "ui_options.h"
#include "senddialog.h"
#include "jiditemmodel.h"

#include "deferredstanzasender.h"

#define cVer "0.5.3"

#define POPUP_OPTION "Mass Mailing Plugin"


class StopSpam: public QObject, public PsiPlugin, public OptionAccessor, public StanzaSender,  public StanzaFilter,
public AccountInfoAccessor, public ApplicationInfoAccessor, public PopupAccessor, public IconFactoryAccessor,
public PluginInfoProvider, public EventFilter, public ContactInfoAccessor, public MenuAccessor
{
	Q_OBJECT
        Q_INTERFACES(PsiPlugin OptionAccessor StanzaSender StanzaFilter AccountInfoAccessor ApplicationInfoAccessor
                     PopupAccessor IconFactoryAccessor PluginInfoProvider EventFilter ContactInfoAccessor MenuAccessor)

public:
	StopSpam();
	virtual QString name() const;
	virtual QString shortName() const;
	virtual QString version() const;
	virtual PsiPlugin::Priority priority();
        virtual QWidget* options();
	virtual bool enable();
        virtual bool disable();
        virtual void applyOptions();
        virtual void restoreOptions();
        virtual void setOptionAccessingHost(OptionAccessingHost* host);
	virtual void optionChanged(const QString& ) {};
        virtual void setStanzaSendingHost(StanzaSendingHost *host);
        virtual bool incomingStanza(int account, const QDomElement& xml);
	virtual bool outgoingStanza(int account, QDomElement& xml);
        virtual void setAccountInfoAccessingHost(AccountInfoAccessingHost* host);
        virtual void setApplicationInfoAccessingHost(ApplicationInfoAccessingHost* host);
        virtual void setPopupAccessingHost(PopupAccessingHost* host);
        virtual void setIconFactoryAccessingHost(IconFactoryAccessingHost* host);
	virtual void setContactInfoAccessingHost(ContactInfoAccessingHost* host);
	virtual QString pluginInfo();

	virtual bool processEvent(int , QDomElement& ) { return false; }
        virtual bool processMessage(int , const QString& , const QString& , const QString& ) { return false; }
	virtual bool processOutgoingMessage(int account, const QString& fromJid, QString& body, const QString& type, QString& subject);
        virtual void logout(int ) {}


        virtual QList < QVariantHash > getAccountMenuParam();
        virtual QList < QVariantHash > getContactMenuParam();
        virtual QAction* getContactAction(QObject* , int , const QString& ) { return 0; }
        virtual QAction* getAccountAction(QObject* , int ) { return 0; }

private slots:
	void close(int w, int h);
	void changeWidgetsState();

        void menuActivated();

private:

        QHash<int, JidsViewModel *> tree_model_list;

	bool enabled;
	OptionAccessingHost* psiOptions;        
        StanzaSendingHost* stanzaHost;
	AccountInfoAccessingHost *accInfoHost;
	ApplicationInfoAccessingHost *appInfoHost;
        IconFactoryAccessingHost* icoHost;
        PopupAccessingHost* popup;
	ContactInfoAccessingHost* contactInfo;

	int Height; //высота и ширина
	int Width;

	QPointer<QWidget> options_;
	Ui::Options ui_;
};

Q_EXPORT_PLUGIN(StopSpam);

StopSpam::StopSpam()
	: enabled(false)
	, psiOptions(0)
	, stanzaHost(0)
	, accInfoHost(0)
	, appInfoHost(0)
	, icoHost(0)
	, Height(500)
        , Width(600)
	, options_(0)
{
}

QString StopSpam::name() const {
        return "Mass Mailing Plugin";
}

QString StopSpam::shortName() const {
        return "massmailing";
}

QString StopSpam::version() const {
        return cVer;
}

PsiPlugin::Priority StopSpam::priority() {
	return PriorityHighest;
}

bool StopSpam::enable() {
	if (psiOptions) {
		enabled = true;

		//register popup option
//		popup->registerOption(POPUP_OPTION, Interval, "plugins.options."+shortName()+"."+constInterval);
	}
	return enabled;
}

bool StopSpam::disable() {
	delete stanzaHost;
	stanzaHost = 0;

	enabled = false;        
	return true;
}

void StopSpam::applyOptions() {
	if (!options_)
		return;

}

void StopSpam::restoreOptions() {
	if (!options_)
		return;

}

QWidget* StopSpam::options() {
    return 0;
}

void StopSpam::setOptionAccessingHost(OptionAccessingHost* host) {
	psiOptions = host;
}

void StopSpam::setIconFactoryAccessingHost(IconFactoryAccessingHost* host) {
	icoHost = host;
}

void StopSpam::setPopupAccessingHost(PopupAccessingHost* host) {
	popup = host;
}

void StopSpam::setStanzaSendingHost(StanzaSendingHost *host) {
    stanzaHost = host;
        ///stanzaHost = new DefferedStanzaSender(host);
}

void StopSpam::setAccountInfoAccessingHost(AccountInfoAccessingHost* host) {
	accInfoHost = host;
}

void StopSpam::setApplicationInfoAccessingHost(ApplicationInfoAccessingHost* host) {
	appInfoHost = host;
}

void StopSpam::setContactInfoAccessingHost(ContactInfoAccessingHost *host) {
	contactInfo = host;
}

bool StopSpam::incomingStanza(int account, const QDomElement& stanza) {
    if (enabled) {
        if(stanza.tagName() == "iq") {
                QDomElement query = stanza.firstChildElement("query");
                if(!query.isNull()
                        && query.attribute("xmlns") == "jabber:iq:roster") {

                        QDomElement child = query.firstChildElement("item");
                        JidsViewModel *jidsModel = new JidsViewModel();
                        QStandardItem *rootItem = new QStandardItem(tr("Root")); //Сюда попадают юзеры без группы
                        rootItem->setCheckable(true);
                        jidsModel->appendRow(rootItem);

                        QStandardItem *groupItem;
                        while ( !child.isNull() ) {
                            QDomElement group = child.firstChildElement("group");

                            if ( !group.isNull() ){  //Если у юзера есть группа
                                QString groupName = group.text();
                                QList<QStandardItem *> items = jidsModel->findItems(groupName); //Пытаемся найти группу, если были контакты с такой группой
                                if (items.count() > 0){
                                    groupItem = items[0];

                                }   else {
                                    groupItem = new QStandardItem(groupName);
                                    groupItem->setCheckable(true);
                                    jidsModel->appendRow(groupItem);
                                }
                            } else {
                                groupItem = rootItem;  //По умолчанию - кидаем в корень
                            }

                            QStandardItem *clientItem = new QStandardItem(child.attribute("name"));
                            clientItem->setData(child.attribute("jid"), Qt::EditRole);
                            clientItem->setCheckable(true);
                            groupItem->appendRow(clientItem);

                            //qDebug() << "Group: " << child.attribute("jid");
                            child = child.nextSiblingElement("item");
                        }

                        tree_model_list[account] = jidsModel;


                        /*QStringList Roster = accInfoHost->getRoster(account);
                        QStringList UnblockedList = Unblocked.split("\n");
                        while(!Roster.isEmpty()) {
                                QString jid = Roster.takeFirst();
                                UnblockedList.removeOne(jid);
                        }
                        Unblocked = "";
                        while(!UnblockedList.isEmpty()) {
                                QString jid = UnblockedList.takeFirst();
                                if(jid != "") {
                                        Unblocked += jid + "\n";
                                }
                        }
                        psiOptions->setPluginOption(constUnblocked, QVariant(Unblocked));*/
                }
        }
    }

//		QString from = stanza.attribute("from");
//		QString to = stanza.attribute("to");
//		QString valF = from.split("/").takeFirst();
//		QString valT = to.split("/").takeFirst();

//		if(valF.toLower() == valT.toLower()
//			|| valF.toLower() == accInfoHost->getJid(account).toLower())
//			return false;

//		if(!from.contains("@"))
//			return false;

//		// Нам необходимо сделать эту проверку здесь,
//		// иначе мы рискуем вообще ее не сделать
//		if (stanza.tagName() == "message") {
//			bool findInvite = false;
//			QString invFrom;
//			QDomElement x = stanza.firstChildElement("x");
//			while(!x.isNull()) {
//				QDomElement invite = x.firstChildElement("invite");
//				if(!invite.isNull()) {
//					findInvite = true;
//					invFrom = invite.attribute("from");
//					break;
//				}
//				x = x.nextSiblingElement("x");
//			}
//			if(findInvite) {  // invite to MUC
//				QStringList r = accInfoHost->getRoster(account);
//				if(r.contains(invFrom.split("/").first(), Qt::CaseInsensitive))
//					return false;
//				else {
//					bool findRule = false;
//					for(int i = 0; i < Jids.size(); i++) {
//						QString jid_ = Jids.at(i);
//						if(jid_.isEmpty())
//							continue;
//						if(invFrom.contains(jid_, Qt::CaseInsensitive)) {
//							findRule = true;
//							if(!selected[i].toBool())
//								return false;
//							break;
//						}
//					}
//					if(!findRule && DefaultAct)
//						return false;
//					else {
//						updateCounter(stanza, false);
//						return true;
//					}
//				}
//			}
//		}

//		if(contactInfo->isConference(account, valF)
//			|| contactInfo->isPrivate(account, from)
//			|| findMucNS(stanza))
//			{
//			if(UseMuc)
//				return processMuc(account, stanza);
//			else
//				return false;
//		}

//		QStringList Roster = accInfoHost->getRoster(account);
//		if(Roster.isEmpty() || Roster.contains("-1"))
//			return false;
//		if(Roster.contains(valF, Qt::CaseInsensitive))
//			return false;

//		QStringList UnblockedJids = Unblocked.split("\n");
//		if(UnblockedJids.contains(valF, Qt::CaseInsensitive))
//			return false;

//		bool findRule = false;
//		for(int i = 0; i < Jids.size(); i++) {
//			QString jid_ = Jids.at(i);
//			if(jid_.isEmpty())
//				continue;
//			if(from.contains(jid_, Qt::CaseInsensitive)) {
//				findRule = true;
//				if(!selected[i].toBool())
//					return false;
//				break;
//			}
//		}
//		if(!findRule && DefaultAct)
//			return false;

//		if (stanza.tagName() == "message") {
//			QString subj = stanza.firstChildElement("subject").text();
//			QString type = "";
//			type = stanza.attribute("type");
//			if(type == "error" && subj == "StopSpam Question") {
//				updateCounter(stanza, false);
//				return true;
//			}

//			if (subj == "AutoReply" || subj == "StopSpam" || subj == "StopSpam Question")
//				return false;

//			if(type == "groupchat" || type == "error")
//				return false;

//			QDomElement captcha = stanza.firstChildElement("captcha");
//			if(!captcha.isNull() && captcha.attribute("xmlns") == "urn:xmpp:captcha")
//				return false; // CAPTCHA

//			QDomElement Body = stanza.firstChildElement("body");
//                        qDebug() << Body;
//                        /*if(!Body.isNull()) {
//				QString BodyText = Body.text();
//				if(BodyText == Answer) {
//					Unblocked += valF + "\n";
//					psiOptions->setPluginOption(constUnblocked, QVariant(Unblocked));
//					psiOptions->setPluginOption(constLastUnblock, QVariant(QDate::currentDate().toString("yyyyMMdd")));
//					stanzaHost->sendMessage(account, from, Congratulation, "StopSpam", "chat");
//					updateCounter(stanza, true);
//					if(LogHistory)
//						logHistory(stanza);
//					return true;
//				}
//				else {
//					int i = BlockedJids.size();
//					if(findAcc(account, valF, i)) {
//						Blocked &B = BlockedJids[i];
//						if(B.count < Times) {
//							stanzaHost->sendMessage(account, from,  Question, "StopSpam Question", "chat");
//							updateCounter(stanza, false);
//							if(LogHistory)
//								logHistory(stanza);
//							B.count++;
//							B.LastMes = QDateTime::currentDateTime();
//							return true;
//						}
//						else {
//							if(QDateTime::currentDateTime().secsTo(B.LastMes) >= -ResetTime*60) {
//								updateCounter(stanza, false);
//								if(LogHistory)
//									logHistory(stanza);
//								return true;
//							}
//							else {
//								B.count = 1;
//								B.LastMes = QDateTime::currentDateTime();
//								stanzaHost->sendMessage(account, from,  Question, "StopSpam Question", "chat");
//								updateCounter(stanza, false);
//								if(LogHistory)
//									logHistory(stanza);
//								return true;
//							}
//						}
//					}
//					else {
//						Blocked B = { account, valF, 1, QDateTime::currentDateTime() };
//						BlockedJids << B;
//						stanzaHost->sendMessage(account, from,  Question, "StopSpam Question", "chat");
//						updateCounter(stanza, false);
//						if(LogHistory)
//							logHistory(stanza);
//						return true;
//					}
//				}
//			}
//			updateCounter(stanza, false);
//                        */return true;
//		}

//		return false;
//	}

        return false;
}

bool StopSpam::outgoingStanza(int /*account*/, QDomElement& /*xml*/) {
	return false;
}

bool StopSpam::processOutgoingMessage(int acc, const QString &fromJid, QString &body, const QString &type, QString &/*subject*/) {
        /*if(enabled && type != "groupchat" && !body.isEmpty()) {
		QString bareJid;
		if(contactInfo->isPrivate(acc, fromJid)) {
			bareJid = fromJid;
		}
		else {
			bareJid =  fromJid.split("/").first();
			if(contactInfo->inList(acc, bareJid))
				return false;
		}
		if(!Unblocked.split("\n").contains(bareJid, Qt::CaseInsensitive)) {
			Unblocked += bareJid + "\n";
			psiOptions->setPluginOption(constUnblocked, QVariant(Unblocked));
			psiOptions->setPluginOption(constLastUnblock, QVariant(QDate::currentDate().toString("yyyyMMdd")));
		}
        }*/
	return false;
}



void StopSpam::close(int width, int height) {
        //Height = height;
        //Width = width;
        //psiOptions->setPluginOption(constHeight, QVariant(Height));
        //psiOptions->setPluginOption(constWidth, QVariant(Width));
}

void StopSpam::changeWidgetsState() {

}

QString StopSpam::pluginInfo() {
        return tr("Author: ") +  "Dmitrij Kostin\n";
}

QList < QVariantHash > StopSpam::getAccountMenuParam() {
    QList< QVariantHash > l;
    QVariantHash hash;
    hash["name"] = QVariant(tr("Mass mailing2!"));
    //hash["icon"] = QVariant(QString("chessplugin/chess"));
    hash["reciver"] = qVariantFromValue(qobject_cast<QObject *>(this));
    hash["slot"] = QVariant(SLOT(menuActivated()));
    l.push_back(hash);
    return l;
      //  return QList < QVariantHash >();
}

QList < QVariantHash > StopSpam::getContactMenuParam() {
        QList< QVariantHash > l;
        QVariantHash hash;
        hash["name"] = QVariant(tr("Mass mailing!"));
        hash["reciver"] = qVariantFromValue(qobject_cast<QObject *>(this));
        hash["slot"] = QVariant(SLOT(menuActivated()));
        l.push_back(hash);
        return l;
}

void StopSpam::menuActivated() {
    /*  if(!enabled) {
                      return;
      }*/

      int account_ = sender()->property("account").toInt();
      if(accInfoHost->getStatus(account_) == "offline") {
              return;
      }

      if ( tree_model_list.contains(account_) ) {
          SendDialog* send_dlg = new SendDialog(0, tree_model_list[account_]);
          send_dlg->exec();
      }

     // QStringList Roster = accInfoHost->getRoster(account_);

  // qDebug() << Roster;

  //    qDebug() << "menu";
}


#include "stopspamplugin.moc"
