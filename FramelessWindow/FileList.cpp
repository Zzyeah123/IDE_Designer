#include "FileList.h"
#include<QMessageBox>
#include<QFileDialog>
#include<QTextStream>
FileList::FileList(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("border:none; border-radius:20px;background-color:rgb(242, 239, 249);");
}



bool FileList::MaybeSave(){
    if(!curIsModified)//没有做出修改
        return true;
    //已做出修改，选择是否保存
    const QMessageBox::StandardButton mesgbutton
            =QMessageBox::warning(this,tr("Warning"),tr("Not saved yet"),
                                  QMessageBox::Save|QMessageBox::Cancel);
    switch (mesgbutton) {
    case QMessageBox::Save:
        return Save();//保存
        break;
     case QMessageBox::Cancel://不保存
        return true;
    default:
        break;
    }
    return false;
}
void FileList::loadFile(const QString &filename){
    QFile file(filename);
    if(!file.open(QFile::ReadOnly|QFile::Text)){//打开文件失败
        QMessageBox::warning(this,tr("Error"),tr("Open File failed"));
    }
    QTextStream streamin(&file);
    emit(LoadData(streamin.readAll()));//向编辑区发送从文件中获取的内容

    setCurrentFile(filename);//重置当前文件信息
}

void FileList::OpenFile(){

    if(MaybeSave()){//打开文件前先判断是否保存之前文件内容
        QString path=QFileDialog::getOpenFileName(this,tr("打开文件"),tr(""),tr("C source files(*.c)"));
        if(!path.isEmpty())//已选择文件
            loadFile(path);
    }
}
bool FileList::Save(){
    if(currentFile.isEmpty()){//新建文件，先另存
        return SaveAs();
    }else{
       return SaveFile(currentFile);
    }
}

bool FileList::SaveFile(const QString &filename){
    QFile file(filename);
    if(!file.open(QFile::WriteOnly|QFile::Text)){//保存失败
        QMessageBox::warning(this,tr("Error"),tr("Save File failed"));
        return false;
    }
    QTextStream out(&file);

    emit(GetText());//从编辑区获取文本

    out<<curPlainText;

    setCurrentFile(filename);//重置当前编辑文件状态
    return true;
}
void FileList::NewFile(){
    if(MaybeSave()){//新建文件前先保存

        emit(ClearText());//发送清空编辑区信号
        setCurrentFile("");
    }

}
bool FileList::SaveAs(){
//    QFileDialog dialog(this);
//    dialog.setWindowModality(Qt::WindowModal);
//    dialog.setAcceptMode((QFileDialog::AcceptSave));

//    if (dialog.exec() != QDialog::Accepted)
//              return false;
//          return SaveFile(dialog.selectedFiles().first());
    QString path=QFileDialog::getSaveFileName(this,tr("另存文件"),tr(""),tr("C source files(*.c)"));
    if(path.isEmpty()) return false;//未选择另存文件，另存失败
    else return SaveFile(path);
}
void FileList::setCurrentFile(const QString &filename){
    currentFile= filename;
    curIsModified=false;//设置为未修改过

    if(currentFile.isEmpty())
        shownName="未命名";
    else shownName=QFileInfo(currentFile).fileName();
    emit(SetTitle(shownName));
}
void FileList::Close(){//关闭当前文件
    if(MaybeSave()){
        emit(ClearText());
        setCurrentFile("");
    }
}
void FileList::SetCurrentFilemodified(){//编辑区做出修改
    curIsModified=true;
}
void FileList::GetPlainText(QString Text){//从编辑区收到文本内容
    curPlainText=Text;
}
