#include "Visitor.hpp"
#include <iostream>
#include <vector>

class Square;
class Circle;
class Triangle;

class ShapeVisitor : public Visitor<Square, Circle, Triangle>
{
};
class Shape : public Visitable<ShapeVisitor>
{
};

class Square : public Shape
{
  void accept(ShapeVisitor& visitor)
  {
    visitor.visit(*this);
  }
};

class Circle : public Shape
{
  void accept(ShapeVisitor& visitor)
  {
    visitor.visit(*this);
  }
};

class Triangle : public Shape
{
  void accept(ShapeVisitor& visitor)
  {
    visitor.visit(*this);
  }
};

//*****************************************************************
// The 'draw' visitor.
//*****************************************************************
class DrawVisitor : public ShapeVisitor
{
public:
  void visit(Square& square)
  {
    std::cout << "Draw the square\n";
  }

  void visit(Circle& circle)
  {
    std::cout << "Draw the circle\n";
  }

  void visit(Triangle& triangle)
  {
    std::cout << "Draw the triangle\n";
  }
};

//*****************************************************************
// The 'serialise' visitor.
//*****************************************************************
class SerialiseVisitor : public ShapeVisitor
{
public:
  void visit(Square& square)
  {
    std::cout << "Serialise the square\n";
  }

  void visit(Circle& circle)
  {
    std::cout << "Serialise the circle\n";
  }

  void visit(Triangle& triangle)
  {
    std::cout << "Serialise the triangle\n";
  }
};

void apply(ShapeVisitor& visitor, std::vector<Shape*> shape_list)
{
  for (std::vector<Shape*>::size_type i = 0; i < shape_list.size(); ++i)
  {
    // Send the visitor to the shape.
    shape_list[i]->accept(visitor);
  }
}

int main() {
  Square square;
  Circle circle;
  Triangle triangle;

  std::vector<Shape*> shapes;
  shapes.push_back(&square);
  shapes.push_back(&circle);
  shapes.push_back(&triangle);

  DrawVisitor drawVisitor;
  SerialiseVisitor serialiseVisitor;

  apply(drawVisitor,shapes);
  apply(serialiseVisitor,shapes);

  return 0;
}