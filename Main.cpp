#include<iostream>
#include<SFML/Graphics.hpp>
#include<sstream>
#include<string>

struct Node
{
	sf::RectangleShape rect;
	sf::Text text;
	sf::Font font;
	int data;
	Node* next;
	Node* prev;
};
Node *start=NULL;

sf::Font font;

void update(sf::RenderWindow*,Node*);
void updateOrigin(Node*);
void dupdateOrigin(Node*);
void dupdate(sf::RenderWindow*, Node*);
void insert(sf::RenderWindow*);
void Options(sf::RenderWindow*);
Node* newNode(int data)
{
	std::string ch=std::to_string(data);
	std::cout <<"string value  "<<ch << std::endl;
	
	
	Node* newnode = new Node;
	newnode->font.loadFromFile("times.ttf");
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->text.setFont(newnode->font);
	newnode->text.setString(ch);
	newnode->text.setCharacterSize(40);
	newnode->text.setOrigin(sf::Vector2f(0, 0));
	newnode->rect.setOrigin(sf::Vector2f(0, 0));
	newnode->text.setFillColor(sf::Color::White);
	newnode->rect.setSize(sf::Vector2f(120, 50));
	newnode->rect.setFillColor(sf::Color::Blue);
	newnode->rect.setOutlineColor(sf::Color::White);
	newnode->rect.setOutlineThickness(10);
	return newnode;
	
	
}
void deleteAtPos(sf::RenderWindow* window,int position)
{
	Node* temp;
	int count;
	if (start == NULL)
	{
		return;
	}
	else
	{
		count = 1;
		temp = start;
		while (count < position)
		{
			temp = temp->next;
			count++;

		}
		if (temp->next != NULL) 
		{
			if (temp == start)
			{

				start = temp->next;
				start->prev = NULL;
				dupdateOrigin(temp);
				dupdate(window,temp);
				return;
			}
			if (temp != start)
			{
				(temp->next)->prev = temp->prev;
				(temp->prev)->next = temp->next;
				dupdateOrigin(temp);
				dupdate(window, temp);
				return;
			}
		}
		else
		{
			if (temp == start) {
				start = NULL;
				dupdate(window, NULL);
				return;
			}
			else
			{
				temp->prev->next = NULL;
				dupdateOrigin(temp);
				dupdate(window, temp);
			}
		}
		
		
	}

}
int retNum()
{
	
	int count = 1;
	if (start != NULL) {
		Node* temp = start;
		while (temp->next != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
	else return 0;
	
	
}

void insertAfter(sf::RenderWindow* display, int position, int data)
{


	Node* newnode = newNode(data);
	if (start == NULL)
	{

		start = newnode;

		start->rect.setPosition(sf::Vector2f(150, 400));
		start->text.setPosition(sf::Vector2f(150, 400));
		update(display, newnode);
		return;
	}
	else
	{

		if (position != 0)
		{
			Node* temp;
			temp = start;
			int count = 0;
			while (count < (position - 1))
			{

				temp = temp->next;
				count++;
			}

			newnode->next = temp->next;
			newnode->prev = temp;
			if (temp->next != NULL)
			{
				temp->next->prev = newnode;
			}
			temp->next = newnode;


			updateOrigin(newnode);
			update(display, newnode);
		}
		if (position == 0)
		{


			newnode->next = start;
			start->prev = newnode;
			start = newnode;

			updateOrigin(newnode);
			update(display, newnode);
		}
		return;
	}





}

void dupdateOrigin(Node* t)
{
	Node* p = t->prev;
	if (t->next != NULL)
	{
		t = t->next;
		if (p != NULL)
		{

			while (t != NULL)
			{

				p = t->prev;
				sf::Vector2f pos = p->rect.getPosition();

				t->rect.setPosition(sf::Vector2f(pos.x +200, pos.y));
				t->text.setPosition(sf::Vector2f(pos.x + 200, pos.y));
				t = t->next;
			}

			return;
		}

		else if (p == NULL)
		{
			t->rect.setPosition(sf::Vector2f(150, 400));
			t->text.setPosition(sf::Vector2f(150, 400));
			t = t->next;
			while (t != NULL)
			{
				p = t->prev;
				sf::Vector2f pos = p->rect.getPosition();

				t->rect.setPosition(sf::Vector2f(pos.x+200, pos.y));
				t->text.setPosition(sf::Vector2f(pos.x + 200, pos.y));
				t = t->next;

			}

		}
	}
	
}
void updateOrigin(Node* t)
{
	
	
	Node* p = t->prev;
	
	if (p != NULL) 
	{
		
		while (t!= NULL)
		{

			p = t->prev;
			sf::Vector2f pos = p->rect.getPosition();
			
			t->rect.setPosition(sf::Vector2f(pos.x+200 , pos.y));
			t->text.setPosition(t->rect.getPosition());
			t = t->next;
		}
		
		return;
	}
	else
	{

		
		
		t->rect.setPosition(sf::Vector2f(150, 400));
		t->text.setPosition(sf::Vector2f(150, 400));
		t = t->next;
		while (t!= NULL) 
		{
			p = t->prev;
			sf::Vector2f pos = p->rect.getPosition();
			std::cout << pos.x << "     " << pos.y << std::endl;
			t->rect.setPosition(sf::Vector2f(pos.x + 200, pos.y));
			t->text.setPosition(t->rect.getPosition());
			t = t->next;
			
		}
	}
}
void dupdate(sf::RenderWindow* display, Node *n)
{
	if(n!=NULL)
	update(display,n->next);
	else {
		display->clear(sf::Color::Black);
		display->display();
		sf::Time time;
		sf::Clock clk;
		clk.restart();

		while (time.asMilliseconds() < 3000)
		{
			time = clk.getElapsedTime();

		}

	}
}
void update(sf::RenderWindow* dis,Node* n)
{
	sf::Text txt;
	sf::Font fnt;
	fnt.loadFromFile("times.ttf");
	txt.setFont(fnt);
	txt.setString("Press Space to hold the display");
	txt.setCharacterSize(40);
	txt.setPosition(sf::Vector2f(40, 40));
	txt.setFillColor(sf::Color::White);
	sf::CircleShape startPic;
	startPic.setRadius(40);
	startPic.setPosition(sf::Vector2f(150, 300));
	sf::Texture startTex;
	startTex.loadFromFile("Capture.jpg");
	startPic.setTexture(&startTex);
	sf::RectangleShape arrow;
	arrow.setSize(sf::Vector2f(40, 20));
	sf::Texture t;
	t.loadFromFile("Arrow1.jpg");
	arrow.setTexture(&t);
	sf::RectangleShape arrow2;
	arrow2.setSize(sf::Vector2f(40, 20));
	sf::Texture t2;
	t2.loadFromFile("Arrow2.jpg");
	arrow2.setTexture(&t2);
	sf::RectangleShape nullPic;
	nullPic.setSize(sf::Vector2f(60, 60));
	sf::Texture t3;
	t3.loadFromFile("Null.jpg");
	nullPic.setTexture(&t3);
	Node* temp;
	temp = start;
	
	dis->clear(sf::Color::Black);
	dis->draw(txt);
	dis->draw(startPic);
	arrow2.setPosition(sf::Vector2f(100, 400));
	dis->draw(arrow2);
	nullPic.setPosition(sf::Vector2f(40, 400));
	dis->draw(nullPic);
	while (temp != NULL) 
		{
		    if (temp == start)
			{
				temp->rect.setFillColor(sf::Color::Green);
			}
			else if (temp == n)
			{
				temp->rect.setFillColor(sf::Color::Red);
			}
			else temp->rect.setFillColor(sf::Color::Blue);
			
			dis->draw(temp->rect);
			arrow.setPosition(sf::Vector2f(temp->rect.getPosition().x+150, temp->rect.getPosition().y));
			arrow2.setPosition(sf::Vector2f(temp->rect.getPosition().x + 150, temp->rect.getPosition().y+40));
			dis->draw(arrow);
			if(temp->next!=NULL)
			dis->draw(arrow2);
			else
			{
				nullPic.setPosition(sf::Vector2f(temp->rect.getPosition().x + 200, temp->rect.getPosition().y ));
				dis->draw(nullPic);
			}
			dis->draw(temp->text);
			
			
			temp = temp->next;
		}
		dis->display();
		sf::Clock clk;
		sf::Time time;
		clk.restart();

		while (time.asMilliseconds() < 3000)
		{
			time = clk.getElapsedTime();

		}
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{

		}
	
	
	
	
	
}

void insert(sf::RenderWindow* window, char x, int options, char deleteOradd)
{
	int position, data;
	sf::Text head[2];
	sf::Text inputtext[20];
	sf::RectangleShape cursor;
	cursor.setSize(sf::Vector2f(3.0f, 40.0f));
	cursor.setOrigin(sf::Vector2f(0, 0));
	cursor.setPosition(sf::Vector2f(210, 310));
	cursor.setFillColor(sf::Color::Black);
	int i;
	int j;

	sf::RectangleShape rect[4][3], rectBig;
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 3; i++)
		{
			rect[j][i].setSize(sf::Vector2f(100, 100));
			rect[j][i].setOrigin(sf::Vector2f(0, 0));
			rect[j][i].setPosition(sf::Vector2f(200 + 100 * i, 400 + j * 100));
			rect[j][i].setFillColor(sf::Color::Magenta);
			rect[j][i].setOutlineThickness(10.0f);

			rect[j][i].setOutlineColor(sf::Color::Black);
		}
	}
	rectBig.setSize(sf::Vector2f(300, 500));
	rectBig.setOrigin(sf::Vector2f(0, 0));
	rectBig.setPosition(sf::Vector2f(200, 270));
	rectBig.setOutlineThickness(10.0f);
	rectBig.setOutlineColor(sf::Color::Green);
	sf::Font font;
	font.loadFromFile("times.ttf");
	for (i = 0; i < 2; i++) {
		head[i].setFont(font);
		head[i].setPosition(sf::Vector2f(190, 180));
		head[i].setCharacterSize(60);
		head[i].setFillColor(sf::Color::Blue);
	}
	head[0].setString(">>Insert the Position ");
	head[1].setString(">>Insert the data ");
	for (i = 0; i < 20; i++)
	{
		inputtext[i].setFont(font);
		inputtext[i].setPosition(sf::Vector2f(205, 300));
		inputtext[i].setCharacterSize(50);
		inputtext[i].setFillColor(sf::Color::Black);
	}
	int flag;
	if (x == 'P')
		flag = 0;
	else if (x == 'D' || deleteOradd=='R')
		flag = 1;
	

	sf::Text text[4][3];
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 3; i++)
		{
			text[j][i].setFont(font);
			text[j][i].setPosition(sf::Vector2f(225 + 100 * i, 400 + j * 100));
			text[j][i].setCharacterSize(70);
			text[j][i].setFillColor(sf::Color::Yellow);
		}
	}
	text[0][0].setString('1');
	text[0][1].setString("2");
	text[0][2].setString("3");
	text[1][0].setString("4");
	text[1][1].setString("5");
	text[1][2].setString("6");
	text[2][0].setString("7");
	text[2][1].setString("8");
	text[2][2].setString("9");
	text[3][0].setString("Clear");
	text[3][1].setString("0");
	text[3][2].setString("OK");
	text[3][0].setCharacterSize(35);
	text[3][0].setPosition(sf::Vector2f(205 + 100 * 0, 430 + 3 * 100));
	text[3][2].setCharacterSize(40);
	text[3][2].setPosition(sf::Vector2f(210 + 100 * 2, 430 + 3 * 100));
	int k = 1;
	sf::Clock clock;
	sf::Time t;
	clock.restart();
	int l = 0;

	int number = 0;

	int numberValue = 0;
	
	{
		while (window->isOpen())
		{

			window->clear(sf::Color::Black);
			sf::Event event;
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window->close();
			}
			if (flag == 0)
				window->draw(head[0]);
			else if (flag == 1 && deleteOradd == 'A')
				window->draw(head[1]);
			else if (flag == 1 && deleteOradd == 'R')
				window->draw(head[0]);
			window->draw(rectBig);
			for (i = 0; i < 20; i++) {
				window->draw(inputtext[i]);
			}
			t = clock.getElapsedTime();
			if (k == 1)
			{
				window->draw(cursor);
				if (t.asMilliseconds() > 500)
					k = 0;
			}
			{

				if (t.asMilliseconds() > 1000)
				{
					k = 1;
					clock.restart();
				}


			}
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 3; j++)
				{
					window->draw(rect[i][j]);
					window->draw(text[i][j]);
				}
			}

			window->display();
			sf::Vector2i mousePos = sf::Mouse::getPosition();
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (abs(mousePos.x) > rect[i][j].getPosition().x && abs(mousePos.x) < (rect[i][j].getPosition().x + rect[i][j].getSize().x) && abs(mousePos.y) > (rect[i][j].getPosition().y + 40) && abs(mousePos.y) < (rect[i][j].getPosition().y + rect[0][0].getSize().y + 40))
					{
						rect[i][j].setFillColor(sf::Color::White);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							if (!((i == 3 && j == 2) || (i == 3 && j == 0))) {
								inputtext[l].setString(text[i][j].getString());
								inputtext[l].setPosition(cursor.getPosition().x - 10, cursor.getPosition().y);
								cursor.move(sf::Vector2f(25, 0));
								l++;
							}

							//Backspace
							if (i == 3 && j == 0)
							{
								cursor.move(sf::Vector2f(-25, 0));
								if (cursor.getPosition().x < 210)
									cursor.setPosition(sf::Vector2f(210, 310));

								else l--;


							}
							inputtext[l].setString("");
							std::string  ch[20];
							int T = l;
							//OK
							if (i == 3 && j == 2)
							{
								int f = 0;
								while (inputtext[f].getString() != "")
								{
									ch[f] = inputtext[f].getString();

									std::stringstream(ch[f]) >> numberValue;
									number += numberValue * powf(10, T - f - 1);
									f++;
								}
								if (flag == 0) {
									position = number;
									if (position >( retNum()))
										return;
								}
								else if (flag == 1 )
									data = number;

								f = 0;
								while (inputtext[f].getString() != "")
								{
									inputtext[f].setString("");
									f++;

								}

								cursor.setPosition(sf::Vector2f(210, 310));
								l = 0;
								if (flag == 1)
								{
									if (deleteOradd == 'A') {
										if (options == 0) {
											window->clear(sf::Color::Black);
											window->display();
											insertAfter(window, 0, data);
											return;
										}
										else if (options == 2)
										{
											window->clear(sf::Color::Black);
											window->display();
											
											insertAfter(window, position, data);
											return;
										}
										else if (options == 1)
										{
											window->clear(sf::Color::Black);
											window->display();
											insertAfter(window, retNum(), data);
											return;
										}
									}
									if (deleteOradd == 'R') {
										
										
										{
											if (data > retNum())
											{
												return;
											}
											window->clear(sf::Color::Black);
											window->display();
											deleteAtPos(window,data);
											return;
										}
									}
								}
								number = 0;
								if (flag == 0)
									flag = 1;
								else flag = 0;
							}

							sf::Clock clk;
							sf::Time time;
							clock.restart();

							while (time.asMilliseconds() < 200)
							{
								time = clock.getElapsedTime();

							}
						}
					}
					else rect[i][j].setFillColor(sf::Color::Magenta);
				}
			}
		}
	}

	
}
void insOption(int x, sf::RenderWindow* window)
{
	
	
	sf::RectangleShape rect[3];
	sf::Text text[3];
	sf::Font font;
	font.loadFromFile("times.ttf");
	for (int i = 0; i < 3; i++)
	{
		text[i].setFont(font);

		rect[i].setOrigin(sf::Vector2f(0, 0));
		rect[i].setPosition(sf::Vector2f(300, 205 + i * 100));
		text[i].setPosition(sf::Vector2f(305, 205 + i * 100));
		text[i].setCharacterSize(65);
		text[i].setFillColor(sf::Color::Black);
		rect[i].setFillColor(sf::Color::White);
		rect[i].setSize(sf::Vector2f(800, 100));
		rect[i].setOutlineThickness(10);
		rect[i].setOutlineColor(sf::Color::Yellow);
	}
	if (x == 0) 
	{
		text[0].setString(">>Insert At Beginning ");
		text[1].setString(">>Insert At Last ");
		text[2].setString(">>Insert after certain position ");
	}
	else if (x == 1)
	{
		text[0].setString(">>Delete At Beginning ");
		text[1].setString(">>Delete At Last ");
		text[2].setString(">>Delete at certain position ");
	}
		while (window->isOpen())
	{
		window->clear(sf::Color::Black);
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		for (int i = 0; i < 3; i++)
		{
			window->draw(rect[i]);
			window->draw(text[i]);
		}
		
		window->display();
		sf::Vector2i mousePos = sf::Mouse::getPosition();
		for (int i = 0; i < 3; i++)
		{
			if (abs(mousePos.x) > rect[i].getPosition().x && abs(mousePos.x) < (rect[i].getPosition().x + rect[i].getSize().x) && abs(mousePos.y) > (rect[i].getPosition().y + 40) && abs(mousePos.y) < (rect[i].getPosition().y + rect[0].getSize().y + 40))
			{
				rect[i].setFillColor(sf::Color::White);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (x == 0) 
					{
						if (i == 0)
						{
							insert(window, 'D',0,'A');
							return;
						}
						else if (i == 1)
						{
							insert(window, 'D', 1,'A');
							return;
						}
						else if (i == 2)
						{
							insert(window, 'P', 2,'A');
							return;
						}
						
					}
					else if (x == 1)
					{
						if (i == 0)
						{
							deleteAtPos(window, 1);
							sf::Clock clock;
							sf::Time time;
							clock.restart();

							while (time.asMilliseconds() < 200)
							{
								time = clock.getElapsedTime();

							}
							return;
						}
						else if (i == 1)
						{
							deleteAtPos(window, retNum());
							sf::Clock clock;
							sf::Time time;
							clock.restart();

							while (time.asMilliseconds() < 200)
							{
								time = clock.getElapsedTime();

							}
							return;
						}
						else if (i == 2)
						{
							insert(window, 'D', 2,'R');
							return;
						}
					}
				}
			}
			else rect[i].setFillColor(sf::Color::Magenta);
		}
	}
	
}
void Options( sf::RenderWindow* window)
	{
	
	
	sf::RectangleShape rect[2];
	sf::Text text[2];
	sf::Font font;
	font.loadFromFile("times.ttf");
	
	for (int i = 0; i < 2; i++)
	{
		text[i].setFont(font);
		
		rect[i].setOrigin(sf::Vector2f(0, 0));
		rect[i].setPosition(sf::Vector2f(300, 205 + i * 100));
		text[i].setPosition(sf::Vector2f(305, 205 + i * 100));
		text[i].setCharacterSize(80);
		text[i].setFillColor(sf::Color::Black);
		rect[i].setFillColor(sf::Color::White);
		rect[i].setSize(sf::Vector2f(500,100));
		rect[i].setOutlineThickness(10);
		rect[i].setOutlineColor(sf::Color::Yellow);
	}
	text[0].setString("Insert ");
	text[1].setString("Delete ");
	
	while (window->isOpen())
	{
		window->clear(sf::Color::Black);
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		for (int i = 0; i < 2; i++)
		{
			window->draw(rect[i]);
			window->draw(text[i]);
		}

		
		window->display();
		sf::Vector2i mousePos = sf::Mouse::getPosition();
		for (int i = 0; i < 2; i++)
		{
			if (abs(mousePos.x) > rect[i].getPosition().x && abs(mousePos.x) < (rect[i].getPosition().x + rect[i].getSize().x) && abs(mousePos.y) > (rect[i].getPosition().y + 40) && abs(mousePos.y) < (rect[i].getPosition().y + rect[0].getSize().y + 40))
			{
				rect[i].setFillColor(sf::Color::White);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					sf::Clock clk;
					sf::Time time;
					clk.restart();

					while (time.asMilliseconds() < 400)
					{
						time = clk.getElapsedTime();

					}
					if (i == 0)
						insOption(0, window);
					else if (i == 1)
						insOption(1, window);
				}
			}
			else rect[i].setFillColor(sf::Color::Magenta);
		}
		
		
		
		
	}
}
 

void Createwindow()
{
	
	sf::RenderWindow window(sf::VideoMode(1600, 920), "Linked List");
	
	sf::Texture text;
	text.loadFromFile("S.png");
	sf::Sprite sprite;
	sprite.setTexture(text);
	

	sprite.setOrigin(sf::Vector2f(-50, -200));
	
	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

	          window.draw(sprite);
		
		window.display();
		sf::Vector2i mousePos = sf::Mouse::getPosition();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (abs(mousePos.x) > 420 && abs(mousePos.x) < 1230 && abs(mousePos.y) > 444 && abs(mousePos.y) < 687)) 
		{
			//insert(&window);
			Options(&window);
			sf::Clock clock;
			sf::Time time;
			clock.restart();

			while (time.asMilliseconds() < 200)
			{
				time = clock.getElapsedTime();

			}
			
			
		}
		

	}
	
	
	
	
}
int main()
{
	
	Createwindow();
}
