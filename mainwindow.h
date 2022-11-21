#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QMenuBar>
#include <QWidget>
#include <QMenu>
#include <QStatusBar>
#include <QTabWidget>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QMenuBar* _menuBar;
    QMenu* _fileMenu;
    QAction* _newAction;
    QAction* _openAction;
    QMenu* _openRecentMenu;
    QAction* _saveAction;
    QAction* _saveAsAction;
    QAction* _printAction;
    QAction* _exitAction;
    QMenu* _editMenu;
    QAction* _undoAction;
    QAction* _redoAction;
    QMenu* _aboutMenu;
    QAction* _aboutAction;
    QAction* _aboutQtAction;

    QToolBar* _toolBar;

    QTabWidget* _tabs;

    QStatusBar* _statusBar;

public slots:

    void aboutActionTriggered();
    void aboutQtActionTriggered();

};
#endif // MAINWINDOW_H
