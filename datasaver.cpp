#include "datasaver.h"

QString DataSaver::pathPhoto = QDir::currentPath() + "/photo/";
QString DataSaver::pathAlpha = QDir::currentPath() + "/circle_yoga/";
QString DataSaver::path = QDir::currentPath()+"/yogadata.xml";

DataSaver::DataSaver(bool lang)
{
    path = QDir::currentPath()+"/yogadata" + (lang ? "_ru.xml" : "_en.xml");
    updateDB();
}

void DataSaver::updateDB() {
    // Use Cashing For DB Updating
    QFile file(path);
    if (!file.exists()) {
        QMessageBox::critical(0, tr("ERROR STARTING APP"),
                              tr("DATABASE IS INVALID!\n"
                                 "Please, Check \"yogabase.xml\" File And Restart App!"));
        isError = true;
        return;
    }

    asanas.clear();
    rows = 0;
    cols = headerOption.count();

    QString tempCell;
    Asana* newAsana = nullptr;
    if(file.open(QIODevice::ReadOnly)) {
        QXmlStreamReader sr(&file);
        int curCol=0;
        do {

            sr.readNext();
            tempCell = sr.text().toString();

            if (tempCell.isEmpty() || tempCell.at(0) == ' ' || tempCell.at(0) == '\t' || tempCell.at(0) == '\n') continue;

            if (curCol%cols == 0) {
                rows++;

                newAsana = new Asana();
                asanas.emplace_back(*newAsana);

                asanas.back().pic = tempCell;

                if (curCol != 0) {
                    curCol=0;
                }
            }
            else {

                switch (curCol) {
                case 1:
                    asanas.back().name = tempCell.toUpper();
                    break;
                case 2:
                    asanas.back().altName = tempCell.toCaseFolded();
                    break;
                case 3:
                    asanas.back().posType = tempCell.toCaseFolded();
                    poseTypeSet.insert(tempCell);
                    break;
                case 4:
                    asanas.back().desc = tempCell.toCaseFolded();
                    break;
                default:

                    asanas.back().options = (tempCell[0] == '+') ?
                                                (asanas.back().options | (1 << (31-curCol+5))) :
                                                (asanas.back().options & ~(1 << (31-curCol+5)));
                    break;
                }
            }

            curCol++;
        } while(!sr.atEnd());
        if (sr.hasError()) {
            QMessageBox::information(0, tr("Error Starting Programm"),
                                     tr("DATA BASE IS INCORRECT! PLEASE, CHECK IT AND START APPLICATION AGAIN!"));
            file.close();
            isError = true;
            return;
        }
    }
    file.close();
}

const QVector<Asana>& DataSaver::getAsanas() const {
    return this->asanas;
}

const QVector<QString>& DataSaver::getHeaderOptions() const {
    return this->headerOption;
}

const QSet<QString>& DataSaver::getPoseTypeSet() const {
    return this->poseTypeSet;
}

const std::pair<int&, int&> DataSaver::getDimentions() const {
    return std::pair<int&, int&>(this->rows, this->cols);
}

const std::array<QString, 32>& DataSaver::getOptFiles() const {
    return this->optFiles;
}
