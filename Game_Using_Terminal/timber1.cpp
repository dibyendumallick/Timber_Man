#include <SMFL/Graphics.hpp>
using namespace sf;
int main()
{
	VideoMode vm(1920,1080);
	RenderWindow window(vm,"Timber",Style::Fullscreen);
	while(window.isOpen())
	{
		if(Keyboard::isKeyPressed(Keyword::Escape))
		{
			window.close();
		}
		window.clear();
		window.display();
	}
	return 0;
}
