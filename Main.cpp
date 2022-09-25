#include <Engine.h>

int main()
{
	sf::RenderWindow m_pencere(sf::VideoMode(1000, 600), "EEG Engine - OpenGL");
	ImGui::SFML::Init(m_pencere);

	bool goster = true;
	float buyutkucut = 200.0f;
	int sekil = 100;
	float renk[3] = { (float)204 / 255, (float)77 / 255, (float)5 / 255, };
	float positionX = 400;
	float positionY = 400;
	sf::CircleShape daire(buyutkucut, sekil);
	daire.setFillColor(sf::Color(
		(int)(renk[0] * 255),
		(int)(renk[1] * 255),
		(int)(renk[2] * 255)
	));
	daire.setOrigin(positionX, positionY);

	while (m_pencere.isOpen())
	{
		sf::Event olay;
		sf::Clock zaman;

		while (m_pencere.pollEvent(olay))
		{
			ImGui::SFML::ProcessEvent(olay);
			if (olay.type == sf::Event::Closed)
			{
				m_pencere.close();
			}
		}
		ImGui::SFML::Update(m_pencere, zaman.restart());

		ImGui::Begin("Ev");	
		ImGui::Text("Build 1005 = EEG Engine Test Edirmektedir!");
		ImGui::Text("Resim Mode");
		ImGui::Checkbox("Goster", &goster);
		ImGui::SliderFloat("Buyut Kucut", &buyutkucut, 100.0f, 300.0f);
		ImGui::SliderInt("Sekil", &sekil, 3, 150);
		ImGui::ColorEdit3("Renk Degisim", renk);
		ImGui::Text("X ve Y Position");
		ImGui::SliderFloat("X", &positionX, 100.0f, 1000.0f);
		ImGui::SliderFloat("Y", &positionY, 100.0f, 600.0f);
		ImGui::End();

		daire.setRadius(buyutkucut);
		daire.setPointCount(sekil);
		daire.setFillColor(sf::Color(
			(int)(renk[0] * 255),
			(int)(renk[1] * 255),
			(int)(renk[2] * 255)
		));
		daire.setOrigin(buyutkucut, buyutkucut);
		daire.setPosition(positionX, positionY);

		m_pencere.clear(sf::Color(20, 30, 40));
		if (goster)
		{
			m_pencere.draw(daire);
		}
		ImGui::SFML::Render(m_pencere);
		m_pencere.display();
	}
	ImGui::SFML::Shutdown(m_pencere);
}