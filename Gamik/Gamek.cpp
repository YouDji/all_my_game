//https://www.youtube.com/watch?v=5_n5sehF-ME
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;
int offsetX=0, offsetY=0;
int offsetX2=0, offsetY2=0;
int offsetX3=0, offsetY3=0;
int offsetX4=0, offsetY4=0;
int offsetX5=0, offsetY5=0;
int offsetX6=0, offsetY6=0;
 // подключаем пространство имен sf
 int HeroDirection;
 float speed =0.1;
int main()
{	
	RenderWindow window(VideoMode(500, 400), "Gamek");
	//(VideoMode(1850, 1100), "Gamek");
 CircleShape MyCircle(100.f);
 MyCircle.setFillColor(Color::Green);
 Texture t,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15;
 t.loadFromFile("images/Hero.png");
 t2.loadFromFile( "images/backend.png");
 t3.loadFromFile("images/avatar.png");
 t4.loadFromFile("images/enemy.png");;
 t5.loadFromFile("images/xitpoint.png");
 t6.loadFromFile("images/stone.png");
 t7.loadFromFile("images/pregrada.png");
 t8.loadFromFile("images/pregrada.png");
 t9.loadFromFile("images/money.png");
 t10.loadFromFile("images/city.png");
 t11.loadFromFile("images/backendtwo.png");
 t12.loadFromFile("images/backendthree.png");
 t13.loadFromFile("images/backendfour.png");
 t14.loadFromFile("images/backendfive.png");
 t15.loadFromFile("images/HeroTwo.png");
 float currentFrame=0;
 float currentFrame2=0;
 float currentFrame3=0;
 Sprite s,s2(t2),s3(t3),s5(t5),s4(t4),s6(t6),s7(t7),s8(t8),s9(t9),s10(t10),s11(t11),s12(t12),s13(t13),s14(t14),s15(t15);
 s.setTexture(t);
 s.setTextureRect( IntRect(0,100,31,47));
 s.setPosition(65,150);
//лицо персонажа
s3.setTexture(t3);
s3.setTextureRect( IntRect(0,90,250,100));
s3.setPosition(-190,-24);
s4.setTexture(t4);
s5.setTexture(t5);
s4.setTextureRect( IntRect(58,80,40,50));
s4.setPosition(445,160);
s6.setTexture(t6);
s6.setTextureRect( IntRect(58,80,40,50));
s6.setPosition(105,300);
s7.setTexture(t7);
s7.setTextureRect( IntRect(178,80,6,45));
s7.setPosition(360,180);
s8.setTexture(t8);
s8.setTextureRect( IntRect(178,80,6,45));
s8.setPosition(480,180);
//вопрос с монетами заморраживаю на время
s9.setTexture(t9);
//s9.setTextureRect( IntRect(4,63,30,44));
s9.setPosition(180,80);
//
s15.setTexture(t15);
//s8.setTextureRect( IntRect(178,80,6,45));
s15.setPosition(680,180);


//лицо персонажа
 float x=100, y=100;

 Clock clock;
  int HeroDirectiontwo;
	while (window.isOpen())
	{
	float time=clock.getElapsedTime().asMicroseconds();
	clock.restart();
	time=time/800;
		Event event;
		while (window.pollEvent(event))
		{
	
			if (event.type == Event::Closed)
				window.close(); 
		}
 sf::FloatRect s4Enemy=s4.getGlobalBounds();//изымаем данные врага
 sf::FloatRect s6Stone= s6.getGlobalBounds();
 sf::FloatRect shero= s.getGlobalBounds();
 sf::FloatRect sstone= s7.getGlobalBounds();
 sf::FloatRect sstonetwo= s8.getGlobalBounds(); 
		if (s6Stone.intersects(shero))
		{
			if(HeroDirection==0)
			s6.move(-speed*time,0);
			if(HeroDirection==1)
			s6.move(speed*time,0);
			if(HeroDirection==2)
			s6.move(0,-speed*time);
			if(HeroDirection==3)
			s6.move(0,speed*time);
		}
		if( sstone.intersects(s4Enemy))
		{
			if(HeroDirection==0)
			s4.move(speed*time,0);
			if(HeroDirection==1)
			s4.move(speed*time,0);
			if(HeroDirection==2)
			s4.move(speed*time,0);
			if(HeroDirection==3)
			s4.move(speed*time,0);	
		}
			if( s4Enemy.intersects(s6Stone))
			{
				if(HeroDirection==0)
			s4.move(speed*time,0);
			if(HeroDirection==1)
			s4.move(speed*time,0);
			if(HeroDirection==2)
			s4.move(speed*time,0);
			if(HeroDirection==3)
			s4.move(speed*time,0);
			}
	if(Keyboard::isKeyPressed(Keyboard::A))
	{

		
		s.move(-0.1*time,0);
		 HeroDirection=0;
		currentFrame +=0.003*time;
		if(currentFrame>3) currentFrame -=3;
		s.setTextureRect(IntRect(32*int(currentFrame),50,31,47));
		currentFrame2 +=0.003*time;
		if(currentFrame2>3) currentFrame2 -=3;
		s3.setTextureRect(IntRect(70*int(currentFrame2),90,250,100));
			if(currentFrame2>3) currentFrame2 -=3;
		s4.setTextureRect(IntRect(32*int(currentFrame2),80,35,50));
			s4.move(-0.1*time,0);				
	}
	if(Keyboard::isKeyPressed(Keyboard::D))
	{
		s.move(0.1*time,0);
		 HeroDirection=1;
		currentFrame +=0.003*time;
		if(currentFrame>3) currentFrame -=3;
		s.setTextureRect(IntRect(32*int(currentFrame),100,31,47));
		currentFrame2 +=0.003*time;
		if(currentFrame2>3) currentFrame2 -=3;
		s3.setTextureRect(IntRect(70*int(currentFrame2),90,250,100));
		if(currentFrame2>3) currentFrame2 -=3;
		s4.setTextureRect(IntRect(32*int(currentFrame2),80,35,50));
			s4.move(-0.1*time,0);	
	}
	if(Keyboard::isKeyPressed(Keyboard::W))
	{
		s.move(0,-0.1*time);
		 HeroDirection=2;
		currentFrame +=0.003*time;
		if(currentFrame>3) currentFrame -=3;
		s.setTextureRect(IntRect(32*int(currentFrame),150,31,47));
			currentFrame2 +=0.003*time;
		if(currentFrame2>3) currentFrame2 -=3;
		s3.setTextureRect(IntRect(70*int(currentFrame2),90,250,100));
		if(currentFrame2>3) currentFrame2 -=3;
		s4.setTextureRect(IntRect(32*int(currentFrame2),80,35,50));
			s4.move(-0.1*time,0);
	}
	if(Keyboard::isKeyPressed(Keyboard::S))
	{
		s.move(0,0.1*time);
		 HeroDirection=3;
		currentFrame +=0.003*time;
		if(currentFrame>3) currentFrame -=3;
		s.setTextureRect(IntRect(32*int(currentFrame),0,31,47));
			currentFrame2 +=0.003*time;
		if(currentFrame2>3) currentFrame2 -=3;
		s3.setTextureRect(IntRect(70*int(currentFrame2),90,250,100));
		if(currentFrame2>3) currentFrame2 -=3;
		s4.setTextureRect(IntRect(32*int(currentFrame2),80,35,50));
			s4.move(-0.1*time,0);
	}			
if(x>1) offsetX =x-100;
if(y>100) offsetY =y-20;
if(x>1) offsetX2 =x-1221;
if(y>100) offsetY2 =y+260;
if(x>1) offsetX3 =x-627;
if(y>1) offsetY3 =y-518;
if(x>1) offsetX4 =x-627;
if(y>1) offsetY4 =y-60;
if(x>1) offsetX5 =x-27;
if(y>1) offsetY5 =y-518;
if(x>1) offsetX6 =x-1220;
if(y>1) offsetY6 =y-518;
	window.clear(Color::White);	
	s2.setPosition(-offsetX,-offsetY);
	window.draw(s2);
	s10.setPosition(-offsetX2,-offsetY2);
	window.draw(s10);
	s11.setPosition(-offsetX3,-offsetY3);
	window.draw(s11);
	s12.setPosition(-offsetX4,-offsetY4);
	window.draw(s12);
	s13.setPosition(-offsetX5,-offsetY5);
	window.draw(s13);
	s14.setPosition(-offsetX6,-offsetY6);
	window.draw(s14);
	
		//window.clear();
		window.draw(s);
		window.draw(s3);
		window.draw(s4);
		window.draw(s6);
		//window.draw(s7);
		//window.draw(s8);
		//window.draw(s9);
			//window.draw(s15);
		window.display();
	
	}
	return 0;
}

