#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    VideoMode vm(1366, 768);							 	//Tells the program to create a window of size 1920x1080
    RenderWindow window(vm, "Timber", Style::Fullscreen);	//RenderWindow is class in SFML that represents the window WHERE graphics are displayed.

	//texture of background
	Texture textureBackground;								//used to load and manage image data from a file.
	textureBackground.loadFromFile("graphics/background (1).png");
	Sprite spriteBackground;								//is used to display a texture on the screen
	spriteBackground.setTexture(textureBackground);			//set Background Image
	spriteBackground.setPosition(0,0);						//set Position through coordinate.

	//texture tree
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(550,0);

	//Texture bee
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(900,250);
	bool beeActive=false;
	float beeSpeed=0.0f;

	Texture textureCloud;
	textureCloud.loadFromFile("graphics/cloud.png");
	Sprite spriteCloud1;
	Sprite spriteCloud2;
	Sprite spriteCloud3;

	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);

	spriteCloud1.setPosition(0,0);
	spriteCloud2.setPosition(0,250);
	spriteCloud3.setPosition(0,500);

	bool cloud1Active=false;
	bool cloud2Active=false;
	bool cloud3Active=false;

	float cloud1Speed=0.0f;
	float cloud2Speed=0.0f;
	float cloud3Speed=0.0f;


	//time
	Clock clock;								//used to measure time
	Time dt=clock.restart();
	if(!beeActive)
	{
		srand((int)time(0));
		beeSpeed=(rand()%200)+200;

		srand((int)time(0));
		float height=(rand()%500)+500;
		spriteBee.setPosition(900,height);
		beeActive=true;
	}
	else{
		spriteBee.setPosition(spriteBee.getPosition().x- (beeSpeed*dt.asSeconds()),spriteBee.getPosition().y);
		if(spriteBee.getPosition().x<-100)
		{
			beeActive=false;
		}
	}

    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }
        window.clear();
		window.draw(spriteBackground);
		window.draw(spriteTree);
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);
		
		window.draw(spriteBee);
        window.display();
    }
    return 0;
}

