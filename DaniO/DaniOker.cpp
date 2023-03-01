#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
//#include "helper.h"
using namespace sf;
float offsetX = 0;
class Tile 
{
	public:
		int x,y;
		int sx,sy;
		bool isCollidable;
		
		
	Tile(int x,int y, int sx, int sy, bool isCollidable )
	{
		this->x = x;
		this->y = y;
		this->sx = sx;
		this->sy = sy;
		this->isCollidable = isCollidable;
	}
	Tile(){	}
};
std::vector<Tile> map;

void loadMap(const char n[])
{
	std::fstream in;
	in.open(n);
	Tile temp;
	while(!in.eof())
	{
		in>>temp.x;
		in>>temp.y;
		in>>temp.sx;
		in>>temp.sy;
		in>>temp.isCollidable;
		map.push_back(temp);
	}
	in.close();
}
class Player {
public:
	float dx, dy;
	float currentFrame;
	Sprite s ;
	FloatRect rect;
	 bool onGround;
Player(Texture &t ,FloatRect rectangle)
{
	dx = 0;
	dy = 0;
	currentFrame = 0;
	s.setTexture(t);
	s.setTextureRect(IntRect(0,100,31,47));
	rect = rectangle ;
	onGround = false; 
}
	void update (float time)
	//float time
	{
		rect.left +=dx*time ;
		resolveCollision(0);
		if(onGround== false) dy+=0.0005*time;
		rect.top+=dy*time ;
		onGround = false;
	resolveCollision(1);
		currentFrame +=0.003*time; 
		if(currentFrame>3) currentFrame -=3;
		if(dx>0)s.setTextureRect(IntRect(32*int(currentFrame),100,31,47));
		if(dx<0)s.setTextureRect(IntRect(32*int(currentFrame),50,31,47));
		s.setPosition(rect.left - offsetX, rect.top-100);
		dx = 0;
	 };
void resolveCollision(int dir)
{
	for(int i = 0; i<map.size(); i++ )
	{
		if(map.at(i).x +1 > rect.left/32 || map.at(i).x < (rect.left + rect.width ) / 32 ||
		   map.at(i).y + 1> rect.top/32 || map.at(i).y < (rect.top + rect.height ) / 32 ||
		   map.at(i).isCollidable)
		   {
		   	if(dx<0 && dir == 0) rect.left = map.at(i).x*32 + 32;
			else if (dx > 0 && dir == 0) rect.left = map.at(i).x * 32- rect.width; 
			if(dy<0 && dir == 1)
			{
				rect.top = map.at(i).y *32 +32;
				dy = 0;
			} else if (dy>0 && dir == 1)
			{
					rect.top = map.at(i).y *32 -rect.height;
						dy = 0;
						onGround= true;
			}
		   }
	}
}
};
int main()
{
RenderWindow window(VideoMode(500,500),"Dani-Runi");
	Texture t,t2;
	t.loadFromFile("res/Hero.png");
	t2.loadFromFile("res/Map.png");
	Player player (t, FloatRect(300,200,31,47));
	//float currentFrame=0;
	Sprite  tile(t2);
	Clock clock;
	float time;
	loadMap("res/map.txt");
	while (window.isOpen())
	{
    time=clock.getElapsedTime().asMicroseconds();
    clock.restart();
    time/=800;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		
		}
		
		
			if(Keyboard::isKeyPressed(Keyboard::A))
			{
				player.dx=-0.1;
			}
			if(Keyboard::isKeyPressed(Keyboard::D))
			{
				player.dx=0.1;
			}
		if(Keyboard::isKeyPressed(Keyboard::W))
			{
             if(player.onGround == true )
             {
             	player.onGround= false;
             	player.dy = -0.4;
			 }
			}
		offsetX = player.rect.left- 250;
		player.update(time);
		window.clear();
		for(int i = 0; i<map.size() ; i++)
		{
			tile.setTextureRect(IntRect(map.at(i).sx*32, map.at(i).sy*32,32,32));
				tile.setPosition(map.at(i).x * 32-offsetX,map.at(i).y  * 32);
			window.draw(tile);
		}
		window.draw(player.s);
		window.display();
}
return 0;
}

