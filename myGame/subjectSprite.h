#ifndef SUBJECTSPRITE__H
#define SUBJECTSPRITE__H

#include <string>
#include <cmath>
#include <list>
#include "two-way_multi-frame_sprite.h"
// #include "observerSprite.h"

class ObserverSprite;

class SubjectSprite : public TwoWaysMultiSprite {
public:
    SubjectSprite(const SubjectSprite&);
    SubjectSprite(
        const std::string& name, 
        const std::string& inv, 
        const std::string& idle, 
        const std::string& idle_inv
        );
    void notify(Uint32 ticks);
    void attach(ObserverSprite* os);
    void detach(ObserverSprite* os);
protected:
    std::list<ObserverSprite*> observers;
    SubjectSprite& operator=(const SubjectSprite&);

};
#endif