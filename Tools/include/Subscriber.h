//
// Created by megaxela on 06.07.15.
//

#ifndef GRAPHICS_SYSTEM_SUBSCRIBER_H
#define GRAPHICS_SYSTEM_SUBSCRIBER_H

//TODO: Разобраться и засунуть реализацию в CPPddd
template <class T>
class Subscriber
{
public:
    Subscriber()
    {
        _subject = nullptr;
    }

    T* value() const
    {
        return _subject;
    }

    void update( T* updated )
    {
        _subject = updated;
    }
private:
    T* _subject;
};


#endif //GRAPHICS_SYSTEM_SUBSCRIBER_H
