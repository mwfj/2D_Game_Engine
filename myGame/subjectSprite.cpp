#include "subjectSprite.h"
#include "observerSprite.h"
#include "gameData.h"
#include "renderContext.h"

SubjectSprite::SubjectSprite( 
        const std::string& name, 
        const std::string& inv, 
        const std::string& idle, 
        const std::string& idle_inv
    ) :
    TwoWaysMultiSprite(name, inv, idle, idle_inv),
    observers()
{}

SubjectSprite::SubjectSprite( const SubjectSprite& s ):
    TwoWaysMultiSprite(s),
    observers(s.observers)
{}

void SubjectSprite::detach( ObserverSprite* os ){
    std::list<ObserverSprite*>::iterator it = observers.begin();
    while (it != observers.end())
    {
        if (*it == os) {
            it = observers.erase(it);
            return;
        }
        ++it;   
    }
}

void SubjectSprite::attach(ObserverSprite* os){
    observers.push_back(os);
}

void SubjectSprite::notify(Uint32 ticks){
    TwoWaysMultiSprite::update(ticks);
    std::list<ObserverSprite *>::iterator it = observers.begin();
    while (it != observers.end())
    {
       int offset = rand()%5;
       offset = offset*(rand()%2?-1:1);
       const Vector2f off(offset, offset);
       (*it)->setPlayerPos( getPosition()+off );
        ++it;
    }
}