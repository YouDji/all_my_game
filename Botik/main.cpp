#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
int main()
{	
RenderWindow window(VideoMode(1920, 1080), "SFML Works!");
	Texture t,t1,t2,t3,t4,t5,t6 ;
	t1.loadFromFile("images/avatar.png");
	Sprite s2,s1(t1);
//	s1.setTextureRect(IntRect(0,90,250,100));
	s1.setPosition(1500, -100);
	
//Map map(t, FloatRect(300,200,31,47));
FloatRect wall;
CircleShape square(35.f, 130);
square.setPosition(-20, -20); 
square.setFillColor(Color::Red);

CircleShape squaretwo(35.f, 130);
squaretwo.setPosition(-20,350);
squaretwo.setFillColor(Color::Red);

CircleShape squarethree(35.f, 130);
squarethree.setPosition(330,350);
squarethree.setFillColor(Color::Red);

CircleShape squarefour(35.f, 130);
squarefour.setPosition(330,-20);
squarefour.setFillColor(Color::Red);

RectangleShape rectfour(Vector2f(400.0f,20.0f));
rectfour.setPosition(0,400);
rectfour.setFillColor(Color::Yellow);

RectangleShape rectfive(Vector2f(400.0f,20.0f));
rectfive.setPosition(400,0);
rectfive.rotate(90);
rectfive.setFillColor(Color::Yellow);

CircleShape squarefive(35.f, 3);
squarefive.setPosition(60,280);
squarefive.setFillColor(Color::Red);

CircleShape squaresix(35.f, 3);
squaresix.setPosition(340,60);
squaresix.rotate(75);
squaresix.setFillColor(Color::Red);

CircleShape squareseven(35.f, 4);
squareseven.setPosition(220,160);
squareseven.rotate(75);
squareseven.setFillColor(Color::Magenta);

RectangleShape rectsix(Vector2f(80.0f,20.0f));
rectsix.setPosition(120,80);
rectsix.rotate(130);
rectsix.setFillColor(Color::Red);

RectangleShape rectseven(Vector2f(80.0f,20.0f));
rectseven.setPosition(320,260);
rectseven.rotate(130);
rectseven.setFillColor(Color::Red);

std::vector<CircleShape>squares;
squares.push_back(square);
squares.push_back(squaretwo);
squares.push_back(squarethree);
squares.push_back(squarefour);
squares.push_back(squarefive);
squares.push_back(squaresix);
squares.push_back(squareseven);
//squares.push_back(rectfour);

std::vector<RectangleShape>rquares;
rquares.push_back(rectfour);
rquares.push_back(rectfive);
rquares.push_back(rectsix);
rquares.push_back(rectseven);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(Color());
	CircleShape circle(50.f);
	circle.setFillColor(Color(230, 0, 230));
//		window.draw(circle);
//		window.draw(map.s);
		window.draw(square);
		window.draw(squaretwo);
		window.draw(squarethree);
		window.draw(squarefour);
		window.draw(squarefive);
		window.draw(squaresix);
		window.draw(squareseven);
		window.draw(rectfour);
		window.draw(rectfive);
		window.draw(rectsix);
		window.draw(rectseven);
		window.draw(s1);
		window.display();
	}
	return 0;
}
