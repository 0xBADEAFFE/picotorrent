#include "systemtrayicon.hpp"

#include <QAction>
#include <QMenu>

#include "translator.hpp"

using pt::SystemTrayIcon;

SystemTrayIcon::SystemTrayIcon(QObject* parent)
    : QSystemTrayIcon(parent)
{
    m_menu                = new QMenu();
    m_addTorrentAction    = new QAction(i18n("add_torrent"));
    m_addMagnetLinkAction = new QAction(i18n("add_magnet_link_s"));
    m_preferencesAction   = new QAction(i18n("preferences"));
    m_exitAction          = new QAction(i18n("exit"));

    m_menu->addAction(m_addTorrentAction);
    m_menu->addAction(m_addMagnetLinkAction);
    m_menu->addSeparator();
    m_menu->addAction(m_preferencesAction);
    m_menu->addSeparator();
    m_menu->addAction(m_exitAction);

    connect(m_addTorrentAction,    &QAction::triggered, this, &SystemTrayIcon::addTorrentRequested);
    connect(m_addMagnetLinkAction, &QAction::triggered, this, &SystemTrayIcon::addMagnetLinkRequested);
    connect(m_preferencesAction,   &QAction::triggered, this, &SystemTrayIcon::viewPreferencesRequested);
    connect(m_exitAction,          &QAction::triggered, this, &SystemTrayIcon::exitRequested);

    this->setContextMenu(m_menu);
    this->setIcon(QIcon(":res/app.ico"));
}
