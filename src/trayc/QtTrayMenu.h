#ifndef TRAYMENU_H
#define TRAYMENU_H

#include <QSystemTrayIcon>
#include <QMenu>
#include <QObject>
#include "tray.h"

class QtTrayMenu : public QObject
        {
            Q_OBJECT

            public:
                QtTrayMenu();
                ~QtTrayMenu();
                virtual bool eventFilter(QObject *watched, QEvent *event) override;
                int init(struct tray *tray);
                void update(struct tray *tray);
                int loop(int blocking, struct tray *tray);
                void exit();

            private:
                void createMenu(struct tray_menu_item *items, QMenu *menu);
                void onTrayActivated(QSystemTrayIcon::ActivationReason reason);
                void onMenuItemTriggered();
                QApplication *app;
                QSystemTrayIcon *trayIcon;
                struct tray *trayStruct;
                QString toolTip(struct tray *tray);
                bool continueRunning;
                struct tray_menu_item *getTrayMenuItem(QAction *action);

            signals:
                void exitRequested();

            private slots:
                void onExitRequested();

};


#endif // TRAYMENU_H
