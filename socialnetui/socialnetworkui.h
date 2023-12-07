
#ifndef SOCIALNETWORKUI_H
#define SOCIALNETWORKUI_H
#include "Network.h"
#include "stack"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class socialnetworkui; }
QT_END_NAMESPACE

class socialnetworkui : public QMainWindow

{
    Q_OBJECT

public:
    socialnetworkui(QWidget *parent = nullptr);
    ~socialnetworkui();

private slots:
    void gohome();
    void visitDisplayed();
    void visitNewDisplayed();

//    void findUser();
    void reccommendFriend();
    void Checkname();
    void addFriend();
    void goback();



private:
    Ui::socialnetworkui *ui;
    Network alpha;
    User* lgd;
    User* displayed;
    std::stack<std::string> pastUsers;
    std::stack<std::string> actions;


};

#endif // SOCIALNETWORKUI_H
