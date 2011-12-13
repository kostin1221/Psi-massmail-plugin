/*
 * massmailing.cpp - plugin
 * Copyright (C) 2009-2011  Kostin Dmitrij
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
#include <QMessageBox>

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

#include "senddialog.h"
#include "jiditemmodel.h"

#define cVer "0.1"

#define POPUP_OPTION "Mass Mailing Plugin"


class MassMailing: public QObject, public PsiPlugin, public OptionAccessor, public StanzaSender,  public StanzaFilter,
public AccountInfoAccessor, public ApplicationInfoAccessor, public PopupAccessor, public IconFactoryAccessor,
public PluginInfoProvider, public EventFilter, public ContactInfoAccessor, public MenuAccessor
{
	Q_OBJECT
        Q_INTERFACES(PsiPlugin OptionAccessor StanzaSender StanzaFilter AccountInfoAccessor ApplicationInfoAccessor
                     PopupAccessor IconFactoryAccessor PluginInfoProvider EventFilter ContactInfoAccessor MenuAccessor)

public:
        MassMailing();
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

public slots:
        void sendMessage(int account, QString jid, QString message, bool imp, QString topic = "");
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
};

Q_EXPORT_PLUGIN(MassMailing);

MassMailing::MassMailing()
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

QString MassMailing::name() const {
        return "Mass Mailing Plugin";
}

QString MassMailing::shortName() const {
        return "massmailing";
}

QString MassMailing::version() const {
        return cVer;
}

PsiPlugin::Priority MassMailing::priority() {
	return PriorityHighest;
}

bool MassMailing::enable() {
	if (psiOptions) {
		enabled = true;

		//register popup option
//		popup->registerOption(POPUP_OPTION, Interval, "plugins.options."+shortName()+"."+constInterval);
	}
	return enabled;
}

bool MassMailing::disable() {
        //delete stanzaHost;
        //stanzaHost = 0;

	enabled = false;        
	return true;
}

void MassMailing::applyOptions() {
	if (!options_)
		return;

}

void MassMailing::restoreOptions() {
	if (!options_)
		return;

}

QWidget* MassMailing::options() {
    return 0;
}

void MassMailing::setOptionAccessingHost(OptionAccessingHost* host) {
	psiOptions = host;
}

void MassMailing::setIconFactoryAccessingHost(IconFactoryAccessingHost* host) {
	icoHost = host;
}

void MassMailing::setPopupAccessingHost(PopupAccessingHost* host) {
	popup = host;
}

void MassMailing::setStanzaSendingHost(StanzaSendingHost *host) {
    stanzaHost = host;
        ///stanzaHost = new DefferedStanzaSender(host);
}

void MassMailing::setAccountInfoAccessingHost(AccountInfoAccessingHost* host) {
	accInfoHost = host;
}

void MassMailing::setApplicationInfoAccessingHost(ApplicationInfoAccessingHost* host) {
	appInfoHost = host;
}

void MassMailing::setContactInfoAccessingHost(ContactInfoAccessingHost *host) {
	contactInfo = host;
}

bool MassMailing::incomingStanza(int account, const QDomElement& stanza) {
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
                    clientItem->setData(child.attribute("jid"), Qt::UserRole);
                    clientItem->setCheckable(true);
                    groupItem->appendRow(clientItem);

                    //qDebug() << "Group: " << child.attribute("jid");
                    child = child.nextSiblingElement("item");
                }

                tree_model_list[account] = jidsModel;
            }
        }
        else if (stanza.tagName() == "message") {
            QString subj = stanza.firstChildElement("subject").text();
            QString type = "";
            type = stanza.attribute("type");
            //return true;
            if (type == "impchat"){
                QDomElement Body = stanza.firstChildElement("body");
                QDomElement Subj = stanza.firstChildElement("subject");
                QString from_jid = stanza.attribute("from");
                if(!Body.isNull()) {

                    QString BodyText = Body.text();

                    QString SubjText = QString::fromUtf8("Срочное сообщение!");

                    JidsViewModel *model = tree_model_list[account];


                    if ( from_jid.contains("/") )
                        from_jid = from_jid.split("/").at(0);
                    QString name = model->findNameByJid( from_jid );
                    ///if (!Subj.isNull()) {
                    //    SubjText = QString::fromUtf8("Срочное сообщение!: ") + SubjText;
                    //}

                    QMessageBox *msg = new QMessageBox(QMessageBox::Warning, SubjText, QString::fromUtf8("От: <font color=red>")+ name + "</font><br>" + BodyText, QMessageBox::Ok, 0, Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowStaysOnTopHint );
                    msg->setFont( QFont( "Arial", 11) );
                    msg->exec();
                    return true;
                }
            }
        }

    }
    return false;
}

void MassMailing::sendMessage(int account, QString jid, QString message, bool imp, QString topic){
    if (enabled){
        QString type;
        if (imp) {
            type = "impchat";
        } else type = "chat";
        stanzaHost->sendMessage(account, jid,  message, QString::fromUtf8("Рассылка сообщений"), type);
    }
}

bool MassMailing::outgoingStanza(int /*account*/, QDomElement& /*xml*/) {
    return false;
}

bool MassMailing::processOutgoingMessage(int acc, const QString &fromJid, QString &body, const QString &type, QString &/*subject*/) {

    return false;
}


void MassMailing::close(int width, int height) {
        //Height = height;
        //Width = width;
        //psiOptions->setPluginOption(constHeight, QVariant(Height));
        //psiOptions->setPluginOption(constWidth, QVariant(Width));
}

void MassMailing::changeWidgetsState() {

}

QString MassMailing::pluginInfo() {
        return tr("Author: ") +  "Dmitrij Kostin\n";
}

QList < QVariantHash > MassMailing::getAccountMenuParam() {
    QList< QVariantHash > l;
    //QVariantHash hash;
    //hash["name"] = QVariant(tr("Mass mailing2!"));
    //hash["reciver"] = qVariantFromValue(qobject_cast<QObject *>(this));
    //hash["slot"] = QVariant(SLOT(menuActivated()));
    //l.push_back(hash);
    return l;
}

QList < QVariantHash > MassMailing::getContactMenuParam() {
    QList< QVariantHash > l;
    QVariantHash hash;
    hash["name"] = QVariant(QString::fromUtf8("Массовая рассылка"));
    hash["reciver"] = qVariantFromValue(qobject_cast<QObject *>(this));
    hash["slot"] = QVariant(SLOT(menuActivated()));
    l.push_back(hash);
    return l;
}

void MassMailing::menuActivated() {
      if(!enabled) {
          return;
      }

      int account_ = sender()->property("account").toInt();
      if(accInfoHost->getStatus(account_) == "offline") {
          return;
      }

      if ( tree_model_list.contains(account_) ) {
          SendDialog* send_dlg = new SendDialog(0, tree_model_list[account_], account_);
          send_dlg->setAttribute( Qt::WA_DeleteOnClose, true );
          QObject::connect(send_dlg, SIGNAL(sendMessage(int, QString, QString, bool)), this, SLOT(sendMessage(int, QString, QString, bool)));


          send_dlg->exec();
      }
}


#include "massmailingplugin.moc"
