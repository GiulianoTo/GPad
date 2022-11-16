#include <QVBoxLayout>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _menuBar = new QMenuBar();
    _fileMenu = new QMenu("File");
    _openAction = new QAction(QIcon(":/icons/open.png"), "Open", _menuBar);
    _openAction->setShortcut(Qt::CTRL | Qt::Key_O);
    _fileMenu->addAction(_openAction);
    _editMenu = new QMenu("Edit");
    _aboutMenu = new QMenu("?");
    _menuBar->addMenu(_fileMenu);
    _menuBar->addMenu(_editMenu);
    _menuBar->addMenu(_aboutMenu);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->setContentsMargins(5,5,5,5);
    layout->addWidget(_menuBar);
    this->setLayout(layout);

}

MainWindow::~MainWindow()
{
}

