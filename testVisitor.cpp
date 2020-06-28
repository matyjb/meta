#include "Visitor.hpp"
#include <iostream>
#include <vector>

class Mesh;
class Text;
class Button;

class GameObjectVisitor : public Visitor<Mesh, Text, Button> {};
class Mesh : public VisitableImpl<Mesh,GameObjectVisitor>{};
class Text : public VisitableImpl<Text,GameObjectVisitor>{};
class Button : public VisitableImpl<Button,GameObjectVisitor>{};

class Renderer : public GameObjectVisitor
{
public:
  void visit(Mesh& Mesh)
  {
    std::cout << "Rendering mesh\n";
  }

  void visit(Text& Text)
  {
    std::cout << "Rendering text\n";
  }

  void visit(Button& Text)
  {
    std::cout << "Rendering button\n";
  }
};

class ShaderAllBlue : public GameObjectVisitor
{
public:
  void visit(Mesh& Mesh)
  {
    std::cout << "Caly mesh na niebiesko\n";
  }

  void visit(Text& Text)
  {
    std::cout << "Caly text na niebiesko\n";
  }

  void visit(Button& Text)
  {
    std::cout << "Caly button na niebiesko\n";
  }
};



// pomocnicza funkcja
void apply(GameObjectVisitor& visitor, std::vector<Visitable<GameObjectVisitor>*> gameObject_list)
{
  for (std::vector<Visitable<GameObjectVisitor>*>::size_type i = 0; i < gameObject_list.size(); ++i)
  {
	  gameObject_list[i]->accept(visitor);
  }
}

int main() {
  Mesh mesh;
  Text text;
  Button button;

  std::vector<Visitable<GameObjectVisitor>*> gameObjects;
  gameObjects.push_back(&mesh);
  gameObjects.push_back(&text);
  gameObjects.push_back(&button);

  ShaderAllBlue allBlueShader;
  Renderer renderer;

  apply(renderer, gameObjects);
  apply(allBlueShader, gameObjects);

  return 0;
}
