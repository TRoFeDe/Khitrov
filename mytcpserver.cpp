void MyTcpServer::slotServerRead(){
    QTcpSocket* curr_mTcpSocket = ((QTcpSocket*)sender()); // узнаём сокет отправителя
    while(curr_mTcpSocket->bytesAvailable()>0)
    {
        QByteArray array =curr_mTcpSocket->readAll();
        curr_mTcpSocket->write(array);
        QDataStream in(curr_mTcpSocket); in.setVersion(QDataStream::Qt_6_2);
        if (in.status()==QDataStream::Ok){
            qDebug()<<"read...";
            QString str;
            in>>str;
            qDebug()<<str;
            SendToClient(str, curr_mTcpSocket);
        }


    }

    void MyTcpServer::slotClientDisconnected(){

        QTcpSocket* curr_mTcpSocket = ((QTcpSocket*)sender());
        curr_mTcpSocket->close();
    }
    void MyTcpServer::SendToClient(QString str, QTcpSocket* curr_mTcpSocket){
        Data.clear();
        QDataStream out(&Data, QIODevice::WriteOnly); out.setVersion(QDataStream::Qt_6_2);
        out <<parsing(str);
        curr_mTcpSocket->write(Data);
    }
    QString MyTcpServer::parsing(QString str){
        std::string ans = str.toStdString();
        if (str=="task1"){
            ans=task1();}
        else if (str=="task2"){
            ans=task2();}
        else if (str=="task3"){
            ans=task3();}
        else if (str=="task4"){
            ans=task4();}
        else if (str=="authorization"){
            ans=autor();}
        else if (str=="registration"){
            ans=reg();}
        else if (str=="statistics"){
            ans=stat();}
        return QString::fromStdString(ans);
    }

    std::string MyTcpServer::task1(){
        std::string ans=" ";
        return ans;
    }
    std::string MyTcpServer::task2(){
        std::string ans=" ";
        return ans;
    }
    std::string MyTcpServer::task3(){
        std::string ans=" ";
        return ans;
    }
    std::string MyTcpServer::task4(){
        std::string ans=" ";
        return ans;
    }
    std::string MyTcpServer::autor(){
        std::string ans=" ";
        return ans;
    }
    std::string MyTcpServer::reg(){
        std::string ans=" ";
        return ans;
    }
    std::string MyTcpServer::stat(){
        std::string ans=" ";
        return ans;
    }
