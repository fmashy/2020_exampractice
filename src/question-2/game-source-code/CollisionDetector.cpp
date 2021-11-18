#include "CollisionDetector.h"
#include <iostream>
using namespace std;

CollisionDetector::CollisionDetector()
{
    score = 0;
    _gameOver = false;
}

bool CollisionDetector::hasCollided(shared_ptr<Galaxian> galaxian, BulletPtr bullet)
{
    if((bullet->getYpos()-BULLETRADIUS) >= galaxian->getYpos() && (bullet->getYpos()-BULLETRADIUS) <= (galaxian->getYpos() + 40))
    {
        if(((bullet->getXpos()-BULLETRADIUS) >= galaxian->getXpos() && (bullet->getXpos()-BULLETRADIUS) <= galaxian->getXpos()+30) ||((bullet->getXpos()+BULLETRADIUS) >= galaxian->getXpos() && (bullet->getXpos()+BULLETRADIUS) <= galaxian->getXpos()+30))
            return true;
    }
    return false;
}

bool CollisionDetector::hasCollided(shared_ptr<Galaxian> galaxian, Galaxip galaxip)
{
    if((galaxian->getYpos()+40 >= galaxip.getYpos() && galaxian->getYpos()+40 <= galaxip.getYpos()+40)||(galaxian->getYpos() >= galaxip.getYpos() && galaxian->getYpos() <= galaxip.getYpos()+40) )
    {
        if((galaxian->getXpos() >= galaxip.getXpos() && galaxian->getXpos() <= galaxip.getXpos()+30) || (galaxian->getXpos()+30 >= galaxip.getXpos() && galaxian->getXpos()+30 <= galaxip.getXpos()+30))return true;
    }
    return false;
}

bool CollisionDetector::hasCollided(BulletPtr galaxianBullet, BulletPtr galaxipBullet)
{
    if((galaxianBullet->getYpos()+3 >= galaxipBullet->getYpos()-3 && galaxianBullet->getYpos()+3 <= galaxipBullet->getYpos()+3))
    {
        if((galaxianBullet->getXpos()-3 >= galaxipBullet->getXpos()-3 && galaxianBullet->getXpos()-3 <= galaxipBullet->getXpos()+3) || (galaxianBullet->getXpos()+3 >= galaxipBullet->getXpos()-3 && galaxianBullet->getXpos()+3 <= galaxipBullet->getXpos()+3))return true;
    }
    return false;
}

bool CollisionDetector::hasCollided(Galaxip galaxip, BulletPtr bullet)
{
    if( bullet->getYpos()+BULLETRADIUS >= galaxip.getYpos() && bullet->getYpos()+BULLETRADIUS <= galaxip.getYpos()+40)
    {
        if((bullet->getXpos()-BULLETRADIUS >= galaxip.getXpos() && bullet->getXpos()-BULLETRADIUS <= galaxip.getXpos()+30 )|| (bullet->getXpos()+BULLETRADIUS >= galaxip.getXpos() && bullet->getXpos()+BULLETRADIUS <= galaxip.getXpos()+30)) return true;
    }
    return false;
}

void CollisionDetector::checkGalaxianAndBullet(VecOfGalaxians& galaxians,BulletList& bullets, int points)
{
    for (auto galaxian : galaxians)
    {
        for (auto bullet : bullets)
        {
            if (!galaxian->isDead() && !bullet->isDead() && bullet->getDirection() == UP)
            {
                if (hasCollided (galaxian,bullet))
                {
                    if (galaxian->isDiving()) score += 50; // any galaxian shot while diving is worth an extra 50 points
                    score += points;
                    galaxian->setState(DEAD);
                    bullet->setState(DEAD);
                }
            }
        }
    }
}

void CollisionDetector::checkGalaxianAndGalaxip(VecOfGalaxians& galaxians, Galaxip& galaxip)
{
    for (auto galaxian : galaxians)
    {
        if (galaxian->isDiving())
        {
            if (hasCollided (galaxian,galaxip))
            {
                galaxian->setState(DEAD);
                galaxip.setState(DEAD);
                _gameOver = true;
            }
        }
    }
}

void CollisionDetector::checkGalaxipAndBullet(Galaxip& galaxip, BulletList& bullets)
{
    for (auto bullet : bullets)
    {
        if(!bullet->isDead() && bullet->getDirection() == DOWN)
        {
            if (hasCollided(galaxip,bullet))
            {
                bullet->setState(DEAD);
                galaxip.setState(DEAD);
                _gameOver = true;
            }
        }
    }
}

void CollisionDetector::checkGalaxipBulletAndGalaxianBullet(BulletList& bullets,int points)
{
    for (auto iter=begin(bullets); iter!=end(bullets); ++iter)
    {
        if(!(*iter)->isDead()&& (*iter)->getDirection()== DOWN)
        {
            for (auto bullet2 : bullets )
            {
                if(!bullet2->isDead() && bullet2->getDirection()== UP)
                {
                    if (hasCollided(*iter,bullet2))
                    {
                        (*iter)->setState(DEAD);
                        bullet2->setState(DEAD);
                        score += points;
                    }
                }
            }
        }
    }
}

void CollisionDetector::checkCollisions(VecOfGalaxians& galaxians,VecOfGalaxians& galaxians2,VecOfGalaxians& flagShipEscorts,VecOfGalaxians& flagShips, BulletList& bullets, Galaxip& galaxip)
{
    checkGalaxianAndBullet(galaxians,bullets,20); // Galaxians in the fourth and fifth rows from the top, worth 20 points
    checkGalaxianAndBullet(galaxians2,bullets,50); // Galaxians in the third row from the top, worth 50 points
    checkGalaxianAndBullet(flagShipEscorts,bullets,100); // Flagship escorts (in the second row from the top), worth 100 points
    checkGalaxianAndBullet(flagShips,bullets,150); // Flagships (top row), worth 150 points
    checkGalaxianAndGalaxip(galaxians,galaxip);
    checkGalaxianAndGalaxip(galaxians2, galaxip);
    checkGalaxianAndGalaxip(flagShipEscorts,galaxip);
    checkGalaxianAndGalaxip(flagShips,galaxip);
    checkGalaxipAndBullet(galaxip,bullets);
    checkGalaxipBulletAndGalaxianBullet(bullets,60); // Galaxian bullets are worth 60 points
}


