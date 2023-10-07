
    //comportamento do gladiador
    float r = 1;
float hp;
int start = 1;
int hit;
int dodgeSide = 1;
void defendToMeleeEnemy();
void dodge();
loop(){
    //comportamento do gladiador
    moveTo(12.5, 12.5);
r = 12.5 - getSafeRadius() / 2;
hit = 0;
upgradeSTR(3);
upgradeAGI(1);

if (hp != getHp()) {
    hp = getHp();
    hit = 1;
    moveToTarget();
    attackMelee();
}

if (hit) {
    if (getBlockTimeLeft() < 0.5) {
        block();
        teleport(getTargetX(),getTargetY());
        speak("Caneta Azul");
    }
    turnToAngle(getLastHitAngle());
    moveToTarget();
    attackMelee();
    speak("Azul Caneta");
}
if(getHp() < 150.0){
    useItem("pot-hp-2");
}
if (getHighHp()) {
    charge();
} else {
    if (!start) {
        turn(50);
    } else if (start) {
        if (moveTo(12.5, 12.5)) {
            start = 0;
            moveToTarget();
            attackMelee();
        }
    }
}
float dist = getDistToTarget();

if (getAmbushTimeLeft() > 0) {
    // Verifique se o alvo está próximo antes de atacar
    double distanciaAlvo = getDistToTarget();
    if (distanciaAlvo < 2.0) { // Ajuste a distância de ataque conforme necessário
        attackMelee(getTargetX(), getTargetY());
        assassinate(getTargetX(), getTargetY());
    }else{
        teleport(getTargetX(),getTargetY());
        speak("Ta marcada com minhas letra");
    }
}
void defendToMeleeEnemy()
{
    stepLeft();
    turnToTarget();
    stepLeft();
    turnToTarget();
    stepLeft();
    turnToTarget();
    stepLeft();
    turnToTarget();
    stepLeft();
    turnToTarget();
    
}
void dodge()
{
    if(dodgeSide % 2 == 0)
    {
        int i = 0;
        while(isSafeHere() && i < 3)
        {
            stepLeft();
            //turnToLastHit();
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
            //turnToLastHit();
            i++;
        } 
        dodgeSide++;
    } 
}
if(getHp() < 100.0){
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
		
	fireball(getTargetX(), getTargetY());
	}
}
    

}
