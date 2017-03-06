#ifndef TAG_HPP
#define TAG_HPP

#include <string>
#include <QColor>

class Tag {
private:
    std::string name;
    QColor colour;
public:
    Tag(std::string name, QColor colour);

    std::string getName();
    QColor getColour();
};

#endif // TAG_HPP
