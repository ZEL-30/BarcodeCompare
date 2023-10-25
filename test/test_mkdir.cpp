#include <QDir>
#include <QDebug>
#include <QString>

QString createMultipleFolder(QString createDir)
{
    QDir dir(createDir);
    if (dir.exists(createDir)) {
        return createDir;
    }
 
    QString parentDir = createMultipleFolder(createDir.mid(0, createDir.lastIndexOf('/')));
    QString dirName = createDir.mid(createDir.lastIndexOf('/') + 1);
    qDebug() << dirName;
    
    QDir parentPath(parentDir);
    if (!dirName.isEmpty())
    {
        parentPath.mkpath(dirName);
    }
    return parentDir + "/" + dirName;
}


int main() {

    QString path = "./a/b/c/d";
    createMultipleFolder(path);

    return 0;
}
