
#include "socialnetworkui.h"
#include "ui_socialnetworkui.h"
#include <QDebug>
#include<QFile>

socialnetworkui::socialnetworkui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::socialnetworkui)
{
    ui->setupUi(this);

//    if(alpha.read_users("C:/Users/totoz/Downloads/SN-2 (3).txt")){
//        qDebug() << "read success";
//    } else {
//        qDebug() << "read fail";
//    }
    if(alpha.read_users("../socialnetui/social_network.txt")){
                qDebug() << "read success";
    }
    else {
                qDebug() << "read fail";
    }
            //alpha.print_users();


    if(alpha.read_posts("../socialnetui/posts (1).txt")){
        qDebug() << "read success";
    } else {
        qDebug() << "read fail";
    }


    ui->AddFriend->setVisible(false);
    ui->FriendList->setVisible(false);
    ui->HomeButton->setVisible(false);
    ui->backButton->setVisible(false);
    ui->NameProfile->setVisible(false);
    ui->TablePosts->setVisible(false);
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->scrollArea->setVisible(false);
    ui->FriendSuggestions->setVisible(false);
    ui->scrollArea->setFrameShape(QFrame::NoFrame);
    ui->scrollArea_2->setVisible(false);
    ui->scrollArea_2->setFrameShape(QFrame::NoFrame);
    ui->scrollArea_3->setVisible(false);
    ui->scrollArea_3->setFrameShape(QFrame::NoFrame);
        connect(ui->LoginButton,&QPushButton::clicked,this,&socialnetworkui::Checkname);
        connect(ui->FriendList,&QListWidget::itemClicked,this,&socialnetworkui::visitDisplayed);
        connect(ui->FriendSuggestList,&QListWidget::itemClicked,this,&socialnetworkui::visitNewDisplayed);
        connect(ui->HomeButton,&QPushButton::clicked,this,&socialnetworkui::gohome);
        connect(ui->AddFriend,&QPushButton::clicked,this,&socialnetworkui::addFriend);
        connect(ui->FriendSuggestions,&QPushButton::clicked,this,&socialnetworkui::reccommendFriend);
        connect(ui->backButton,&QPushButton::clicked,this,&socialnetworkui::goback);
}


socialnetworkui::~socialnetworkui()
{
    delete ui;
}
/*
Method: Checkname

param: none
Checks if name exists and assigns User LGD to the same User of entered name
*/
void socialnetworkui::Checkname(){

    QString q = ui->LoginLine->text();
    int a = alpha.get_id(q.toStdString());
    lgd = alpha.get_user(a);
    if(alpha.get_id(q.toStdString())>-1){
        ui->FriendList->setVisible(true);
        ui->FriendSuggestList->setVisible(true);
        ui->FriendSuggestions->setVisible(true);
        ui->NameProfile->setVisible(true);
        ui->TablePosts->setVisible(true);
        ui->label->setVisible(true);
        ui->label_2->setVisible(true);
        ui->label_3->setVisible(true);
        ui->scrollArea->setVisible(true);
        ui->scrollArea_2->setVisible(true);
        ui->scrollArea_3->setVisible(true);
        ui->scrollArea_3->setFrameShape(QFrame::NoFrame);
        ui->LoginButton->setVisible(false);
        ui->LoginLine->setVisible(false);
        ui->backButton->setVisible(true);
        QString x = QString::fromStdString(lgd->get_fullName());
//        count++;
        ui->NameProfile->setText(x);
        for(int i = 0; i<lgd->get_connections().size(); i++){
            int x= lgd->get_connections()[i];
            QString s = QString::fromStdString(alpha.get_user(x)->get_fullName());
            ui->FriendList->addItem(s);
        }
        ui->TablePosts->addItem(QString::fromStdString(lgd->display_posts(5, false)));
        pastUsers.push(lgd->get_fullName());
        actions.push("Visit");

    }
    ui->LoginLine->setText("No Name Exists");

}
/*
Method: gohome

param: none
returns UI to User LGD
*/
void socialnetworkui::gohome(){
    ui->label->setVisible(true);
    ui->scrollArea_2->setVisible(true);
    ui->FriendSuggestions->setVisible(true);
    ui->HomeButton->setVisible(false);
    ui->AddFriend->setVisible(false);
    QString x = QString::fromStdString(lgd->get_fullName());
    ui->NameProfile->setText(x);
    while(ui->FriendSuggestList->count()>0)
    {
        ui->FriendSuggestList->takeItem(0);
    }
    while(ui->FriendList->count()>0)
    {
        ui->FriendList->takeItem(0);
    }
    while(ui->TablePosts->count()>0)
    {
        ui->TablePosts->takeItem(0);
    }
    for(int i = 0; i<lgd->get_connections().size(); i++){
        int x= lgd->get_connections()[i];
        QString s = QString::fromStdString(alpha.get_user(x)->get_fullName());
        ui->FriendList->addItem(s);
    }
    ui->TablePosts->addItem(QString::fromStdString(lgd->display_posts(5, false)));
    pastUsers.push(lgd->get_fullName());
    actions.push("Visit");
}
//void socialnetworkui::findUser(){
////           QString q = ui->shortestPath->text();
////           QString l = "No Path";
////            string a;
////           if(alpha.get_id(q.toStdString())>-1){

////           int x = alpha.shortest_path(lgd->get_id(),alpha.get_id(q.toStdString())).size();
////           vector<int> hi = alpha.shortest_path(lgd->get_id(),alpha.get_id(q.toStdString()));
////           a = x;
////           if(x>0){
////    //        for(int i = 0; i<x;i++){
////    //        a= to_string(hi[i]);
////    //        }

////    //       }
////            l = l.fromStdString(a);
////           }


////           ui->shortestPath->setText(l);

////    }
//}
/*
Method: reccommendFriend

param: none
reccomends friends to LGD
*/
void socialnetworkui::reccommendFriend(){
    if(ui->FriendSuggestList->count()==0){
        actions.push("Reccomend");
    }
    size_t i = 1;
    size_t& score = i;
    ui->FriendSuggestList->clear();
    std::vector<int> suggest = alpha.suggest_friends(lgd->get_id(),score);
    for(int i = 0; i< suggest.size();i++){
        QString s = QString::fromStdString(alpha.get_user(suggest[i])->get_fullName());
        ui->FriendSuggestList->addItem(s);
    }

}
/*
Method: visitDisplayed

param: none
visits the clicked User on the friend list
*/
void socialnetworkui::visitDisplayed(){
    ui->label_3->setVisible(false);
    ui->scrollArea_2->setVisible(false);
    ui->FriendSuggestions->setVisible(false);
    ui->HomeButton->setVisible(true);
    ui->AddFriend->setVisible(true);
    ui->backButton->setVisible(true);
    QString s = ui->FriendList->currentItem()->text();
    if(s.toStdString()==lgd->get_fullName()){
        gohome();
    }
    else{
   // alpha.print_users();
    //std::cout<<s.toStdString()<< std::endl;
    int a = alpha.get_id(s.toStdString());
    displayed = alpha.get_user(a);
    ui->NameProfile->setText(s);
    while(ui->FriendList->count()>0)
    {
        ui->FriendList->takeItem(0);
    }
    while(ui->TablePosts->count()>0)
    {
        ui->TablePosts->takeItem(0);
    }

    ui->TablePosts->addItem(QString::fromStdString(displayed->display_posts(5, false)));
    if(displayed->get_connections().size()>0){
    int x = displayed->get_connections()[0];
        s = QString::fromStdString(alpha.get_user(x)->get_fullName());
        ui->TablePosts->clear();
        ui->TablePosts->addItem(QString::fromStdString(alpha.get_user(a)->display_posts(5,true)));

        for(int i = 0; i<displayed->get_connections().size(); i++){
            int x= displayed->get_connections()[i];
            s = QString::fromStdString(alpha.get_user(x)->get_fullName());
            ui->FriendList->addItem(s);
        }
    }
    pastUsers.push(displayed->get_fullName());
    actions.push("Visit");
    }
//    else{
//        std::cout<<"why is this not working"<<std::endl;
//    }



}
/*
Method: visitNewDisplayed

param: none
visits the clicked User on the reccommended list
*/
void socialnetworkui::visitNewDisplayed(){
    ui->label_3->setVisible(false);
    ui->scrollArea_2->setVisible(false);
    ui->FriendSuggestions->setVisible(false);
    ui->HomeButton->setVisible(true);
    ui->AddFriend->setVisible(true);
    ui->backButton->setVisible(true);
    QString s = ui->FriendSuggestList->currentItem()->text();
    int a = alpha.get_id(s.toStdString());
    displayed = alpha.get_user(a);
    std::cout<<displayed->get_fullName()<<std::endl;
    ui->NameProfile->setText(s);

    while(ui->FriendList->count()>0)
    {
        ui->FriendList->takeItem(0);
    }
    while(ui->TablePosts->count()>0)
    {
        ui->TablePosts->takeItem(0);
    }
    ui->TablePosts->addItem(QString::fromStdString(displayed->display_posts(5, false)));
    if(displayed->get_connections().size()>0){
        int x = displayed->get_connections()[0];
        s = QString::fromStdString(alpha.get_user(x)->get_fullName());
        ui->TablePosts->clear();
        ui->TablePosts->addItem(QString::fromStdString(displayed->display_posts(5,true)));

        for(int i = 0; i<displayed->get_connections().size(); i++){
            int x= displayed->get_connections()[i];
            s = QString::fromStdString(alpha.get_user(x)->get_fullName());
            ui->FriendList->addItem(s);
        }
    }
    pastUsers.push(displayed->get_fullName());
    actions.push("Visit");

}
/*
Method: addFriend

param: none
Adds non-LGD Users as friends if they weren't already
*/
void socialnetworkui::addFriend(){
    QString s = ui->NameProfile->text();
    bool connected =false;
    for(int i =0; i<lgd->get_connections().size();i++){
        int x= lgd->get_connections()[i];
        if(s.toStdString()==alpha.get_user(x)->get_fullName()){
            connected = true;
            break;
        }

    }
    if(connected ==false){
        alpha.add_connection(s.toStdString(), lgd->get_fullName());
        lgd->add_friend(alpha.get_id(s.toStdString()));
        actions.pop();
        actions.push("VisitAdd");
    }
}
/*
Method: goback

param: none
reverts any changes to UI
*/
void socialnetworkui::goback(){
    std::cout<<pastUsers.top()<<std::endl;
    if(actions.size() <=1){
        pastUsers.pop();
        actions.pop();
        ui->AddFriend->setVisible(false);
        ui->FriendList->setVisible(false);
        ui->HomeButton->setVisible(false);
        ui->backButton->setVisible(false);
        ui->NameProfile->setVisible(false);
        ui->TablePosts->setVisible(false);
        ui->label->setVisible(false);
        ui->label_2->setVisible(false);
        ui->label_3->setVisible(false);
        ui->scrollArea->setVisible(false);
        ui->FriendSuggestions->setVisible(false);
        ui->scrollArea->setFrameShape(QFrame::NoFrame);
        ui->scrollArea_2->setVisible(false);
        ui->scrollArea_2->setFrameShape(QFrame::NoFrame);
        ui->scrollArea_3->setVisible(false);
        ui->scrollArea_3->setFrameShape(QFrame::NoFrame);
        ui->LoginButton->setVisible(true);
        ui->LoginLine->setVisible(true);


    }
    else if(actions.top()=="Reccomend"){
        actions.pop();
        while(ui->FriendSuggestList->count()>0)
        {
            ui->FriendSuggestList->takeItem(0);
        }
    }
    else{
        std::string b = actions.top();
        std::cout << b << std::endl;

            if(b=="VisitAdd"){
            std::string a = pastUsers.top();
            alpha.remove_connection( lgd->get_fullName(), a);
            lgd->delete_friend(alpha.get_id(a));
            std::cout << "deleted" << std::endl;

            }
            pastUsers.pop();
            actions.pop();
            std::string a = pastUsers.top();
            ui->label_3->setVisible(false);
            ui->scrollArea_2->setVisible(false);
            ui->FriendSuggestions->setVisible(false);
            ui->HomeButton->setVisible(true);
            ui->AddFriend->setVisible(true);
            ui->backButton->setVisible(true);

        if(a==lgd->get_fullName()){
            ui->label->setVisible(true);
            ui->scrollArea_2->setVisible(true);
            ui->FriendSuggestions->setVisible(true);
            ui->HomeButton->setVisible(false);
            ui->AddFriend->setVisible(false);
            QString x = QString::fromStdString(lgd->get_fullName());

            ui->NameProfile->setText(x);
            while(ui->FriendList->count()>0)
            {
            ui->FriendList->takeItem(0);
            }
            for(int i = 0; i<lgd->get_connections().size(); i++){
            int x= lgd->get_connections()[i];
            QString s = QString::fromStdString(alpha.get_user(x)->get_fullName());
            ui->FriendList->addItem(s);
            }
            ui->TablePosts->addItem(QString::fromStdString(lgd->display_posts(5, false)));
         }
            else{
            // alpha.print_users();
            //std::cout<<s.toStdString()<< std::endl;
            int y = alpha.get_id(a);
            displayed = alpha.get_user(y);
            ui->NameProfile->setText(QString::fromStdString(a));
            while(ui->FriendList->count()>0)
            {
            ui->FriendList->takeItem(0);
            }
            if(displayed->get_connections().size()>0){
            int x = displayed->get_connections()[0];
            QString s = QString::fromStdString(alpha.get_user(x)->get_fullName());
            ui->TablePosts->clear();
            ui->TablePosts->addItem(QString::fromStdString(alpha.get_user(alpha.get_id(a))->display_posts(5,true)));

            for(int i = 0; i<displayed->get_connections().size(); i++){
                int x= displayed->get_connections()[i];
                s = QString::fromStdString(alpha.get_user(x)->get_fullName());
                ui->FriendList->addItem(s);
            }
            }
            ui->TablePosts->addItem(QString::fromStdString(displayed->display_posts(5, false)));



     }


    }
}

