#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <iterator>
#include <string>
#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include <QVBoxLayout>
#include <QString>
#include <QLabel>
#include <QKeySequence>
#include <QIcon>
#include "session.hpp"
#include <QPushButton>
#include <QGroupBox>
#include <QString>
#include <QFrame>
#include <QInputDialog>
#include <QDir>
#include <QTreeView>
#include <QCommandLineParser>
#include <QFileSystemModel>
#include <QFileIconProvider>
#include <QDirModel>
#include <QModelIndex>
#include <QTreeWidget>
#include <QList>
#include <QPalette>
#include <QTextEdit>
#include <QFormLayout>
#include <QListView>
#include <QBoxLayout>
#include <QSignalMapper>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Session* session;
    void createQuickAccessGroupBox();
    void createActions();
    void createMenus();
    void createDirectory();

    Ui::MainWindow *ui;

    QFrame* horizontalGroupBox;
    QFrame* groupQA;
    QFrame* tagQA;
    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* findMenu;
    QMenu* helpMenu;
    QAction* newTagAct;
    QAction* newGroupAct;
    QAction* addToGroupAct;
    QAction* removeFromGroupAct;
    QAction* changeTagAct;
    QAction* removeTagAct;
    QAction* removeDataTagAct;
    QAction* associateTagAct;
    QAction* disassociateTagAct;
    QAction* searchTagAct;
    QAction* aboutAct;
    QAction* exitAct;
    QLabel* infoLabel;
    QGridLayout* layoutQuickAccess;
    QGridLayout* layoutTagQA;
    QGridLayout* layoutGroupQA;
    QTreeView* treeView;
    QDirModel* model;
    QDialog* aboutDialog;
    QDialog* searchDialog;
    QStringList* searchStrings;
    QSignalMapper* signalMapper;
    QLineEdit* tag1Edit;
    QLineEdit* tag2Edit;

private slots:
    void newTag();
    void newGroup();
    void addToGroup();
    void removeFromGroup();
    void changeTag();
    void removeTag();
    void removeDataTag();
    void associateTag();
    void disassociateTag();
    void search();
    void about();
    void handleButton();
    void searchHandleButton();
    void addSearchString();
    void setSelectGroup(const QString &groupName);
    void addToGroupView(const QModelIndex &toAdd, const QString &groupName);

};

#endif // MAINWINDOW_HPP
