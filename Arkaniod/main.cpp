#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{	
	RenderWindow window(VideoMode(800, 700), "SFML Works!");
	float dx,dy,dx2,dy2;
	dx= 665;
	dy=650;
	dx2 = 665;
	dy2 = 50;
	Texture t,t2;
//	Player player;
    t.loadFromFile("images/Scream.png ");
    RectangleShape rectangle(Vector2f(7.f, 10.f));	
	rectangle.setPosition(dx, dy);
	rectangle.setFillColor(Color::Red);
	RectangleShape Recttwo(Vector2f(70.f, 70.f));
	Recttwo.setPosition(dx2, dy2);
	Recttwo.setFillColor(Color::Red);
	Sprite s(t);
	s.setPosition(-50,-30);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		
		if(Keyboard::isKeyPressed(Keyboard::A))
		{
		rectangle.move(-0.1,0);	
		dx= dx-0.1;
		dy = dy;
		}
		if(Keyboard::isKeyPressed(Keyboard::D))
		{
		rectangle.move(0.1,0);
		dx= dx+0.1;	
		dy = dy;
		}
		if(Keyboard::isKeyPressed(Keyboard::W))
		{
		rectangle.move(0,-0.1);	
		dy = dy-0.1;
		dx = dx;
		}
		if(Keyboard::isKeyPressed(Keyboard::S))
		{
		rectangle.move(0,0.1);	
		dy = dy+0.1;
		dx = dx;
		}
	
		window.clear();
			if (dx==dx2 || dy==dy2)
		{
			window.draw(s);
		}
		
		sf::FloatRect rectangleBounds = rectangle.getGlobalBounds();
		sf::FloatRect RecttwoBounds = Recttwo.getGlobalBounds();
		if (rectangleBounds.intersects(RecttwoBounds))
		{
		window.draw(s);
		}
		window.draw(Recttwo);
		window.draw(rectangle);
	//	window.draw(s);
		window.display();
	}
	return 0;
}

#include <SFML\Graphics.hpp>
/* 
int main() {
    using namespace sf;
 
    RenderWindow window(VideoMode(800, 600), "Test", Style::Close);
 
    int w = 120;
    int h = 50;
 
    RectangleShape rect(Vector2f(w, h));
    RectangleShape rect2(Vector2f(w, h));
    
    rect.setPosition(350, 400);
    rect2.setPosition(350 + w  / 2, 200 + h / 2);
    rect2.setFillColor(Color(255, 0, 0));
    rect2.setOrigin(w / 2, h / 2); // ??? ??? ?????? ???????? ???????????? ??????
 
    while (window.isOpen()) {
        Event event;
 
 
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
 
 
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::A)){
                rect.rotate(-5);
                rect2.rotate(-5);
            }
 
 
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::D)){
                rect.rotate(5);
                rect2.rotate(5);
            }
        }
        
        window.clear();
        window.draw(rect);
        window.draw(rect2);
        window.display();
 
    }
 
    return 0;
}
 
*/
    
 
    
