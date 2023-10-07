float hp;
void dodge();
int dodgeSide = 1, isStart = 1, isInTheCenter = 0;
loop(){
    //comportamento do gladiador
   upgradeINT(2);
     hp = getHp();
	if (getCloseEnemy() && getDist(getTargetX(), getTargetY()) < 5){
		float dx,dy;
		float safe = sqrt(pow(getSafeRadius(), 2)/2);
		float x = getX() - getTargetX();
		if (x < 0)
			dx = 12.5 + safe - 1;
		else
			dx = 12.5 - safe + 1;
		float y = getY() - getTargetY();
		if (y < 0)
			dy = 12.5 + safe - 1;
		else
			dy = 12.5 - safe + 1;
		teleport(dx,dy);
	}
	else if(getLowHp()){
		if (getAp() >= 50)
			fireball(getTargetX(), getTargetY());
		else
			attackRanged(getTargetX(), getTargetY());
	}
	else if (getLastHitTime() < 1){
		turnToAngle(getLastHitAngle());
	}
	else{
		if (getX() != 12.5 || getY() != 12.5)
			moveTo(12.5,12.5);
		else 
			turn(50);
	}
	void dodge()
{
    if(dodgeSide % 2 == 0)
    {
        int i = 0;
        while(isSafeHere() && i < 3)
        {
            stepLeft();
            turnToLastHit();
            i++;
        } 
        dodgeSide++;
    }
    
    else
    {
        int i = 0;
        while(isSafeHere() && i < 3)
        {
            stepRight();
            turnToLastHit();
            i++;
        } 
        dodgeSide++;
    } 
}
if(hp < 40){
   useItem("pot-hp-3");
}
if(getAp() < 60){
useItem("pot-ap-3");
}
}
