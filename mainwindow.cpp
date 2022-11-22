#include "mainwindow.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include "document.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _menuBar = new QMenuBar();

    // File menu
    _fileMenu = new QMenu("File");

    _newAction = new QAction(QIcon(":/icons/new.png"), "New", _fileMenu);
    _newAction->setShortcut(Qt::CTRL | Qt::Key_N);
    _fileMenu->addAction(_newAction);

    _openAction = new QAction(QIcon(":/icons/open.png"), "Open", _fileMenu);
    _openAction->setShortcut(Qt::CTRL | Qt::Key_O);
    _fileMenu->addAction(_openAction);

    _openRecentMenu = new QMenu("Open recent");
    _fileMenu->addMenu(_openRecentMenu);

    _saveAction = new QAction(QIcon(":/icons/save.png"), "Save", _fileMenu);
    _saveAction->setShortcut(Qt::CTRL | Qt::Key_S);
    _fileMenu->addAction(_saveAction);

    _saveAsAction = new QAction("Save as", _fileMenu);
    _fileMenu->addAction(_saveAsAction);

    _printAction = new QAction(QIcon(":/icons/printer.png"), "Print", _fileMenu);
    _printAction->setShortcut(Qt::CTRL | Qt::Key_P);
    _fileMenu->addSeparator();
    _fileMenu->addAction(_printAction);
    _fileMenu->addSeparator();

    _exitAction = new QAction("Exit", _fileMenu);
    _exitAction->setShortcut(Qt::CTRL | Qt::Key_Q);
    _fileMenu->addAction(_exitAction);

    // Edit menu
    _editMenu = new QMenu("Edit");

    _undoAction = new QAction(QIcon(":/icons/undo.png"), "Undo", _fileMenu);
    _undoAction->setShortcut(Qt::CTRL | Qt::Key_Z);
    _editMenu->addAction(_undoAction);

    _redoAction = new QAction(QIcon(":/icons/redo.png"), "Redo", _fileMenu);
    _redoAction->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_Z);
    _editMenu->addAction(_redoAction);

    // About menu
    _aboutMenu = new QMenu("?");

    _aboutQtAction = new QAction("About Qt", _aboutMenu);
    _aboutMenu->addAction(_aboutQtAction);

    _aboutAction = new QAction(QIcon(":/icons/about.png"), "About GPad", _aboutMenu);
    _aboutMenu->addAction(_aboutAction);

    _menuBar->addMenu(_fileMenu);
    _menuBar->addMenu(_editMenu);
    _menuBar->addMenu(_aboutMenu);

    // tool bar
    _toolBar = new QToolBar();
    _toolBar->addAction(_newAction);
    _toolBar->addAction(_openAction);
    _toolBar->addAction(_saveAction);
    _toolBar->addAction(_printAction);
    _toolBar->addSeparator();
    _toolBar->addAction(_undoAction);
    _toolBar->addAction(_redoAction);
    _toolBar->addSeparator();
    _toolBar->addAction(_aboutAction);

    _tabs = new QTabWidget();
    _tabs->addTab(new Document(), "new 1");

    _statusBar = new QStatusBar();
    _statusBar->showMessage("Hello! Gpad");

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(_menuBar);
    layout->addWidget(_toolBar);
    layout->addWidget(_tabs);
    layout->addWidget(_statusBar);

    auto _central = new QWidget;
    _central->setLayout(layout);
    setCentralWidget(_central);
    //setMinimumSize(800,600);
    setWindowIcon(QIcon(":/icons/notepad.png"));
    //setWindowState(Qt::WindowMaximized);

    // connections
    connect(_aboutAction, SIGNAL(triggered(bool)), this, SLOT(aboutActionTriggered()));
    connect(_aboutQtAction, SIGNAL(triggered(bool)), this, SLOT(aboutQtActionTriggered()));
}

MainWindow::~MainWindow() {}

void MainWindow::aboutActionTriggered()
{
    QMessageBox::about(this, "About GPad", "<html><b>GPad 1.0</b>");
}

void MainWindow::aboutQtActionTriggered()
{
    QMessageBox::aboutQt(this);
}
