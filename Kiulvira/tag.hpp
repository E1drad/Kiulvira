#ifndef TAG_HPP
#define TAG_HPP

#include <QColor>
#include <algorithm>
#include <QString>

class Tag {
private:
    QString name;
    QColor colour;
public:
    Tag(QString name, QColor colour);
    Tag(QString name);
    QString getName();
    QColor getColour();
    bool operator==(const Tag& other);
    Tag& operator=(Tag tag);

};

#endif // TAG_HPP
